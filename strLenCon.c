#include <stdio.h>
#include <string.h>
int main()
{
    char a[20]="Program";
    char b[20]={'P','r','o','g','r','a','m','\0'};

    printf("Length of string a = %d \n",strlen(a));
    printf("Length of string b = %d \n\n",strlen(b));


    char str1[] = "abcd", str2[] = "abCd", str3[] = "abcd";
    int result;

    result = strcmp(str1, str2);
    printf("strcmp(str1, str2) = %d\n", result);

    result = strcmp(str1, str3);
    printf("strcmp(str1, str3) = %d\n\n", result);


    //concatenation
    char s1[100] = "Sadia ", s2[] = "Salsabil";
    int length, j;

    // store length of s1 in the length variable
    length = 0;
    while (s1[length] != '\0') {
        ++length;
    }

    // concatenate s2 to s1
    for (j = 0; s2[j] != '\0'; ++j, ++length) {
        s1[length] = s2[j];
    }

    // terminating the s1 string
    s1[length] = '\0';

    printf("After concatenation: ");
    puts(s1);

    return 0;
}
