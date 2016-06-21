cmake_minimum_required(VERSION 2.8.11)

add_executable(dtr main.cpp randomizer.h randomizer.cpp cli.h cli.cpp)

set_property(TARGET dtr PROPERTY CXX_STANDARD 11)
set_property(TARGET dtr PROPERTY CXX_STANDARD_REQUIRED ON)

if (MSVC)
	foreach(flag_var
			CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE
			CMAKE_CXX_FLAGS_MINSIZEREL CMAKE_CXX_FLAGS_RELWITHDEBINFO)
		if(${flag_var} MATCHES "/MD")
			string(REGEX REPLACE "/MD" "/MT" ${flag_var} "${${flag_var}}")
		endif(${flag_var} MATCHES "/MD")
	endforeach(flag_var)
endif(MSVC)
