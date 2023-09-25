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
            url: "https://github.com/bugfender/BugfenderSDK-iOS/releases/download/1.13.1/BugfenderSDK.xcframework.zip",
            checksum: "8b445e48e2d8a431d5b10d8beb86804f01f4a228d6da4ed9f3119d9b7d3bc224"
        )
    ]
)
