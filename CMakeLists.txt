cmake_minimum_required(VERSION 3.0)
project(TuProyecto)

# Agrega aquí tus archivos fuente
set(SOURCES
    Enemy.cpp
    Game.cpp
    SDLGameObject.cpp
    TextureManager.cpp
    Tortuga.cpp
    main.cpp
)

# Agrega aquí tus archivos de encabezado
set(HEADERS
    Enemy.h
    Game.h
    GameObject.h
    LoaderParams.h
    SDLGameObject.h
    TextureManager.h
    Tortuga.h
)

# Añade el ejecutable
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Configura SDL2
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})
