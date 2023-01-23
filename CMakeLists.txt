cmake_minimum_required(VERSION 3.7)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_definitions(-std=c++17)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

project(SortVisualizer)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} src)

find_package(SDL2_ttf REQUIRED)
include_directories(${SDL2_TTF_INCLUDE_DIR})

add_executable(VisualSortAlgo src/main.cpp src/sortvisualizer.cpp src/controller.cpp src/renderer.cpp src/visualizerstatemachine.cpp src/menustatemachine.cpp )

string(STRIP ${SDL2_LIBRARIES} SDL2_LIBRARIES)
target_link_libraries(VisualSortAlgo ${SDL2_LIBRARIES})
target_link_libraries(VisualSortAlgo ${SDL2_LIBRARY} ${SDL2_TTF_LIBRARY})
