cmake_minimum_required(VERSION 3.24)
project(project)

set(CMAKE_CXX_STANDARD 17)

add_definitions(-DSFML_STATIC)

include_directories("ext/SFML/include/")
include_directories("inc/")
include_directories("content/")
link_directories("ext/SFML/lib/")

add_executable(project TamaTama.cpp
			Game.cpp
			Game.h
			Pet.hpp
			Information.hpp
)

target_link_libraries("project"
#        sfml-graphics-s
#        sfml-window-s
#        sfml-system-s
#        sfml-audio-s
        sfml-graphics-s-d
        sfml-window-s-d
        sfml-system-s-d
        sfml-audio-s-d
        opengl32
        freetype
        winmm
        gdi32
        openal32
        flac
        vorbisenc
        vorbisfile
        vorbis
        ogg)

file(COPY "content" DESTINATION "/")