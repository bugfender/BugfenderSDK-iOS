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
            url: "https://github.com/bugfender/BugfenderSDK-iOS/releases/download/3.1.0/BugfenderSDK.xcframework.zip",
            checksum: "70af6d56872d060d46624531dab81756b9c8148d6e3c5cd44575a7e320dc96ac"
        )
    ]
)
