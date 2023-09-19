#ifndef _HELPER_H_
#define _HELPER_H_


#define MAKE_FILE_COTENT "SRC = sol.cpp\nCFLAGS = -Wall -std=c++17 -O2 -Wextra -Wno-unused-result -Wshadow\nOUTPUT = out\nCC = g++\n\n$(OUTPUT): $(SRC)\n\t@$(CC) $(CFLAGS) $(SRC) -o $(OUTPUT)\n\nrun: $(OUTPUT)\n\t@./$(OUTPUT)\n\nclean:\n\t@rm $(OUTPUT)"
#define VERSION "v0.02"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// #include <dirent.h>





void show_usages(void);
void create_sub_dire(char * dir_name);
void create_template(char * file_path_with_name, bool general_flag);



#endif
