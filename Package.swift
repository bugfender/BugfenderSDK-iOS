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
            url: "https://github.com/bugfender/BugfenderSDK-iOS/releases/download/2.2.0/BugfenderSDK.xcframework.zip",
            checksum: "e2d7903692878ff8cf6888a9547c4bb755570bdbd16ce5cc2dd06beb4440880e"
        )
    ]
)
