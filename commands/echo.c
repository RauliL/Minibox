/*****************************
 * MINIBOX echo Command File *
 *****************************/

#include "../minibox.h"

#ifdef COMMAND_ECHO
int command_echo(int argc, char *argv[])
{
   char backslash_escapes = 0;
   char new_line = 1;
   int i = 2;
   int parameter_length = 0;
   int j = 0;
   char character;

#ifdef HELP
   if(!strcmp(argv[2], "--help"))
   {
      puts("MINIBOX echo - Prints specified messages.");
      puts("  MINIBOX echo [options] message");
      puts("  MINIBOX echo --help|--version\r\n");
      puts("Options:");
      puts("-e  Prints special characters. Message must be quoted.");
      puts("    Characters are: \\a \\b \\c \\e \\f \\r \\t \\v \\x");
      puts("-n  In addition, prints newline character.");
      return 0;
   }
#endif

#ifdef VERSION
   if(!strcmp(argv[2], "--version"))
   {
      version();
      return 0;
   }
#endif

   if(!strcmp(argv[2], "-e"))
   {
      backslash_escapes = 1;
      if(!strcmp(argv[3], "-n"))
      {
         new_line = 0;
         i = 4;
      }
      else
      {
         i = 3;
      }  
   }

   if(!strcmp(argv[2], "-n"))
   {
      new_line = 0;
      if(!strcmp(argv[3], "-e"))
      {
         backslash_escapes = 1;
         i = 4;
      }
      else
      {
         i = 3;
      }  
   }

   for(i; i < argc; i++)
   {
      parameter_length = strlen(argv[i]);

      for(j = 0; j < parameter_length; j++)
      {
         if(backslash_escapes && argv[i][j] == '\\')
         {
            j++;

            if(argv[i][j] == '\\')
            {
               character = '\\';
            }
            else if(argv[i][j] == 'a')
            {
               character = '\a';
            }
            else if(argv[i][j] == 'b')
            {
               character = '\b';
            }
            else if(argv[i][j] == 'c')
            {
               return 0;
            }
            else if(argv[i][j] == 'e')
            {
               character = '\e';
            }
            else if(argv[i][j] == 'f')
            {
               character = '\f';
            }
            else if(argv[i][j] == 'n')
            {
               character = '\n';
            }
            else if(argv[i][j] == 'r')
            {
               character = '\r';
            }
            else if(argv[i][j] == 't')
            {
               character = '\t';
            }
            else if(argv[i][j] == 'v')
            {
               character = '\v';
            }
            /*else if(argv[i][j] == '0')   FIX ME!
            {
               
            }
            else if(argv[i][j] == 'x')     FIX ME!
            {
               
            }*/
            else
            {
               j--;

               continue;
            }
         }
         else
         {
            character = argv[i][j];
         }

         putchar(character);
      }

         if((i + 1) != argc)
         {
            putchar(' ');
         }
   }

   if(!new_line)
   {
      putchar('\r');
      putchar('\n');
   }

   return 0;
}
#endif