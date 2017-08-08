# Define an executable
add_executable(app
    src/main.cpp)

target_compile_features(lib1 PUBLIC cxx_std_14)

# Define the libraries this project depends upon
target_link_libraries(app
    lib1)

install(TARGETS app DESTINATION ${CMAKE_INSTALL_BINDIR})