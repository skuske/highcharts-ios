// swift-tools-version:5.3
// The swift-tools-version declares the minimum version of Swift required to build this package.
// Copyright (c) 2009-2024 Highsoft AS

import PackageDescription

let package = Package(name: "Highcharts",
                      platforms: [.iOS(.v12)],
                      products: [.library(name: "Highcharts",
                                          targets: ["Highcharts"])],
                      targets: [.binaryTarget(name: "Highcharts",
                                              path: "Highcharts.xcframework")])
