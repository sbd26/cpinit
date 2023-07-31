#include "helper.h"
#include "config.h"


void
show_usages(void)
{
  printf("-----------------------------------------------------------------------\n");
  printf("use [-v] for display version\n");
  printf("use [-d] [dir name] for creating a directory for contest\n");
  printf("BY DEFAULT IT WILL INCLUDE THE MAKE FILE FOR COMPILING THE PROGRAM\n");
  printf("THE PROGRAM NAME WILL BE sol.cpp\n");
  // printf("use [-h] for help manual\n");
  printf("-----------------------------------------------------------------------\n");
}

void
create_template(char * file_path_with_name)
{
      // const char* cppCodeTemplate = "/*\n"
      //                             "* Author : bd26\n"
      //                             "* Time   : %s\n"
      //                             "*/\n"
      //                             "\n"
      //                             "#include <bits/stdc++.h>\n"
      //                             "using namespace std;\n"
      //                             "\n\n"
      //                             "int main(){\n"
      //                             "  ios::sync_with_stdio(false);\n"
      //                             "  cin.tie(0);\n"
      //                             "\n\n\n"
      //                             "  return 0;\n"
      //                             "}\n";

  time_t now;
  struct tm * timeinfo;
  char timeStr[50];


  time(&now);
  timeinfo = localtime(&now);
  strftime(timeStr, sizeof(timeStr), "%Y-%m-%d %H:%M:%S", timeinfo);

  char cppCode[500];
  sprintf(cppCode, cppCodeTemplate, USER_NAME, timeStr);

  FILE* file;
  file = fopen(file_path_with_name, "w");

  if (file != NULL)
  {
    fputs(cppCode, file);
    fclose(file);
  }
  else {
    printf("ERROR COULD NOT WRITE THE FILE\n");
  }
}






void
create_sub_dire(char * dir_name)
{
  char * sub_dir_name[3] = {"a", "b", "c"};
  char cmd[100];
  for (int i = 0; i < 3; i++)
  {
    snprintf(cmd, sizeof(cmd), "mkdir -p %s/%s",dir_name, sub_dir_name[i]);
    system(cmd);
    snprintf(cmd, sizeof(cmd), "touch %s/%s/Makefile", dir_name, sub_dir_name[i]);
    system(cmd);
    snprintf(cmd, sizeof(cmd), "touch %s/%s/sol.cpp", dir_name, sub_dir_name[i]);
    system(cmd);
    snprintf(cmd, sizeof(cmd), "%s/%s/sol.cpp", dir_name, sub_dir_name[i]);
    create_template(cmd);

    char mk_file_path[100];
    snprintf(mk_file_path, sizeof(mk_file_path), "%s/%s/Makefile",dir_name, sub_dir_name[i]);

    FILE * makefile = fopen(mk_file_path, "w");

    if (!makefile)
    {
      fprintf(stderr, "COULD NOT OPEN MAKEFILE\n");
      exit(1);
    }

    fprintf(makefile, "%s", MAKE_FILE_COTENT);
    fclose(makefile);
  }
}
