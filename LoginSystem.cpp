// FCAI – Programming 1 – 2022 - Assignment 4
// Program Name: LoginSystem.cpp
// Last Modification Date: xx/xx/xxxx
// Author : Ziad Mohammed ibrahim, 20211044
#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include<conio.h>

using namespace std;
void Register();
void Login();
void Change_Password();
string password();

string new_line = "--------------------------------------------------";

struct Information {
	string email, password, name;
};
map<string, Information> data_information;
int main() {
	
	while (true) {
		cout << "Welcome to my Login System simulator.\n";
		cout << "1-Register\n2-Login\n3-Change Password\n4-Exit\n";
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
	string ID,repeated_pass;
	Information student;
	cout << "Enter your ID: ";
	cin >> ID;
	data_information[ID] = student;
	cout << "\n" << new_line;
	cout << "\nYour name must be in this format\nonly alphabitic letters or underscore (_)\nEnter Your name: ";
	cin >> data_information[ID].name;
	cout << "\n" << new_line;
	cout << "\nYour email must be in this format\nalphabets or digit characters followed by @ and then the domain followed by (.com)\nEnter your email: ";
	cin >> data_information[ID].email;
	cout << new_line;
	cout << "Password must be in this format\nmust contain at least on alphabitic character and one digit and one symbol\nThe length must be at least 12 letters.\nEnter your password: ";
	data_information[ID].password = password();
	cout << "\nEnter your password again: ";
	repeated_pass = password();
	while (repeated_pass != data_information[ID].password) {
		cout << "\nThose passwords didn't match. Try again.\n";
		cout << "\nEnter your password again: ";
		repeated_pass = password();
		cout << endl;
	}
	 

}
string password() {
	string password{};
	int ch = _getch();
	while (ch != 13) {
		password.push_back(ch);
		cout << "*";
		ch = _getch();
	}
	return password;
}
void Login() {

}
void Change_Password() {

}

//todo 1: make function that checks an existing id if it has been found take another one from the user 
// todo 2 : make function that load all the information from the file to the map 
