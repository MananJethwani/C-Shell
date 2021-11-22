#ifndef len
    #define len 1024
#endif

using namespace std;

class Shell
{
private:
    string username, hostname;
    vector<string> initialDirectory, PWD;

public:
    Shell();
    string prompt();

    
};
