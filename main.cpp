#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>

#define READ_LEN 38

std::vector<std::vector<std::pair<std::string, std::string>>> courses;

void outfp() {
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
}

void infp() {
	char buf1[20]{ 0 };
	char buf2[40]{ 0 };
	std::fstream infile;
	infile.open("c.txt", std::ios::in);
	//std::vector<std::vector<std::pair<std::string, std::string>>> courses;

	for (int i = 0; i < 7; i++) {
		infile.seekg(38 * (i * 13), std::ios::beg);
		memset(buf2, 0, sizeof(buf2));
		infile.get(buf2, READ_LEN, ' ');
		if (infile.eof()) {
			break;
		}
		//printf("%s\n", buf2);
		std::vector<std::pair<std::string, std::string>> course;
		for (int j = 0; j < 12; j++) {
			infile.seekg(38 * (i * 13 + j + 1), std::ios::beg);
			memset(buf1, 0, sizeof(buf1));
			infile.get(buf1, 12, ' ');
			//printf("%s", buf1);

			infile.seekg(38 * (i * 13 + j + 1) + 12, std::ios::beg);
			memset(buf2, 0, sizeof(buf2));
			infile.get(buf2, 30, ' ');
			//printf("%s\n", buf2);

			course.push_back({ std::string(buf1), std::string(buf2) });
		}
		courses.push_back(course);
	}

	infile.close();
}

void printInfo() {
	std::cout << "***************** 课程表 ******************" << std::endl;
	std::cout << "*               0.显示课程                *" << std::endl;
	std::cout << "*               1.添加课程                *" << std::endl;
	std::cout << "*               2.删除课程                *" << std::endl;
	std::cout << "*               3.有课时间                *" << std::endl;
	std::cout << "*               4.空闲时间                *" << std::endl;
	std::cout << "*               5.清空课程                *" << std::endl;
	std::cout << "*               6.清空增加                *" << std::endl;
	std::cout << "*               7.退出操作                *" << std::endl;
	std::cout << "*******************************************" << std::endl;
}

//显示某一天的课程
void showCourses(int num) {
	for (int i = 0; i < 12; i++) {
		std::cout.setf(std::ios::left);
		std::cout << std::setw(12) << courses.at(num - 1).at(i).first;
		if (courses.at(num - 1).at(i).second == std::string("null"))
			std::cout << std::endl;
		else
			std::cout << std::setw(24) << courses.at(num - 1).at(i).second << std::endl;
	}
}

//0.显示课程
void showTimetable() {
	std::cout << "显示哪天的课程?" << std::endl;
	int dayNum = 0;
	std::cin >> dayNum;
	switch (dayNum) {
	case 1:
		showCourses(1);
		break;
	case 2:
		showCourses(2);
		break;
	case 3:
		showCourses(3);
		break;
	case 4:
		showCourses(4);
		break;
	case 5:
		showCourses(5);
		break;
	case 6:
		showCourses(6);
		break;
	case 7:
		showCourses(7);
		break;
	default:
		break;
	}
}

//1.添加课程
void addCourse() {
	std::cout << "addCourse" << std::endl;
}

//2.删除课程
void deleteCourse() {
	std::cout << "showTimetable" << std::endl;
}

//3.有课时间
void classTime() {
	int totalClassTime = 0;
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 12; j++) {
			if (courses.at(i).at(j).second != std::string("null"))
				totalClassTime++;
		}
	}
	std::cout << "Tatal class time: " << totalClassTime * 50 << "min" << std::endl;
}

//4.空闲时间
void spaceTime() {
	int totalSpaceTime = 0;
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 12; j++) {
			if (courses.at(i).at(j).second == std::string("null"))
				totalSpaceTime++;
		}
	}
	std::cout << "Tatal space time: " << totalSpaceTime * 50 << "min" << std::endl;
}

//5.清空课程
void emptyCourse() {
	courses.clear();
}

//6.清空增加
void emptyAdd() {
	courses.clear();
	infp();
}

int main(int argc, char* argv[]) {
	infp();	
	int optNum = 8;
	bool isStop = false;
	while (!isStop) {
		printInfo();
		std::cout << "选择操作: " << std::endl;
		std::cin >> optNum;
		switch (optNum) {
		case 0:
			showTimetable();
			break;
		case 1:
			addCourse();
			break;
		case 2:
			deleteCourse();
			break;
		case 3:
			classTime();
			break;
		case 4:
			spaceTime();
			break;
		case 5:
			emptyCourse();
			break;
		case 6:
			emptyAdd();
			break;
		case 7:
			isStop = true;
			break;
		default:
			std::cout << "重新输入命令" << std::endl; 
			break;
		}
	}

	return 0;
}