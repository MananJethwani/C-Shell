#include<bits/stdc++.h>

using namespace std;

#include "shell.h"
#include "util.h"

int Shell::execute_pwd () {
    cout<<"/" + convertToString(PWD, "/")<<endl;
    return 0;
}