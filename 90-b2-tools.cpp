/*�����2�� ��� 1652289*/
#include "90-b2.h"

void data_input(int &line, int &col, int index)//���õ����뺯��
{
	cout << "����������(7-9)��";
	cin >> line;
	cout << "����������(7-9)��";
	cin >> col;
	while (line < 7 || line>9 || col < 7 || col>9)
	{
		cout << "���������������" << endl;
		Sleep(500);
		system("cls");
		cin.clear();
		cin.ignore();
		cout << "����������(7-9)��";
		cin >> line;
		cout << "����������(7-9)��";
		cin >> col;
	}
}

void ball_produce(int(*ball)[9], int num, int col, int line, int *color, int flag)//���ɳ�ʼС���Լ����С��
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

int search_way(int(*ball)[9], char *start, char *end, int col, int line, int direct, int i)//��1��2��3��4��ʼ0(���ݷ���)
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
	{//��ʵ����ĺ���˳����Ը���Ŀ��λ������ʼλ�õķ�����ģ�������һЩ�����Ż���·��
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