#pragma warning(disable: 4996)
#include "LoggerOptions.h"
#include <iostream>
#include <codecvt>
#include <locale>
#include <chrono>
#include <ctime>


std::unordered_set<std::wstring> LoggerOptions::s_validLoggerPrefixes;
uint8_t LoggerOptions::s_validLoggerLevels = static_cast<uint8_t>(LoggerOptions::LoggerLevel::Mask);

LoggerOptions::LoggerOptions(const std::wstring& prefix, LoggerLevel level)
	:m_instanceLoggerPrefix{ prefix },
	 m_instanceLoggerLevel{ level }
	{
	}
bool LoggerOptions::isValidLogChunk() const {
	if ((static_cast<uint8_t>(m_instanceLoggerLevel) & s_validLoggerLevels) == 0)
		return false;

	return (s_validLoggerPrefixes.find(m_instanceLoggerPrefix) != s_validLoggerPrefixes.end());
}

std::wostream& operator<<(std::wostream& out, const LoggerOptions& object) {
	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
	auto current_time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	std::wstring time_string = converter.from_bytes(std::ctime(&current_time));
	std::wstring time_string_perapared{ time_string.begin(), time_string.end() - 1 };

	out << converter.from_bytes('[')
		<< time_string_perapared
		<< converter.from_bytes("][")
		<< object.m_instanceLoggerPrefix
		<< converter.from_bytes("][")
		<< std::to_wstring(static_cast<uint8_t>(object.m_instanceLoggerLevel))
		<< converter.from_bytes("]: ");
	
	return out;
}
void LoggerOptions::insertValidLoggerPrefix(const std::wstring& prefix) {
	s_validLoggerPrefixes.insert(prefix);
}
void LoggerOptions::removeValidLoggerPrefix(const std::wstring& prefix) {
	s_validLoggerPrefixes.erase(prefix);
}
void LoggerOptions::setValidLoggerLevel(uint8_t level) {
	s_validLoggerLevels = level;
}

