#include "hello/hello.grpc.pb.h"

#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>

#include "hello/hello.h"
#include "SerialPort.h"


grpc::Status HelloServiceImpl::SayHello(grpc::ServerContext*, const HelloRequest* request, HelloResponse* reply) 
{
    std::cout << "got a request!\n";

	const char *port = request->name().c_str();
	SerialPort serial(port , 9600);
	serial.writeSerialPort("HELLO SERIAL \n", 13);
	const std::string message = ("Menssagem enviada para %s" ,request->name());
	reply->set_message(message);
	return grpc::Status::OK;
}

