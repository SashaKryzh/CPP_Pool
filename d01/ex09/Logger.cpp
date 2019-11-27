#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>

#include "Logger.hpp"

Logger::Logger(std::string filename)
{
	_filename = filename;
}

typedef void (Logger::* logDest) (std::string) const;

void Logger::log(std::string const & dest, std::string const & message)
{
	std::string destsString[2] = {
		CONSOLE_DEST,
		FILE_DEST,
	};

	logDest dests[2] = {
		&Logger::logToConsole,
		&Logger::logToFile,
	};

	std::string log = makeLogEntry(message);

	for (int i = 0; i < 2; i++)
	{
		if (destsString[i] == dest)
		{
			(this->*dests[i])(log);
			return ;
		}
	}
}

void Logger::logToConsole(std::string log) const
{
	std::cout << log << std::endl;
}

void Logger::logToFile(std::string log) const
{
	std::ofstream fs;
	fs.open(_filename, std::ios::app);

	if (fs.is_open() == false)
	{
		std::cout << "Can't open the file: " << _filename << std::endl;
		return ;
	}

	fs << log << std::endl;
	fs.close();
}

std::string Logger::makeLogEntry(std::string str) const
{
	std::time_t time = std::time(nullptr);
	tm *t = localtime(&time);

	std::stringstream buffer;
	buffer << "["
			  << t->tm_year + 1900
			  << std::setw(2) << std::right << std::setfill('0')
			  << t->tm_mon
			  << std::setw(2) << std::right << std::setfill('0')
			  << t->tm_mday
			  << "_"
			  << std::setw(2) << std::right << std::setfill('0')
			  << t->tm_hour
			  << std::setw(2) << std::right << std::setfill('0')
			  << t->tm_min
			  << std::setw(2) << std::right << std::setfill('0')
			  << t->tm_sec
			  << "] "
			  << str;

	return buffer.str();
}