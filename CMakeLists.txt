cmake_minimum_required(VERSION 3.13)

if(APPLE)
  # Target macOS version, Have to set this before creating project.
  set(CMAKE_OSX_DEPLOYMENT_TARGET 10.10)
elseif(WIN32)
  # Use Windows 10 SDK.
  set(CMAKE_SYSTEM_VERSION 10.0)
endif()

# Project name and executable name
project(facedetect)
set(APP_NAME "facedetect")

# The main executable.
file(GLOB SRC_FILES "src/*.h" "src/*.hpp" "src/*.cc" "src/*.rc" "src/*.xml" "src/*.ico")
add_executable(${APP_NAME} ${SRC_FILES})

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(${APP_NAME} ${OpenCV_LIBS})
