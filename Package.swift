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
            url: "https://github.com/bugfender/BugfenderSDK-iOS/releases/download/2.0.1/BugfenderSDK.xcframework.zip",
            checksum: "08f8d986e21601cadea8568fcee60955efa02d3697e57683b3e741072a65659b"
        )
    ]
)
