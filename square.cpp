#include "square.h"

//��ӡ����
void Square::Draw() {
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

//���ɷ���
void Square::create_block() {
	this->other_x1 = this->b_x;
	this->other_y1 = this->b_y - 1;

	this->other_x2 = this->b_x + 2;
	this->other_y2 = this->b_y;

	this->other_x3 = this->b_x + 2;;
	this->other_y3 = this->b_y - 1;
}

//ɾ������
void Square::delete_block() {
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


//˳ʱ����ת
void Square::Clockwise() {

}

//��ʱ����ת
void Square::anti_clockwise() {

}

Square::Square(int x, int y) {
	this->b_x = x;
	this->b_y = y;
}


//������ͼ
void Square::add_map(vector<vector<int>> &arr){
	arr[this->b_y][this->b_x] = 1;
	arr[this->other_y1][this->other_x1] = 1;
	arr[this->other_y2][this->other_x2] = 1;
	arr[this->other_y3][this->other_x3] = 1;
}

//�߽��ж�
bool Square::Boundary_judgment(vector<vector<int>> &arr){
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
bool Square::Move_judgment(vector<vector<int>> &arr, int state){
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
	default:
		return false;
		break;
	}
}