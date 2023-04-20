#!/usr/bin/env bash
set -e

token=${1:-$BUGFENDER_SYMBOLICATION_TOKEN}
if [ -z "$token" ]; then
    echo 'Symbolication Token is required'
    exit 0 # Do not fail, we don't want to break people's BC builds
fi
url=${BUGFENDER_SYMBOLICATION_URL:-https://dashboard.bugfender.com/}
[[ "$url" != */ ]] && url="$url/"

version=$MARKETING_VERSION
build=$CURRENT_PROJECT_VERSION

dsympath="$DWARF_DSYM_FOLDER_PATH/$DWARF_DSYM_FILE_NAME"
if [ -f "$dsympath" ] && [ ! -s "$dsympath" ]; then
    echo 'dSYM path leads to an empty file'
    echo 'Check that you are not hitting https://developer.apple.com/forums/thread/659187'
    exit 0 # Do not fail, we don't want to break people's BC builds
fi
if [ -z "$(find "$dsympath" -type f)" ]; then
    echo 'No files found inside dSYM bundle'
    echo 'Probably a BitCode enabled build?'
    echo 'For now, these have to have symbols uploaded manually through the Dashboard'
    exit 0 # Do not fail, we don't want to break people's BC builds
fi

tempdir=$(mktemp -d -t 'bugfender')
zippath="$tempdir/dSYMs.zip"
function cleanup {
    rm -f "$zippath"
    rmdir "$tempdir"
}
trap cleanup EXIT

zip -r "$zippath" "$dsympath"

resp=$(curl -i# \
    -H "Authorization: Bearer $token" \
    -F version="$version" \
    -F build="$build" \
    -F file=@"$zippath" \
    "${url}api/upload-symbols"
)
statuscode=$(echo "$resp" | head -n1 | cut -d' ' -f2)
if [ "$statuscode" -eq 100 ]; then
    statuscode=$(echo "$resp" | head -n3 | tail -n1 | cut -d' ' -f2)
fi
if [ "$statuscode" -ne 200 ]; then
    message=$(echo "$resp" | tail -n1)
    echo "Upload failed with code $statuscode and message: $message"
    exit 0 # Do not fail, we don't want to break people's BC builds
fi
