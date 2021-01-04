#ifndef __COURSEOPT__
#define __COURSEOPT__
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include "FileOpt.h"

class CCourseOpt : public CFile {
public:
	CCourseOpt(std::string filename);
	void printInfo();
	void showCourses(int num);
	void showTimetable();
	void addCourse();
	void deleteCourse();
	void classTime();
	void spaceTime();
	void emptyCourse();
	void emptyAdd();
	void exitOpt();

	virtual void infile();
	virtual void outfile();

private:
	std::string filename;
	std::vector<std::vector<std::pair<std::string, std::string>>> courses;
};

#endif //__COURSEOPT__

