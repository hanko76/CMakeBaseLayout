
# Define library. Only source files here!

set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN 1)

add_library(lib1
    src/HelloWriter.cpp
	include/lib1/HelloWriter.h)
	
include(GenerateExportHeader)
generate_export_header(lib1)
install(FILES ${PROJECT_BINARY_DIR}/lib1/lib1_export.h DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/lib1)

# Add generated sources after library has been defined
target_sources(lib1 PRIVATE ${PROJECT_BINARY_DIR}/lib1/lib1_export.h)

target_compile_features(lib1 PUBLIC cxx_std_17)

# Define headers for this library. PUBLIC headers are used for
# compiling the library, and will be added to consumers' build
# paths.
target_include_directories(lib1 PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
    $<INSTALL_INTERFACE:include>
    PRIVATE src)

# Depend on a library that we defined in the top-level file
target_link_libraries(lib1
  boost)

# 'make install' to the correct locations (provided by GNUInstallDirs).
install(TARGETS lib1 EXPORT lib1Config
    ARCHIVE  DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY  DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME  DESTINATION ${CMAKE_INSTALL_BINDIR})
  
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
 

# This makes the project importable from the install directory
# Put config file in per-project dir (name MUST match), can also
# just go into 'cmake'.
install(EXPORT lib1Config DESTINATION share/lib1/cmake)

# This makes the project importable from the build directory
export(TARGETS lib1 FILE lib1Config.cmake)

# Every library has unit tests, of course
#add_executable(testlib1
#    test/testlib1.cpp)

#target_link_libraries(testlib1
#    lib1)

#add_test(testlib1 testlib1)
