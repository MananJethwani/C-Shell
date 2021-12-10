#include<bits/stdc++.h>

using namespace std;

#include "shell.h"
#include "util.h"

// TODO add pipeline support.

void Shell::readCommand() {
    // separators: | && ||
    string s, ss = "";
    getline(cin, s);
    int l = s.size();
    Shell::runOutput prefix = {"", 0};
    string prevCommand;
    int i = 0;
    do {
        string op = "";
        while (i < l && (s[i] == '|' || s[i] == '&')) {
            op += s[i++];
        }
        int j = l;
        for (char ch : {'|', '&'}) {
            size_t pos = s.find_first_of(ch);
            if (pos != string::npos && pos < j) {
                j = pos;
            }
        }
        if (op == "" || (op == "&&" && prefix.exitCode == 0) || (op == "||" && prefix.exitCode != 0)) {
            // cout << "running `" << s.substr(i, j - i) << "` with op = " << op << endl;
            prefix = runCommand(s.substr(i, j - i));
        }
        else {
            cout << "Invalid Command" << endl;
            break;
        }
        i = j;
    } while (i < l);

    // for (int i = 0; i < l; i++)
    // {
    //     if (s[i] == '|' || s[i] == '&') {
    //         if ((s[i] == '&' && (i+1)<l && s[i + 1] == '&')) {
    //             if (!prefix.exitCode) {
    //                 runCommand(s.substr(i + 2));
    //             }
    //             ss = "";
    //             i++;
    //         } else if ((s[i] == '&' && (i+1)<l && s[i + 1] == '&')) {
    //             if (prefix.exitCode) {
    //                 runCommand(s.substr(i + 2));
    //             }
    //             ss = "";
    //             i++;
    //         } else {
    //             ss += s[i];
    //         }
    //     } else {
    //         if (!prefix.exitCode) {
    //             prefix = runCommand(ss);
    //             // cout<<prefix.output;
    //         }
    //     }
    // }
    cout<<endl;
}

Shell::runOutput Shell::runCommand(string command) {
    if (command == "") return {"", 0};
    vector<string> commands = split(command, " ", false);
    // cout << "printing commands" << endl;
    // for (auto &s : commands) {
    //     cout << s << endl;
    // }
    // cout << "printed" << endl;
    if (commands[0] == "cd")
    {
        if (commands.size() > 2) {
            return {"Too many Arguments \n", 1};
        }
        else if (commands.size() == 2) {
            // cout << "CDed " << commands[1] << endl;
            return this->cd(commands[1]);
        } 
        else {
            return this->cd("");
        }
    }
}