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
            url: "https://github.com/bugfender/BugfenderSDK-iOS/releases/download/2.1.0/BugfenderSDK.xcframework.zip",
            checksum: "04e27940a53f0888b7a64620a61ff2dd7b660c79013cd919daa765e0f174976a"
        )
    ]
)
