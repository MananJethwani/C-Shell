#define ALLUTIL

using namespace std;

#ifndef len
    #define len 1024
#endif

// bool debug;
// template<typename A, typename B> istream& operator>>(istream &is, pair<A, B> &p); 
// template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> istream& operator>>(istream &is, T_container &v);
// template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p); 
// template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v);
// void dbg_out();
// template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T);
// #define dbg(...) cerr << "[" << #__VA_ARGS__ << "]:", debug = true, dbg_out(__VA_ARGS__), debug = false

vector<string> split(string, char);
string convertToString(char *);
string convertToString(const vector<string> &v, const string delimiter);
