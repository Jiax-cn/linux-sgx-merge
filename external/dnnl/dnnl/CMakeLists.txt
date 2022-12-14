#===============================================================================
# Copyright 2016-2019 Intel Corporation
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#===============================================================================

cmake_minimum_required(VERSION 2.8.11)

if(POLICY CMP0022)
    cmake_policy(SET CMP0022 NEW)
endif()

if(POLICY CMP0054)
    cmake_policy(SET CMP0054 NEW)
endif()

# Enable RPATH on MacOS/OSX
if(POLICY CMP0042)
    cmake_policy(SET CMP0042 NEW)
endif()

# Do not export symbols from executables
if(POLICY CMP0065)
    cmake_policy(SET CMP0065 NEW)
endif()

# Pass all flags to try_compile
if(POLICY CMP0056)
    cmake_policy(SET CMP0056 NEW)
endif()
if(POLICY CMP0066)
    cmake_policy(SET CMP0066 NEW)
endif()

set(PROJECT_NAME "DNNL")
set(PROJECT_FULL_NAME "Deep Neural Network Library (DNNL)")
set(PROJECT_VERSION "1.1.1")

set(LIB_NAME dnnl)

if (CMAKE_VERSION VERSION_LESS 3.0)
    project(${PROJECT_NAME} C CXX)
else()
    cmake_policy(SET CMP0048 NEW)
    project(${PROJECT_NAME} VERSION "${PROJECT_VERSION}" LANGUAGES C CXX)
endif()

if (NOT CMAKE_SIZEOF_VOID_P EQUAL 8)
    message(FATAL_ERROR "DNNL supports 64 bit platforms only")
endif()

if("${CMAKE_BUILD_TYPE}" STREQUAL "")
    message(STATUS "CMAKE_BUILD_TYPE is unset, defaulting to Release")
    set(CMAKE_BUILD_TYPE "Release")
endif()

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

set(CMAKE_SRC_CCXX_FLAGS)       # SRC specifics
set(CMAKE_EXAMPLE_CCXX_FLAGS)   # EXAMPLE specifics
set(CMAKE_TEST_CCXX_FLAGS)      # TESTS specifics

if(UNIX OR MINGW)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif()

include("cmake/mkldnn_compat.cmake")

include("cmake/utils.cmake")
include("cmake/options.cmake")
include("cmake/OpenMP.cmake")
include("cmake/TBB.cmake")
include("cmake/OpenCL.cmake")
include("cmake/platform.cmake")
include("cmake/SDL.cmake")
include("cmake/MKL.cmake")
include("cmake/Doxygen.cmake")
include("cmake/version.cmake")

# Handle cases when OpenMP runtime is requested but not found: override CPU
# runtime to be sequential
if(DNNL_CPU_RUNTIME STREQUAL "OMP" AND
   DNNL_CPU_THREADING_RUNTIME STREQUAL "SEQ")
    set(DNNL_CPU_RUNTIME "SEQ" CACHE STRING "" FORCE)
endif()

enable_testing()

include_directories(include)

configure_file(
    "${PROJECT_SOURCE_DIR}/include/dnnl_config.h.in"
    "${PROJECT_BINARY_DIR}/include/dnnl_config.h"
)
include_directories(${PROJECT_BINARY_DIR}/include)

if(DNNL_INSTALL_MODE STREQUAL "BUNDLE" AND NOT DEFINED CMAKE_INSTALL_LIBDIR)
    # define CMAKE_INSTALL_LIBDIR as "lib" in the case of bundle
    set(CMAKE_INSTALL_LIBDIR "lib")
endif()

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

add_subdirectory(src)
add_subdirectory(examples)
add_subdirectory(tests)

if(DNNL_INSTALL_MODE STREQUAL "BUNDLE")
    install(FILES LICENSE DESTINATION ${CMAKE_INSTALL_PREFIX})
    install(FILES README.md DESTINATION ${CMAKE_INSTALL_PREFIX})
else()
    # Cannot use CMAKE_INSTALL_DOCDIR since it uses PROJECT_NAME and not LIB_NAME
    install(FILES LICENSE DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/doc/${LIB_NAME})
endif()
