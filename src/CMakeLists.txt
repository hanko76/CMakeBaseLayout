# At LEAST 3.8 but newer is better
cmake_minimum_required(VERSION 3.8 FATAL_ERROR)
project(myproject VERSION 0.1 LANGUAGES CXX)

# Must use GNUInstallDirs to install libraries into correct
# locations on all platforms.
include(GNUInstallDirs)

set(CMAKE_INSTALL_PREFIX ${PROJECT_BINARY_DIR}/installation)

# Include Boost as an imported target
if(WIN32) 
  set(BOOST_ROOT C:/work/boost)
elseif(UNIX)
  set(BOOST_ROOT /opt/boost_1_64_0)
endif()
find_package(Boost REQUIRED)
add_library(boost INTERFACE IMPORTED)
set_property(TARGET boost PROPERTY
    INTERFACE_INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR})

# Some other library that we import that was also built using CMake
# and has an exported target.
#find_package(MyOtherLibrary REQUIRED)

# Targets that we develop here
#enable_testing()
add_subdirectory(lib1)
add_subdirectory(app)
