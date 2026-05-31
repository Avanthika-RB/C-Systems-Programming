/* 
* A vulnerable login program. 
*
* Vahab Pournaghshband
* University of San Francisco
*
* Compile with and without gcc stack protector (-fno-stack-protector)
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define SIZE 10

int main()
{
  char correct_password[] = "fgH!12";
  char password[SIZE];
  char name[SIZE];

  bool logged_in = false;

  printf("Enter Password:");
  scanf("%s",password);

  if ( strcmp(password,correct_password) == 0 )
    logged_in = true;

  if ( logged_in == true )
    printf("The secret word is USF.\n");
  else
    printf("Invalid password!\n");

  return EXIT_SUCCESS;
}
