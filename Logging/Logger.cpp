#pragma warning(disable: 4996)
#include "Logger.h"
#include <iomanip>

Logger::Logger(std::ostream& out, Level minLogLevel) :
	m_out(out), m_minLogLevel(minLogLevel)
{
	// Empty
}

void Logger::Log(const std::string& message, Level level)
{
	if (level < m_minLogLevel)
	{
		return;
	}
	switch (level)
	{
	case Logger::Level::Debug:
		m_out << "[DEBUG] ";
		break;
	case Logger::Level::Info:
		m_out << "[INFO] ";
		break;
	case Logger::Level::Warning:
		m_out << "[WARNING] ";
		break;
	case Logger::Level::Error:
		m_out << "[ERROR] ";
		break;
	default:
		break;
	}
	std::time_t time_now = std::time(nullptr);
	std::tm tm = *std::localtime(&time_now);
	m_out << "<" << std::put_time(&tm, "%c") << "> ";
	m_out << message << "\n";
	m_out.flush();
}
