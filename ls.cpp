#include "headers.h"
#include <bits/stdc++.h>
#include <sys/stat.h>
#include <locale.h>
#include <dirent.h>
#include <sys/types.h>
#include <pwd.h>

using namespace std;

#include "shell.h"
#include "util.h"

void print_details(struct stat file_stats, int year, const char *file_name) {
    if (S_ISLNK(file_stats.st_mode)) cout << ("l");
    else if (S_ISREG(file_stats.st_mode)) cout << ("-");
    else if (S_ISDIR(file_stats.st_mode)) cout << ("d");
    else if (S_ISCHR(file_stats.st_mode)) cout << ("c");
    else if (S_ISBLK(file_stats.st_mode)) cout << ("b");
    else if (S_ISFIFO(file_stats.st_mode)) cout << ("p");
    else if (S_ISSOCK(file_stats.st_mode)) cout << ("s");

    // printf("%c", ((file_stats.st_mode & S_IRUSR) ? 'r' : '-'));
    cout << (file_stats.st_mode & S_IRUSR ? 'r' : '-');
    // printf("%c", ((file_stats.st_mode & S_IWUSR) ? 'w' : '-'));
    cout << (file_stats.st_mode & S_IWUSR ? 'w' : '-');
    // printf("%c", ((file_stats.st_mode & S_IXUSR) ? 'x' : '-'));
    cout << (file_stats.st_mode & S_IXUSR ? 'x' : '-');
    // printf("%c", ((file_stats.st_mode & S_IRGRP) ? 'r' : '-'));
    cout << (file_stats.st_mode & S_IRGRP ? 'r' : '-');
    // printf("%c", ((file_stats.st_mode & S_IWGRP) ? 'w' : '-'));
    cout << (file_stats.st_mode & S_IWGRP ? 'w' : '-');
    // printf("%c", ((file_stats.st_mode & S_IXGRP) ? 'x' : '-'));
    cout << (file_stats.st_mode & S_IXGRP ? 'x' : '-');
    // printf("%c", ((file_stats.st_mode & S_IROTH) ? 'r' : '-'));
    cout << (file_stats.st_mode & S_IROTH ? 'r' : '-');
    // printf("%c", ((file_stats.st_mode & S_IWOTH) ? 'w' : '-'));
    cout << (file_stats.st_mode & S_IWOTH ? 'w' : '-');
    // printf("%c", ((file_stats.st_mode & S_IXOTH) ? 'x' : '-'));
    cout << (file_stats.st_mode & S_IXOTH ? 'x' : '-');

    // printf("\t%ld\t", (long) file_stats.st_nlink);
    cout << "\t" << file_stats.st_nlink << "\t";

    struct passwd *user;
    struct group *grp;
    user = getpwuid(file_stats.st_uid);
    grp = getgrgid(file_stats.st_gid);

    // printf("%s\t", user->pw_name);
    cout << (user->pw_name) << "\t";
    // printf("%s\t", grp->gr_name);
    cout << (grp->gr_name) << "\t";

    printf("%lld\t", (long long) file_stats.st_size);
    cout << file_stats.st_size << "\t";

    tm *new_time = localtime(&file_stats.st_mtime);

    vector<string> months = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                      "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

    // printf("%s\t", months[new_time->tm_mon]);
    cout << months[new_time->tm_mon] << "\t";
    // printf("%d\t", new_time->tm_mday);
    cout << new_time->tm_mday << "\t";

    if (year == (int) new_time->tm_year + 1900) {
        // new_time->tm_hour >= 10 ? printf("%d:", new_time->tm_hour) : printf("0%d:", new_time->tm_hour);
        // cout << (new_time->tm_hour >= 10 ? new_time->tm_hour )
        cout << (new_time->tm_hour >= 10 ? "" : "0") << new_time->tm_hour << ":";
        // new_time->tm_min >= 10 ? printf("%d\t", new_time->tm_min) : printf("0%d\t", new_time->tm_min);
        cout << (new_time->tm_min >= 10 ? "" : "0") << new_time->tm_min << "\t";
    }
    else
    {
        // printf("%d\t", new_time->tm_year + 1900);
        cout << new_time->tm_year + 1900 << "\t";
    }

    // printf("%s\t", file_name);
    // printf("\n");
    cout << file_name << "\t\n";


}

int print_for_directory(string path, struct dirent *file, bool a, bool l, int year) {

    if (l) {
        if (file->d_name[0] != '.' || (a)) {

            char *new_file = new char[len];
            strcpy(new_file, path.c_str());
            // string new_fi

            unsigned int length = strlen(new_file);
            if (new_file[length - 1] != '/') {
                strcat(new_file, "/");
            }

            strcat(new_file, file->d_name);

            struct stat file_stats;
            if (stat(new_file, &file_stats) < 0) {
                perror("Cannot Access file");
                free(new_file);
                // *errorCode = 1;
                return 1;
            }

            print_details(file_stats, year, file->d_name);
            // *errorCode = 0;

            free(new_file);

        }
    } else {

        if (file->d_name[0] != '.' || (a)) {
            printf("%s\n", file->d_name);
        }
    }

    return 0;
}

int Shell::execute_ls(vector<string> commands)
{
    auto flags = extractFlags(commands);
    auto args = extractArgs(commands);

    if (args.empty())
    {
        args.push_back("/" + convertToString(PWD, "/") + "/");
    }

    bool a_option = false, l_option = false;
    for (auto &flag : flags)
    {
        for (auto &ch : flag)
        {
            if (ch == 'a')
                a_option = true;
            if (ch == 'l')
                l_option = true;
        }
    }

    int argc = args.size();

    struct tm *curr_time;
    time_t ts = time(0);
    curr_time = localtime(&ts);
    int year = curr_time->tm_year + 1900;

    for (int i = 0; i < argc; i++)
    {
        if (args[i][0] == '~')
        {
            args[i] = "/" + convertToString(initialDirectory, "/") + args[i].substr(1);
        }

        if (argc > 1)
        {
            cout << args[i] << ":\n";
        }

        struct stat file_stat;
        // stat file_stat;
        if (stat(args[i].c_str(), &file_stat) < 0)
        {
            cout << "Cannot access" << endl;
        }

        if (S_ISDIR(file_stat.st_mode))
        {
            struct dirent **file_list;
            int no_of_files = scandir(args[i].c_str(), &file_list, NULL, alphasort);
            if (no_of_files < 0)
            {
                cout << "ls: Cannot access :" + args[i] << endl;
                return 1;
            }
            long long blocks = 0;

            for (int j = 0; l_option && j < no_of_files; j++)
            {
                if (file_list[j]->d_name[0] != '.' || (a_option))
                {

                    int length = args[i].size();
                    char *file_path = convertToCharArray(args[i]);

                    if (file_path[length - 1] != '/')
                    {
                        strcat(file_path, "/");
                    }
                    strcat(file_path, file_list[j]->d_name);
                    struct stat file;
                    stat(file_path, &file);
                    blocks += file.st_blocks;
                }
            }

            if (l_option) cout << "total " << blocks/2 << endl;

            for (int j = 0; j < no_of_files; j++) {
                print_for_directory(args[i], file_list[j], a_option, l_option, year);
            }

            // for (int j = 0; j < no_of_files; j++) free(file_list[j]);
            // free(file_list);
        }
        else {
            if (l_option) print_details(file_stat, year, args[i].c_str());
            else cout << args[i];
        }
    }
    return 0;
}

/*
		bool a_option = false, l_option = false;
    for (int i = 0; flags[i] != NULL; i++) {
        unsigned int len = strlen(flags[i]);
        for (int j = 0; j < len; j++) {
            if (flags[i][j] == 'a') a_option = true;
            if (flags[i][j] == 'l') l_option = true;
        }
    }

    int argc = 0;
    while (args[argc] != NULL) argc++;

    struct tm *curr_time;
    time_t ts = time(0);
    curr_time = localtime(&ts);
    int year = curr_time->tm_year + 1900;

    for (int i = 0; args[i] != NULL; i++) {

        if (args[i][0] == '~') {
            char *temp = malloc(path_len);
            strcpy(temp, shell_root);
            strcat(temp, args[i] + 1);
            strcpy(args[i], temp);
            free(temp);
        }

        if (argc > 1) {
            printf("%s:\n", args[i]);
        }


        struct stat file_stat;
        if (stat(args[i], &file_stat) < 0) {
            perror("Cannot access");
            *errorCode = 1;
            continue;
        }

        if (S_ISDIR(file_stat.st_mode)) {

            struct dirent **file_list;

            int no_of_files = scandir(args[i], &file_list, NULL, alphasort);
            if (no_of_files < 0) {
                printf("ls: Cannot access '%s':", args[i]);
                fflush(stdout);
                perror("");
                *errorCode = 1;
                continue;
            }

            long long blocks = 0;

            for (int j = 0; l_option && j < no_of_files; j++) {
                if (file_list[j]->d_name[0] != '.' || (a_option)) {

                    char *file_path = malloc(path_len);
                    strcpy(file_path, args[i]);
                    unsigned int len = strlen(file_path);
                    if (file_path[len - 1] != '/') {
                        strcat(file_path, "/");
                    }
                    strcat(file_path, file_list[j]->d_name);

                    struct stat file;
                    stat(file_path, &file);
                    blocks += file.st_blocks;
                    free(file_path);
                }
            }

            if (l_option) printf("total %lld\n", blocks / 2);

            for (int j = 0; j < no_of_files; j++) {
                print_for_directory(args[i], file_list[j], a_option, l_option, year, errorCode);
            }

            for (int j = 0; j < no_of_files; j++) free(file_list[j]);
            free(file_list);

        } else {
            if (l_option) print_details(file_stat, year, args[i]);
            else printf("%s\n", args[i]);
        }
        *errorCode = 0;*/