#include "low_block.h"

//��ӡ����
void Low_Block::Draw() {
	if (this->b_y > 3) {
		Gotoxy(this->b_x, this->b_y);
		cout << "��";
	}
	if (this->other_y1 > 3) {
		Gotoxy(this->other_x1, this->other_y1);
		cout << "��";
	}
	if (this->other_y2 > 3) {
		Gotoxy(this->other_x2, this->other_y2);
		cout << "��";
	}
	if (this->other_y3 > 3) {
		Gotoxy(this->other_x3, this->other_y3);
		cout << "��";
	}
}

//����һ�����ɷ�����
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

//����һ��ɾ��������
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

//����һ��˳ʱ����ת
void Low_Block::Clockwise() {
	if (this->attitude == 2) {
		this->attitude = 1;
	}
	else {
		this->attitude = 2;
	}
}

//����һ����ʱ����ת
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

//������ͼ
void Low_Block::add_map(vector<vector<int>> &arr) {
	arr[this->b_y][this->b_x] = 1;
	arr[this->other_y1][this->other_x1] = 1;
	arr[this->other_y2][this->other_x2] = 1;
	arr[this->other_y3][this->other_x3] = 1;
}

//�߽��ж�
bool Low_Block::Boundary_judgment(vector<vector<int>> &arr) {
	if ((arr[this->b_y + 1][this->b_x] == 0) && (arr[this->other_y1 + 1][this->other_x1] == 0) && (arr[this->other_y2 + 1][this->other_x2] == 0) && (arr[this->other_y3 + 1][this->other_x3] == 0))
	{
		//δ���߽�
		return false;
	}
	else
	{
		//�ѵ��߽�
		return true;
	}
}

//�ƶ��߽��ж�
bool Low_Block::Move_judgment(vector<vector<int>> &arr, int state) {
	switch (state) {
	case 1://����
		if ((arr[this->b_y][this->b_x - 2] == 0) && (arr[this->other_y1][this->other_x1 - 2] == 0) && (arr[this->other_y2][this->other_x2 - 2] == 0) && (arr[this->other_y3][this->other_x3 - 2] == 0))
		{
			return true;
		}
		else
		{
			return false;
		}
		break;
	case 2://����
		if ((arr[this->b_y][this->b_x + 2] == 0) && (arr[this->other_y1][this->other_x1 + 2] == 0) && (arr[this->other_y2][this->other_x2 + 2] == 0) && (arr[this->other_y3][this->other_x3 + 2] == 0))
		{
			return true;
		}
		else
		{
			return false;
		}
		break;
	case 3://��ʱ����ת
		if (this->attitude == 1) {//��2
			if ((arr[this->b_y][this->b_x - 2] == 0) && (arr[this->b_y - 1][this->b_x] == 0) && (arr[this->b_y - 1][this->b_x + 2] == 0)) {
				return true;
			}
			else {
				return false;
			}
		}
		else if (this->attitude == 2) {//��1
			if ((arr[this->b_y - 1][this->b_x] == 0) && (arr[this->b_y][this->b_x + 2] == 0) && (arr[this->b_y + 1][this->b_x + 2] == 0)) {
				return true;
			}
			else {
				return false;
			}
		}


	case 4://˳ʱ����ת
		if (this->attitude == 1) {//��2
			if ((arr[this->b_y][this->b_x - 2] == 0) && (arr[this->b_y - 1][this->b_x] == 0) && (arr[this->b_y - 1][this->b_x + 2] == 0)) {
				return true;
			}
			else {
				return false;
			}
		}
		else if (this->attitude == 2) {//��1
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