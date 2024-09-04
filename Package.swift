// swift-tools-version:5.3

import PackageDescription

let package = Package(
    name: "BugfenderPackage",
    platforms: [
        .iOS("12")
    ],
    products: [
        .library(
            name: "BugfenderLibrary",
            targets: ["BugfenderSDK"])
    ],
    targets: [
        .binaryTarget(
            name: "BugfenderSDK",
            url: "https://github.com/bugfender/BugfenderSDK-iOS/releases/download/2.0.0/BugfenderSDK.xcframework.zip",
            checksum: "bb093f8d0467dbcabf891a9809ba7b8d3022255ba17397737640554b50c0a20a"
        )
    ]
)
