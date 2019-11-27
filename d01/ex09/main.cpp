#include "Logger.hpp"

int main()
{
	Logger logger("test.log");

	logger.log(CONSOLE_DEST, "this is log to console");
	logger.log(CONSOLE_DEST, "this is another log to console");

	logger.log(FILE_DEST, "this is log to file");
	logger.log(FILE_DEST, "this is another log to file");

	return 0;
}
