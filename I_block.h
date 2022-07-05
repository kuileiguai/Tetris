#pragma once
#include <iostream>
#include <Windows.h>
#include "block.h"
using namespace std;

class I_Block : public Block {
public:
	int attitude;//姿态*2
	int other_x1;
	int other_x2;
	int other_x3;
	int other_y1;
	int other_y2;
	int other_y3;

	//打印方块
	virtual void Draw();

	//抽象一个生成方块类
	virtual void create_block();

	//抽象一个删除方块类
	virtual void delete_block();

	//抽象一个顺时针旋转
	virtual void Clockwise();

	//抽象一个逆时针旋转
	virtual void anti_clockwise();

	I_Block(int x, int y, int att);

	//添加入地图
	virtual void add_map(vector<vector<int>> &arr);

	//边界判断
	virtual bool Boundary_judgment(vector<vector<int>> &arr);

	//移动边界判断
	virtual bool Move_judgment(vector<vector<int>> &arr, int state);
};