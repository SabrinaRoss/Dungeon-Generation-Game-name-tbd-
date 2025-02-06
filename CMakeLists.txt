# Notice from Rowan Althorp in order to maintain Academic Integritiy
# This CMakeLists.txt was created using guidance from a response by an AI language model, most specifically Google Gemini 2.0 Flash Experimental.
# The specific configuration of build directories and cross-platform settings was based on
# instructions provided by the AI, which it than used to make the program more crossplatform and accessible.
#
#  Details of the interaction can be provided by request.

cmake_minimum_required(VERSION 3.10)
project(dpg_game)

# --- Configure Output Directories ---
# Set the runtime output directory to the 'bin' folder at the project root
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")

# Set the library and archive output directories to 'lib' folder inside the build directory
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

# --- Find SFML ---
find_package(SFML REQUIRED COMPONENTS graphics window system)
message(STATUS "SFML_LIBRARIES: ${SFML_LIBRARIES}")
if (NOT SFML_FOUND)
    message(FATAL_ERROR "SFML not found, please install SFML or specify SFML_DIR or CMAKE_PREFIX_PATH.")
    message(STATUS "On Debian/Ubuntu-based systems, try: sudo apt-get install libsfml-dev")
    message(STATUS "On Fedora/CentOS/RHEL-based systems, try: sudo dnf install SFML-devel")
    message(STATUS "On macOS using Homebrew, try: brew install sfml")
    message(STATUS "Alternatively, you can download SFML from the official website and")
    message(STATUS "set the SFML_DIR CMake variable to the SFML installation directory.")
else()
    message(STATUS "Found SFML: ${SFML_INCLUDE_DIRS}, ${SFML_LIBRARIES}")
endif()

# --- Define Source and Include Directories ---
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

# --- Create Executable ---
add_executable(dpg_game ${SOURCE_DIR}/main.cpp)

# --- Set Include Directories (for compilation) ---
target_include_directories(dpg_game PUBLIC
    ${SFML_INCLUDE_DIRS}
    ${INCLUDE_DIR}
    $(SOURCE_DIR)
)

# --- Link Libraries ---
target_link_libraries(dpg_game
    sfml-graphics
    sfml-window
    sfml-system
)
# --- Install Target ---
# This ensures the executable is copied to the 'bin' folder after building
install(TARGETS dpg_game
    RUNTIME DESTINATION bin
)

# --- Copy Headers to Include Directory ---
file(GLOB_RECURSE HEADER_FILES "${SOURCE_DIR}/*.h" "${SOURCE_DIR}/*.hpp")

foreach(HEADER_FILE ${HEADER_FILES})
    # Get the relative path from the source directory
    string(REPLACE "${SOURCE_DIR}" "" HEADER_SUBPATH "${HEADER_FILE}")

    # Construct the destination path in the include directory
    set(DESTINATION_PATH "${CMAKE_BINARY_DIR}/include/${HEADER_SUBPATH}")

    # Get the destination directory
    get_filename_component(DESTINATION_DIR "${DESTINATION_PATH}" DIRECTORY)

    # Create the destination directory if it doesn't exist
    file(MAKE_DIRECTORY "${DESTINATION_DIR}")

    # Copy the header file
    file(COPY "${HEADER_FILE}" DESTINATION "${DESTINATION_DIR}")
endforeach()

# --- Set Include Directories (for usage of copied headers) ---
# This makes the copied headers available to other projects that might use this one
target_include_directories(dpg_game PUBLIC
    "${CMAKE_BINARY_DIR}/include"
)

# --- Explanation of Changes and How to Build ---
message(STATUS "Build will output the executable to the 'bin' folder in the project root.")
message(STATUS "The .h and .hpp files from 'src' will be copied to the 'include' folder in the build directory.")
message(STATUS "To build, create a 'build' directory, navigate into it, and run 'cmake ..' followed by 'cmake --build .'")
# --- Cross-Platform Build Instructions ---
message(STATUS "Build will output the executable to the 'bin' folder in the build directory.")
message(STATUS "To build:")
message(STATUS "  1. Create a 'build' directory in the project root: mkdir build")
message(STATUS "  2. Navigate into the 'build' directory: cd build")
message(STATUS "  3. Run CMake to configure the project: cmake ..")
message(STATUS "  4. Run the appropriate build command for your system:")
message(STATUS "     - On most systems: cmake --build .")
message(STATUS "     - On Linux/macOS with Makefiles: make")
message(STATUS "     - On Windows with MinGW: mingw32-make")
message(STATUS "     - On Windows with NMake (Visual Studio): nmake")
