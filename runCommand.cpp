#include<bits/stdc++.h>

using namespace std;

#include "shell.h";
#include "util.h";

string Shell::runCommand(string command) {
    if (command == "") return "";
    vector<string> commands = split(command, " ", false);
    if (commands[0] == "cd") {
        if (command.size() > 2) {
            return "Too many arguments";
        }
        if (commands.size() == 2 ) {
            this->cd(commands[1]);
        } else {
            this->cd("");
        }
    }
}