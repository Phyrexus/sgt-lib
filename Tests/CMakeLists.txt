include_directories(${PROJECT_SOURCE_DIR}/HexMap/include)

set(TEST_SOURCES src/Tests.cpp
                 src/HexMapTests.cpp)

add_executable(tests ${TEST_SOURCES})
target_link_libraries(tests HexMap)
