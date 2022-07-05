#include "low_block.h"

//打印方块
void Low_Block::Draw() {
	if (this->b_y > 3) {
		Gotoxy(this->b_x, this->b_y);
		cout << "■";
	}
	if (this->other_y1 > 3) {
		Gotoxy(this->other_x1, this->other_y1);
		cout << "■";
	}
	if (this->other_y2 > 3) {
		Gotoxy(this->other_x2, this->other_y2);
		cout << "■";
	}
	if (this->other_y3 > 3) {
		Gotoxy(this->other_x3, this->other_y3);
		cout << "■";
	}
}

//抽象一个生成方块类
void Low_Block::create_block() {

	switch (this->attitude)
	{
	case 1:
	{
		this->other_x1 = this->b_x;
		this->other_y1 = this->b_y - 1;

		this->other_x2 = this->b_x + 2;
		this->other_y2 = this->b_y;

		this->other_x3 = this->b_x + 2;
		this->other_y3 = this->b_y + 1;

	}
	break;
	case 2:
	{
		this->other_x1 = this->b_x - 2;
		this->other_y1 = this->b_y;

		this->other_x2 = this->b_x;
		this->other_y2 = this->b_y - 1;

		this->other_x3 = this->b_x + 2;
		this->other_y3 = this->b_y - 1;
	}
	break;
	default:
		break;
	}

}

//抽象一个删除方块类
void Low_Block::delete_block() {
	if (this->b_y > 3) {
		Gotoxy(this->b_x, this->b_y);
		cout << "  ";
	}
	if (this->other_y1 > 3) {
		Gotoxy(this->other_x1, this->other_y1);
		cout << "  ";
	}
	if (this->other_y2 > 3) {
		Gotoxy(this->other_x2, this->other_y2);
		cout << "  ";
	}
	if (this->other_y3 > 3) {
		Gotoxy(this->other_x3, this->other_y3);
		cout << "  ";
	} 
}

//抽象一个顺时针旋转
void Low_Block::Clockwise() {
	if (this->attitude == 2) {
		this->attitude = 1;
	}
	else {
		this->attitude = 2;
	}
}

//抽象一个逆时针旋转
void Low_Block::anti_clockwise() {
	if (this->attitude == 2) {
		this->attitude = 1;
	}
	else {
		this->attitude = 2;
	}
}

Low_Block::Low_Block(int x, int y, int att) {
	this->b_x = x;
	this->b_y = y;
	this->attitude = att;
}

//添加入地图
void Low_Block::add_map(vector<vector<int>> &arr) {
	arr[this->b_y][this->b_x] = 1;
	arr[this->other_y1][this->other_x1] = 1;
	arr[this->other_y2][this->other_x2] = 1;
	arr[this->other_y3][this->other_x3] = 1;
}

//边界判断
bool Low_Block::Boundary_judgment(vector<vector<int>> &arr) {
	if ((arr[this->b_y + 1][this->b_x] == 0) && (arr[this->other_y1 + 1][this->other_x1] == 0) && (arr[this->other_y2 + 1][this->other_x2] == 0) && (arr[this->other_y3 + 1][this->other_x3] == 0))
	{
		//未到边界
		return false;
	}
	else
	{
		//已到边界
		return true;
	}
}

//移动边界判断
bool Low_Block::Move_judgment(vector<vector<int>> &arr, int state) {
	switch (state) {
	case 1://左移
		if ((arr[this->b_y][this->b_x - 2] == 0) && (arr[this->other_y1][this->other_x1 - 2] == 0) && (arr[this->other_y2][this->other_x2 - 2] == 0) && (arr[this->other_y3][this->other_x3 - 2] == 0))
		{
			return true;
		}
		else
		{
			return false;
		}
		break;
	case 2://右移
		if ((arr[this->b_y][this->b_x + 2] == 0) && (arr[this->other_y1][this->other_x1 + 2] == 0) && (arr[this->other_y2][this->other_x2 + 2] == 0) && (arr[this->other_y3][this->other_x3 + 2] == 0))
		{
			return true;
		}
		else
		{
			return false;
		}
		break;
	case 3://逆时针旋转
		if (this->attitude == 1) {//变2
			if ((arr[this->b_y][this->b_x - 2] == 0) && (arr[this->b_y - 1][this->b_x] == 0) && (arr[this->b_y - 1][this->b_x + 2] == 0)) {
				return true;
			}
			else {
				return false;
			}
		}
		else if (this->attitude == 2) {//变1
			if ((arr[this->b_y - 1][this->b_x] == 0) && (arr[this->b_y][this->b_x + 2] == 0) && (arr[this->b_y + 1][this->b_x + 2] == 0)) {
				return true;
			}
			else {
				return false;
			}
		}


	case 4://顺时针旋转
		if (this->attitude == 1) {//变2
			if ((arr[this->b_y][this->b_x - 2] == 0) && (arr[this->b_y - 1][this->b_x] == 0) && (arr[this->b_y - 1][this->b_x + 2] == 0)) {
				return true;
			}
			else {
				return false;
			}
		}
		else if (this->attitude == 2) {//变1
			if ((arr[this->b_y - 1][this->b_x] == 0) && (arr[this->b_y][this->b_x + 2] == 0) && (arr[this->b_y + 1][this->b_x + 2] == 0)) {
				return true;
			}
			else {
				return false;
			}
		}
	default:
		return false;
		break;
	}
}