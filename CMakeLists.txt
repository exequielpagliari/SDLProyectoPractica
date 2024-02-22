cmake_minimum_required(VERSION 3.10)

project(SDL2Test)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
include_directories(${SDL2_IMAGE_INCLUDE_DIRS})
INCLUDE_DIRECTORIES("includes")
INCLUDE_DIRECTORIES("Assets")
# Se añade el directorio a la ruta de búsqueda del compilador de turno
FILE(GLOB MiProyecto_SRC "src/*.cpp")
FILE(GLOB MiProyecto_SRC "includes/*.h")
# FILE GLOB selecciona todos los archivos que cumplan la característica y los almacena en MiProyecto_SRC
# GLOB no es recursivo. Si lo necesitas, usa GLOB_RECURSE

add_executable(SDL2Test WIN32 	main.cpp  
			      	src/Enemy.cpp
				includes/Enemy.h
			      	src/Game.cpp
			      	includes/Game.h
				src/SDLGameObject.cpp
				includes/SDLGameObject.h
				src/TextureManager.cpp
				includes/TextureManager.h
				includes/Vector2D.h
				src/Tortuga.cpp
				includes/Tortuga.h
				)

target_link_libraries(SDL2Test ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})
