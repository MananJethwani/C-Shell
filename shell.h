#ifndef SHELL_H
    #define SHELL_H
    #ifndef len
        #define len 1024
    #endif

    using namespace std;

    class Shell
    {
    private:
        vector<string> initialDirectory, PWD, prevDirectory;

    public:
        string username, hostname;
        Shell();
        struct runOutput {
            string output;
            int exitCode;
        };
        void readCommand();
        string prompt();
        runOutput runCommand(string);
        runOutput cd(string);
    };
#endif