#include"��.h"
int main()
{
	int an = 1;

	while (an != 0) {
		cout << "\t\t\t**ͼ�����ϵͳ**" << endl;
		cout << "\t\t\t1��������Ϣ" << endl;
		cout << "\t\t\t2�����߽���" << endl;
		cout << "\t\t\t0���������" << endl;
		cout << "  �����룺";
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

	//�����������,ɾ������
	delete_node();
}