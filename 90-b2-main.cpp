/*计算机2班 杨宇航 1652289*/
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
		cout << "1.内部数组，随机生成初始5个球" << endl;
		cout << "2.内部数组，随机生成60%的球，寻找移动路径" << endl;
		cout << "3.内部数组，完整版" << endl;
		cout << "4.画出n*n的框架（无分隔线），随机显示5个球" << endl;
		cout << "5.画出n*n的框架（有分隔线），随机显示5个球" << endl;
		cout << "6.n*n的框架，60%的球，支持鼠标，完成一次移动" << endl;
		cout << "7.cmd图形界面完整版" << endl;
		cout << "0.退出" << endl;
		/*暂时不要8，9*/
		cout << "---------------------------------------------" << endl;
		cout << "[请选择0-7]";

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