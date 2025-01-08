#include <stdio.h>
#include <unistd.h>
#include <string.h>

void main() {
   char str[50], rev[50];
   int len, i;

   if(vfork() == 0) {
      printf("Enter a string: ");
      scanf(" %[^\n]s", str);

      len = strlen(str);

      for(i = 0; i <= len; i++)
         rev[i] = str[len - i - 1];
      rev[len] = '\0';

      _exit(0);
   } else {
      if(!strcmp(str, rev))
         printf("Palindrome\n");
      else
         printf("Not palindrome\n");
   }
}