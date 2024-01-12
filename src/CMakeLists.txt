# SPDX-License-Identifier: LGPL-3.0-only

set(ID3LIB_SOURCES
	c_wrapper.cpp
	field.cpp
	field_binary.cpp
	field_integer.cpp
	field_string_ascii.cpp
	field_string_unicode.cpp
	frame.cpp
	frame_impl.cpp
	frame_parse.cpp
	frame_render.cpp
	globals.cpp
	header.cpp
	header_frame.cpp
	header_tag.cpp
	helpers.cpp
	io.cpp
	io_decorators.cpp
	io_helpers.cpp
	misc_support.cpp
	mp3_parse.cpp
	readers.cpp
	spec.cpp
	tag.cpp
	tag_file.cpp
	tag_find.cpp
	tag_impl.cpp
	tag_parse.cpp
	tag_parse_lyrics3.cpp
	tag_parse_musicmatch.cpp
	tag_parse_v1.cpp
	tag_render.cpp
	utils.cpp
	writers.cpp)


add_library(id3 SHARED ${ID3LIB_SOURCES})
target_link_libraries(id3 PRIVATE ${zlib_LINK_LIBRARIES})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})
install(TARGETS id3 LIBRARY)
