#include <iostream>
#include <fstream>
#include <string>

int main(void)
{
	{ // writing on a text file
		std::ofstream myfile("out/example.txt", std::ios::out | std::ios::app);
		// Given option overrides the default value of fstream but is combined with the default value of ofstream/ifstream.

		if (myfile.is_open())
		{
			myfile << "This is a line.\n";
			myfile << "This is another line.\n";
			myfile.close();
		}
		else std::cout << "Unable to open file";
	}

	{ // reading a text file
		std::string line;
		std::ifstream myfile("out/example.txt");

		if (myfile.is_open())
		{
			while (getline(myfile, line)) // getline does not reside in std namespace
			{
				std::cout << line << '\n';
			}
			myfile.close();
		}
		else std::cout << "Unable to open file";
	}

	{ // obtaining file size
		std::ifstream myfile("out/example.txt", std::ios::binary);

		std::streampos begin = myfile.tellg(); // tellg() returns get position of the stream (tellp() for put position).
		myfile.seekg(0, std::ios::end); // seekg() moves get position of the stream (by an offset relative to the end of the stream in this case).
		std::streampos end = myfile.tellg();

		myfile.close();

		std::cout << "size is: " << (end - begin) << " bytes.\n";
	}

	{
		std::ifstream file("out/example.txt", std::ios::in | std::ios::binary | std::ios::ate); // get pointer positioned at the end of the file
		if (file.is_open())
		{
			std::streampos size = file.tellg();
			char* memblock = new char[size];

			file.seekg(0, std::ios::beg);
			file.read(memblock, size);

			file.close();

			std::cout << "The entire file content is in memory." << std::endl;

			delete[] memblock;
		}
		else std::cout << "Unable to open file";
	}

	std::cin.get();	
	return 0;
}