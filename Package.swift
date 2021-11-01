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
            url: "https://github.com/bugfender/BugfenderSDK-iOS/releases/download/1.10.4/BugfenderSDK.xcframework.zip",
            checksum: "9f4e450b3e67211405fe5ea53f02c8ec54a8d13b0c1954db41e66b7197678c76"
        )
    ]
)
