#include <bits/stdc++.h>
using namespace std;

#include "shell.h"
#include "util.h"

int Shell::execute_cd(vector<string> args) {

    if (args.size() == 1) {
        return 0;
    }
    if (args.size() > 2) {
        // return {"Too many Arguments \n", 1};
        cout << "cd: Too many Arguments" << endl;
        return 1;
    }
    string arg = args[1];
    // cout << "args = " << args << endl;
    auto temp1 = PWD;
    // auto temp = PWD;
    string ret = "";
    if (arg == "" || arg == "~") {
        // temp = initialDirectory;
        arg = "/" + convertToString(initialDirectory, "/");
    } 
    else if (arg == "-") {
        ret = "/" + convertToString(prevDirectory, "/");
        arg = ret;
        // temp = prevDirectory;
    }
    char *path = (char *)malloc(len);
    strcpy(path, arg.c_str());
    if (chdir(path) != 0)
    {
        free(path);
        // return {"Invalid Path\n", 1};
        cout << "cd: Unable to reach path" << endl;
        return 1;
    }
    getcwd(path, len);
    PWD = split(convertToString(path), "/", true);
    free(path);
    prevDirectory = temp1;
    if (ret != "") {
        cout << ret << endl;
    }
    return 0;
}

/*
/home/manan/
PWD -> [home, manan, ]

..
.

../d/../d/../
*/