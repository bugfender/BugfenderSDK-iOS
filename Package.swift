// swift-tools-version:5.3

import PackageDescription

let package = Package(
    name: "BugfenderPackage",
    platforms: [
        .iOS("15")
    ],
    products: [
        .library(
            name: "BugfenderLibrary",
            targets: ["BugfenderSDK"])
    ],
    targets: [
        .binaryTarget(
            name: "BugfenderSDK",
            url: "https://github.com/bugfender/BugfenderSDK-iOS/releases/download/3.1.1/BugfenderSDK.xcframework.zip",
            checksum: "7f96aeb0cfe831bfaa6714315d4b578fe3fd31620aaa90bc61df762c3ed32d81"
        )
    ]
)
