cmake_minimum_required(VERSION 3.1.0)

project(ibapi LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)

include_directories(
${CMAKE_SOURCE_DIR}/external/twsapi
${CMAKE_SOURCE_DIR}/external/qcustomplot
${CMAKE_SOURCE_DIR}/include/App
${CMAKE_SOURCE_DIR}/include/View
${CMAKE_SOURCE_DIR}/include/IbHandle
${CMAKE_SOURCE_DIR}/include/Utils
${CMAKE_SOURCE_DIR}/include/Model
${CMAKE_SOURCE_DIR}/include/Controller

)

add_subdirectory(external)
add_subdirectory(source)


