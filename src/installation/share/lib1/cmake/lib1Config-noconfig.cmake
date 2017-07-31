#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "lib1" for configuration ""
set_property(TARGET lib1 APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(lib1 PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_NOCONFIG "CXX"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/liblib1.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS lib1 )
list(APPEND _IMPORT_CHECK_FILES_FOR_lib1 "${_IMPORT_PREFIX}/lib/liblib1.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
