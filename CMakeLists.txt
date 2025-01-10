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

if (NOT SFML_FOUND)
    message(FATAL_ERROR "SFML not found, please install SFML or specify SFML_DIR")
else()
    message(STATUS "Found SFML: ${SFML_INCLUDE_DIRS}, ${SFML_LIBRARIES}")
endif()

# --- Define Source and Include Directories ---
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

# --- Create Executable ---
add_executable(dpg_game ${SOURCE_DIR}/main.cpp)

# --- Set Include Directories ---
target_include_directories(dpg_game PUBLIC
    ${SFML_INCLUDE_DIRS}
    ${INCLUDE_DIR}
)

# --- Link Libraries ---
target_link_libraries(dpg_game sfml-graphics sfml-window sfml-system)

# --- Install Target ---
# This ensures the executable is copied to the 'bin' folder after building
install(TARGETS dpg_game
    RUNTIME DESTINATION bin
)

# --- Explanation of Changes and How to Build ---
message(STATUS "Build will output the executable to the 'bin' folder in the project root.")
message(STATUS "To build, create a 'build' directory, navigate into it, and run 'cmake ..' followed by 'cmake --build .'")
