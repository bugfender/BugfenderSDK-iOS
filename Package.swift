// swift-tools-version:5.3

import PackageDescription

let package = Package(
    name: "BugfenderPackage",
    platforms: [
        .iOS("10")
    ],
    products: [
        .library(
            name: "BugfenderLibrary",
            targets: ["BugfenderSDK"])
    ],
    targets: [
        .binaryTarget(
            name: "BugfenderSDK",
            url: "https://github.com/bugfender/BugfenderSDK-iOS/releases/download/1.10.1/BugfenderSDK.xcframework.zip",
            checksum: "72f3f43189f12049ba6c42eee269a034dce2d4c6cc4c968f76efa2a6cb95eec5"
        )
    ]
)
