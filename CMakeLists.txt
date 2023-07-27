cmake_minimum_required (VERSION 3.8)

project("inetpp")                                                       # 保存在全局变量 PROJECT_NAME 内

if(${CMAKE_BUILD_TYPE} MATCHES "Debug")
    message(STATUS "[Compile mode]: debug")
    add_definitions(-DDEBUG)
    add_compile_options(-Og)
else()
    message(STATUS "[Compile mode]: release")
    add_compile_options(-O2)
endif()

add_compile_options(                                                    # 添加公共的编译选项
    -std=c++11
    -Wall
    -Wextra
)

add_subdirectory(
    inetsock
)

aux_source_directory(. SRCS)                                            # 查找源文件
add_executable(${PROJECT_NAME} ${SRCS})                                 # 标识一个可执行文件
target_link_libraries(                                                  # 将目标文件与上面生成的可执行文件链接在一起
    ${PROJECT_NAME}
    mod_inetsock
)
