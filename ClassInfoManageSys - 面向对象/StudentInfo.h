#pragma once
#include <vector>
#include <iostream>
using namespace std;

struct student
{
	int no;
	char name[11];
	char stuID[10];
	short age;
};

class StudentInfo
{
public:
	StudentInfo(void);
	~StudentInfo(void);
	void help();
	void add();
	void del();
	void update();
	void query();
	void show();
private:
	vector<student> stuInfo;
	student stu;
};

