#include "protocol/commands/DefaultCommand.h"

#include "services/device.grpc.pb.h"

#pragma once

class Istxrx 
{
public:
    Istxrx();
    void setStateDeviceComand(SetStateArgs args);
    void linkInputToOutput(linkInputToOutputArgs args);
    char* getCommandSerialized();
    

private:
    Command _command;
    char _cri;
    char _crs;
};