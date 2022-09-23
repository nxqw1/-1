#include"软工.h"
int main()
{
	int an = 1;

	while (an != 0) {
		cout << "\t\t\t**图书管理系统**" << endl;
		cout << "\t\t\t1、管理信息" << endl;
		cout << "\t\t\t2、读者进入" << endl;
		cout << "\t\t\t0、程序结束" << endl;
		cout << "  请输入：";
		cin >> an;
		switch (an)
		{
		case 1:
			usermain();
			break;
		case 2:
			readermain();
			break;
		}
	}

	//程序运行完成,删除链表
	delete_node();
}