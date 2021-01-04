#include <iostream>
#include "CourseOpt.h"

/*void outfp() {
	std::fstream outfile;
	outfile.open("c.txt", std::ios::app);
	outfile.setf(std::ios::left);
	outfile.fill(' ');
	outfile << std::setw(36) << "7" << std::endl;
	outfile << std::setw(12) << "8:30-9:20" << std::setw(24) << "软件需求分析与设计" << std::endl;
	outfile << std::setw(12) << "9:30-10:20" << std::setw(24) << "软件需求分析与设计" << std::endl;
	outfile << std::setw(12) << "10:40-11:30" << std::setw(24) << "软件需求分析与设计" << std::endl;
	outfile << std::setw(12) << "11:40-12:30" << std::setw(24) << "软件需求分析与设计" << std::endl;
	outfile << std::setw(12) << "14:00-14:50" << std::setw(24) << "null" << std::endl;
	outfile << std::setw(12) << "15:00-15:50" << std::setw(24) << "null" << std::endl;
	outfile << std::setw(12) << "16:10-17:00" << std::setw(24) << "null" << std::endl;
	outfile << std::setw(12) << "17:10-18:00" << std::setw(24) << "null" << std::endl;
	outfile << std::setw(12) << "18:30-19:20" << std::setw(24) << "null" << std::endl;
	outfile << std::setw(12) << "19:30-20:20" << std::setw(24) << "null" << std::endl;
	outfile << std::setw(12) << "20:30-21:20" << std::setw(24) << "null" << std::endl;
	outfile << std::setw(12) << "21:30-22:20" << std::setw(24) << "null" << std::endl;
	outfile.close();
}*/

int main(int argc, char* argv[]) {
	int optNum = 8;
	bool isStop = false;
	CCourseOpt courseOpt(std::string("c.txt"));
	while (!isStop) {
		courseOpt.printInfo();
		std::cout << "选择操作: " << std::endl;
		std::cin >> optNum;
		switch (optNum) {
		case 0:
			courseOpt.showTimetable();
			break;
		case 1:
			courseOpt.addCourse();
			break;
		case 2:
			courseOpt.deleteCourse();
			break;
		case 3:
			courseOpt.classTime();
			break;
		case 4:
			courseOpt.spaceTime();
			break;
		case 5:
			courseOpt.emptyCourse();
			break;
		case 6:
			courseOpt.emptyAdd();
			break;
		case 7:
			isStop = true;
			courseOpt.exitOpt();
			break;
		default:
			std::cout << "重新输入命令" << std::endl; 
			break;
		}
	}

	return 0;
}