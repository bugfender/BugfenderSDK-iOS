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
            url: "https://github.com/bugfender/BugfenderSDK-iOS/releases/download/3.0.1/BugfenderSDK.xcframework.zip",
            checksum: "473596c40ee44f80a7184c236ca18734e2413cc8aaef577a023c478d6153ca47"
        )
    ]
)
