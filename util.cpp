#include <bits/stdc++.h>

using namespace std;

#include "util.h"

// d contains all the delimeters
// flag will be true if we don't want to take first character
// useful when given '/' in paths 
vector<string> split(string s, string d, bool flag = false)
{
    vector<string> ret;
    int i = 0;
    int last = 0;
    if (flag) {
        i = 1;
        last = 1;
    }
    for (; i <= s.size(); i++)
    {
        if (i == s.size() || s.substr(i, d.size()) == d)
        {
            if (i == s.size() && s.substr(last, i - last) == "") {
                continue;
            }
            ret.emplace_back(s.substr(last, i - last));
            last = i + 1;
        }
    }
    return ret;
}

// To convert char array to string
string convertToString(char *a)
{
    string s = "";
    for (int i = 0; i < len; i++)
    {
        if (a[i] == '\0')
            break;
        s = s + a[i];
    }
    return s;
}

string convertToString(const vector<string> &v, const string delimiter)
{
    bool ok = false;
    string s = "";
    for (auto &ss : v)
    {
        if (ok)
        {
            s += delimiter;
        }
        s += ss;
        ok = true;
    }
    return s;
}

char * convertToCharArray(string s) {
    char ch[s.length() + 1];
    for(int i=0;i<s.length();i++) {
        ch[i] = s[i];
    }
    ch[s.length()] = '\0';
    char *x = ch;
    return x;
}