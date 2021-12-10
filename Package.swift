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
            url: "https://github.com/bugfender/BugfenderSDK-iOS/releases/download/1.10.5/BugfenderSDK.xcframework.zip",
            checksum: "267406342acb0336a5dfde917637f30d20c4027e6d9a5ab7541ce3a109dc260d"
        )
    ]
)
