#include <bits/stdc++.h>

using namespace std;

#include "main.h"
#include "shell.h"

int main()
{
    Shell shell;
    shell.STDIN_COPY = dup(0);
    shell.STDOUT_COPY = dup(1);
    while (true) {
        cout << shell.prompt() << " ";
        shell.readCommand();
    }
    return 0;
}