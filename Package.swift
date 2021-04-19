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
            url: "https://github.com/bugfender/BugfenderSDK-iOS/releases/download/1.10.2/BugfenderSDK.xcframework.zip",
            checksum: "21b546d1d32fe606bf30eb96ef85c13e657c7a09d5f399c3defe600717752c5a"
        )
    ]
)
