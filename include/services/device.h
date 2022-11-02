#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>

#include "services/device.grpc.pb.h"

class DeviceServiceImpl final : public DeviceService::Service
{
	grpc::Status SetStateOutput(grpc::ServerContext*, const SetStateOutputRequest* request, SetStateOutputResponse* reply) override ;
	grpc::Status LinkInputToOutput(grpc::ServerContext* ,const LinkInputToOutputRequest* request , LinkInputToOutputResponse* reply ) override ;
};
