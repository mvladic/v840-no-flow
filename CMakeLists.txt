cmake_minimum_required(VERSION 3.12)
project (v8-no-flow-no-eez-framework)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -s USE_SDL=2")
set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -O2 -s USE_SDL=2")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -s INITIAL_MEMORY=83886080 -sLLD_REPORT_UNDEFINED -s USE_SDL=2 -L/opt/freetype-2.14.1/build -lfreetype")

include_directories(
    ${PROJECT_SOURCE_DIR}
    /opt/freetype-2.14.1/include
)

add_subdirectory(lvgl)
add_subdirectory(lv_drivers)
file(GLOB MY_SOURCES "./*.c")
set(SOURCES ${MY_SOURCES})

file(GLOB_RECURSE my_src
    ./src/*.cpp
    ./src/*.c
)
list(APPEND SOURCES ${my_src})

add_executable(index ${SOURCES} ${INCLUDES})

set(CMAKE_EXECUTABLE_SUFFIX ".html")
target_link_libraries(index
    lvgl
    lv_drivers
)
set_target_properties(index PROPERTIES LINK_FLAGS "--shell-file ${PROJECT_SOURCE_DIR}/index.html --preload-file ${PROJECT_SOURCE_DIR}/Oswald-Medium.ttf@/Oswald-Medium.ttf")
