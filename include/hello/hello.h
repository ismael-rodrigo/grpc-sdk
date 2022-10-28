#include "hello/hello.grpc.pb.h"

#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>



using grpc::ServerContext;
using grpc::Status;


class HelloServiceImpl final : public HelloService::Service
{
	Status SayHello(ServerContext*, const HelloRequest* request, HelloResponse* reply) override ;
};



