// FCAI – Programming 1 – 2022 - Assignment 4
// Program Name: LoginSystem.cpp
// Last Modification Date: xx/xx/xxxx
// Author : Ziad Mohammed ibrahim, 20211044
#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include<conio.h>
#include <regex>
using namespace std;
void Register();
void Login();
void Change_Password();
void password(string& password);

string new_line = "--------------------------------------------------";

struct Information {
	string email, password, name, phone;
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
	cout << "\nPassword must be in this format\nmust contain at least on alphabitic character and one digit and one symbol\nThe length must be at least 12 letters.\nEnter your password: ";
	password(data_information[ID].password);
	cout << "\nEnter your password again: ";
	password(repeated_pass);
	cout <<"\n" << new_line;
	while (repeated_pass != data_information[ID].password) {
		cout << "\nThose passwords didn't match. Try again.\n";
		cout << "\nEnter your password again: ";
		password(repeated_pass);
		cout << endl;
	}
	cout << "\nPhono number must be in this format\n(010) or (011) or (012) or (015) followed by 8 digits\nEnter your phono number : ";
	cin >> data_information[ID].phone;
}
void password(string &password) {
	int ch{};
	while ((ch = _getch()) != '\r') {
		if (ch == '\b') {
			if (password.size() > 0) {
				password.pop_back();
				cout << "\b \b";
			}
		}
		else{
			password.push_back(ch);
			cout << "*";
		}
	}
}
void Login() {
	string ID,login_password;
	while (true) {
		cout << "Enter Your ID: ";
		cin >> ID;
		cout << "Enter your password : ";
		password(login_password);
		if (!data_information.count(ID) || login_password != data_information[ID].password) {
			cout << "\nFailed login. Try again.\n";
			continue;
		}
		else 
			cout << "Successful login, Welcome back " << data_information[ID].name << endl;
	}
}
void Change_Password() {

}

//todo 1: make function that checks an existing id if it has been found take another one from the user 
// todo 2 : make function that load all the information from the file to the map 
