#include "drawing_part.h"
#include "sign_inFile.h"

void directions();

void Draw_Backdrop() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 20; j++) {
			cout << "��";
		}
		cout << endl;
	}
	for (int i = 4; i < 35; i++) {
		cout << "��";
		for (int i = 0; i < 18; i++) {
			cout << "  ";
		}
		cout << "��"<<endl;
	}
	for (int i = 0; i < 20; i++) {
		cout << "��";
	}

	Gotoxy(47, 5);
	for (int i = 0; i < 7; i++) {
		cout << "��";
	}
	int temp = 6;
	for (int i = 0; i < 5; i++) {
		Gotoxy(47, temp++);
		cout << "��          ��";
	}
	Gotoxy(47, temp++);
	for (int i = 0; i < 7; i++) {
		cout << "��";
	}	
	directions();
}

void Draw_Welcome() {
	for (int i = 0; i < 10; i++) {
		cout << endl;
	}

	cout << "\t\t";
	for (int i = 0; i < 18; i++) {
		cout << "��";
	}
	cout << endl;
	cout << "\t\t��\t\t\t\t  ��" << endl;
	cout << "\t\t��\t ��ӭ��������˹����\t  ��" << endl;
	cout << "\t\t��\t\t\t\t  ��" << endl;
	cout << "\t\t";
	for (int i = 0; i < 18; i++) {
		cout << "��";
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
		cout << "  \t      ��¼����"<<endl;
		cout << endl;

	//�û����� ���룺�����ļ��д�����˵���û���ע�ᣬ�����û�δע�Ტ�����û�ע�ᣩ

	#pragma region �û�������
		cout << "\t\t\t\t\t    ��";
		for (int i = 0; i < 18; i++) {
			cout << "��";
		}
		cout << "��" << endl;
		cout << "\t\t\t\t     �û���:��";
		for (int i = 0; i < 18; i++) {
			cout << " ";
		}
		cout << "��" << endl;
		cout << "\t\t\t\t\t    ��";
		for (int i = 0; i < 18; i++) {
			cout << "��";
		}
		cout << "��" << endl;
	#pragma endregion

	#pragma region �������
			cout << "\t\t\t\t\t    ��";
			for (int i = 0; i < 18; i++) {
				cout << "��";
			}
			cout << "��" << endl;
			cout << "\t\t\t\t       ����:��";
			for (int i = 0; i < 18; i++) {
				cout << " ";
			}
			cout << "��" << endl;
			cout << "\t\t\t\t\t    ��";
			for (int i = 0; i < 18; i++) {
				cout << "��";
			}
			cout << "��" << endl;
	#pragma endregion
	
	string admin_name;
	string password;
	Sign_inFile si;
		//�ƶ���������ֵ
		
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
			cout << "��¼�ɹ�" << endl;

			break;
		}
		else if (judge == 2) {
			for (int i = 0; i < 40; i++) {
				cout << " ";
			}
			cout << "�������" << endl;
			break;
		}
		else if (judge == 3) {
			cout << "�û���������" << endl;
			for (int i = 0; i < 40; i++) {
				cout << " ";
			}
			cout << "�Ƿ����ע���˺ţ�  1-��  2-��" << endl;
			int temp;
			cin >> temp;
			if (temp == 1) {
				//ע�����
			}
			else if (temp == 2) {
				//�˳�
			}
			break;
		}
		else {
			cout << "�û����������������������" << endl;
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
	cout << "�á����Ʒ�������";
	Gotoxy(46, 17);
	cout << "�á����Ʒ�������";
	Gotoxy(46, 19);
	cout << "a:��ʱ����ת";
	Gotoxy(46, 21);
	cout << "d:˳ʱ����ת";
	Gotoxy(46, 23);
	cout << "Space:��ͣ��Ϸ";
}