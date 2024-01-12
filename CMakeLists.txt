cmake_minimum_required(VERSION 3.12)
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 98)

# Overwrite the init values choosen by CMake
#set(CMAKE_CXX_FLAGS_RELEASE_INIT "-ggdb3 -O0")


project(libid3 VERSION 3.8.3 LANGUAGES C CXX)
set(PROJECT_AUTHOR "Ahmad Khalifa")
set(PROJECT_HOMEPAGE_URL "...")
set(PROJECT_DESCRIPTION "Library for manipulating ID3v1/v1.1 and ID3v2 tags")

set(ID3LIB_INTERFACE_AGE 0)
set(ID3LIB_BINARY_AGE 0)
set(ID3LIB_COMPILE_DEBUG "")

#include(CheckIncludeFiles)
include(CheckIncludeFileCXX)
include(FindPkgConfig)

check_include_file_cxx("bitset" HAVE_BITSET)
check_include_file_cxx("getopt.h" HAVE_GETOPT_LONG)
check_include_file_cxx("iconv.h" HAVE_ICONV_H)
check_include_file_cxx("sys/param.h" HAVE_SYS_PARAM_H)
check_include_file_cxx("sys/stat.h" HAVE_SYS_STAT_H)
check_include_file_cxx("unistd.h" HAVE_UNISTD_H)


pkg_check_modules(zlib REQUIRED IMPORTED_TARGET zlib)

set(config_h_out ${CMAKE_SOURCE_DIR}/include/config.h)
configure_file(config.h.in ${config_h_out})

add_compile_definitions(HAVE_CONFIG_H)
add_compile_definitions(_FORTIFY_SOURCE=2)

include_directories(${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/include/id3)


# Tests
if (WITH_TESTS)
    message("Enabled Tests")
    enable_testing()
endif()

# API Docs
if (WITH_DOCS)
    message("Enabled docs")
    include(FindDoxygen)
    set(DOXYGEN_OUTPUT_DIRECTORY docs)
    set(DOXYGEN_GENERATE_HTML YES)
    set(DOXYGEN_HTML_OUTPUT api)
    # no example documentation, but adding anyway
    set(DOXYGEN_EXAMPLE_PATH ${CMAKE_SOURCE_DIR}/examples)
    set(DOXYGEN_EXAMPLE_PATTERNS "*.cpp *.c *.h")
    doxygen_add_docs(apidocs src/
        include/id3/field.h
        include/id3/frame.h
        include/id3/globals.h
        include/id3/misc_support.h
        include/id3/reader.h
        include/id3/readers.h
        include/id3/sized_types.h
        include/id3/tag.h
        include/id3/writer.h
        include/id3/writers.h
        ALL)

    set(DOX_DIR_HTML api)
    configure_file(doc/index.html.in ${CMAKE_BINARY_DIR}/docs/index.html)
    file(COPY doc/ DESTINATION ${CMAKE_BINARY_DIR}/docs FILES_MATCHING PATTERN *.gif)
    file(COPY doc/ DESTINATION ${CMAKE_BINARY_DIR}/docs FILES_MATCHING PATTERN id3lib*php )
    file(COPY doc/ DESTINATION ${CMAKE_BINARY_DIR}/docs FILES_MATCHING PATTERN id3lib*doc )
    file(COPY doc/man DESTINATION ${CMAKE_BINARY_DIR}/docs FILES_MATCHING PATTERN *.1)
endif()


add_subdirectory(src)
add_subdirectory(examples)
