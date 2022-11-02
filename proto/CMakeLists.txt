find_package(Protobuf CONFIG REQUIRED)
find_package(gRPC CONFIG REQUIRED)
find_package(Threads)


add_library(
    sdk_protobuf 
    services/commands/setStateOutput.proto
    services/commands/linkInputToOutput.proto
    services/device.proto

    protocol/protocol_messages.proto


)
message(STATUS "GERATING FILES WITH PROTO")

target_link_libraries(
    sdk_protobuf

    PUBLIC
        protobuf::libprotobuf
        gRPC::grpc
        gRPC::grpc++
)

target_include_directories(
    sdk_protobuf 
    PUBLIC ${CMAKE_CURRENT_BINARY_DIR}
)

protobuf_generate(
    TARGET sdk_protobuf 
    LANGUAGE cpp
)

get_target_property(grpc_cpp_plugin_location gRPC::grpc_cpp_plugin LOCATION)

protobuf_generate(
    TARGET sdk_protobuf 
    LANGUAGE grpc 
    GENERATE_EXTENSIONS .grpc.pb.h .grpc.pb.cc
    PLUGIN "protoc-gen-grpc=${grpc_cpp_plugin_location}"
)