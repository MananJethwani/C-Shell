#include<bits/stdc++.h>

using namespace std;

#include "shell.h";
#include "util.h";

string Shell::cd(string arg) {
    auto temp1 = PWD;
    auto temp = PWD;
    string ret = "";
    if (arg == "" || arg == "~") {
        temp = initialDirectory;
        arg = "/" + convertToString(initialDirectory, "/");
    } 
    else if (arg == "-") {
        ret = "/" + convertToString(prevDirectory, "/");
        arg = ret;
        temp = prevDirectory;
    }
    char *path = (char *)malloc(len);
    strcpy(path, arg.c_str());
    if (chdir(path) == -1) {
        free(path);
        return "Invalid Path";
    }
    getcwd(path, len);
    PWD = split(convertToString(path), "/", true);
    free(path);
    prevDirectory = temp1;
    return ret;
}

/*
/home/manan/
PWD -> [home, manan, ]

..
.

../d/../d/../
*/