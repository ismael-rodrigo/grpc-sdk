#include "protocol/istxrx.h"


void Istxrx::setStateDeviceComand(SetStateArgs args)
{
    this->_command.cri = _cri;
    this->_command.cmd = 75;
    this->_command.b1 = args.io_address();
    this->_command.b2 = args.new_state();
    this->_command.crs = _crs;
}