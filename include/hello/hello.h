#include "hello/hello.grpc.pb.h"
#include <grpcpp/grpcpp.h>

using grpc::ServerContext;
using grpc::Status;


class HelloServiceImpl final : public HelloService::Service
{
	grpc::Status SayHello(grpc::ServerContext*, const HelloRequest* request, HelloResponse* reply) override ;
};



