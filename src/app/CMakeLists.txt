# Define an executable
add_executable(app
    src/main.cpp)

target_compile_features(lib1 PUBLIC cxx_std_17)

# Define the libraries this project depends upon
if(UNIX AND NOT APPLE)
    set(ADDITIONAL_LIBRARIES pthread)
else()
    set(ADDITIONAL_LIBRARIES "")
endif()


target_link_libraries(app lib1 ${ADDITIONAL_LIBRARIES})


install(TARGETS app DESTINATION ${CMAKE_INSTALL_BINDIR})