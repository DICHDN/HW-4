# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\QtWidget_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\QtWidget_autogen.dir\\ParseCache.txt"
  "QtWidget_autogen"
  )
endif()
