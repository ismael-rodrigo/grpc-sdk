#include "hello/hello.grpc.pb.h"

#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>

#include "hello/hello.h"
#include "SerialPort.h"

#include "protocol/istxrx.h"


grpc::Status HelloServiceImpl::SayHello(grpc::ServerContext*, const HelloRequest* request, HelloResponse* reply) 
{
	SerialPort serial(request->info().port_name().c_str() , request->info().baud_rate());
	Istxrx protocol_manager;
	protocol_manager.setStateDeviceComand(request->set_state_args());
	char* command = protocol_manager.getCommandSerialized();
	serial.writeSerialPort(command, 8);
	const std::string message = ("Menssagem enviada");
	reply->set_message("ok");
	return grpc::Status::OK;
}

