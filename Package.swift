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
            url: "https://github.com/bugfender/BugfenderSDK-iOS/releases/download/1.12.2/BugfenderSDK.xcframework.zip",
            checksum: "b1cbe24fc89935fae89de0724ea8901c093a0b3e59823e8dac912eb4c90fc620"
        )
    ]
)
