#include "CourseOpt.h"

CCourseOpt::CCourseOpt(std::string filename) :
	filename(filename){
	infile();
}

void CCourseOpt::printInfo() {
	std::cout << "***************** �γ̱� ******************" << std::endl;
	std::cout << "*               0.��ʾ�γ�                *" << std::endl;
	std::cout << "*               1.��ӿγ�                *" << std::endl;
	std::cout << "*               2.ɾ���γ�                *" << std::endl;
	std::cout << "*               3.�п�ʱ��                *" << std::endl;
	std::cout << "*               4.����ʱ��                *" << std::endl;
	std::cout << "*               5.��տγ�                *" << std::endl;
	std::cout << "*               6.�������                *" << std::endl;
	std::cout << "*               7.�˳�����                *" << std::endl;
	std::cout << "*******************************************" << std::endl;
}

//��ʾĳһ��Ŀγ�
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

//0.��ʾ�γ�
void CCourseOpt::showTimetable() {
	std::cout << "��ʾ����Ŀγ�?" << std::endl;
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

//1.��ӿγ�
void CCourseOpt::addCourse() {
	std::cout << "�������Ŀγ�?" << std::endl;
	int dayNum = 0;
	std::cin >> dayNum;
	std::cout << "����Ľڿγ�?" << std::endl;
	int courseNum = 0;
	std::cin >> courseNum;
	std::cout << "��ӵĿγ�: " << std::endl;
	char buf[40]{ 0 };
	std::cin >> buf;
	if (dayNum < 1 || dayNum > 7 || courseNum < 1 || courseNum > 12)
		return;
	if (courses.at(dayNum - 1).at(courseNum - 1).second == std::string("null"))
		courses.at(dayNum - 1).at(courseNum - 1).second = std::string(buf);
}

//2.ɾ���γ�
void CCourseOpt::deleteCourse() {
	std::cout << "ɾ������Ŀγ�?" << std::endl;
	int dayNum = 0;
	std::cin >> dayNum;
	std::cout << "ɾ���Ľڿγ�?" << std::endl;
	int courseNum = 0;
	std::cin >> courseNum;
	if (dayNum < 1 || dayNum > 7 || courseNum < 1 || courseNum > 12)
		return;
	if (courses.at(dayNum - 1).at(courseNum - 1).second != std::string("null"))
		courses.at(dayNum - 1).at(courseNum - 1).second = std::string("null");
}

//3.�п�ʱ��
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

//4.����ʱ��
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

//5.��տγ�
void CCourseOpt::emptyCourse() {
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 12; j++) {
			if (courses.at(i).at(j).second != std::string("null"))
				courses.at(i).at(j).second = std::string("null");
		}
	}
}

//6.�������
void CCourseOpt::emptyAdd() {
	courses.clear();
	infile();
}

//7.�˳�����
void CCourseOpt::exitOpt() {
	outfile();
}

//���ļ�
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

//д�ļ�
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

