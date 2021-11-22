using namespace std;

bool debug;
template<typename A, typename B> istream& operator>>(istream &is, pair<A, B> &p); 
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> istream& operator>>(istream &is, T_container &v);
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p); 
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v);
void dbg_out();
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T);
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]:", debug = true, dbg_out(__VA_ARGS__), debug = false