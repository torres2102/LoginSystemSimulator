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
bool Login();
void Change_Password();
void password(string& password);
void Filter(string &str , string &phone_num , string &gmail);

string new_line = "--------------------------------------------------";
string ID;
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
    regex name("[^!@#$&*]+[^0-9]+");
    regex phone("[0][1][0125][0-9]{8}");
    regex email("[^ .][a-zA-Z0-9]+@[Gmailgmail]+.[comCom]+[^.]");
    regex strongPassword("^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)(?=.*[@$!%*?&])[A-Za-z\\d@$!%*?&]{8,}$")
    string repeated_pass;
    Information student;
    cout << "Enter your ID: ";
    cin >> ID;
    data_information[ID] = student;
    cout << "\n" << new_line;
    cout << "\nYour name must be in this format\nonly alphabetic letters or underscore (_)\n";
    do {
        cout << "Enter your name in the properly: ";
        cin >> data_information[ID].name;
    } while (!regex_match(data_information[ID].name, name));

    cout << "\n" << new_line;
    cout
            << "\nYour email must be in this format\nalphabets or digit characters followed by @ and then the domain followed by (.com)\n";

    do {
        cout << "Enter your email in the properly: ";
        cin >> data_information[ID].email;
    } while (!regex_match(data_information[ID].email, email));
    cout << new_line;
    cout
            << "\nPassword must be in this format\nmust contain at least on alphabetic character and one digit and one symbol\n"
               "The length must be at least 12 letters.\nEnter your password: ";

    password(data_information[ID].password);
    cout << "\nConfirm your password again: ";
    password(repeated_pass);
    cout << "\n" << new_line;
    while (repeated_pass != data_information[ID].password) {
        cout << "\nThose passwords didn't match. Try again.\n";
        cout << "\nConfirm your password again: ";
        password(repeated_pass);
        cout << endl;
    }
    cout
            << "\nPhone number must be in this format\n(010) or (011) or (012) or (015) followed by 8 digits\n";
    do {
        cout << "Enter your phone in the properly: ";
        cin >> data_information[ID].phone;
    } while (!regex_match(data_information[ID].phone, phone));
}

void password(string &password) {
    int ch{};
    password = "";
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
bool Login() {
    string login_password;
    int attempts{};
    while (attempts < 3) {
        cout << "Enter Your ID: ";
        cin >> ID;
        cout << "Enter your password : ";
        password(login_password);
        if (!data_information.count(ID) || login_password != data_information[ID].password) {
            cout << "\nFailed login. Try again.\n";
            attempts++;
            if (attempts == 3)
                cout << "You are denied from accessing the system\n";
            continue;
        }
        else {
            cout << "Successful login, Welcome back " << data_information[ID].name << endl;
            return true;
        }

    }
}

void Change_Password() {
    string new_password,new_password2;
    cout << "You should login first.\n";
    if (Login()) {
        cout << "Please enter your new password : ";
        password(new_password);
        cout << "Enter your new password again : ";
        password(new_password2);
        if (new_password == new_password2)
            data_information[ID].password = new_password;
    }

}



//todo 1: make function that checks an existing id if it has been found take another one from the user
// todo 2 : make function that load all the information from the file to the map
