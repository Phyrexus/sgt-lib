cmake_minimum_required(VERSION 3.9)

set(PROJECT_NAME sgt)
project(${PROJECT_NAME} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

# Check for required external libs
include_directories(${PROJECT_SOURCE_DIR}/include/catch)
include_directories(${PROJECT_SOURCE_DIR}/include/cereal)
include_directories(${PROJECT_SOURCE_DIR}/include/fmt)
include_directories(${PROJECT_SOURCE_DIR}/include/spdlog)

# Faction
include_directories(${PROJECT_SOURCE_DIR}/Faction/include)
add_subdirectory(Faction)

# HexMap
include_directories(${PROJECT_SOURCE_DIR}/HexMap/include)
add_subdirectory(HexMap)

# MapRegion
include_directories(${PROJECT_SOURCE_DIR}/MapRegion/include)
add_subdirectory(MapRegion)

# Urils
include_directories(${PROJECT_SOURCE_DIR}/Utils/include)

# Tests
include_directories(${PROJECT_SOURCE_DIR}/Tests/include)
add_subdirectory(Tests)

set(LIBS Faction HexMap MapRegion)

add_library(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} ${LIBS})
