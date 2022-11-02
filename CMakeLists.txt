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


# get simple-serial from github
find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
# Update submodules as needed
    option(GIT_SUBMODULE "Check submodules during build" ON)
    if(GIT_SUBMODULE)
        message(STATUS "Submodule update")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --remote --merge
                        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                        RESULT_VARIABLE GIT_SUBMOD_RESULT)
        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
        endif()
    endif()
endif()

#           CHECK ALL THE SUBMODULES
if(NOT EXISTS "${PROJECT_SOURCE_DIR}/external/simple-serial/CMakeLists.txt")
    message(FATAL_ERROR "The simple-serial submodules was not downloaded! GIT_SUBMODULE was turned off or failed. Please update submodules and try again.")
endif()


add_subdirectory(proto)
add_subdirectory(external/simple-serial)

add_library(
    ${PROJECT_NAME}SRC
    src/services/device.cpp

    src/protocol/istxrx.cpp
    src/protocol/commands/setStateDevice.cpp
    src/protocol/commands/linkInputToOutput.cpp

    src/serializer/serializer.cpp



)




add_executable(
    ${PROJECT_NAME}
    src/main.cpp
)    

target_include_directories(
    ${PROJECT_NAME}SRC

    PUBLIC
        ./include
        ./external/simple-serial/src
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


