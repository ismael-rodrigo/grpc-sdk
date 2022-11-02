#include "protocol/istxrx.h"

void Istxrx::linkInputToOutput(linkInputToOutputArgs args)
{
    this->_command.cri = _cri;
    this->_command.cmd = 76;
    this->_command.b1 = args.input_address();
    this->_command.b2 = args.output_address();
    this->_command.b3 = args.input_active_mode();
    this->_command.b4 = 0;
    this->_command.b5 = 0;
    this->_command.crs = _crs;
}