#include "CourseOpt.h"

CCourseOpt::CCourseOpt(std::string filename) :
	filename(filename){
	infile();
}

void CCourseOpt::printInfo() {
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
void CCourseOpt::showCourses(int num) {
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
void CCourseOpt::showTimetable() {
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
void CCourseOpt::addCourse() {
	std::cout << "添加哪天的课程?" << std::endl;
	int dayNum = 0;
	std::cin >> dayNum;
	std::cout << "添加哪节课程?" << std::endl;
	int courseNum = 0;
	std::cin >> courseNum;
	std::cout << "添加的课程: " << std::endl;
	char buf[40]{ 0 };
	std::cin >> buf;
	if (dayNum < 1 || dayNum > 7 || courseNum < 1 || courseNum > 12)
		return;
	if (courses.at(dayNum - 1).at(courseNum - 1).second == std::string("null"))
		courses.at(dayNum - 1).at(courseNum - 1).second = std::string(buf);
}

//2.删除课程
void CCourseOpt::deleteCourse() {
	std::cout << "删除哪天的课程?" << std::endl;
	int dayNum = 0;
	std::cin >> dayNum;
	std::cout << "删除哪节课程?" << std::endl;
	int courseNum = 0;
	std::cin >> courseNum;
	if (dayNum < 1 || dayNum > 7 || courseNum < 1 || courseNum > 12)
		return;
	if (courses.at(dayNum - 1).at(courseNum - 1).second != std::string("null"))
		courses.at(dayNum - 1).at(courseNum - 1).second = std::string("null");
}

//3.有课时间
void CCourseOpt::classTime() {
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
void CCourseOpt::spaceTime() {
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
void CCourseOpt::emptyCourse() {
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 12; j++) {
			if (courses.at(i).at(j).second != std::string("null"))
				courses.at(i).at(j).second = std::string("null");
		}
	}
}

//6.清空增加
void CCourseOpt::emptyAdd() {
	courses.clear();
	infile();
}

//7.退出操作
void CCourseOpt::exitOpt() {
	outfile();
}

//读文件
void CCourseOpt::infile() {
	char buf1[20]{ 0 };
	char buf2[40]{ 0 };
	std::fstream infile;
	infile.open(filename.c_str(), std::ios::in);

	for (int i = 0; i < 7; i++) {
		infile.seekg(38 * (i * 13), std::ios::beg);
		memset(buf2, 0, sizeof(buf2));
		infile.get(buf2, 38, ' ');
		if (infile.eof()) {
			break;
		}
		std::vector<std::pair<std::string, std::string>> course;
		for (int j = 0; j < 12; j++) {
			infile.seekg(38 * (i * 13 + j + 1), std::ios::beg);
			memset(buf1, 0, sizeof(buf1));
			infile.get(buf1, 12, ' ');

			infile.seekg(38 * (i * 13 + j + 1) + 12, std::ios::beg);
			memset(buf2, 0, sizeof(buf2));
			infile.get(buf2, 30, ' ');

			course.push_back({ std::string(buf1), std::string(buf2) });
		}
		courses.push_back(course);
	}

	infile.close();
}

//写文件
void CCourseOpt::outfile() {
	std::fstream outfile;
	outfile.open(filename.c_str(), std::ios::out);
	outfile.setf(std::ios::left);
	outfile.fill(' ');
	for (int i = 0; i < 7; i++) {
		outfile << std::setw(36) << std::to_string(i + 1).c_str() << std::endl;
		for (int j = 0; j < 12; j++) {
			outfile << std::setw(12) << courses.at(i).at(j).first.c_str() << std::setw(24) << courses.at(i).at(j).second.c_str() << std::endl;
		}
	}
	outfile.close();
}

