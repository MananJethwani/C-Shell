#include<bits/stdc++.h>

using namespace std;

#include "shell.h"
#include "util.h"

Shell::runOutput Shell::cd(string arg) {
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
        return {"Invalid Path\n", 1};
    }
    getcwd(path, len);
    PWD = split(convertToString(path), "/", true);
    free(path);
    prevDirectory = temp1;
    if (ret != "") {
        ret += '\n';
    } 
    return {ret, 0};
}

/*
/home/manan/
PWD -> [home, manan, ]

..
.

../d/../d/../
*/