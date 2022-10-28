cmake_minimum_required(VERSION 3.17)
set (VCPKG_HOME "c:/vcpkg")
set (CMAKE_TOOLCHAIN_FILE "${VCPKG_HOME}/scripts/buildsystems/vcpkg.cmake")

set(CMAKE_CXX_COMPILER "")


project(
    TesteGRPC2
    LANGUAGES CXX
)

find_package(Protobuf CONFIG REQUIRED)
find_package(Threads REQUIRED)
find_package(gRPC CONFIG REQUIRED)


add_subdirectory(proto)
add_subdirectory(external/serial)

add_library(
    ${PROJECT_NAME}SRC
    src/hello/hello.cpp
)




add_executable(
    ${PROJECT_NAME}
    src/main.cpp
)    

target_include_directories(
    ${PROJECT_NAME}SRC

    PUBLIC
        ./include
        ./external/serial/src
        ${CMAKE_CURRENT_BINARY_DIR}/protos/
        
)

target_link_libraries(${PROJECT_NAME}SRC PUBLIC gRPC::gpr gRPC::grpc gRPC::grpc++ gRPC::grpc++_alts gRPC::grpc++_reflection )
target_link_libraries(${PROJECT_NAME}SRC PUBLIC sdk_protobuf)
target_link_libraries(${PROJECT_NAME}SRC PUBLIC serial)

target_link_libraries(
   ${PROJECT_NAME}

    PUBLIC
        ${PROJECT_NAME}SRC
)


