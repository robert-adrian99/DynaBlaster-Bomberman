#include "Logger.h"

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
	m_out << message << "\n";
	m_out.flush();
}
