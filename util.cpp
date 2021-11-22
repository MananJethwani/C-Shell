#include <bits/stdc++.h>

using namespace std;

#include "util.h"


// d contains all the delimeters
vector<string> split(string s, char d) {
    vector<string> ret;
    int last = 0;
    for(int i = 0; i <= s.size(); i++) {
        if(i == s.size() || s[i] == d) {
            ret.emplace_back(s.substr(last, i - last));
            last = i + 1;
        }
    }
    return ret;
}

string convertToString(char* a) {
    string s = "";
    for (int i = 0; i < len; i++) {
        if(a[i] == '\0')
            break;
        s = s + a[i];
    }
    return s;
}

string convertToString(const vector<string> &v, const string delimiter) {
    bool ok = false;
    string s = "";
    for (auto &ss : v) {
        if (ok) {
            s += delimiter;
        }
        s += ss;
        ok = true;
    }
    return s;
}
