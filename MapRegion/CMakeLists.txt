include_directories(${PROJECT_SOURCE_DIR}/HexMap/include)
include_directories(${PROJECT_SOURCE_DIR}/Utils/include)

set(SOURCES src/MapRegion.cpp)

add_library(MapRegion ${SOURCES})
