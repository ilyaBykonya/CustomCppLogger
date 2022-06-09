#pragma once
#include "LoggerOptions.h"
#include <iostream>
#include <sstream>
#include <string>

class Logger : public std::wstringstream
{
private:
	LoggerOptions m_options;
public:
	explicit Logger(const LoggerOptions& options);
	~Logger();
};

