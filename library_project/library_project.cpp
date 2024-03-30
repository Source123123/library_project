#include <iostream>
using namespace std;

bool authenticate(const string& username, const string& password) {
    // 实现登录验证逻辑,此处为示例代码
    return username == "admin" && password == "password";
}

void Display_Menu() {
    cout << "What do you want to do?" << endl;
    cout << "1.Login to your account" << endl;
    cout << "2.Log out your account" << endl;
    cout << "3.Check book status" << endl;
    cout << "4.exit" << endl;
    cout << "==============================================================" << endl;
}
int getValidChoice() {
    int c;
    while (true) {
        cout << "> ";
        if (cin >> c && c>= 1 && c <= 4) {
            // 清空输入缓冲区
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return c;
        }
        else {
            cout << "Invalid choice! Please try again." << endl;
            cin.clear(); // 重置 cin 的状态
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 清空输入缓冲区
        }
    }
    return 0;
}
bool handleChoice(int c){
    switch (c) {
    case 1: {
        string username, password;
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;
        if (authenticate(username, password)) {
            cout << "Log in successful!" << endl;
        }
        else {
            cout << "Invalid username or password!" << endl;
        }
        break;
    }
    case 2:
        cout << "Log out" << endl;
        break;
    case 3:
        cout << "Check books" << endl;
        break;
    case 4:
        cout << "Exiting..." << endl;
        return false;
    default:
        cout << "Invalid choice!" << endl;
    }
    return true;
}

int main()
{   
    int choice;
    do {
        Display_Menu();
        choice = getValidChoice();
        handleChoice(choice);
    } while (choice != 4);
    

    return 0;
}

