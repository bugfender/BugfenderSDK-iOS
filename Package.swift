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
            url: "https://github.com/bugfender/BugfenderSDK-iOS/releases/download/3.0.0/BugfenderSDK.xcframework.zip",
            checksum: "ddc59e9c662ebce82c4ce4d2958206ed85e6b5e1ef587452221758109a18affa"
        )
    ]
)
