#include <bits/stdc++.h>

using namespace std;

#include "shell.h"
#include "util.h"
// #include "debug.h"

Shell::Shell() {
    username = getenv("USERNAME");
    char host[len];
    gethostname(host, len);
    hostname = convertToString(host);
    char pwd[len];
    getcwd(pwd, len);
    string cwd = convertToString(pwd);
    PWD = split(cwd, '/');
    initialDirectory = PWD;
}

string Shell::prompt() {
    return username + "@" + hostname + ":" + (PWD == initialDirectory ? "~" : convertToString(PWD, "/"));
}

/*
References:
https://thevivekpandey.github.io/posts/2017-09-25-linux-system-calls.html

*/