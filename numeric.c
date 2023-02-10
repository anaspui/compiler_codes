//Program 2: Whether the Given Input is Numeric Constant or Not
/* */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXINPUT 100
int main()
{
    char input[MAXINPUT] = "";
    int length,i;

    puts("Enter a string");
    scanf ("%s", input);
    length = strlen (input);
    for (i=0;i<length; i++)
        if (!isdigit(input[i]))
        {
            printf ("Entered input is not a number\n");
            exit(1);
        }
    printf ("Given input is a number\n");
}
