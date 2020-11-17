cmake_minimum_required (VERSION 2.8)	# 最低版本要求

project (demo)

set(OBJ_NAME app)   # 定义生成的二进制可执行文件的名字
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/obj)   # 指定生成的二进制文件存放的位置

aux_source_directory(${PROJECT_SOURCE_DIR}/user/src SRC_LIST)           # 指定目录下的源文件都存放在变量 SRC_LIST 中
aux_source_directory(${PROJECT_SOURCE_DIR}/easylogger/src SRC_LIST)    # 指定目录下的源文件都存放在变量 SRC_LIST 中

include_directories(${PROJECT_SOURCE_DIR}/user/inc ${PROJECT_SOURCE_DIR}/easylogger/inc)    # 向工程添加多个指定头文件的搜索路径，路径之间用空格分隔

add_executable (${OBJ_NAME} ${SRC_LIST})    # 生成可执行文件
target_link_libraries (${OBJ_NAME} pthread)
