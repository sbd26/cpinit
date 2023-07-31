#include <string.h>
#include <sys/stat.h>
#include "helper.h"

#define and &&
#define or ||


typedef enum {
  FOUND_DIR_NAME,
  FOUND_DIR_FLAG,
  LAST_INDEX
}helper;

bool found_arr[LAST_INDEX];

int
main(int argc, char * argv[])
{
  char * dir_name;
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
      }
    }
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
