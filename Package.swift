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
            url: "https://github.com/bugfender/BugfenderSDK-iOS/releases/download/1.10.6/BugfenderSDK.xcframework.zip",
            checksum: "36c2ced3a7f3b43e50db44c19187411e0b748369cd5a32a4335a8c5632b97544"
        )
    ]
)
