#include <bits/stdc++.h>

using namespace std;

#include "main.h"
#include "shell.h"

int main()
{
    Shell shell;
    cout << shell.prompt()<<endl;
    shell.readCommand();
    cout << shell.prompt()<<endl;
    return 0;
}