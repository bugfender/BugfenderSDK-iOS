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
            url: "https://github.com/bugfender/BugfenderSDK-iOS/releases/download/1.13.2/BugfenderSDK.xcframework.zip",
            checksum: "43c50a80ead9a73a2d99c327ec77e476fb6aa4b150df03d94292444ecdc01db5"
        )
    ]
)
