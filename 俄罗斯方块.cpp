/*
0 = 黑色 8 = 灰色
1 = 蓝色 9 = 淡蓝色
2 = 绿色 A = 淡绿色
3 = 浅绿色 B = 淡浅绿色
4 = 红色 C = 淡红色
5 = 紫色 D = 淡紫色
6= 黄色 E = 淡黄色
7 = 白色 F = 亮白色
*/
#include <iostream>
#include <string>
#include <windows.h>
#include <vector>
#include <stdlib.h>
#include <ctime>
#include <random>
#include <conio.h>
#include "drawing_part.h"
#include "L_block.h"
#include "LL_block.h"
#include "square.h"
#include "high_block.h"
#include "low_block.h"
#include "I_block.h"
#include "T_block.h"
using namespace std;

vector<vector<int>> map(36);

void color(WORD c) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void Draw_Backdrop(int x,int y) {

}

void Clear_Map(vector<vector<int>> &arr) {
	bool temp;

	for (int i = 4; i < 35; i++) {
		temp = true;
		for (int j = 2; j < 38; j += 2) {
			if (arr[i][j] == 0) 
			{
				temp = false;
			}
		}
		
		if (temp == true) {
			

			for (int x = i; x > 3; x--) {
				for (int y = 2; y < 38; y+=2) {
					arr[x][y] = arr[x - 1][y];
				}
			}
			for (int p = 0; p < 40; p++) {
				arr[0][p] = 0;
			}
		}
	}
}

void GameStart() {
	srand(time(nullptr));
	system("mode con cols=68 lines=36");
	color(0x0E);
	Draw_Backdrop();
	color(0x07);
	int y_y;
	int x_x;
	int temp;
	temp = (rand() % (3 - 1 + 1)) + 1;
	Block * BB = NULL;

	bool runing = true;

	while (runing) {
		y_y = 2;
		x_x = 18;		
		switch (temp)
		{
		case 1:
			BB  = new L_Block(x_x, y_y, 1);
			BB->create_block();
			BB->b_c = (WORD)0x01;
			break;
		case 2:
			 BB = new LL_Block(x_x, y_y, 1);
			 BB->create_block();
			 BB->b_c = (WORD)0x02;
			break;
		case 3:
			BB = new Square(x_x, y_y);
			BB->create_block();
			BB->b_c = (WORD)0x06;
			break;
		case 4:
			BB = new High_Block(x_x, y_y, 1);
			BB->create_block();
			BB->b_c = (WORD)0x0D;
			break;
		case 5:
			BB = new Low_Block(x_x, y_y, 1);
			BB->create_block();
			BB->b_c = (WORD)0x03;
			break;
		case 6:
			BB = new I_Block(x_x, y_y, 1);
			BB->create_block();
			BB->b_c = (WORD)0x04;
			break;
		case 7:
			BB = new T_Block(x_x, y_y, 1);
			BB->create_block();
			BB->b_c = (WORD)0x0F;
			break;
		default:
			break;
		}
		
		temp = (rand() % (7 - 1 + 1)) + 1;

		for (int i = 6; i < 11;i++) {
			Gotoxy(49, i);
			cout << "          ";
		}

		switch (temp)
		{ 
		case 1:
			color(0x01);
			Gotoxy(51, 7);
			cout << "■";
			Gotoxy(51, 8);
			cout << "■■■";
			break;
		case 2:
			color(0x02);
			Gotoxy(55, 7);
			cout << "■";
			Gotoxy(51, 8);
			cout << "■■■";
			break;
		case 3:
			color(0x06);
			Gotoxy(52, 7);
			cout << "■■";
			Gotoxy(52, 8);
			cout << "■■";
			break;
		case 4:
			color(0x0D);
			Gotoxy(54, 7);
			cout << "■";
			Gotoxy(52, 8);
			cout << "■■";
			Gotoxy(52, 9);
			cout << "■";
			break;
		case 5:
			color(0x03);
			Gotoxy(52, 7);
			cout << "■";
			Gotoxy(52, 8);
			cout << "■■";
			Gotoxy(54, 9);
			cout << "■";
			break;
		case 6:
			color(0x04);
			Gotoxy(50, 8);
			cout << "■■■■";
			break;
		case 7:
			color(0x0F);
			Gotoxy(53, 7);
			cout << "■";
			Gotoxy(51, 8);
			cout << "■■■";
			break;
		default:
			break;
		}

		while (true) {
			color(BB->b_c);
			if (_kbhit()) {
				char ch = _getch();
				switch (ch)
				{
				case 75://左
				{
					if (BB->Move_judgment(map, 1)) 
					{
						BB->delete_block();
						BB->b_x -= 2;
						BB->create_block();
					}
					if (BB->b_y + 1 == 35) {
						BB->delete_block();
						BB->add_map(map);
					}
				}
				break;
				case 77://右
				{
					if (BB->Move_judgment(map, 2)) {
						BB->delete_block();
						BB->b_x += 2;
						BB->create_block();
					}
					if (BB->b_y + 1 == 35) {
						BB->delete_block();
						BB->add_map(map);
					}
				}
				break;
				case 97://a
					if (BB->Move_judgment(map, 3)) 
					{
						BB->anti_clockwise();
						BB->delete_block();
						BB->create_block();
						BB->Draw();
					}
					break;
				case 100://d
					if (BB->Move_judgment(map, 4))
					{
						BB->Clockwise();
						BB->delete_block();
						BB->create_block();
						BB->Draw();
					}
					break;
				default:
					break;
				}

			}

			else {
				if (BB->b_y + 1 == 35||BB->Boundary_judgment(map) == true) {				
					BB->delete_block();
					BB->add_map(map);
					for (int i = 0; i < 4; i++) {
						for (int j = 2; j < 38; j += 2) {
							if (map[i][j] == 1) {
								runing = false;
								break;
							}
						}
					}
					break;
				}
				else {
					BB->delete_block();
					BB->b_y++;
					BB->create_block();
					BB->Draw();					
				}

				Sleep(100);
			}


		}

		Clear_Map(map);
		delete BB;
		BB = NULL;		
		//触碰边界跳出循环，将当前方块置为红色并打印在地图上
		for (int i = 4; i < 35; i++) {
			for (int j = 2; j < 38; j+=2) {
				if (map[i][j] == 1) {
					Gotoxy(j, i);
					color(0x08);
					cout << "■";
				}
				else {
					Gotoxy(j, i);
					cout << "  ";
				}
				
			}

		}
		color(0x07);
	
		
	}

	system("cls");
}

int main()
{
 	for (int i = 0; i < 36; i++) {
			map[i].resize(40);
	}

	for (int i = 0; i < 36; i++) {
		map[i][0] = 1;
		map[i][1] = 1;
		map[i][38] = 1;
		map[i][39] = 1;
		if (i == 35) {
			for (int j = 2; j < 38; j++) {
				map[i][j] = 1;
			}
		}
	}

	GameStart();
	system("pause");
	return 0;
}

