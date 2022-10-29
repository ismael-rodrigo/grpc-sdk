SET ARG=%1


IF "%ARG%"=="-c" cmake -S . -B out/build/ -G "Visual Studio 16 2019"

IF "%ARG%"=="-b" cmake --build out/build