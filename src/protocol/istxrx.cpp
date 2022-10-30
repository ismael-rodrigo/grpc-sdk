#include "protocol/istxrx.h"
#include "serializer/serializer.h"

Istxrx::Istxrx():
_cri(77),
_crs(88)
{};

char* Istxrx::getCommandSerialized()
{
    return serializer_command_to_char(this->_command);
};
