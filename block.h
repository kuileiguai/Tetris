#pragma once
#include <iostream>
#include <Windows.h>
#include <list>
#include <vector>
#include "cursor.h"
using namespace std;

class Block {

public:
	WORD b_c;
	int b_x;
	int b_y;
	int attitude;
	
	//抽象一个生成方块方法
	virtual void create_block() = 0;

	//抽象一个删除方块方法
	virtual void delete_block() = 0;

	//抽象一个顺时针旋转
	virtual void Clockwise() = 0;

	//抽象一个逆时针旋转
	virtual void anti_clockwise() = 0;

	//加入地图
	virtual void add_map(vector<vector<int>> &arr) = 0;

	//绘制
	virtual void Draw() = 0;

	//边界触碰判断
	virtual bool Boundary_judgment(vector<vector<int>> &arr) = 0;

	//移动边界判断
	virtual bool Move_judgment(vector<vector<int>> &arr,int state) = 0;
};