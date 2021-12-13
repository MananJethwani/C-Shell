#include<bits/stdc++.h>

using namespace std;

#include "shell.h"
#include "util.h"

int Shell::execute_echo(vector<string> commands) {
	for (int i=1;i<commands.size();i++) {
		cout << commands[i]<<" ";
	}
	cout << endl;
	return 0;
}