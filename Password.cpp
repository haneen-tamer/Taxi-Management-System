#include "Password.h"

#include "Password.h"
#include<iostream>
#include <conio.h>
using namespace std;

Password::Password()
{
    pass = "";
}

void Password::read_pass() {
    char ch;
    ch = _getch();
    while (ch != 13) {//character 13 is enter
        if (ch == '\b') {
            pass.erase(pass.length() - 1);
            _putch('\b');
            _putch(' ');
            _putch('\b');
        }
        else {
            pass += ch;
            cout << '*';
        }
        ch = _getch();
    }
    cout << endl;
}


void Password::set_pass(string p) {
    pass = p;
}

string Password::get_pass() {
    return pass;
}
