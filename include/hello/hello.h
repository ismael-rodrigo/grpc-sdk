#include "hello/hello.grpc.pb.h"

#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>



class HelloServiceImpl final : public HelloService::Service
{
	grpc::Status SayHello(grpc::ServerContext*, const HelloRequest* request, HelloResponse* reply) override ;
};
