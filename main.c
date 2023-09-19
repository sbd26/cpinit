#include <string.h>
#include <sys/stat.h>
#include "helper.h"

#define and &&
#define or ||


typedef enum {
  FOUND_DIR_NAME,
  FOUND_DIR_FLAG,
  FOUND_ONE_FILE_FALG,
  FOUND_ONE_FILE_NAME,
  FOUND_GENERAL_FLAG,
  LAST_INDEX
}helper;

bool found_arr[LAST_INDEX];

int
main(int argc, char * argv[])
{
  char * dir_name;
  char * one_file_name;
  if (argc == 2 and !strcmp(argv[1], "-v"))
  {
    printf("󰀵 VERSION IS %s\n",VERSION);
    return 0;
  }

  if (argc == 2 and !strcmp(argv[1], "-h"))
  {
    show_usages();
    return 0;
  }

  if (argc >= 2)
  {
    for (int i = 1; i < argc; i++)
    {
      if (!strcmp(argv[i], "-d")){
        found_arr[FOUND_DIR_FLAG] = true;
        if (i + 1 < argc)
          if(argv[i + 1][0] != '-'){
            found_arr[FOUND_DIR_NAME] = true;
            dir_name = argv[i + 1];
        }
      } else if (!strcmp(argv[i], "-o")){
        found_arr[FOUND_ONE_FILE_FALG] = true;
        if (i + 1 < argc)
          if (argv[i+1][0] != '-'){
            found_arr[FOUND_ONE_FILE_NAME] = true;
            dir_name = argv[i + 1];
          }
      }

      if (!strcmp(argv[i], "-g")) found_arr[FOUND_GENERAL_FLAG] = true;
    }
  }

  if (found_arr[FOUND_ONE_FILE_FALG] && found_arr[FOUND_ONE_FILE_NAME]){
    printf("Creating.....\n");
    create_template(dir_name, found_arr[FOUND_GENERAL_FLAG]);
    exit(10);
  }

  if (!found_arr[FOUND_DIR_FLAG] or !found_arr[FOUND_DIR_NAME])
  {
    printf("use [-h] for help manual\n");
    exit(26);
  }

  if (found_arr[FOUND_DIR_FLAG] and !found_arr[FOUND_DIR_NAME]){
    show_usages();
    // fprintf(stderr, "[] : DIRECTORY FLAG IS FOUND BUT DIR NAME NOT FOUND\n");
    exit(1);
  }
  
  int res = mkdir(dir_name, S_IRWXU);

  if (res == 0)
  {
    printf("󰱱 INIT DONE <3\n");
    create_sub_dire(dir_name);
  }
  else
    fprintf(stderr, "[ ] : COULD NOT CREATE THE DIRECTORY\n");

  return 0;
}
