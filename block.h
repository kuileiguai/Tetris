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
	
	//����һ�����ɷ��鷽��
	virtual void create_block() = 0;

	//����һ��ɾ�����鷽��
	virtual void delete_block() = 0;

	//����һ��˳ʱ����ת
	virtual void Clockwise() = 0;

	//����һ����ʱ����ת
	virtual void anti_clockwise() = 0;

	//�����ͼ
	virtual void add_map(vector<vector<int>> &arr) = 0;

	//����
	virtual void Draw() = 0;

	//�߽紥���ж�
	virtual bool Boundary_judgment(vector<vector<int>> &arr) = 0;

	//�ƶ��߽��ж�
	virtual bool Move_judgment(vector<vector<int>> &arr,int state) = 0;
};