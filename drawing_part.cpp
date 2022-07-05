#include "drawing_part.h"
#include "sign_inFile.h"

void directions();

void Draw_Backdrop() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 20; j++) {
			cout << "■";
		}
		cout << endl;
	}
	for (int i = 4; i < 35; i++) {
		cout << "■";
		for (int i = 0; i < 18; i++) {
			cout << "  ";
		}
		cout << "■"<<endl;
	}
	for (int i = 0; i < 20; i++) {
		cout << "■";
	}

	Gotoxy(47, 5);
	for (int i = 0; i < 7; i++) {
		cout << "■";
	}
	int temp = 6;
	for (int i = 0; i < 5; i++) {
		Gotoxy(47, temp++);
		cout << "■          ■";
	}
	Gotoxy(47, temp++);
	for (int i = 0; i < 7; i++) {
		cout << "■";
	}	
	directions();
}

void Draw_Welcome() {
	for (int i = 0; i < 10; i++) {
		cout << endl;
	}

	cout << "\t\t";
	for (int i = 0; i < 18; i++) {
		cout << "■";
	}
	cout << endl;
	cout << "\t\t■\t\t\t\t  ■" << endl;
	cout << "\t\t■\t 欢迎来到俄罗斯方块\t  ■" << endl;
	cout << "\t\t■\t\t\t\t  ■" << endl;
	cout << "\t\t";
	for (int i = 0; i < 18; i++) {
		cout << "■";
	}

	for (int i = 0; i < 6; i++) {
		cout << endl;
	}

	for (int i = 0; i < 24; i++) {
		cout << " ";
	}

	system("pause");
	system("cls");
	Draw_Admin();
}

void Draw_Admin() {
	while (true) {

		for (int i = 0; i < 9; i++) {
			cout << endl;
		}
		cout << "\t\t\t\t";
		cout << "  \t      登录界面"<<endl;
		cout << endl;

	//用户名： 密码：（若文件中存在则说明用户已注册，否则用户未注册并帮助用户注册）

	#pragma region 用户名绘制
		cout << "\t\t\t\t\t    ┍";
		for (int i = 0; i < 18; i++) {
			cout << "─";
		}
		cout << "┑" << endl;
		cout << "\t\t\t\t     用户名:│";
		for (int i = 0; i < 18; i++) {
			cout << " ";
		}
		cout << "┃" << endl;
		cout << "\t\t\t\t\t    ┕";
		for (int i = 0; i < 18; i++) {
			cout << "━";
		}
		cout << "┙" << endl;
	#pragma endregion

	#pragma region 密码绘制
			cout << "\t\t\t\t\t    ┍";
			for (int i = 0; i < 18; i++) {
				cout << "─";
			}
			cout << "┑" << endl;
			cout << "\t\t\t\t       密码:│";
			for (int i = 0; i < 18; i++) {
				cout << " ";
			}
			cout << "┃" << endl;
			cout << "\t\t\t\t\t    ┕";
			for (int i = 0; i < 18; i++) {
				cout << "━";
			}
			cout << "┙" << endl;
	#pragma endregion
	
	string admin_name;
	string password;
	Sign_inFile si;
		//移动光标输入各值
		
		Gotoxy(46, 12);
		cin >> admin_name;

		Gotoxy(46, 15);
		cin >> password;

		int judge = si.checkFile(admin_name, password);

		for (int i = 0; i < 6; i++) {
			cout << endl;
		}
		for (int i = 0; i < 40; i++) {
			cout << " ";
		}

		if (judge == 1) {
			for (int i = 0; i < 40; i++) {
				cout << " ";
			}
			cout << "登录成功" << endl;

			break;
		}
		else if (judge == 2) {
			for (int i = 0; i < 40; i++) {
				cout << " ";
			}
			cout << "密码错误" << endl;
			break;
		}
		else if (judge == 3) {
			cout << "用户名不存在" << endl;
			for (int i = 0; i < 40; i++) {
				cout << " ";
			}
			cout << "是否决定注册账号？  1-是  2-否" << endl;
			int temp;
			cin >> temp;
			if (temp == 1) {
				//注册界面
			}
			else if (temp == 2) {
				//退出
			}
			break;
		}
		else {
			cout << "用户名或密码错误，请重新输入" << endl;
			for (int i = 0; i < 43; i++) {
				cout << " ";
			}
			system("pause");
		}
		
		system("pause");
		system("cls");
	}
	system("pause");
	system("cls");


}

void directions() {
	Gotoxy(46, 15);
	cout << "用←控制方块左移";
	Gotoxy(46, 17);
	cout << "用→控制方块右移";
	Gotoxy(46, 19);
	cout << "a:逆时针旋转";
	Gotoxy(46, 21);
	cout << "d:顺时针旋转";
	Gotoxy(46, 23);
	cout << "Space:暂停游戏";
}