/*�����2�� ��� 1652289*/
#include "90-b2.h"

void cmd_draw(int(*ball)[9], int line, int col, int index)
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	if (index == 4)
	{
		showstr(hout, 0, 1, "�X", 15, 0);
		for (int i = 0; i < 2 * col; i += 2)showstr(hout, i + 2, 1, "�T", 15, 0);
		showstr(hout, 2 * col + 2, 1, "�[", 15, 0);
		for (int j = 0; j < line; j++)
		{
			showstr(hout, 0, 2 + j, "�U", 15, 0);
			showstr(hout, 2 + col * 2, 2 + j, "�U", 15, 0);
		}
		showstr(hout, 0, 2 + line, "�^", 15, 0);
		for (int k = 0; k < 2 * col; k += 2)showstr(hout, k + 2, 2 + line, "�T", 15, 0);
		showstr(hout, 2 * col + 2, 2 + line, "�a", 15, 0);
		for (int i = 0; i < line; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (ball[i][j] == 0)showstr(hout, 2 * j + 2, i + 2, "  ", 15, 0);
				else showstr(hout, 2 * j + 2, i + 2, "��", ball[i][j], 15);
			}
		}
		showstr(hout, 0, 0, "��Ļ��15��35��");
	}
	if (index == 5 || index == 6 || index == 7)
	{
		for (int i = 0; i <= line; i++)
		{
			if (i == 0)showstr(hout, 0, 1, "�X", 15, 0);
			else if (i == line)
			{
				showstr(hout, 0, 2 * line, "�U", 15, 0);
				showstr(hout, 0, 2 * line + 1, "�^", 15, 0);
			}
			else
			{
				showstr(hout, 0, 2 * i, "�U", 15, 0);
				showstr(hout, 0, 2 * i + 1, "�c", 15, 0);
			}
			for (int j = 0; j < 4 * col; j += 4)
			{
				if (i == 0)showstr(hout, j + 2, 1, "�T�h", 15, 0);
				else if (i == line)
				{
					showstr(hout, j + 2, 2 * line, "��", 15, 15);
					showstr(hout, j + 4, 2 * line, "��", 15, 0);
					showstr(hout, j + 2, 2 * line + 1, "�T�k", 15, 0);
				}
				else
				{
					showstr(hout, j + 2, 2 * i, "��", 15, 15);
					showstr(hout, j + 4, 2 * i, "��", 15, 0);
					showstr(hout, j + 2, 2 * i + 1, "����", 15, 0);
				}
			}
			if (i == 0)showstr(hout, 4 * col - 2, 1, "�T�[", 15, 0);
			else if (i == line)
			{
				showstr(hout, 4 * col - 2, 2 * line, "��", 15, 15);
				showstr(hout, 4 * col, 2 * line, "�U", 15, 0);
				showstr(hout, 4 * col - 2, 2 * line + 1, "�T�a", 15, 0);
			}
			else
			{
				showstr(hout, 4 * col - 2, 2 * i, "��", 15, 15);
				showstr(hout, 4 * col, 2 * i, "�U", 15, 0);
				showstr(hout, 4 * col - 2, 2 * i + 1, "���f", 15, 0);
			}
		}

		for (int i = 0; i < line; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (ball[i][j] != 0)showstr(hout, 2 + j * 4, 2 + i * 2, "��", ball[i][j], 15);
			}
		}
		if(index!=7)showstr(hout, 0, 0, "��Ļ��23��39��");
		else showstr(hout, 0, 0, "��Ļ��23��71��");
	}
}

void case_7_draw(int total, int *color, int(*ball)[9], int line, int col,int *del)
{
	int ball_color[8] = { 0 };
	
	for (int k = 0; k < line; k++)
	{
		for (int l = 0; l < col; l++)
		{
			switch (ball[k][l])
			{
			case 0:ball_color[0]++; break;
			case 1:ball_color[1]++; break;
			case 2:ball_color[2]++; break;
			case 3:ball_color[3]++; break;
			case 4:ball_color[4]++; break;
			case 5:ball_color[5]++; break;
			case 6:ball_color[6]++; break;
			case 7:ball_color[7]++; break;
			}
		}
	}

	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	showstr(hout, 45, 1, "�X�T�T�T�T�T�[", 15, 0);
	showstr(hout, 45, 2, "�U�÷֣�", 15, 0);
	cout << setw(4) << total;
	showstr(hout, 57, 2, "�U", 15, 0);
	showstr(hout, 45, 3, "�^�T�T�T�T�T�a", 15, 0);

	showstr(hout, 45, 5, "�X�T�T�T�T�T�[", 15, 0);
	showstr(hout, 45, 6, "�U�����������U", 15, 0);
	showstr(hout, 47, 6, "��", color[0], 15);
	showstr(hout, 51, 6, "��", color[1], 15);
	showstr(hout, 55, 6, "��", color[2], 15);
	showstr(hout, 45, 7, "�^�T�T�T�T�T�a", 15, 0);

	showstr(hout, 45, 9, "�X�T�T�T�T�T�T�T�T�T�T�T�[", 15, 0);
	showstr(hout, 45, 18, "�^�T�T�T�T�T�T�T�T�T�T�T�a", 15, 0);

	for (int j = 0; j < 8; j++)
	{
		showstr(hout, 45, 10 + j, "�U", 15, 0);
		if (j != 0)showstr(hout, 47, 10 + j, "��", j, 15);
		else showstr(hout, 47, 10 + j, "��", 15, 15);
		setcolor(hout,15 , 0);
		cout << setw(2) << ball_color[j] << "/(" << float(ball_color[j] / col / line) << ") del-   " << setw(6) << del[j];
		showstr(hout, 69, 10 + j, "�U", 15, 0);
	}

}

void ball_up(int j, int i, int color)
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	showstr(hout, -2 + i * 4, j * 2, "��", 15, 15);
	showstr(hout, -2 + i * 4, j * 2 - 1, "��", color, 15);
	Sleep(300);
	showstr(hout, -2 + i * 4, j * 2 - 1, "��", 15, 0);
	showstr(hout, -2 + i * 4, j * 2 - 2, "��", color, 15);
	Sleep(300);
}

void ball_down(int j, int i, int color)
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	showstr(hout, -2 + i * 4, j * 2, "��", 15, 15);
	showstr(hout, -2 + i * 4, j * 2 + 1, "��", color, 15);
	Sleep(300);
	showstr(hout, -2 + i * 4, j * 2 + 1, "��", 15, 0);
	showstr(hout, -2 + i * 4, j * 2 + 2, "��", color, 15);
	Sleep(300);
}

void ball_right(int j, int i, int color)
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	showstr(hout, -2 + i * 4, j * 2, "��", 15, 15);
	showstr(hout, i * 4, j * 2, "��", color, 15);
	Sleep(300);
	showstr(hout, i * 4, j * 2, "��", 15, 0);
	showstr(hout, 2 + i * 4, j * 2, "��", color, 15);
	Sleep(300);
}

void ball_left(int j, int i, int color)
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	showstr(hout, -2 + i * 4, j * 2, "��", 15, 15);
	showstr(hout, i * 4 - 4, j * 2, "��", color, 15);
	Sleep(300);
	showstr(hout, i * 4 - 4, j * 2, "��", 15, 0);;
	showstr(hout, i * 4 - 6, j * 2, "��", color, 15);
	Sleep(300);
}

void Move(char *start, char *end, int(*ball)[9], int color, int direction, int line, int col)//��1��2��3��4��ʼ0(���ݷ���)
{
	if (strcmp(start, end) == 0)return;

	else
	{
		if (start[1] < '0' + col &&ball[int(start[0]) - 65][int(start[1]) - 49 + 1] == -4)
		{
			ball_right(int(start[0]) - 64, int(start[1]) - 48, color);
			start[1]++;
			Move(start, end, ball, color, 3, line, col);
			start[1]--;
			return;
		}
		if (start[0] < 'A' + line - 1 && ball[int(start[0]) - 65 + 1][int(start[1]) - 49] == -2)
		{
			ball_down(int(start[0]) - 64, int(start[1]) - 48, color);
			start[0]++;
			Move(start, end, ball, color, 1, line, col);
			start[0]--;
			return;
		}
		if (start[1] > '1'&&ball[int(start[0]) - 65][int(start[1]) - 49 - 1] == -3)
		{
			ball_left(int(start[0]) - 64, int(start[1]) - 48, color);
			start[1]--;
			Move(start, end, ball, color, 4, line, col);
			start[1]++;
			return;
		}
		if (start[0] > 'A'&&ball[int(start[0]) - 65 - 1][int(start[1]) - 49] == -1)
		{
			ball_up(int(start[0]) - 64, int(start[1]) - 48, color);
			start[0]--;
			Move(start, end, ball, color, 2, line, col);
			start[0]++;
			return;
		}
	}
	return;
}

void case_4()
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	int line, col;
	int ball[9][9] = { 0 };
	int color[3];
	int ball_num = 5;
	char ch;
	wchar_t fontname[] = L"������";

	data_input(line, col, 4);
	ball_produce(ball, 5, col, line, color, 0);
	cout << endl << "��ʼ���飺" << endl;
	ball_print(ball, col, line);

	cout << endl << "���س�����ʾͼ��...";

	do
	{
		ch = _getch();
	} while (ch != 13);

	setconsoleborder(hout, 35, 15, 200);
	setfontsize(hout, fontname, 20);
	system("cls");
	cmd_draw(ball, line, col, 4);

	gotoxy(hout, 0, 13);
	cout << "�������������س�������";
	char ch2;
	do
	{
		ch2 = _getch();
	} while (ch != 13);
}

void case_5()
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	int line, col;
	int ball[9][9] = { 0 };
	int color[3];
	int ball_num = 5;
	char ch;
	wchar_t fontname[] = L"������";

	data_input(line, col, 5);
	ball_produce(ball, 5, col, line, color, 0);
	cout << endl << "��ʼ���飺" << endl;
	ball_print(ball, col, line);

	cout << endl << "���س�����ʾͼ��...";

	do
	{
		ch = _getch();
	} while (ch != 13);

	setconsoleborder(hout, 39, 23, 200);
	setfontsize(hout, fontname, 20);
	system("cls");
	cmd_draw(ball, line, col, 5);
	gotoxy(hout, 0, 21);
	cout << "�������������س�������";
	char ch2;
	do
	{
		ch2 = _getch();
	} while (ch != 13);
}

void case_6()
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE hin = GetStdHandle(STD_INPUT_HANDLE);
	int line, col;
	int ball[9][9] = { 0 };
	int color[3];
	int ball_num = 5;
	int action;
	int X, Y;
	int tell;
	int i, j;
	char start[3] = { 0 }, end[3] = { 0 };
	wchar_t fontname[] = L"������";

	data_input(line, col, 5);
	ball_produce(ball, int(col*line * 0.6), col, line, color, 0);

	setconsoleborder(hout, 39, 23);
	setfontsize(hout, fontname, 20);
	system("cls");
	cmd_draw(ball, line, col, 6);
	cout << "(�Ҽ��˳�)";

	enable_mouse(hin);
	setcursor(hout, 3);
	do
	{
		action = read_mouse(hin, X, Y, 1);
		if (X >= 2 && X <= 38 && Y >= 2 && Y <= 19)
		{
			i = (X + 2) / 4;
			j = Y / 2;
			gotoxy(hout, 0, 21);
			setcolor(hout, 0, 7);
			cout << "[��ǰ���]:" << char(64 + j) << "��" << i << "��";
			if (action == 1 && ball[j - 1][i - 1] != 0)
			{
				start[0] = char(64 + j);
				start[1] = char(48 + i);
				for (int k = 0; k < line; k++)
				{
					for (int l = 0; l < col; l++)
					{
						if (ball[k][l] != 0)
						{
							if ((k + 1) == j && (l + 1) == i)showstr(hout, -2 + i * 4, j * 2, "��", ball[j - 1][i - 1], 15);
							else showstr(hout, 2 + l * 4, 2 + k * 2, "��", ball[k][l], 15);
						}
					}
				}
			}
			if (action == 1 && ball[j - 1][i - 1] == 0)
			{

				end[0] = char(64 + j);
				end[1] = char(48 + i);

				tell = search_way(ball, start, end, col, line, 0, 0);

				if (tell == 1)Move(start, end, ball, ball[int(start[0]) - 65][int(start[1]) - 49], 0, line, col);
				else
				{
					gotoxy(hout, 0, 21);
					setcolor(hout, 0, 7);
					cout << "�����޷��ҵ�·��";
					end[0] = 0;
					end[1] = 0;
					for (int k = 0; k < line; k++)
					{
						for (int l = 0; l < col; l++)
						{
							if (ball[k][l] <= -1)ball[k][l] = 0;
						}
					}
				}
			}

			if (end[0] != 0 && start[0] != 0)break;
		}
	} while (action != 3);
	gotoxy(hout, 0, 22);
	setcolor(hout, 0, 7);
	cout << "�������������س�������";
	char ch;
	do
	{
		ch = _getch();
	} while (ch != 13);
}

void case_7()
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE hin = GetStdHandle(STD_INPUT_HANDLE);
	int line, col;
	int ball[9][9] = { 0 };
	int color[3];
	int ball_num = 5;
	int action;
	int X, Y;
	int i, j;
	int tell;
	char start[3] = { 0 }, end[3] = { 0 };
	wchar_t fontname[] = L"������";
	int score = 0, total = 0;
	int del[8] = { 0 };
	int num;

	data_input(line, col, 7);
	ball_produce(ball, 5, col, line, color, 0);

	setconsoleborder(hout, 71, 23);
	setfontsize(hout, fontname, 20);
	system("cls");
	cmd_draw(ball, line, col, 7);
	chose_color(color);
	case_7_draw(total, color, ball, line, col, del);

	enable_mouse(hin);
	setcursor(hout, 3);
	do
	{
		action = read_mouse(hin, X, Y, 1);
		if (X >= 2 && X <= 38 && Y >= 2 && Y <= 19)
		{
			i = (X + 2) / 4;
			j = Y / 2;
			gotoxy(hout, 0, 21);
			setcolor(hout, 0, 7);
			cout << "[��ǰ���]:" << char(64 + j) << "��" << i << "��";
			if (action == 1 && ball[j - 1][i - 1] != 0)
			{
				start[0] = char(64 + j);
				start[1] = char(48 + i);
				for (int k = 0; k < line; k++)
				{
					for (int l = 0; l < col; l++)
					{
						if (ball[k][l] != 0)
						{
							if ((k + 1) == j && (l + 1) == i)showstr(hout, -2 + i * 4, j * 2, "��", ball[j - 1][i - 1], 15);
							else showstr(hout, 2 + l * 4, 2 + k * 2, "��", ball[k][l], 15);
						}
					}
				}
			}
			if (action == 1 && ball[j - 1][i - 1] == 0)
			{
				end[0] = char(64 + j);
				end[1] = char(48 + i);

				if (start[0] != 0)
				{
					tell = search_way(ball, start, end, col, line, 0, 0);

					if (tell == 1)
					{
						Move(start, end, ball, ball[int(start[0]) - 65][int(start[1]) - 49], 0, line, col);
						ball[j - 1][i - 1] = ball[int(start[0]) - 65][int(start[1]) - 49];
						ball[int(start[0]) - 65][int(start[1]) - 49] = 0;
						for (int k = 0; k < line; k++)
						{
							for (int l = 0; l < col; l++)
							{
								if (ball[k][l] <= -1)ball[k][l] = 0;
							}
						}

						num = score_check(ball, line, col);
						if (num >= 5)score = num*(num - 3);
						else score = 0;
						total += score;

						if (score == 0)//ԭ����д�Ʒֺ���ʱû�п��ǵ�ͳ��������С������del������ʵû�취ͳ�ƣ�����ʱ�䲻�����ٸ��ˣ������������BUG
						{
							ball_produce(ball, 3, col, line, color, 1);
							ball_num += 3;
							chose_color(color);
						}
						else ball_num -= num;
						cmd_draw(ball, line, col, 7);
						case_7_draw(total, color, ball, line, col, del);
					}
					else
					{
						gotoxy(hout, 0, 21);
						setcolor(hout, 0, 7);
						cout << "�����޷��ҵ�·��";
						end[0] = 0;
						end[1] = 0;
						for (int k = 0; k < line; k++)
						{
							for (int l = 0; l < col; l++)
							{
								if (ball[k][l] <= -1)ball[k][l] = 0;
							}
						}
					}
				}

			}
		}
	} while (action != 3 || ball_num >= col*line || ball_num == 0);
	cout << "�������������س�������";
	char ch;
	do
	{
		ch = _getch();
	} while (ch != 13);
}