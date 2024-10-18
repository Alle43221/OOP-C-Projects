# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\gaming_store_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\gaming_store_autogen.dir\\ParseCache.txt"
  "gaming_store_autogen"
  )
endif()
