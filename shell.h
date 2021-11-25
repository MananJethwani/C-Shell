#ifndef SHELL_H
    #define SHELL_H
    #ifndef len
        #define len 1024
    #endif

    using namespace std;

    class Shell
    {
    private:
        string username, hostname;
        vector<string> initialDirectory, PWD, prevDirectory;

    public:
        Shell();
        string prompt();
        void readCommand();
        string runCommand(string);
        string cd(string);
    };
#endif