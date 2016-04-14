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
			cout<<"��������ȷ�����"<<endl;
		}
	}
}

void help()
{
	cout<<"        ѧ����Ϣ����ϵͳ       "<<endl;
	cout<<"-------------------------------"<<endl;
	cout<<"|       ������Ϣ    a         |"<<endl;
	cout<<"|       ɾ����Ϣ    d         |"<<endl;
	cout<<"|       �޸���Ϣ    m         |"<<endl;
	cout<<"|       ��ѯ��Ϣ    q         |"<<endl;
	cout<<"|       ��ʾ��Ϣ    s         |"<<endl;
	cout<<"|       �˳�        e         |"<<endl;
	cout<<"-------------------------------"<<endl;
}

void add(vector<student>* stuInfo, student& stu)
{
	cout<<"������ѧ��������"<<endl;
	cin>>stu.name;
	cout<<"������ѧ��ѧ�ţ�"<<endl;
	cin>>stu.stuID;
	cout<<"������ѧ�����䣺"<<endl;
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
	cout<<"������Ҫɾ����ѧ����ţ�"<<endl;
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
	cout<<"������Ҫ�޸ĵ�ѧ����ţ�"<<endl;
	cin>>stu.no;
	cout<<"������Ҫ�޸ĵ�ѧ��������"<<endl;
	cin>>stu.name;
	cout<<"������Ҫ�޸ĵ�ѧ��ѧ�ţ�"<<endl;
	cin>>stu.stuID;
	cout<<"������Ҫ�޸ĵ�ѧ�����䣺"<<endl;
	cin>>stu.age;
	vector<student>::iterator it = (*stuInfo).begin()+stu.no-1;
	(*stuInfo).insert(it,stu);
	(*stuInfo).erase(it+1);
	show(stuInfo);
}

void query(vector<student>* stuInfo, student& stu)
{
	char command;
	cout<<"1   �����    2    ������   3   ��ѧ��   4   ������"<<endl;
	cin>>command;
	if(command == '1')
	{
		int no;
		cout<<"������Ҫ��ѯ����ţ�"<<endl;
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
		cout<<"������Ҫ��ѯ��������"<<endl;
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
		cout<<"������Ҫ��ѯ��ѧ�ţ�"<<endl;
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
		cout<<"������Ҫ��ѯ�����䣺"<<endl;
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
		cout<<"��������ȷ�����"<<endl;
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