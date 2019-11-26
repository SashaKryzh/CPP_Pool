#include "replacer.hpp"

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cout << "Wrong number of arguments" << std::endl;
		return 0;
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if (filename.empty() || s1.empty() || s2.empty())
	{
		std::cout << "Argument is empty" << std::endl;
		return 0;
	}

	std::cout << filename << " | " << s1 << " | " << s2 << std::endl;

	std::ifstream fs1(filename);
	if (fs1.is_open() == false)
	{
		std::cout << "File can not be opened" << std::endl;
		return 0;
	}

	std::stringstream buffer;
	buffer << fs1.rdbuf();
	fs1.close(); // Close file 1

	std::string content;
	content = buffer.str();

	size_t start;
	while((start = content.find(s1)) != std::string::npos)
	{
		content.replace(start, s1.length(), s2);
	}
	
	std::ofstream fs2(filename + ".replace");
	fs2 << content;
	fs2.close(); // Close file 2

	return 0;
}