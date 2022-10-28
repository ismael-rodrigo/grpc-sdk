#include <iostream>
#include <memory>
#include <string>

#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h> 
#include "hello/hello.grpc.pb.h"



using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;

class HelloServiceImpl final : public HelloService::Service
{
	Status SayHello(ServerContext*, const HelloRequest* request, HelloResponse* reply) override {
    std::cout << "got a request!\n";
		reply->set_message(request->name());
		return Status::OK;
  }
};



void RunServer() {
 
  std::string server_address("0.0.0.0:50051");
  HelloServiceImpl teste;

  grpc::EnableDefaultHealthCheckService(true);
  grpc::reflection::InitProtoReflectionServerBuilderPlugin();
  ServerBuilder builder;
  builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
  builder.RegisterService(&teste);

  std::unique_ptr<Server> server(builder.BuildAndStart());
  std::cout << "Server listening on " << server_address << std::endl;

  server->Wait();
}

int main(int argc, char** argv) {
  RunServer();
  return 0;
}