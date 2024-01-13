# SPDX-License-Identifier: LGPL-3.0-only

# put examples with .so in build/
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

if(CMAKE_SYSTEM MATCHES Windows)
	add_link_options( -static-libgcc -static-libstdc++)
	# not great, but better than shipping mingw dlls
	add_link_options( -Wl,-allow-multiple-definition )
endif()

# Tool examples
add_executable(id3cp id3cp.cpp)
target_link_libraries(id3cp id3)
install(TARGETS id3cp RUNTIME)

add_executable(id3convert id3convert.cpp)
target_link_libraries(id3convert id3)
install(TARGETS id3convert RUNTIME)

add_executable(id3info id3info.cpp)
target_link_libraries(id3info id3)
install(TARGETS id3info RUNTIME)

add_executable(id3tag id3tag.cpp)
target_link_libraries(id3tag id3)
install(TARGETS id3tag RUNTIME)

add_executable(id3image id3image.cpp)
target_link_libraries(id3image id3)

# Basic examples
add_executable(example_cwrapper example_cwrapper.c)
target_link_libraries(example_cwrapper id3)

add_executable(example_writetag example_writetag.cpp)
target_link_libraries(example_writetag id3)
