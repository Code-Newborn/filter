cmake_minimum_required(VERSION 3.0.0) # 要求cmake的最小版本。
project(opencv_vs_cmake VERSION 0.1.0)# 定义工程名称

#指定.h头文件目录列表
set(INCLUDE_DIR 
    
)

#添加.h头文件目录到项目
include_directories(${INCLUDE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})   # 包含CmakeList.txt所在目录
 
find_package(OpenCV
        PATHS D:\\OpenCV-4.5.0-withContribNonfree-VS2022-VScode # 指定第三方Opencv库的OpenCVConfig.cmake所在路径
        NO_DEFAULT_PATH
        REQUIRED)
if (OpenCV_FOUND)
    include_directories(${OpenCV_INCLUDE_DIRS}) # 包含Opencv路径
    message( ${OpenCV_LIBS})    # 打印Opencv库Lib模块内容
else()
    message("OpenCV not found, so we won't build the project.")
endif()

SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}) # 指定.exe文件输出路径

#指定.cpp源文件列表并存于变量 SRCS_LIST
file(GLOB  SRCS_LIST
    ./*.cpp
)
add_executable(${PROJECT_NAME} ${SRCS_LIST}) # 基于特定的源文件${SRCS_LIST}，创建名为${PROJECT_NAME}的可执行文件
target_link_libraries( ${PROJECT_NAME} ${OpenCV_LIBS} ) # 为可执行文件 链接目标库lib。

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
