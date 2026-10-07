# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/SVATool_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/SVATool_autogen.dir/ParseCache.txt"
  "SVATool_autogen"
  )
endif()
