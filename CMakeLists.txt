cmake_minimum_required(VERSION 3.10)
project(project)

set(CMAKE_CXX_STANDARD 17)

find_package(X11 REQUIRED)
include_directories(${X11_INCLUDE_DIR})

add_executable(project main.cpp
        src/widget.cpp include/widget.h
        src/window.cpp include/window.h
        src/text.cpp include/text.h
        src/button.cpp include/button.h
        src/radiobutton.cpp include/radiobutton.h
        src/text_input.cpp include/text_input.h
        src/MyDialog.cpp include/MyDialog.h
        )
target_link_libraries(project ${X11_LIBRARIES})