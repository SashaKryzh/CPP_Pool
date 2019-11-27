#include <iostream>
#include <fstream>

void pipeStream(std::istream &istream)
{
	std::cout << istream.rdbuf();
}

int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		pipeStream(std::cin);
		return 0;
	}

	if (argc == 2 && std::string(argv[1]) == "--")
	{
		pipeStream(std::cin);
		return 0;
	}

	for (int i = 1; i < argc; i++)
	{
		std::string arg(argv[i]);

		if (arg == "--" && i == 1)
		{
			continue;
		}

		if (arg == "-")
		{
			pipeStream(std::cin);
			continue;
		}

		std::ifstream fs(argv[i]);
		if (fs.good())
		{
			pipeStream(fs);
			fs.close();
		}
		else
		{
			std::cout << argv[0] << ": "
					  << argv[i] << ": "
					  << strerror(errno)
					  << std::endl;
		}
	}

	return 0;
}
