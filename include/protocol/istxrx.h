#include "protocol/commands/DefaultCommand.h"
#include "protocol/commands/setStateDevice.h"
#pragma once

class Istxrx 
{
public:
    Istxrx();
    void setStateDeviceComand(SetStateDeviceArgs args);

    char* getCommandSerialized();

private:
    Command _command;
    char _cri;
    char _crs;
};