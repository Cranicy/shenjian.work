/*�����2�� ��� 1652289*/
#include "90-b2.h"

void manu_choice(char *choice)
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	do
	{
		setconsoleborder(hout, 80, 25);
		setcolor(hout, 0, 7);
		system("cls");
		cout << "---------------------------------------------" << endl;
		cout << "1.�ڲ����飬������ɳ�ʼ5����" << endl;
		cout << "2.�ڲ����飬�������60%����Ѱ���ƶ�·��" << endl;
		cout << "3.�ڲ����飬������" << endl;
		cout << "4.����n*n�Ŀ�ܣ��޷ָ��ߣ��������ʾ5����" << endl;
		cout << "5.����n*n�Ŀ�ܣ��зָ��ߣ��������ʾ5����" << endl;
		cout << "6.n*n�Ŀ�ܣ�60%����֧����꣬���һ���ƶ�" << endl;
		cout << "7.cmdͼ�ν���������" << endl;
		cout << "0.�˳�" << endl;
		/*��ʱ��Ҫ8��9*/
		cout << "---------------------------------------------" << endl;
		cout << "[��ѡ��0-7]";

		*choice = _getch();
	} while (*choice < '0' || *choice>'9');

	system("cls");
}

int main()
{
	char choice;
	do
	{
		manu_choice(&choice);

		if (choice == '1')case_1();
		else if (choice == '2')case_2();
		else if (choice == '3')case_3();
		else if (choice == '4')case_4();
		else if (choice == '5')case_5();
		else if (choice == '6')case_6();
		else if (choice == '7')case_7();

	} while (choice != '0');



	return 0;
}