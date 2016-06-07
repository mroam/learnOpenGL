cmake_minimum_required(VERSION 3.0)
project(OurDumbFolder)

option(GLFW_BUILD_DOCS OFF)
option(GLFW_BUILD_EXAMPLES OFF)
option(GLFW_BUILD_TESTS OFF)
add_subdirectory(OurDumbFolder/Vendor/glfw)



if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -std=c++11")
    if(NOT WIN32)
        set(GLAD_LIBRARIES dl)
    endif()
endif()

include_directories(OurDumbFolder/Headers/
                    OurDumbFolder/Vendor/glad/include/
                    OurDumbFolder/Vendor/glfw/include/)

file(GLOB VENDORS_SOURCES OurDumbFolder/Vendor/glad/src/glad.c)
file(GLOB PROJECT_HEADERS OurDumbFolder/Headers/*.hpp)
file(GLOB PROJECT_SOURCES OurDumbFolder/Sources/*.cpp)
file(GLOB PROJECT_SHADERS OurDumbFolder/Shaders/*.comp
                          OurDumbFolder/Shaders/*.frag
                          OurDumbFolder/Shaders/*.geom
                          OurDumbFolder/Shaders/*.vert)
file(GLOB PROJECT_CONFIGS CMakeLists.txt
                          Readme.md)

source_group("Headers" FILES ${PROJECT_HEADERS})
source_group("Shaders" FILES ${PROJECT_SHADERS})
source_group("Sources" FILES ${PROJECT_SOURCES})
source_group("Vendors" FILES ${VENDORS_SOURCES})

add_definitions(-DGLFW_INCLUDE_NONE
                -DPROJECT_SOURCE_DIR=\"${PROJECT_SOURCE_DIR}\")
add_executable(${PROJECT_NAME} ${PROJECT_SOURCES} ${PROJECT_HEADERS}
                               ${PROJECT_SHADERS} ${PROJECT_CONFIGS}
                               ${VENDORS_SOURCES})
target_link_libraries(${PROJECT_NAME} glfw
                      ${GLFW_LIBRARIES} ${GLAD_LIBRARIES})
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${PROJECT_NAME})
