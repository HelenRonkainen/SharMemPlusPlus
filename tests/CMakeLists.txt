cmake_minimum_required(VERSION 2.6)

set(CurrentDir   "${CMAKE_CURRENT_SOURCE_DIR}")
set(SourceDir    "${CurrentDir}/../src")
set(ShMemDir     "${SourceDir}")

link_directories    ("${CurrentDir}/gtest")
include_directories ("${SourceDir}")
set(CMAKE_CXX_FLAGS "-g -W -Wall -Wextra -std=c++1y")

aux_source_directory("${ShMemDir}" ShMemFiles)

add_library         (ShMem "${ShMemFiles}")

##################################################################
add_executable(ShMem_test
  ShMem_test.cpp
  )

target_link_libraries(ShMem_test
  gtest_main
  gtest
  uuid
  pthread
  )
##################################################################
