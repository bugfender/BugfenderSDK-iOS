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
            url: "https://github.com/bugfender/BugfenderSDK-iOS/releases/download/1.9.3/BugfenderSDK.xcframework.zip",
            checksum: "99616fae3dfc5a0513c2105e8ae9a7934945e3a7a4598fab992aef4452c124c2"
        )
    ]
)
