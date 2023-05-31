cmake_minimum_required(VERSION 3.12)
project(YourProjectName)

# Add SFML dependencies
find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)

# Set up your source files
set(SOURCES
    your_source_file1.cpp
    your_source_file2.cpp
    # Add more source files as needed
)

# Set up your executable
add_executable(YourExecutable ${SOURCES})

# Link against SFML libraries
target_link_libraries(YourExecutable PRIVATE sfml-system sfml-window sfml-graphics)