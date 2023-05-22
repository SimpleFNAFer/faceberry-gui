cmake_minimum_required(VERSION 3.25)
project(faceberry_gui)

set(CMAKE_CXX_STANDARD 17)

set(wxWidgets_DIR /home/nasy/Загрузки/wxWidgets)
find_package(wxWidgets COMPONENTS core base REQUIRED CONFIG)
find_package(OpenCV REQUIRED)

set(SOURCE_FILES MainFrame.cpp MainFrame.h App.cpp App.h opencv-funcs.h transition-utils.h)
add_executable(faceberry-gui ${SOURCE_FILES})

target_link_libraries(faceberry-gui ${wxWidgets_LIBRARIES})
target_link_libraries(faceberry-gui ${OpenCV_LIBRARIES})
