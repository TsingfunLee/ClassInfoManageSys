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

void help();
void add(vector<student>*, student&);
void del(vector<student>*, student&);
void update(vector<student>*, student&);
void query(vector<student>*, student&);
void show(vector<student>*);

int main()
{
	vector<student> stuInfo;
	vector<student>* pstuInfo = &stuInfo;
	student stu;
	student& pstu = stu;
	stu.no = 0;
	char command;
	
	while(1)
	{
		help();

		cin>>command;

		if(command == 'a')
		{
			add(pstuInfo, pstu);
		}
		else if(command == 'd')
		{
		    del(pstuInfo, pstu);
		}
		else if(command == 'm')
		{
			update(pstuInfo, pstu);
		}
		else if(command == 'q')
		{
			query(pstuInfo, pstu);
		}
		else if(command == 's')
		{
			show(pstuInfo);
		}
		else if(command == 'e')
		{
			return -1;
		}
		else
		{
			cout<<"请输入正确的命令！"<<endl;
		}
	}
}

void help()
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

void add(vector<student>* stuInfo, student& stu)
{
	cout<<"请输入学生姓名："<<endl;
	cin>>stu.name;
	cout<<"请输入学生学号："<<endl;
	cin>>stu.stuID;
	cout<<"请输入学生年龄："<<endl;
	cin>>stu.age;
	
	if((*stuInfo).empty() == true)
	{
		stu.no = 1;
	}
	else 
	{
        vector<student>::iterator it = (*stuInfo).end()-1;
        stu.no = (*it).no+1;
	}

	(*stuInfo).push_back(stu);
	show(stuInfo);
}

void del(vector<student>* stuInfo, student& stu)
{
	cout<<"请输入要删除的学生序号："<<endl;
	cin>>stu.no;
	(*stuInfo).erase((*stuInfo).begin()+stu.no-1);
	vector<student>::iterator it = (*stuInfo).begin()+stu.no-1;
	for(;it!=(*stuInfo).end();it++)
	{
		(*it).no--;
	}
	show(stuInfo);
}

void update(vector<student>* stuInfo, student& stu)
{
	cout<<"请输入要修改的学生序号："<<endl;
	cin>>stu.no;
	cout<<"请输入要修改的学生姓名："<<endl;
	cin>>stu.name;
	cout<<"请输入要修改的学生学号："<<endl;
	cin>>stu.stuID;
	cout<<"请输入要修改的学生年龄："<<endl;
	cin>>stu.age;
	vector<student>::iterator it = (*stuInfo).begin()+stu.no-1;
	(*stuInfo).insert(it,stu);
	(*stuInfo).erase(it+1);
	show(stuInfo);
}

void query(vector<student>* stuInfo, student& stu)
{
	char command;
	cout<<"1   按序号    2    按姓名   3   按学号   4   按年龄"<<endl;
	cin>>command;
	if(command == '1')
	{
		int no;
		cout<<"请输入要查询的序号："<<endl;
	    cin>>no;
		vector<student>::iterator it = (*stuInfo).begin();
		for(;it!=(*stuInfo).end();it++)
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
		vector<student>::iterator it = (*stuInfo).begin();
		for(;it!=(*stuInfo).end();it++)
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
		vector<student>::iterator it = (*stuInfo).begin();
		for(;it!=(*stuInfo).end();it++)
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
		vector<student>::iterator it = (*stuInfo).begin();
		for(;it!=(*stuInfo).end();it++)
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

void show(vector<student>* stuInfo)
{
	vector<student>::iterator it = (*stuInfo).begin();
	for(;it!=(*stuInfo).end();it++)
	{
		cout<<(*it).no<<" "<<(*it).name<<" "<<(*it).stuID<<" "<<(*it).age<<endl;
	}
}