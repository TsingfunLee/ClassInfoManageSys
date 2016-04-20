#include "StudentInfo.h"


StudentInfo::StudentInfo(void)
{
}


StudentInfo::~StudentInfo(void)
{
}

void StudentInfo::help()
{
	cout<<"        学生信息管理系统       "<<endl;
	cout<<"-------------------------------"<<endl;
	cout<<"|       增加信息    a         |"<<endl;
	cout<<"|       删除信息    d         |"<<endl;
	cout<<"|       修改信息    m         |"<<endl;
	cout<<"|       查询信息    q         |"<<endl;
	cout<<"|       显示信息    s         |"<<endl;
	cout<<"|       退出        e         |"<<endl;
	cout<<"-------------------------------"<<endl;
}

void StudentInfo::add()
{
	cout<<"请输入学生姓名："<<endl;
	cin>>stu.name;
	cout<<"请输入学生学号："<<endl;
	cin>>stu.stuID;
	cout<<"请输入学生年龄："<<endl;
	cin>>stu.age;
	
	if(stuInfo.empty() == true)
	{
		stu.no = 1;
	}
	else 
	{
        vector<student>::iterator it = stuInfo.end()-1;
        stu.no = (*it).no+1;
	}

	stuInfo.push_back(stu);
	show();
}

void StudentInfo::del()
{
	cout<<"请输入要删除的学生序号："<<endl;
	cin>>stu.no;
	stuInfo.erase(stuInfo.begin()+stu.no-1);
	vector<student>::iterator it = stuInfo.begin()+stu.no-1;
	for(;it!=stuInfo.end();it++)
	{
		(*it).no--;
	}
	show();
}

void StudentInfo::update()
{
	cout<<"请输入要修改的学生序号："<<endl;
	cin>>stu.no;
	cout<<"请输入要修改的学生姓名："<<endl;
	cin>>stu.name;
	cout<<"请输入要修改的学生学号："<<endl;
	cin>>stu.stuID;
	cout<<"请输入要修改的学生年龄："<<endl;
	cin>>stu.age;
	vector<student>::iterator it = stuInfo.begin()+stu.no-1;
	stuInfo.insert(it,stu);
	stuInfo.erase(it+1);
	show();
}

void StudentInfo::query()
{
	char command;
	cout<<"1   按序号    2    按姓名   3   按学号   4   按年龄"<<endl;
	cin>>command;
	if(command == '1')
	{
		int no;
		cout<<"请输入要查询的序号："<<endl;
	    cin>>no;
		vector<student>::iterator it = stuInfo.begin();
		for(;it!=stuInfo.end();it++)
		{
			if((*it).no == no)
			{
				cout<<(*it).no<<" "<<(*it).name<<" "<<(*it).stuID<<" "<<(*it).age<<endl;
			}
		}
	}
	else if(command == '2')
	{
		char name[11];
		cout<<"请输入要查询的姓名："<<endl;
		cin>>name;
		vector<student>::iterator it = stuInfo.begin();
		for(;it!=stuInfo.end();it++)
		{
			if(strcmp((*it).name,name) == 0)
			{
				cout<<(*it).no<<" "<<(*it).name<<" "<<(*it).stuID<<" "<<(*it).age<<endl;
			}
		}
	}
	else if(command == '3')
	{
		char stuID[10];
		cout<<"请输入要查询的学号："<<endl;
		cin>>stuID;
		vector<student>::iterator it = stuInfo.begin();
		for(;it!=stuInfo.end();it++)
		{
			if(strcmp((*it).stuID, stuID) == 0)
			{
				cout<<(*it).no<<" "<<(*it).name<<" "<<(*it).stuID<<" "<<(*it).age<<endl;
			}
		}
	}
	else if(command == '4')
	{
		short age;
		cout<<"请输入要查询的年龄："<<endl;
		cin>>age;
		vector<student>::iterator it = stuInfo.begin();
		for(;it!=stuInfo.end();it++)
		{
			if((*it).age == age)
			{
				cout<<(*it).no<<" "<<(*it).name<<" "<<(*it).stuID<<" "<<(*it).age<<endl;
			}
		}
	}
	else
	{
		cout<<"请输入正确的命令！"<<endl;
	}
}

void StudentInfo::show()
{
	vector<student>::iterator it = stuInfo.begin();
	for(;it!=stuInfo.end();it++)
	{
		cout<<(*it).no<<" "<<(*it).name<<" "<<(*it).stuID<<" "<<(*it).age<<endl;
	}
}