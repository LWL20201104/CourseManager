#include <iostream>
#include <fstream>
#include <iomanip>

int main(int argc, char* argv[]) {
	std::fstream infile;
	infile.open("c.txt", std::ios::out);
	infile.setf(std::ios::left);
	infile.fill('\0');
	infile << std::setw(10) << "hello" << std::setw(10) << "world" << "\n";
	infile << std::setw(10) << "hello1" << std::setw(10) << "world1" << "\n";
	infile.close();
	/*
	std::fstream outfile;
	outfile.open("c.txt", std::ios::in);
 	char buf[100]{ 0 };

	outfile.seekg(0, std::ios::beg);
	outfile.get(buf, 10, '\0');
	printf("%s\n", buf);

	outfile.seekg(10, std::ios::beg);
	outfile.get(buf, 10, '\0');
	printf("%s\n", buf);

	outfile.seekg(22, std::ios::beg);
	outfile.get(buf, 10, '\0');
	printf("%s\n", buf);

	outfile.seekg(32, std::ios::beg);
	outfile.get(buf, 10, '\0');
	printf("%s\n", buf);

	outfile.close();*/
	

	//std::cout << "hello world" << std::endl;
	return 0;
}