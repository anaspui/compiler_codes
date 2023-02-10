# include <stdio.h>
int main(){

    FILE *fp ;
    char data[100] ;
    char name[50];
    printf( "Opening the file test.txt in read mode\n" ) ;
    fp = fopen( "test.txt", "r" ) ;
    if(fp == NULL){
        printf( "Could not open file test.txt\n" ) ;
        return 1;
    }
    printf( "Reading the file test.txt\n" ) ;
    while( fgets ( data, 50, fp ) != NULL )
        printf( "%s" , data ) ;
    printf("\nClosing the file test.txt\n\n") ;
    fclose(fp) ;

    //WRITING
    fp = (fopen("student.txt", "w"));
    if(fp == NULL){
       printf("Error!");
       exit(1);
    }
    printf("Writing in the 'student.txt' file\n");
    printf( "Enter student's name: ");
    scanf("%s", name);
    fprintf(fp,"Name: %s \n", name);

    fclose(fp) ;

    //Append
    fp = fopen( "student.txt", "a" ) ;
    if(fp == NULL){
        printf( "Could not open file test.txt\n" ) ;
        return 1;
    }
    printf("\nAppending in the 'student.txt' file\n");
    printf( "Enter student's name: ");
    scanf("%s", name);
    fputs(name, fp);
    fclose(fp) ;

    //Reading
    fp = fopen( "student.txt", "r" ) ;
    if(fp == NULL){
        printf( "\nCould not open file student.txt\n" ) ;
        return 1;
    }
    printf( "\nReading the file student.txt\n" ) ;
    while( fgets ( data, 50, fp ) != NULL )
        printf( "%s" , data ) ;
        printf("\nClosing the file student.txt\n") ;

    fclose(fp) ;


    return 0;
}
