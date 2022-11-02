#include "services/device.grpc.pb.h"

#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>

#include "services/device.h"
#include "SerialPort.h"

#include "protocol/istxrx.h"


grpc::Status DeviceServiceImpl::SetStateOutput(grpc::ServerContext*, const SetStateOutputRequest* request, SetStateOutputResponse* reply) 
{
	SerialPort serial(request->info().port_name().c_str() , request->info().baud_rate());
	
	Istxrx protocol_manager;
	protocol_manager.setStateDeviceComand(request->set_state_args());
	char* command = protocol_manager.getCommandSerialized();

	serial.writeSerialPort(command, 8);

	reply->set_message("ok");
	return grpc::Status::OK;
}




grpc::Status DeviceServiceImpl::LinkInputToOutput(grpc::ServerContext* ,const LinkInputToOutputRequest* request , LinkInputToOutputResponse* reply)
{
	SerialPort serial(request->info().port_name().c_str() , request->info().baud_rate());

	Istxrx protocol_manager;
	protocol_manager.linkInputToOutput(request->link_input_to_output());
	

	char* command = protocol_manager.getCommandSerialized();
	serial.writeSerialPort(command, 8);
	reply->set_message("ok");
	return grpc::Status::OK;
}