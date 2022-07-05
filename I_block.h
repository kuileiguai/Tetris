#pragma once
#include <iostream>
#include <Windows.h>
#include "block.h"
using namespace std;

class I_Block : public Block {
public:
	int attitude;//��̬*2
	int other_x1;
	int other_x2;
	int other_x3;
	int other_y1;
	int other_y2;
	int other_y3;

	//��ӡ����
	virtual void Draw();

	//����һ�����ɷ�����
	virtual void create_block();

	//����һ��ɾ��������
	virtual void delete_block();

	//����һ��˳ʱ����ת
	virtual void Clockwise();

	//����һ����ʱ����ת
	virtual void anti_clockwise();

	I_Block(int x, int y, int att);

	//������ͼ
	virtual void add_map(vector<vector<int>> &arr);

	//�߽��ж�
	virtual bool Boundary_judgment(vector<vector<int>> &arr);

	//�ƶ��߽��ж�
	virtual bool Move_judgment(vector<vector<int>> &arr, int state);
};