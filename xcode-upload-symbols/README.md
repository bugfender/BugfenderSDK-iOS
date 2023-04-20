Bugfender iOS Symbols Upload Script
===================================

Used to automatically upload dSYM bundles to [Bugfender](https://bugfender.com).

Our upload script is meant to be executed locally from the Xcode build environment. It may not yet function in Xcode Cloud.

## Enable Symbol Creation

1. Open project settings.

1. Select your main target from the *TARGETS* list on the left.

1. Select the *Build Settings* tab.

1. Ensure that `Debug Information Format` is set to `DWARF with dSYM File`.

## Configure Build to Upload Symbols

1. Open project settings.

1. Select your main target from the *TARGETS* list on the left.

1. Select the *Build Phases* tab.

1. Open menu under the `+` sign and select *New Run Script Phase*.

1. Configure the new *Run Script* as follows:

    * If you are using CocoaPods:
      ```sh
      ${PODS_ROOT}/BugfenderSDK/upload-symbols.sh <bugfender_symbolication_token>
      ```

    * If you using SPM:

      ```sh
      BUGFENDER_SYMBOLICATION_URL=https://dashboard.bugfender.com/ ${BUILD_DIR%Build/*}SourcePackages/checkouts/BugfenderSDK-iOS/xcode-upload-symbols/upload-symbols.sh <bugfender_symbolication_token>
      ```
      
    * If you copied the script manually:
      ```sh
      <path_to_the_script>/upload-symbols.sh <bugfender_symbolication_token>
      ```   

    * The **bugfender symbolication token** can be obtained from the Bugfender Dashboard and needs to be specified either as a first argument to the script or setting the `BUGFENDER_SYMBOLICATION_TOKEN` environment variable.
  
1. Under the "Input Files" section, add the following path. This will provide access to the debug symbols to our upload script.

    `${DWARF_DSYM_FOLDER_PATH}/${DWARF_DSYM_FILE_NAME}/Contents/Resources/DWARF/${TARGET_NAME}`

1. Done! Here is a screenshot of what the complete settings would look like if you were using SPM.

![XCode Build Phases](/xcode-upload-symbols/xcode.png)
