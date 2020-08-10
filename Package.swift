// swift-tools-version:5.3

import PackageDescription

let package = Package(
    name: "BugfenderSDK",
    platforms: [
        .iOS("10")
    ],
    products: [
        .library(
            name: "BugfenderSDK",
            targets: ["BugfenderSDK"])
    ],
    dependencies: [],
    targets: [
        .binaryTarget(
            name: "BugfenderSDK",
            url: "https://github.com/bugfender/BugfenderSDK-iOS/files/5052642/BugfenderSDK.xcframework.zip",
            checksum: "0224e7d0c227a3c01ccebd77fd56c674464831cdb52c10e323e5af4377bde199"
        )
    ]
)
