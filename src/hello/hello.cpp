#include "hello/hello.h"

grpc::Status SayHello(grpc::ServerContext*, const HelloRequest* request, HelloResponse* reply){
		std::cout << "got a request!\n";
		reply->set_message(request->name());
		return grpc::Status::OK;
};