#include "serializer/serializer.h"

char* serializer_command_to_char(Command command)
{
    char* command_serialized = new char[8];

    command_serialized[0] = command.cri;
    command_serialized[1] = command.cmd;
    command_serialized[2] = command.b1;
    command_serialized[3] = command.b2;
    command_serialized[4] = command.b3;
    command_serialized[5] = command.b4;
    command_serialized[6] = command.b5;
    command_serialized[7] = command.crs;

    return command_serialized;

    }