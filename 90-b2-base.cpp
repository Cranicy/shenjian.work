/*计算机2班 杨宇航 1652289*/
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

int score_check(int(*ball)[9],int line ,int col)//采用的统计相连小球的个数的规则，至少一个方向有五个，其余方向的若与之相连，则锦上添花,num*(num-3)
{
	int depth[4] = { 0 };
	int num = 0;

	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < col; j++)//0:向右搜索,1;右下,2:下,3:左下
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
	cout << "  ￤ ";
	for (int i = 0; i < col; i++)cout << " " << i + 1 << " ";
	cout << endl << "--+-";
	for (int i = 0; i < col; i++)cout << "---";
	cout << endl;

	for (int i = 0; i < line; i++)
	{
		cout << char(65 + i) << " ￤ ";

		for (int j = 0; j < col; j++)
		{
			if (i == int(start[0]) - 65 && j == int(start[1]) - 49)cout << " " << '*' << " ";
			else if (*(*(ball + i) + j) <= -1)cout << " " << '*' << " ";
			else cout << " " << '0' << " ";
		}

		cout << endl;
	}

	cout << endl << endl << "移动路径(不同色标识)：" << endl;
	cout << "  ￤ ";
	for (int i = 0; i < col; i++)cout << " " << i + 1 << " ";
	cout << endl << "--+-";
	for (int i = 0; i < col; i++)cout << "---";
	cout << endl;
	for (int i = 0; i < line; i++)
	{
		cout << char(65 + i) << " ￤ ";

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

void ball_print(int(*ball)[9], int col, int line)//打印宫格与小球
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "  ￤ ";
	for (int i = 0; i < col; i++)cout << " " << i + 1 << " ";
	cout << endl << "--+-";
	for (int i = 0; i < col; i++)cout << "---";
	cout << endl;
	for (int i = 0; i < line; i++)
	{
		cout << char(65 + i) << " ￤ ";

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

void chose_color(int *color)//选定下三个小球的颜色
{
	srand((unsigned int)time(0));

	for (int i = 0; i < 3; i++)
	{
		color[i] = rand() % 7 + 1;
		if (color[i] == 14)i--;
	}
}

void case_input_checkstart(int line, int col, char *choose, int(*ball)[9], int i)//检查选择初始小球的位置是否为空以及输入格式是否错误
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << endl << "请以字母+数字形式[例：c2]输入要移动球的矩阵坐标：";
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
			cout << "输入格式错误，重新输入";
			cout << endl << "请以字母+数字形式[例：c2]输入要移动球的矩阵坐标：";
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
			cout << "起始位置为空，请重新输入." << endl;
			cout << "请以字母+数字形式[例：c2]输入要移动球的矩阵坐标：";
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
	cout << "输入为" << choose[0] << "行" << choose[1] << "列";
}

void case_input_checkend(int line, int col, char *choose, int(*ball)[9],int i)//检查选择初始小球的位置是否为空以及输入格式是否错误
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << endl << "请以字母+数字形式[例：c2]输入要移动球的目的坐标：";
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
			cout << "输入格式错误，重新输入";
			cout << endl << "请以字母+数字形式[例：c2]输入要移动球的目的坐标：";
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
			cout << "目标位置非空，请重新输入." << endl;
			cout << "请以字母+数字形式[例：c2]输入要移动球的目的坐标：";
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
	cout << "输入为" << choose[0] << "行" << choose[1] << "列" << endl;
}

void case_1()/*内部数组，随机生成初始5个球*/
{
	int line, col;
	int color[3];
	int ball[9][9] = { 0 };

	data_input(line, col, 1);
	ball_produce(ball, 5, col, line, color, 0);
	cout << endl << "初始数组：" << endl;
	ball_print(ball, col, line);

	cout << "操作结束，按回车键返回";
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

	cout << endl << "初始数组：" << endl;
	ball_print(ball, col, line);

	cout << endl << "下3个彩球的颜色分别是：";
	for (int i = 0; i < 3; i++)
	{
		cout << color[i] << "  ";
	}

	case_input_checkstart(line, col, start, ball, 18);//检查起始输入
	case_input_checkend(line, col, end, ball, 20);//检查目的输入

	tell = search_way(ball, start, end, col, line, 0, 0);

	if (tell == 0)cout << "无法找到移动路径" << endl;
	else
	{
		cout << "找到移动路径";
		Sleep(500);
		system("cls");
		path_print(ball, col, line, start);
	}

	cout << "操作结束，按回车键返回";
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
	cout << endl << "初始数组：" << endl;
	ball_print(ball, col, line);

	do
	{
		chose_color(color);
		cout << endl << "下3个彩球的颜色分别是：";
		for (int i = 0; i < 3; i++)
		{
			cout << color[i] << "  ";
		}

		case_input_checkstart(line, col, start, ball, distance);//检查起始输入
		case_input_checkend(line, col, end, ball, distance + 3);//检查目的输入

		tell = search_way(ball, start, end, col, line, 0, 0);
		if (tell == 0)
		{
			cout << "无法找到移动路径,";
			for (int i = 0; i < line; i++)
			{
				for (int j = 0; j < col; j++)
				{
					if (ball[i][j] == -1)ball[i][j] = 0;
				}
			}
			cout << "当前数组:" << endl;
			ball_print(ball, col, line);
			distance += 22;
		}
		else
		{
			cout << "找到移动路径" << endl;
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
			cout << "移动后的数组(不同色标识)：" << endl;
			ball_print(ball, col, line);
			cout << endl;
			cout << "本次得分：" << score << "总得分：" << total << endl << endl;

			if (score == 0)
			{
				ball_produce(ball, 3, col, line, color, 1);
				ball_num += 3;
			}
			else ball_num -= num;
			cout << "当前数组:" << endl;
			ball_print(ball, col, line);
			cout << endl;
		}
	} while (ball_num <= col*line&&ball_num > 0);
	cout << "操作结束，按回车键返回";
	char ch;
	do
	{
		ch = _getch();
	} while (ch != 13);
}