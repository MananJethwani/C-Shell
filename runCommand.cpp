#include <bits/stdc++.h>
using namespace std;

#include "shell.h"
#include "util.h"
// TODO add pipeline support.

void Shell::readCommand() {
    
    // separators: |
    string s, ss = "";
    getline(cin, s);
    int l = s.size();
    vector<string> pipe_div = split(s, "|");
    for (auto &command : pipe_div) {
        if (command == string(command.size(), ' ')) {
            cout << "Invalid Syntax" <<endl;
            break;
        }
    }

    // piping begins;
    int pipe_fd[2];
    for(int i = 0; i < pipe_div.size() - 1; i++) {
        string &command = pipe_div[i];
        
        if (pipe(pipe_fd)) {
            cout << "Error in constructing Pipe" << endl;
            return;
        }

        dup2(pipe_fd[1], 1);
        if (runCommand(command)) {
            break;
        }
        dup2(pipe_fd[0], 0);
        close(pipe_fd[1]);
    }

    dup2(STDOUT_COPY, 1);
    runCommand(pipe_div.back());
}

int Shell::runCommand(string command) {

    // strip
    int lo = 0, hi = command.size() - 1;
    while (lo <= hi && command[lo] == ' ') lo++; 
    while (lo <= hi && command[hi] == ' ') hi--;
    command = command.substr(lo, hi - lo + 1);
    
    if (command == "") return 0;
    vector<string> commands = split(command, " ", false);
    // cout << "printing commands" << endl;
    // for (auto &s : commands) {
    //     cout << s << endl;make
    // }
    // cout << "printed" << endl;
    if (commands[0] == "exit") {
        exit(0);
    }
    else if (commands[0] == "cd")
    {
        // if (commands.size() > 2) {
        //     // return {"Too many Arguments \n", 1};
        //     cout << "cd: Too many Arguments" << endl;
        //     return 1;
        // }
        // else if (commands.size() == 2) {
        //     return this->execute_cd(commands[1]);
        // } 
        // else {
        //     return this->execute_cd("");
        // }
        return this->execute_cd(commands);
    } else if (commands[0] == "pwd") {
        return this->execute_pwd();
    } else if (commands[0] == "echo") {
        return this->execute_echo(commands);
    } else if (commands[0] == "setEnv") {
        return this->setEnv(commands);
    } else if (commands[0] == "getEnv") {
        return this->getEnv(commands);
    } else if (commands[0] == "unsetEnv") {
        return this->unsetEnv(commands);
    } else if (commands[0] == "ls") {
        return this->execute_ls(commands);
    }
    else if (commands[0] == "") {}
    assert(false);
}



 // Shell::runOutput prefix = {"", 0};
    // string prevCommand;
    // int i = 0;
    // do {
    //     string op = "";
    //     while (i < l && (s[i] == '|' || s[i] == '&')) {
    //         op += s[i++];
    //     }
    //     int j = l;
    //     for (char ch : {'|', '&'}) {
    //         size_t pos = s.find_first_of(ch);
    //         if (pos != string::npos && pos < j) {
    //             j = pos;
    //         }
    //     }
    //     if (op == "" || (op == "&&" && prefix.exitCode == 0) || (op == "||" && prefix.exitCode != 0)) {
    //         // cout << "running `" << s.substr(i, j - i) << "` with op = " << op << endl;
    //         prefix = runCommand(s.substr(i, j - i));
    //     }
    //     else {
    //         cout << "Invalid Command" << endl;
    //         break;
    //     }
    //     i = j;
    // } while (i < l);

    
    // separators: | && ||
    // string s, ss = "";
    // getline(cin, s);
    // int l = s.size();
    // Shell::runOutput prefix = {"", 0};
    // string prevCommand;
    // int i = 0;
    // do {
    //     string op = "";
    //     while (i < l && (s[i] == '|' || s[i] == '&')) {
    //         op += s[i++];
    //     }
    //     int j = l;
    //     for (char ch : {'|', '&'}) {
    //         size_t pos = s.find_first_of(ch);
    //         if (pos != string::npos && pos < j) {
    //             j = pos;
    //         }
    //     }
    //     if (op == "" || (op == "&&" && prefix.exitCode == 0) || (op == "||" && prefix.exitCode != 0)) {
    //         // cout << "running `" << s.substr(i, j - i) << "` with op = " << op << endl;
    //         prefix = runCommand(s.substr(i, j - i));
    //     }
    //     else {
    //         cout << "Invalid Command" << endl;
    //         break;
    //     }
    //     i = j;
    // } while (i < l);