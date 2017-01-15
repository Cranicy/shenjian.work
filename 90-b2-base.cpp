/*�����2�� ��� 1652289*/
#include "90-b2.h"

void depth_search(int(*ball)[9], int col, int line, int i, int j, int x, int y, int &depth, int color)
{
	if (i < 0 || j < 0 || i >= line || j >= col || ball[i][j] == 0 || ball[i][j] != color)return;
	else
	{
		depth++;
		depth_search(ball, col, line, i + y, j + x, x, y, depth, color);
	}
	return;
}

void find_related_ball(int &num, int(*ball)[9], int i, int j, int color, int line, int col)
{
	if (i < 0 || j < 0 || i >= line || j >= col || ball[i][j] == 0 || ball[i][j] != color)return;
	else
	{
		num++;
		ball[i][j] = 0;
		find_related_ball(num, ball, i, j + 1, color, line, col);
		find_related_ball(num, ball, i, j - 1, color, line, col);
		find_related_ball(num, ball, i + 1, j + 1, color, line, col);
		find_related_ball(num, ball, i + 1, j - 1, color, line, col);
		find_related_ball(num, ball, i + 1, j, color, line, col);
		find_related_ball(num, ball, i - 1, j + 1, color, line, col);
		find_related_ball(num, ball, i - 1, j - 1, color, line, col);
		find_related_ball(num, ball, i - 1, j, color, line, col);
	}
	return;
}

int score_check(int(*ball)[9],int line ,int col)//���õ�ͳ������С��ĸ����Ĺ�������һ����������������෽�������֮�������������,num*(num-3)
{
	int depth[4] = { 0 };
	int num = 0;

	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < col; j++)//0:��������,1;����,2:��,3:����
		{
			if (ball[i][j] != 0)
			{
				depth_search(ball, col, line, i, j, 1, 0, depth[0], ball[i][j]);
				depth_search(ball, col, line, i, j, 1, 1, depth[1], ball[i][j]);
				depth_search(ball, col, line, i, j, 0, 1, depth[2], ball[i][j]);
				depth_search(ball, col, line, i, j, -1, 1, depth[3], ball[i][j]);

				for (int k = 0; k < 4; k++)
				{
					if (depth[k] >= 5)
					{
						find_related_ball(num, ball, i, j, ball[i][j], line, col);
						break;
					}
				}
				for (int k = 0; k < 4; k++)
				{
					depth[k] = 0;
				}

			}
		}
	}
	
	return num;
}

void path_print(int(*ball)[9], int col, int line, char *start)
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "  �W ";
	for (int i = 0; i < col; i++)cout << " " << i + 1 << " ";
	cout << endl << "--+-";
	for (int i = 0; i < col; i++)cout << "---";
	cout << endl;

	for (int i = 0; i < line; i++)
	{
		cout << char(65 + i) << " �W ";

		for (int j = 0; j < col; j++)
		{
			if (i == int(start[0]) - 65 && j == int(start[1]) - 49)cout << " " << '*' << " ";
			else if (*(*(ball + i) + j) <= -1)cout << " " << '*' << " ";
			else cout << " " << '0' << " ";
		}

		cout << endl;
	}

	cout << endl << endl << "�ƶ�·��(��ͬɫ��ʶ)��" << endl;
	cout << "  �W ";
	for (int i = 0; i < col; i++)cout << " " << i + 1 << " ";
	cout << endl << "--+-";
	for (int i = 0; i < col; i++)cout << "---";
	cout << endl;
	for (int i = 0; i < line; i++)
	{
		cout << char(65 + i) << " �W ";

		for (int j = 0; j < col; j++)
		{
			if (i == int(start[0]) - 65 && j == int(start[1]) - 49)
			{
				cout << " ";
				setcolor(hout, 14, 7);
				cout << ball[i][j];
				setcolor(hout, 0, 7);
				cout << " ";
			}
			else if (*(*(ball + i) + j) > -1)cout << " " << '0' << " ";
			else
			{
				cout << " ";
				setcolor(hout, 14, 7);
				cout << "0";
				setcolor(hout, 0, 7);
				cout << " ";
			}
		}

		cout << endl;
	}


}

void ball_print(int(*ball)[9], int col, int line)//��ӡ������С��
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "  �W ";
	for (int i = 0; i < col; i++)cout << " " << i + 1 << " ";
	cout << endl << "--+-";
	for (int i = 0; i < col; i++)cout << "---";
	cout << endl;
	for (int i = 0; i < line; i++)
	{
		cout << char(65 + i) << " �W ";

		for (int j = 0; j < col; j++)
		{
			if (*(*(ball + i) + j) == 0)cout << " " << '0' << " ";
			else
			{
				cout << " ";
				setcolor(hout, 14, *(*(ball + i) + j));
				cout << (*(*(ball + i) + j));
				setcolor(hout, 0, 7);
				cout << " ";
			}
		}

		cout << endl;
	}

	cout << endl;
}

void chose_color(int *color)//ѡ��������С�����ɫ
{
	srand((unsigned int)time(0));

	for (int i = 0; i < 3; i++)
	{
		color[i] = rand() % 7 + 1;
		if (color[i] == 14)i--;
	}
}

void case_input_checkstart(int line, int col, char *choose, int(*ball)[9], int i)//���ѡ���ʼС���λ���Ƿ�Ϊ���Լ������ʽ�Ƿ����
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << endl << "������ĸ+������ʽ[����c2]����Ҫ�ƶ���ľ������꣺";
	cin >> choose;

	if (choose[0] == 'a')choose[0] = 'A';
	if (choose[0] == 'b')choose[0] = 'B';
	if (choose[0] == 'c')choose[0] = 'C';
	if (choose[0] == 'd')choose[0] = 'D';
	if (choose[0] == 'e')choose[0] = 'E';
	if (choose[0] == 'f')choose[0] = 'F';
	if (choose[0] == 'g')choose[0] = 'G';
	if (choose[0] == 'h')choose[0] = 'H';
	if (choose[0] == 'i')choose[0] = 'I';

	while (choose[0] < 'A' || choose[0]>'A' + line - 1 || choose[1]<'1' || choose[1]>'0' + col || ball[int(choose[0]) - 65][int(choose[1]) - 49] == 0)
	{
		if (choose[0] < 'A' || choose[0]>'A' + line - 1 || choose[1]<'1' || choose[1]>'0' + col)
		{
			showch(hout, 0, i, ' ', 0, 7, 100);
			showch(hout, 0, i + 1, ' ', 0, 7, 100);
			showch(hout, 0, i + 2, ' ', 0, 7, 100);
			gotoxy(hout, 0, i);
			cout << "�����ʽ������������";
			cout << endl << "������ĸ+������ʽ[����c2]����Ҫ�ƶ���ľ������꣺";
			cin >> choose;
			if (choose[0] == 'a')choose[0] = 'A';
			if (choose[0] == 'b')choose[0] = 'B';
			if (choose[0] == 'c')choose[0] = 'C';
			if (choose[0] == 'd')choose[0] = 'D';
			if (choose[0] == 'e')choose[0] = 'E';
			if (choose[0] == 'f')choose[0] = 'F';
			if (choose[0] == 'g')choose[0] = 'G';
			if (choose[0] == 'h')choose[0] = 'H';
			if (choose[0] == 'i')choose[0] = 'I';
		}
		else if (ball[int(choose[0]) - 65][int(choose[1]) - 49] == 0)
		{
			showch(hout, 0, i, ' ', 0, 7, 100);
			showch(hout, 0, i + 1, ' ', 0, 7, 100);
			showch(hout, 0, i + 2, ' ', 0, 7, 100);
			gotoxy(hout, 0, i);
			cout << "��ʼλ��Ϊ�գ�����������." << endl;
			cout << "������ĸ+������ʽ[����c2]����Ҫ�ƶ���ľ������꣺";
			cin >> choose;
			if (choose[0] == 'a')choose[0] = 'A';
			if (choose[0] == 'b')choose[0] = 'B';
			if (choose[0] == 'c')choose[0] = 'C';
			if (choose[0] == 'd')choose[0] = 'D';
			if (choose[0] == 'e')choose[0] = 'E';
			if (choose[0] == 'f')choose[0] = 'F';
			if (choose[0] == 'g')choose[0] = 'G';
			if (choose[0] == 'h')choose[0] = 'H';
			if (choose[0] == 'i')choose[0] = 'I';
		}
	}
	gotoxy(hout, 0, i + 2);
	cout << "����Ϊ" << choose[0] << "��" << choose[1] << "��";
}

void case_input_checkend(int line, int col, char *choose, int(*ball)[9],int i)//���ѡ���ʼС���λ���Ƿ�Ϊ���Լ������ʽ�Ƿ����
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << endl << "������ĸ+������ʽ[����c2]����Ҫ�ƶ����Ŀ�����꣺";
	cin >> choose;

	if (choose[0] == 'a')choose[0] = 'A';
	if (choose[0] == 'b')choose[0] = 'B';
	if (choose[0] == 'c')choose[0] = 'C';
	if (choose[0] == 'd')choose[0] = 'D';
	if (choose[0] == 'e')choose[0] = 'E';
	if (choose[0] == 'f')choose[0] = 'F';
	if (choose[0] == 'g')choose[0] = 'G';
	if (choose[0] == 'h')choose[0] = 'H';
	if (choose[0] == 'i')choose[0] = 'I';

	while (choose[0] < 'A' || choose[0]>'A' + line - 1 || choose[1]<'1' || choose[1]>'0' + col || ball[int(choose[0]) - 65][int(choose[1]) - 49] != 0)
	{
		if (choose[0] < 'A' || choose[0]>'A' + line - 1 || choose[1]<'1' || choose[1]>'0' + col)
		{
			showch(hout, 0, i, ' ', 0, 7, 100);
			showch(hout, 0, i + 1, ' ', 0, 7, 100);
			showch(hout, 0, i + 2, ' ', 0, 7, 100);
			gotoxy(hout, 0, i + 1);
			cout << "�����ʽ������������";
			cout << endl << "������ĸ+������ʽ[����c2]����Ҫ�ƶ����Ŀ�����꣺";
			cin >> choose;
			if (choose[0] == 'a')choose[0] = 'A';
			if (choose[0] == 'b')choose[0] = 'B';
			if (choose[0] == 'c')choose[0] = 'C';
			if (choose[0] == 'd')choose[0] = 'D';
			if (choose[0] == 'e')choose[0] = 'E';
			if (choose[0] == 'f')choose[0] = 'F';
			if (choose[0] == 'g')choose[0] = 'G';
			if (choose[0] == 'h')choose[0] = 'H';
			if (choose[0] == 'i')choose[0] = 'I';
		}
		else if (ball[int(choose[0]) - 65][int(choose[1]) - 49] != 0)
		{
			showch(hout, 0, i, ' ', 0, 7, 100);
			showch(hout, 0, i + 1, ' ', 0, 7, 100);
			showch(hout, 0, i + 2, ' ', 0, 7, 100);
			gotoxy(hout, 0, i + 1);
			cout << "Ŀ��λ�÷ǿգ�����������." << endl;
			cout << "������ĸ+������ʽ[����c2]����Ҫ�ƶ����Ŀ�����꣺";
			cin >> choose;
			if (choose[0] == 'a')choose[0] = 'A';
			if (choose[0] == 'b')choose[0] = 'B';
			if (choose[0] == 'c')choose[0] = 'C';
			if (choose[0] == 'd')choose[0] = 'D';
			if (choose[0] == 'e')choose[0] = 'E';
			if (choose[0] == 'f')choose[0] = 'F';
			if (choose[0] == 'g')choose[0] = 'G';
			if (choose[0] == 'h')choose[0] = 'H';
			if (choose[0] == 'i')choose[0] = 'I';
		}
	}
	gotoxy(hout, 0, i + 3);
	cout << "����Ϊ" << choose[0] << "��" << choose[1] << "��" << endl;
}

void case_1()/*�ڲ����飬������ɳ�ʼ5����*/
{
	int line, col;
	int color[3];
	int ball[9][9] = { 0 };

	data_input(line, col, 1);
	ball_produce(ball, 5, col, line, color, 0);
	cout << endl << "��ʼ���飺" << endl;
	ball_print(ball, col, line);

	cout << "�������������س�������";
	char ch;
	do
	{
		ch = _getch();
	} while (ch != 13);
}

void case_2()
{
	int line, col;
	char start[3];
	char end[3];
	int ball[9][9] = { 0 };
	int color[3];
	int ball_num = 5;
	int tell;

	data_input(line, col, 2);
	ball_produce(ball, 5, col, line, color, 0);

	do
	{
		chose_color(color);
		ball_produce(ball, 3, col, line, color, 1);
		ball_num += 3;
	} while (ball_num <= (int)col*line*0.6);

	chose_color(color);

	cout << endl << "��ʼ���飺" << endl;
	ball_print(ball, col, line);

	cout << endl << "��3���������ɫ�ֱ��ǣ�";
	for (int i = 0; i < 3; i++)
	{
		cout << color[i] << "  ";
	}

	case_input_checkstart(line, col, start, ball, 18);//�����ʼ����
	case_input_checkend(line, col, end, ball, 20);//���Ŀ������

	tell = search_way(ball, start, end, col, line, 0, 0);

	if (tell == 0)cout << "�޷��ҵ��ƶ�·��" << endl;
	else
	{
		cout << "�ҵ��ƶ�·��";
		Sleep(500);
		system("cls");
		path_print(ball, col, line, start);
	}

	cout << "�������������س�������";
	char ch;
	do
	{
		ch = _getch();
	} while (ch != 13);
}

void case_3()
{
	int line, col;
	char start[3];
	char end[3];
	int ball[9][9] = { 0 };
	int color[3];
	int ball_num = 5;
	int tell;
	int score = 0, total = 0;
	int distance = 18;
	int num = 0;

	data_input(line, col, 3);
	ball_produce(ball, 5, col, line, color, 0);
	cout << endl << "��ʼ���飺" << endl;
	ball_print(ball, col, line);

	do
	{
		chose_color(color);
		cout << endl << "��3���������ɫ�ֱ��ǣ�";
		for (int i = 0; i < 3; i++)
		{
			cout << color[i] << "  ";
		}

		case_input_checkstart(line, col, start, ball, distance);//�����ʼ����
		case_input_checkend(line, col, end, ball, distance + 3);//���Ŀ������

		tell = search_way(ball, start, end, col, line, 0, 0);
		if (tell == 0)
		{
			cout << "�޷��ҵ��ƶ�·��,";
			for (int i = 0; i < line; i++)
			{
				for (int j = 0; j < col; j++)
				{
					if (ball[i][j] == -1)ball[i][j] = 0;
				}
			}
			cout << "��ǰ����:" << endl;
			ball_print(ball, col, line);
			distance += 22;
		}
		else
		{
			cout << "�ҵ��ƶ�·��" << endl;
			distance += 41;
			for (int i = 0; i < line; i++)
			{
				for (int j = 0; j < col; j++)
				{
					if (ball[i][j] <= -1)ball[i][j] = 0;
				}
			}

			ball[int(end[0]) - 65][int(end[1]) - 49] = ball[int(start[0]) - 65][int(start[1]) - 49];
			ball[int(start[0]) - 65][int(start[1]) - 49] = 0;

			num = score_check(ball, line, col);
			if (num >= 5)score = num*(num - 3);
			else score = 0;
			total += score;

			cout << endl;
			cout << "�ƶ��������(��ͬɫ��ʶ)��" << endl;
			ball_print(ball, col, line);
			cout << endl;
			cout << "���ε÷֣�" << score << "�ܵ÷֣�" << total << endl << endl;

			if (score == 0)
			{
				ball_produce(ball, 3, col, line, color, 1);
				ball_num += 3;
			}
			else ball_num -= num;
			cout << "��ǰ����:" << endl;
			ball_print(ball, col, line);
			cout << endl;
		}
	} while (ball_num <= col*line&&ball_num > 0);
	cout << "�������������س�������";
	char ch;
	do
	{
		ch = _getch();
	} while (ch != 13);
}