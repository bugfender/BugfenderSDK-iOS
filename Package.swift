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
            url: "https://github.com/bugfender/BugfenderSDK-iOS/releases/download/1.10.3/BugfenderSDK.xcframework.zip",
            checksum: "cbd389371f6cdf3e49eb429e7a69c9f4b40f9a7d9728200c81e249dbddf2b509"
        )
    ]
)
