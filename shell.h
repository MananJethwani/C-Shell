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
        string username, hostname;

    public:
        int STDIN_COPY, STDOUT_COPY;
        Shell();
        // struct runOutput {
        //     string output;
        //     int exitCode;
        // };
        void readCommand();
        string prompt();
        int runCommand(string);
        int execute_cd(vector<string>);
        int execute_pwd();
        int execute_echo(vector<string>);
        int setEnv(vector<string>);
        int getEnv(vector<string>);
        int unsetEnv(vector<string>);
    };
#endif