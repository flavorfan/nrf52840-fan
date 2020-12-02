# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.13.1)
find_package(Zephyr HINTS $ENV{ZEPHYR_BASE})
project(external_lib)

#target_sources(app PRIVATE src/hello_world_test.cc)
target_sources(app PRIVATE src/main.cc)
target_sources(app PRIVATE src/main_functions.cc)
target_sources(app PRIVATE src/constants.cc)
target_sources(app PRIVATE src/output_handler.cc)
target_sources(app PRIVATE src/model.cc)
target_sources(app PRIVATE src/assert.cc)

zephyr_include_directories(src)

# Create a wrapper CMake library that our app can link with
set(TF_LIB_DIR     ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(THIRD_PARTY_DIR     ${TF_LIB_DIR}/third_party)

add_library(tf_lib STATIC IMPORTED GLOBAL)

set_target_properties(tf_lib PROPERTIES IMPORTED_LOCATION             ${TF_LIB_DIR}/libtensorflow-microlite.a)
set_target_properties(tf_lib PROPERTIES INTERFACE_INCLUDE_DIRECTORIES "${TF_LIB_DIR};${TF_LIB_DIR}/tensorflow/lite/micro;${THIRD_PARTY_DIR}/flatbuffers/include") 

target_link_libraries(app PUBLIC tf_lib)
