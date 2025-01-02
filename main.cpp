#include "source/LoginManager.h"
#include "source/DataManager.h"
#include "source/Converter.h"
#include <iostream>
#include <string>
#include <cstdlib>

// Passwords are hidden in the console with these libraries.
#ifdef _WIN32
#include <conio.h>
#else
#include <termios.h>
#include <unistd.h>
#endif


using namespace std;

void getPassword(string &password) {
#ifdef _WIN32
    char ch;
    while ((ch = _getch()) != '\r') {
        if (ch == '\b') { // Backspace tuşu
            if (!password.empty()) {
                password.pop_back();
                cout << "\b \b"; // Ekrandan son yıldızı sil
            }
        } else {
            password.push_back(ch);
            cout << '*';
        }
    }
    cout << endl;
#else
    termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    getline(cin, password);
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
#endif
}

// Register a new user.
int RegisterUser() {
    string username;
    string password;
    string password_a;

    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    getPassword(password);
    cout << "Enter your password again: ";
    getPassword(password_a);

    Register(username, password, password_a);

    return 0;
}

//Login with username and password.
int LoginUser() {
    string username;
    string password;

    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    getPassword(password);

    Login(username, password);

    return 0;
}

void Text() {

cout<<"   ____              _                _       " << endl;
cout<<"  / ___| _     _    | |    ___   __ _(_)_ __  " << endl;
cout<<" | |   _| |_ _| |_  | |   / _ \\ / _` | | '_ \\ " << endl;
cout<<" | |__|_   _|_   _| | |__| (_) | (_| | | | | |" << endl;
cout<<"  \\____||_|   |_|   |_____\\___/ \\__, |_|_| |_|" << endl;
cout<<"                                |___/         " << endl;

cout<<"\nPowered by Mal1koRe1ss\n";

    cout << "\t - 1. Register\n";
    cout << "\t - 2. Login\n";

}

int main() {
    int choice;

    system("cls");
    Text();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
    case 1:
        RegisterUser();
        break;
    case 2:
        LoginUser();
        break;
    default:
      cout << "Invalid choice. Please try again." << endl;
      break;
    }   

    cout << "Program finished!" << endl;
    system("pause");

    return 0;
}
    