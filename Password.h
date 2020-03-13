#ifndef PASSWORD_H
#define PASSWORD_H


#include <string>
using namespace std;
class Password
{
    string pass;
public:
    Password();
    void read_pass();
    void set_pass(string p);
    string get_pass();

};

#endif // PASSWORD_H
