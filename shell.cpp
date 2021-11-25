#include <bits/stdc++.h>

using namespace std;

#include "shell.h"
#include "util.h"
// #include "debug.h"

Shell::Shell()
{
    username = getenv("USERNAME");
    char host[len];
    gethostname(host, len);
    hostname = convertToString(host);
    char pwd[len];
    getcwd(pwd, len);
    string cwd = convertToString(pwd);
    PWD = split(cwd, "/", true);
    initialDirectory = PWD;
    prevDirectory = PWD;
}

string Shell::prompt()
{
    return username + "@" + hostname + ":" + (PWD == initialDirectory ? "~" : "/" + convertToString(PWD, "/"));
}

// void Shell::readCommand() {
//     // separators: | && ||
//     string command;
//     getline(cin, command);
//     stack<string> st;
//     int l = command.size();
//     for (int i = 0; i < l; i++)
//     {
//         char ch = command[i];
//         if (command)
//     }
// }    

/*
References:
https://thevivekpandey.github.io/posts/2017-09-25-linux-system-calls.html

*/