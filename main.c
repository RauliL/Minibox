/****************************
 * MINIBOX Main Source File *
 ****************************/

#include "minibox.h"

void version(void)
{
   puts("Version: 0.1");
}

int main(int argc, char *argv[])
{
   if(argc >= 2)
   {
#ifdef COMMAND_BEEP
      if(!strcmp(argv[1], "beep"))
      {
         return command_beep(argc, argv);
      }
#endif

#ifdef COMMAND_CAT
      if(!strcmp(argv[1], "cat"))
      {
         return command_cat(argc, argv);
      }
#endif

#ifdef COMMAND_CD
      if(!strcmp(argv[1], "cd"))
      {
         return command_cd(argc, argv);
      }
#endif

#ifdef COMMAND_CLEAR
      if(!strcmp(argv[1], "clear"))
      {
         return command_clear(argc, argv);
      }
#endif

#ifdef COMMAND_CP
      if(!strcmp(argv[1], "cp"))
      {
         return command_cp(argc, argv);
      }
#endif

#ifdef COMMAND_DATE
      if(!strcmp(argv[1], "date"))
      {
         return command_date(argc, argv);
      }
#endif

#ifdef COMMAND_ECHO
      if(!strcmp(argv[1], "echo"))
      {
         return command_echo(argc, argv);
      }
#endif

#ifdef COMMAND_LS
      if(!strcmp(argv[1], "ls"))
      {
         return command_ls(argc, argv);
      }
#endif

#ifdef COMMAND_MKDIR
      if(!strcmp(argv[1], "mkdir"))
      {
         return command_mkdir(argc, argv);
      }
#endif

#ifdef COMMAND_MV
      if(!strcmp(argv[1], "mv"))
      {
         return command_mv(argc, argv);
      }
#endif

#ifdef COMMAND_PWD
      if(!strcmp(argv[1], "pwd"))
      {
         return command_pwd(argc, argv);
      }
#endif

#ifdef COMMAND_RM
      if(!strcmp(argv[1], "rm"))
      {
         return command_rm(argc, argv);
      }
#endif

#ifdef COMMAND_RMDIR
      if(!strcmp(argv[1], "rmdir"))
      {
         return command_rmdir(argc, argv);
      }
#endif

#ifdef COMMAND_SH
      if(!strcmp(argv[1], "sh"))
      {
         return command_sh(argc, argv);
      }
#endif

#ifdef COMMAND_TIME
      if(!strcmp(argv[1], "time"))
      {
         return command_time(argc, argv);
      }
#endif

#ifdef HELP
      if(!strcmp(argv[1], "--help"))
      {
         puts("MINIBOX - Linux commands on DOS.");
         puts("  MINIBOX command [arguments]");
         puts("  MINIBOX --help|--version");
         puts("  MINIBOX ");
         return 0;
      }
#endif
      
#ifdef VERSION
      if(!strcmp(argv[1], "--version"))
      {
         version();
         return 0;
      }
#endif
   }
   else if(argc < 2)
   {
       puts("No enough arguments.");
       return 1;
   }
   
   return 2;
}