cmake_minimum_required(VERSION 3.24)
project(project)

set(CMAKE_CXX_STANDARD 17)

add_definitions(-DSFML_STATIC)

include_directories("ext/SFML/include/")
include_directories("inc/")
link_directories("ext/SFML/lib/")

add_executable(project TamaTama.cpp)

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
file(COPY ArialRegular.ttf DESTINATION /)
file(COPY "Room1.png" DESTINATION "/")
file(COPY "Room2.png" DESTINATION "/")
file(COPY "Gus.png" DESTINATION "/")