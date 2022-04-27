// FCAI – Programming 1 – 2022 - Assignment 4
// Program Name: LoginSystem.cpp
// Last Modification Date: xx/xx/xxxx
// Author : Ziad Mohammed ibrahim, 20211044
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
void Register();
void Login();
void Change_Password();
int main() {

	while (true) {
		cout << "Welcome to my Login System simulator.\n";
		cout << "1-Register\n2-Login\n3-Change Password\n4-Exit";
		cout << "Enter your choice : ";
		int choice;
		cin >> choice;
		switch (choice) {
		case 1:
			Register();
			break;
		case 2:
			Login();
			break;
		case 3:
			Change_Password();
			break;
		case 4:
			return 0;
		}
	}

}


void Register() {

}
void Login() {

}
void Change_Password() {

}

