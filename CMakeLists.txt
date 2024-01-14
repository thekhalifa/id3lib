cmake_minimum_required(VERSION 3.12)
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 98)

project(id3lib VERSION 3.8.3 LANGUAGES C CXX)
set(PROJECT_AUTHOR "Ahmad Khalifa")
set(PROJECT_HOMEPAGE_URL "...")
set(PROJECT_DESCRIPTION "Library for manipulating ID3v1/v1.1 and ID3v2 tags")

set(ID3LIB_INTERFACE_AGE 0)
set(ID3LIB_BINARY_AGE 0)
set(ID3LIB_COMPILE_DEBUG "")

# Enable warning/notice messages if enabled through cmake
if (ID3_ENABLE_DEBUG)
    add_compile_definitions(ID3_ENABLE_DEBUG=1)
endif()

#include(CheckIncludeFiles)
include(CheckIncludeFileCXX)
include(FindPkgConfig)

check_include_file_cxx("bitset" HAVE_BITSET)
check_include_file_cxx("getopt.h" HAVE_GETOPT_LONG)
check_include_file_cxx("iconv.h" HAVE_ICONV_H)
check_include_file_cxx("stdlib.h" HAVE_MKSTEMP)
check_include_file_cxx("sys/param.h" HAVE_SYS_PARAM_H)
check_include_file_cxx("sys/stat.h" HAVE_SYS_STAT_H)
check_include_file_cxx("unistd.h" HAVE_UNISTD_H)


if(CMAKE_SYSTEM MATCHES Windows)
    message(STATUS "Target system is Windows")
    add_compile_definitions(ID3LIB_LINKOPTION=1)
endif()

pkg_check_modules(zlib REQUIRED IMPORTED_TARGET zlib)

configure_file(${CMAKE_SOURCE_DIR}/src/config.h.in ${CMAKE_BINARY_DIR}/config.h)
add_compile_definitions(HAVE_CONFIG_H)

include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/include/id3
    ${CMAKE_BINARY_DIR})

# API Docs
if (WITH_DOCS)
    message("Enabled doc generation")
    include(FindDoxygen)
    set(DOXYGEN_QUIET YES)
    set(DOXYGEN_WARNINGS NO)
    set(DOXYGEN_WARN_IF_UNDOCUMENTED NO)
    set(DOXYGEN_WARN_IF_DOC_ERROR NO)
    set(DOXYGEN_WARN_IF_INCOMPLETE_DOC NO)
    set(DOXYGEN_OUTPUT_DIRECTORY doc)
    set(DOXYGEN_GENERATE_HTML YES)
    set(DOXYGEN_HTML_OUTPUT api)
    # no example documentation, but adding anyway
    set(DOXYGEN_EXAMPLE_PATH ${CMAKE_SOURCE_DIR}/examples)
    set(DOXYGEN_EXAMPLE_PATTERNS "*.cpp *.c *.h")
    doxygen_add_docs(apidocs src/
        include/id3/field.h
        include/id3/globals.h
        include/id3/helpers.h
        include/id3/misc_support.h
        include/id3/reader.h
        include/id3/readers.h
        include/id3/sized_types.h
        include/id3/tag.h
        include/id3/writer.h
        include/id3/writers.h
        ALL)

    set(DOX_DIR_HTML api)
    configure_file(doc/index.html.in ${CMAKE_BINARY_DIR}/doc/index.html)
    file(COPY doc/ DESTINATION ${CMAKE_BINARY_DIR}/doc FILES_MATCHING PATTERN *.gif)
    file(COPY doc/ DESTINATION ${CMAKE_BINARY_DIR}/doc FILES_MATCHING PATTERN id3lib*php )
    file(COPY doc/ DESTINATION ${CMAKE_BINARY_DIR}/doc FILES_MATCHING PATTERN id3lib*doc )
    file(COPY doc/man DESTINATION ${CMAKE_BINARY_DIR}/doc FILES_MATCHING PATTERN *.1)
    install(DIRECTORY ${CMAKE_BINARY_DIR}/doc/api/
        DESTINATION share/doc/${CMAKE_PROJECT_NAME}-doc
        FILE_PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ)
endif()

# WITH_DOCS or not, install manpages
install(DIRECTORY doc/man/ DESTINATION "share/man/man1"
        FILE_PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ
        PATTERN *.1)


add_subdirectory(src)
add_subdirectory(examples)


# Tests - nothing happening now, needs a refactor
if (WITH_TESTS)
    message("Enabled Tests")
    enable_testing()
    add_subdirectory(tests)
endif()
