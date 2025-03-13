cmake_minimum_required(VERSION 3.16)
# The following line is needed when cmake version is 3.15 or lower
# cmake_policy(SET CMP0091 NEW)

project(HelloWorld)

# Add postfix for debug built file
set(CMAKE_DEBUG_POSTFIX d)

# Set the CXX standard. Qt 6 uses c++ 17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# find dynamic vcpkg packages
find_package(Qt6 CONFIG REQUIRED COMPONENTS Core)

qt_standard_project_setup()

# find static vcpkg packages
# set the path for static vcpkg packages
set(CMAKE_PREFIX_PATH "${STATIC_VCPKG_PATH}" CACHE STRING "Path to vcpkg static packages" FORCE)
find_package(fmt CONFIG REQUIRED)
find_package(Eigen3 CONFIG REQUIRED)
unset(CMAKE_PREFIX_PATH CACHE)

qt_add_executable(HelloWorld main.cpp)
set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES
    WIN32_EXECUTABLE FALSE
    MACOSX_BUNDLE FALSE
    DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX}
    RELEASE_OUTPUT_NAME ${CMAKE_PROJECT_NAME}
)
# target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ${QT_INCLUDE_DIRS})

# set compiler options
if(MSVC)
    target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE /W4 /WX)
else()
    target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic -Werror)
endif()

# target_link_libraries(HelloWorld PRIVATE fmt::fmt-header-only)
target_link_libraries(HelloWorld PRIVATE fmt::fmt Qt6::Core Eigen3::Eigen)
