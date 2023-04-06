// swift-tools-version:5.3

import PackageDescription

let package = Package(
    name: "BugfenderPackage",
    platforms: [
        .iOS("11")
    ],
    products: [
        .library(
            name: "BugfenderLibrary",
            targets: ["BugfenderSDK"])
    ],
    targets: [
        .binaryTarget(
            name: "BugfenderSDK",
            url: "https://github.com/bugfender/BugfenderSDK-iOS/releases/download/1.12.1/BugfenderSDK.xcframework.zip",
            checksum: "693d80368a4dabacd7b8c3720e543448ac7b32fe262445f7c9f804fe106242cf"
        )
    ]
)
