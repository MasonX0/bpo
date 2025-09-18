cmake_minimum_required(VERSION 3.20)
project(YourProjectName)

set(CMAKE_CXX_STANDARD 11)

# Для Windows добавьте эти настройки:
if(WIN32)
    # Указываем компилятору использовать специфичные для BGI настройки
    add_definitions(-D__USE_MINGW_ANSI_STDIO)

    # Подключаем библиотеки
    set(BGI_LIBRARIES -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32)

    # Указываем путь к библиотеке (если libbgi.a в папке проекта)
    link_directories(${CMAKE_CURRENT_SOURCE_DIR})
endif()

add_executable(YourProjectName main.cpp)

# Подключаем библиотеки
target_link_libraries(YourProjectName ${BGI_LIBRARIES})