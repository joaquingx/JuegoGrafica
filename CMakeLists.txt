# CMake entry point
cmake_minimum_required (VERSION 2.6)
project (TrabajoFinal)

find_package(OpenGL REQUIRED)

# if( CMAKE_BINARY_DIR STREQUAL CMAKE_SOURCE_DIR )
#     message( FATAL_ERROR "Please select another Build Directory ! (and give it a clever name, like bin_Visual2012_64bits/)" )
# endif()
# if( CMAKE_SOURCE_DIR MATCHES " " )
#         message( "Your Source Directory contains spaces. If you experience problems when compiling, this can be the cause." )
# endif()
# if( CMAKE_BINARY_DIR MATCHES " " )
#         message( "Your Build Directory contains spaces. If you experience problems when compiling, this can be the cause." )
# endif()
# include_directories(${OPENGL_INCLUDE_DIRS})

add_definitions(
  -DTW_STATIC
  -DTW_NO_LIB_PRAGMA
  -DTW_NO_DIRECT3D
  -DGLEW_STATIC
  -D_CRT_SECURE_NO_WARNINGS
  )

set(LIBSRC Framework)
set(RSRC Resources)

add_subdirectory (external)

include_directories(
  external/AntTweakBar-1.16/include/
  external/glfw-3.1.2/include/GLFW/
  external/glm-0.9.7.1/
  external/glew-1.13.0/include/
  external/assimp-3.0.1270/include/
  external/bullet-2.81-rev2613/src/
  .
  )
# link_directories(/home/joaquin/Documents/Universidad/Grafica/Framework)
# add_subdirectory(Framework)
#include_directories(/home/joaquin/Documents/Universidad/Grafica/Framework)

add_library(myShaders SHARED ${LIBSRC}/myShaders.cpp)
add_library(myConfiguration SHARED ${LIBSRC}/myConfiguration.cpp)
add_library(myControl SHARED ${LIBSRC}/myControl.cpp)
add_library(myTexture SHARED ${LIBSRC}/myTexture.cpp)
add_library(myObjectLoader SHARED ${LIBSRC}/myObjectLoader.cpp)
add_library(myArt SHARED ${LIBSRC}/myArt.cpp)
add_library(myPhisics SHARED ${LIBSRC}/myPhisics.cpp)
add_library(verticesArt SHARED ${RSRC}/verticesArt.cpp)
add_library(myMap SHARED ${LIBSRC}/myMap.cpp)

set(ALL_LIBS
  ${OPENGL_LIBRARY}
  glfw
  GLEW_1130
  myConfiguration
  myShaders
  myControl
  myObjectLoader
  myTexture
  verticesArt
  myArt
  myPhisics
        myMap
  )

add_executable(Final
  Final/final.cpp
  Framework/myConfiguration.cpp
  Framework/myConfiguration.hpp
  Framework/myShaders.cpp
  Framework/myShaders.hpp
  Framework/myControl.cpp
  Framework/myControl.hpp
  Framework/myTexture.cpp
  Framework/myTexture.hpp
  Framework/myObjectLoader.cpp
  Framework/myObjectLoader.hpp
  Framework/myArt.hpp
  Framework/myArt.cpp
  Framework/myPhisics.cpp
        Framework/myMap.cpp
  # Resources/verticesArt.cpp
  Resources/TransformVertexShader.vertexshader
  Resources/ColorFragmentShader.fragmentshader
  )
target_link_libraries(Final
  ${ALL_LIBS}
  )
