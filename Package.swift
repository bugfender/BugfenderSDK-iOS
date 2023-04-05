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
            url: "https://github.com/bugfender/BugfenderSDK-iOS/releases/download/1.12.0/BugfenderSDK.xcframework.zip",
            checksum: "3af060b50c0e0441362429cb739b30766eb8f3fcc24df722e3d3e2311050f8da"
        )
    ]
)
