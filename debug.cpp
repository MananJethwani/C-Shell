#include <bits/stdc++.h>
using namespace std;

template <typename A, typename B>
istream &operator>>(istream &is, pair<A, B> &p) { return is >> p.first >> p.second; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
istream &operator>>(istream &is, T_container &v)
{
    for (T &x : v)
        is >> x;
    return is;
}
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) { return debug ? os << '(' << p.first << ", " << p.second << ')' : os << p.first << " " << p.second; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v)
{
    if (debug)
    {
        os << "{";
        string sep;
        for (const T &x : v)
            os << sep << x, sep = ", ";
        os << '}';
    }
    else
    {
        bool f = false;
        for (const T &x : v)
        {
            if (f)
            {
                os << " ";
            }
            os << x, f = true;
        }
    }
    return os;
}
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T)
{
    cerr << ' ' << H;
    dbg_out(T...);
}