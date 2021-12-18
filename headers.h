#ifndef C_SHELL_HEADERS_H
	#define C_SHELL_HEADERS_H

	#include <stdio.h>
	#include <string.h>
	#include <unistd.h>
	#include <fcntl.h>
	#include <stdlib.h>
	#include <stdbool.h>
	#include <sys/stat.h>
	#include <sys/types.h>
	#include <sys/wait.h>
	#include <dirent.h>
	#include <time.h>
	#include <pwd.h>
	#include <grp.h>
	#include <signal.h>
	#include <setjmp.h>
	#include <bits/stdc++.h>

	#define CF_count 100
	#define CMD_DELIMITER ";\n"
	#define ARG_DELIMITER " \t\r\n\a"
	#define path_len 1024
	#define TOTAL_JOBS 50

	#define BLACK "\e[1;90m"
	#define RED "\e[1;91m"
	#define GREEN "\e[1;32m"
	#define YELLOW "\e[0;93m"
	#define BLUE "\e[1;94m"
	#define MAGENTA "\e[1;95m"
	#define CYAN "\e[0;96m"
	#define WHITE "\e[0;37m"
	#define RESET "\e[0;0m"

	// int STDIN_COPY, STDOUT_COPY;

#endif