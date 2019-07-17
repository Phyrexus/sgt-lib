include_directories(${PROJECT_SOURCE_DIR}/Faction/include)
include_directories(${PROJECT_SOURCE_DIR}/HexMap/include)
include_directories(${PROJECT_SOURCE_DIR}/Sector/include)

set(TEST_SOURCES src/Tests.cpp
                 src/FactionTests.cpp
                 src/HexMapTests.cpp
                 src/SectorTests.cpp)

add_executable(tests ${TEST_SOURCES})
target_link_libraries(tests sgt)
