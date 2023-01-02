#
# Created by lukas koehler on 21.08.18.
#

cmake_minimum_required(VERSION 3.0)
project(SWE_2019_CocktailPro)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -Wfloat-equal -Wundef -Wcast-align -Wwrite-strings -Wlogical-op -Wmissing-declarations -Wredundant-decls -Wshadow -Woverloaded-virtual")

#find_program(CMAKE_CXX_CPPCHECK NAMES cppcheck)
#if (CMAKE_CXX_CPPCHECK)
#    list(
#            APPEND CMAKE_CXX_CPPCHECK
#            "--suppress=missingIncludeSystem"
#            "--inline-suppr"
#            "--enable=all"
#            "--language=c++"
#            "--std=c++11"
#            "--quiet"
#
#    )
#endif()

find_package (Threads)

include(ExternalProject)
ExternalProject_Add(gtest
        URL https://github.com/google/googletest/archive/release-1.8.1.zip
        PREFIX ${CMAKE_CURRENT_BINARY_DIR}/gtest
        INSTALL_COMMAND ""
        )
ExternalProject_Get_Property(gtest source_dir binary_dir)

file(GLOB src
        "main/main.cpp"
        "*.h"
        "*.cpp"
        )

file(GLOB src_testing
        "main/Main_TestAll.cpp"
        "Test/*.cpp"
        "*.h"
        "*.cpp"
        )

add_executable(SWE_2019_CocktailPro ${src})
add_executable(SWE_2019_CocktailPro_Test ${src_testing} Test/Recipe_Test.cpp Test/Mixer_Test.cpp Test/Waage_Test.cpp)
target_include_directories(SWE_2019_CocktailPro_Test PRIVATE ./)
target_include_directories(SWE_2019_CocktailPro PRIVATE ./)

add_dependencies(SWE_2019_CocktailPro_Test gtest)
include_directories(${source_dir}/googletest/include)
target_link_libraries(SWE_2019_CocktailPro_Test ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(SWE_2019_CocktailPro_Test ${binary_dir}/googlemock/gtest/libgtest.a)
target_link_libraries(SWE_2019_CocktailPro_Test ${binary_dir}/googlemock/gtest/libgtest_main.a)

FILE(COPY bin/zutaten.txt DESTINATION "${CMAKE_BINARY_DIR}")