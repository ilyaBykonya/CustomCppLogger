#include "Logger.h"

Logger::Logger(const LoggerOptions& options)
	:m_options{ options }
	{
	}

Logger::~Logger()
{
	if (m_options.isValidLogChunk()) {
		std::wcout << m_options << this->rdbuf();
	}
}
