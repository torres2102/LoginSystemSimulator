#include "LoginSystem.h"


regex name("[^!@#$&*]+[^0-9]+");
regex phone("[0][1][0125][0-9]{8}");
regex email("[^.][a-zA-Z0-9]+@[a-z]+.[comCom]+[^.]");
regex passwordRegex("^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)(?=.*[@$!%*?&])[A-Za-z\\d@$!%*?&]{8,}$");
string new_line = "--------------------------------------------------";
string StrongPassword = "\n######### Strong Password Rules #########\n"
"1-Password must not be less than 8 characters\n"
"2-password must have capital & small letters\n"
"3-Password must have special characters like *@!()$^";
string ID;
struct Information {
    string email, password, name, phone;
};
map<string, Information> data_information;
void Register() {
    string repeated_pass;
    Information student;
    cout << "Enter your ID: ";
    cin >> ID;
    data_information[ID] = student;
    cout << "\n" << new_line;
    cout << "\nYour name must be in this format\nonly alphabetic letters or underscore (_)\n";
    do {
        cout << "Enter your name : ";
        cin >> data_information[ID].name;
    } while (!regex_match(data_information[ID].name, name));

    cout << "\n" << new_line;
    cout
        << "\nYour email must be in this format\nalphabets or digit characters followed by @ and then the domain followed by (.com)\n";

    do {
        cout << "Enter your email : ";
        cin >> data_information[ID].email;
    } while (!regex_match(data_information[ID].email, email));
    cout << new_line;
    cout << StrongPassword;
    do {
        cout << "\nPlease Enter your Password properly: ";
        password(data_information[ID].password);
    } while (!regex_match(data_information[ID].password, passwordRegex));
    cout << "\nConfirm your password again:";
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
        cout << "Enter your phone : ";
        cin >> data_information[ID].phone;
    } while (!regex_match(data_information[ID].phone, phone));
    write_to_file();
}

void password(string& password) {
    int ch{};
    password = "";
    while ((ch = _getch()) != '\r') {
        if (ch == '\b') {
            if (password.size() > 0) {
                password.pop_back();
                cout << "\b \b";
            }
        }
        else {
            password.push_back(ch);
            cout << "*";
        }
    }

}
bool Login() {
    read_from_file();
    string login_password;
    int attempts{};
    while (attempts < 3) {
        cout << "Enter Your ID: ";
        cin >> ID;
        cout << "Enter your password :";
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
    cout << StrongPassword;
    string new_password, new_password2;
    cout << "You should login first.\n";
    if (Login()) {
        password(new_password);
        cout << "Enter your new password again :";
        password(new_password2);
        if (new_password == new_password2)
            data_information[ID].password = new_password;
    }

}
void write_to_file() {
    ofstream out_file{ "data_information.txt", ios::app };

    if (!out_file) {
        cerr << "Error opening the file." << endl;
    }
    for (const auto& myPair : data_information) {
        string id = myPair.first;
        out_file << id << endl;
        out_file << data_information[id].name << endl;
        out_file << data_information[id].email << endl;
        out_file << data_information[id].phone << endl;
        out_file << data_information[id].password << endl;
    }
    out_file.close();
}
void read_from_file(){
    string id, name, email, phone, password;
    ifstream in_file;
    in_file.open("data_information.txt");
    if (!in_file) {
        cerr << "Please check if there's something wrong with the file.";
    }
    while (in_file >> id >> name >> email >> phone >> password) {
        data_information[id].name = name;
        data_information[id].password = password;
        data_information[id].email = email;
        data_information[id].phone= phone;

    }

    in_file.close();

}