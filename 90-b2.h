/*º∆À„ª˙2∞‡ —Ó”Ó∫Ω 1652289*/
#include <iostream>
#include "cmd_console_tools.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>  
#include <string>  
#include <iomanip>
#include <conio.h>
using namespace std;

void case_1();
void case_2();
void case_3();
void case_4();
void case_5();
void case_6();
void case_7();

void data_input(int &line, int &col, int index);
void ball_produce(int(*ball)[9], int num, int col, int line, int *color, int flag);
int search_way(int(*ball)[9], char *start, char *end, int col, int line, int direct, int i);
void ball_print(int(*ball)[9], int col, int line);
void depth_search(int(*ball)[9], int col, int line, int i, int j, int x, int y, int &depth, int color);
void find_related_ball(int &num, int(*ball)[9], int i, int j, int color, int line, int col);
int score_check(int(*ball)[9], int line, int col);
void chose_color(int *color);