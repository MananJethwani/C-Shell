#include <bits/stdc++.h>
using namespace std;

#include "shell.h"
#include "util.h"

int Shell::setEnv(vector<string> commands) {
    if (commands.size() < 2) {
        cout << "Too few arguments" << endl;
        return 1;
    } else if (commands.size() > 3) {
        cout << "Too many arguments" << endl;
    }

    char * name = new char[commands[1].size()];
    strcpy(name, commands[1].c_str());
    char * value;
    if (commands.size() == 2) {
        value = new char[100];
        memset(value, 0, 100);
    } else {
        value = new char[commands[2].size()];
        strcpy(value, commands[2].c_str());
    }
    if (setenv(name, value, 1) < 0) {
        cout<<"setEnv: Error in setting env. variable" << endl;
        return 1;
    }
    return 0;
}

int Shell::getEnv(vector<string> commands) {
    if (commands.size() < 2) {
        cout << "Too few arguments" << endl;
        return 1;
    } else if (commands.size() > 2) {
        cout << "Too many arguments" << endl;
    }

    char * name = new char[commands[1].size()];
    strcpy(name, commands[1].c_str());
    char* value = getenv(name);
    if (value) {        
        cout << value << endl;
    } else {
        cout << "Value doesn't exist" << endl;
    }
    return 0;
}

int Shell::unsetEnv(vector<string> commands) {
    if (commands.size() < 2) {
        cout << "Too few arguments" << endl;
        return 1;
    } else if (commands.size() > 2) {
        cout << "Too many arguments" << endl;
    }

    char * name = new char[commands[1].size()];
    strcpy(name, commands[1].c_str());
    
    if (unsetenv(name) < 0) {
        cout<<"unsetEnv: Error in unsetting env. variable" << endl;
        return 1;
    }
    return 0;
}