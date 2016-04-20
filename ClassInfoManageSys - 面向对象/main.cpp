#include "StudentInfo.h"

int main()
{
	StudentInfo StuInfo;
	char command;
	
	while(1)
	{
		StuInfo.help();

		cin>>command;

		if(command == 'a')
		{
			StuInfo.add();
		}
		else if(command == 'd')
		{
		    StuInfo.del();
		}
		else if(command == 'm')
		{
			StuInfo.update();
		}
		else if(command == 'q')
		{
			StuInfo.query();
		}
		else if(command == 's')
		{
			StuInfo.show();
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

