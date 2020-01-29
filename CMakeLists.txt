cmake_minimum_required(VERSION 3.16)

project(sgt LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

find_package(catch)
include_directories(${catch_INCLUDE_DIR})

# Includes
include_directories(${PROJECT_SOURCE_DIR}/Faction/include)
include_directories(${PROJECT_SOURCE_DIR}/HexMap/include)
include_directories(${PROJECT_SOURCE_DIR}/MapRegion/include)
include_directories(${PROJECT_SOURCE_DIR}/Utils/include)
include_directories(${PROJECT_SOURCE_DIR}/Tests/include)

# Subdirectories
add_subdirectory(Faction)
add_subdirectory(HexMap)
add_subdirectory(MapRegion)
add_subdirectory(Utils)
add_subdirectory(Tests)

add_library(${PROJECT_NAME} SHARED ${SOURCES})
