#include "hello/hello.grpc.pb.h"

#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>

#include "hello/hello.h"
#include "SerialPort.h"

#include "protocol/istxrx.h"


grpc::Status HelloServiceImpl::SayHello(grpc::ServerContext*, const HelloRequest* request, HelloResponse* reply) 
{
    std::cout << "got a request!\n";

	const char *port = request->name().c_str();
	SerialPort serial(port , 9600);

	Istxrx protocol_manager;

	SetStateDeviceArgs arg;

	arg.io_address = 86 ;
	arg.new_state = 78;

	protocol_manager.setStateDeviceComand(arg);

	char* command = protocol_manager.getCommandSerialized();


	serial.writeSerialPort(command, 8);
	const std::string message = ("Menssagem enviada para %s" ,request->name());
	reply->set_message(message);
	return grpc::Status::OK;
}

