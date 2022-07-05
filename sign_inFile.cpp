#include "sign_inFile.h"

int Sign_inFile::checkFile(string p_name,string p_password) {
	ifstream ifs;
	ifs.open(PLAYER_FILE, ios::in);

	this->m_size = 0;
	string name;
	string password;
	while (ifs >> name && ifs >> password) {
		if (p_name == name && p_password == password) {
			return 1;
		}
		else if (p_name == name && p_password != password) {
			return 2;
		}
		else if (p_name != name) {
			return 3;
		}
	}
}

void Sign_inFile::updateFile() {

}