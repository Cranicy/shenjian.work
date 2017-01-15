/*计算机2班 杨宇航 1652289*/
#include "90-b2.h"

void data_input(int &line, int &col, int index)//共用的输入函数
{
	cout << "请输入行数(7-9)：";
	cin >> line;
	cout << "请输入列数(7-9)：";
	cin >> col;
	while (line < 7 || line>9 || col < 7 || col>9)
	{
		cout << "输入错误，重新输入" << endl;
		Sleep(500);
		system("cls");
		cin.clear();
		cin.ignore();
		cout << "请输入行数(7-9)：";
		cin >> line;
		cout << "请输入列数(7-9)：";
		cin >> col;
	}
}

void ball_produce(int(*ball)[9], int num, int col, int line, int *color, int flag)//生成初始小球以及添加小球
{
	int X, Y;
	srand((unsigned int)time(0));

	for (int i = 0; i < num; i++)
	{
		X = rand() % col;
		Y = rand() % line;

		if (*(*(ball + Y) + X) != 0)i--;
		else
		{
			if (flag == 1)*(*(ball + Y) + X) = *(color + i);
			else
			{
				do
				{
					*(*(ball + Y) + X) = rand() % 7 + 1;
				} while (*(*(ball + Y) + X) == 14);
			}
		}
	}
}

int search_way(int(*ball)[9], char *start, char *end, int col, int line, int direct, int i)//上1下2左3右4初始0(传递方向)
{
	if (direct != 0)
	{
		int k;
		if (direct == 3)k = 4;
		else if (direct == 4)k = 3;
		else if (direct == 1)k = 2;
		else if (direct == 2)k = 1;
		ball[int(start[0]) - 65][int(start[1]) - 49] = -k;
	}
	if (strcmp(start, end) == 0)return 1;
	else
	{//其实这里的函数顺序可以根据目标位置与起始位置的方向更改，可以在一些方面优化下路径
		if (start[1] < '0' + col&& i == 0)
		{
			start[1]++;
			if (ball[int(start[0]) - 65][int(start[1]) - 49] == 0)
			{
				i = search_way(ball, start, end, col, line, 3, i);
				if (i == 0)ball[int(start[0]) - 65][int(start[1]) - 49] = 0;
			}

			start[1]--;
		}
		if (start[0] < 'A' + line - 1&& i == 0)
		{
			start[0]++;
			if (ball[int(start[0]) - 65][int(start[1]) - 49] == 0)
			{
				i = search_way(ball, start, end, col, line, 1, i);
				if (i == 0)ball[int(start[0]) - 65][int(start[1]) - 49] = 0;
			}
			start[0]--;
		}
		if (start[1] > '1'&&direct != 3 && i == 0)
		{
			start[1]--;
			if (ball[int(start[0]) - 65][int(start[1]) - 49] == 0)
			{
				i = search_way(ball, start, end, col, line, 4, i);
				if (i == 0)ball[int(start[0]) - 65][int(start[1]) - 49] = 0;
			}
			start[1]++;
		}
		if (start[0] > 'A'&&direct != 1 && i == 0)
		{
			start[0]--;
			if (ball[int(start[0]) - 65][int(start[1]) - 49] == 0)
			{
				i = search_way(ball, start, end, col, line, 2, i);
				if (i == 0)ball[int(start[0]) - 65][int(start[1]) - 49] = 0;
			}
			start[0]++;
		}
	}

	return i;
}