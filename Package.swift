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
            url: "https://github.com/bugfender/BugfenderSDK-iOS/releases/download/1.10.0/BugfenderSDK.xcframework.zip",
            checksum: "3fd533eac972d4eae42da0169918f349f90f15dd6d6847aa12308e40768f9fee"
        )
    ]
)
