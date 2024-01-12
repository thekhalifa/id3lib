# put examples with .so in build/
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})


# Working examples (Tools)
add_executable(id3cp demo_copy.cpp demo_copy_options.c)
target_link_libraries(id3cp id3)

add_executable(id3convert demo_convert.cpp demo_convert_options.c)
target_link_libraries(id3convert id3)

add_executable(id3info demo_info.cpp demo_info_options.c)
target_link_libraries(id3info id3)

add_executable(id3tag demo_tag.cpp demo_tag_options.c)
target_link_libraries(id3tag id3)

# Not really useful ones
add_executable(demo_simple demo_simple.cpp)
target_link_libraries(demo_simple id3)

add_executable(findeng findeng.cpp)
target_link_libraries(findeng id3)

add_executable(findstr findstr.cpp)
target_link_libraries(findstr id3)


# TODO: Tests to be rewritten
if (WITH_TESTS)
	set(ENV{LD_LIBRARY_PATH} .)
	add_executable(test_compression test_compression.cpp)
	target_link_libraries(test_compression id3)
	add_test(NAME compression COMMAND test_compression)

	# add_executable(test_io test_io.cpp)
	# target_link_libraries(test_io id3)
	# add_test(NAME io COMMAND test_io)
endif()
