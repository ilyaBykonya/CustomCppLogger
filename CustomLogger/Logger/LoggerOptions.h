#pragma once
#include <unordered_set>
#include <string>

class LoggerOptions
{
public:
	enum class LoggerLevel {
		None	= 0x0,	//00000
		Info	= 0x1,	//00001
		Debug	= 0x2,	//00010
		Warning = 0x4,	//00100
		Error	= 0x8,	//01000
		Fatal	= 0x10,	//10000
		Mask	= 0x1f	//11111
	};
private:
	static std::unordered_set<std::wstring> s_validLoggerPrefixes;
	static uint8_t s_validLoggerLevels;
private:
	std::wstring m_instanceLoggerPrefix;
	LoggerLevel m_instanceLoggerLevel;
public:
	explicit LoggerOptions(const std::wstring& prefix, LoggerLevel level);
	bool isValidLogChunk() const;
public:
	friend std::wostream& operator<<(std::wostream& out, const LoggerOptions& object);
	static void insertValidLoggerPrefix(const std::wstring& prefix);
	static void removeValidLoggerPrefix(const std::wstring& prefix);
	static void setValidLoggerLevel(uint8_t level);
};

