# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "RelWithDebInfo")
  file(REMOVE_RECURSE
  "CMakeFiles\\ToDo_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\ToDo_autogen.dir\\ParseCache.txt"
  "ToDo_autogen"
  )
endif()
