#include "Logger.h"


int main()
{
    LoggerOptions::setValidLoggerLevel(3);
    LoggerOptions::insertValidLoggerPrefix(L"Fuck");

    Logger{ LoggerOptions{ L"Fuck", LoggerOptions::LoggerLevel::Debug } } << "Hello, world!";
}
