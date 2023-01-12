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
            url: "https://github.com/bugfender/BugfenderSDK-iOS/releases/download/1.11.0/BugfenderSDK.xcframework.zip",
            checksum: "8683af1363a023f3217a70ca4ca826d8d32e511a223c79da9dd79eab74b33845"
        )
    ]
)
