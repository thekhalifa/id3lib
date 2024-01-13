# SPDX-License-Identifier: LGPL-3.0-only

# set_property(TARGET test_compression PROPERTY SKIP_BUILD_RPATH 1)

add_executable(test_compression test_compression.cpp)
target_link_libraries(test_compression id3)
add_test(NAME compression COMMAND test_compression)

# add_executable(test_io test_io.cpp)
# target_link_libraries(test_io id3)
# add_test(NAME io COMMAND test_io)

add_executable(test_pic test_pic.cpp)
target_link_libraries(test_pic id3)
add_test(NAME pic COMMAND test_pic)

add_executable(test_remove test_remove.cpp)
target_link_libraries(test_remove id3)
add_test(NAME remove COMMAND test_remove)

add_executable(test_unicode test_unicode.cpp)
target_link_libraries(test_unicode id3)
add_test(NAME unicode COMMAND test_unicode)

