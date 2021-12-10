#include<bits/stdc++.h>

using namespace std;

#include "shell.h";
#include "util.h";

// TODO add pipeline support.

void Shell::readCommand() {
    // separators: | && ||
    string s, ss = "";
    getline(cin, s);
    int l = s.size();
    Shell::runOutput prefix = {"", 0};
    for (int i=0;i<l;i++) {
        if ((s[i] == '&' && (i+1)<l && s[i + 1] == '&')) {
            if (!prefix.exitCode) {
                prefix = runCommand(ss);
                cout<<prefix.output;
            }
            ss = "";
            i++;
        } else if ((s[i] == '&' && (i+1)<l && s[i + 1] == '&')) {
            if (prefix.exitCode) {
                prefix = runCommand(ss);
            }
            ss = "";
            i++;
        } else {
            ss += s[i];
        }
    }
    cout<<endl;
}

Shell::runOutput Shell::runCommand(string command) {
    if (command == "") return {"", 0};
    vector<string> commands = split(command, " ", false);
    if (commands[0] == "cd") {
        if (command.size() > 2) {
            return {"Too many Arguments \n", 1};
        }
        if (commands.size() == 2 ) {
            return this->cd(commands[1]);
        } else {
            return this->cd("");
        }
    }
}