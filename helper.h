#ifndef _HELPER_H_
#define _HELPER_H_


#define MAKE_FILE_COTENT "all:\n\tg++ -Wall -std=c++17 -O2 -Wextra -Wno-unused-result -Wshadow sol.cpp -o out"
#define VERSION "v0.01"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// #include <dirent.h>





void show_usages(void);
void create_sub_dire(char * dir_name);
void create_template(char * file_path_with_name);



#endif
