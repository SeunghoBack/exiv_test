cmake_minimum_required(VERSION 3.15)
project(exiv_test)

set(CMAKE_CXX_STANDARD 14)

if(CMAKE_HOST_SYSTEM_PROCESSOR STREQUAL x86_64 OR CMAKE_HOST_SYSTEM_PROCESSOR STREQUAL amd64)
    set(EXIV2_LIBRARY_DIR $ENV{HOME}/exiv2/lib)
else()
    set(EXIV2_LIBRARY_DIR $ENV{HOME}/exiv2/lib_aarch64)
endif()

include_directories(
        .
        /home/nvidia/exiv2/include
)

link_directories(
        ${EXIV2_LIBRARY_DIR}
)

add_executable(exiv_test
        exif.cpp)

target_link_libraries(exiv_test
        exiv2
        )
