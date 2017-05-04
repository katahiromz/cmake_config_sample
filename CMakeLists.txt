# CMakeLists.txt --- CMake project settings
#    ex) cmake -G "Visual Studio 9 2008" .
#    ex) cmake -DCMAKE_BUILD_TYPE=Release -G "MSYS Makefiles" .
##############################################################################

# CMake minimum version
cmake_minimum_required(VERSION 2.4)

# project name and language
project(cmake_config_sample C)

# project info
set(PROGRAM_MAJOR 0)
set(PROGRAM_MINOR 0)
set(PROGRAM_BUILD 0)
set(PROGRAM_NAME "cmake_config_sample")
set(PROGRAM_AUTHORS "Katayama Hirofumi MZ")

# set output directory (build/)
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

# check functions
include(CheckFunctionExists)
check_function_exists(strcasecmp HAVE_STRCASECMP)
check_function_exists(strncasecmp HAVE_STRNCASECMP)
check_function_exists(utime HAVE_UTIME)

# check types
include(CheckTypeSize)
check_type_size("long long" HAVE_LONG_LONG)
check_type_size(__int64 HAVE___INT64)

# check stpcpy
include(CheckCSourceCompiles)
check_c_source_compiles("
#include <string.h>
int main(void) {
    char dst[10], src[] = \"hello\";
    stpcpy(dst, src);
    return 0;
}" HAVE_STPCPY)

# configuration file
configure_file(config.h.in config.h)

# executable
add_executable(cmake_config_sample main.c stpcpy.c)
set_target_properties(cmake_config_sample PROPERTIES LINK_SEARCH_START_STATIC 1)
set_target_properties(cmake_config_sample PROPERTIES LINK_SEARCH_END_STATIC 1)
