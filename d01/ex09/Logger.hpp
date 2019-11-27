#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>

#define CONSOLE_DEST "to_console"
#define FILE_DEST "to_file"

class Logger
{
public:
	Logger(std::string filename);

	void log(std::string const & dest, std::string const & message);

private:
	std::string _filename;

	void logToConsole(std::string log) const;
	void logToFile(std::string log) const;
	std::string makeLogEntry(std::string str) const;
};

#endif