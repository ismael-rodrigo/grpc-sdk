#include "protocol/commands/DefaultCommand.h"
#include "hello/hello.grpc.pb.h"

#pragma once

class Istxrx 
{
public:
    Istxrx();
    void setStateDeviceComand(SetStateArgs args);
    char* getCommandSerialized();

private:
    Command _command;
    char _cri;
    char _crs;
};