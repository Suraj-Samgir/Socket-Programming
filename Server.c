#include<stdio.h>

int main()
{
    FILE *test1 = NULL;
    FILE *test2 = NULL;
    test1 = fopen("test.txt", "r");
    test2 = fopen("test2.txt","w");

    char ch;

    while ((ch = fgetc(test1)) != EOF)
    {
        fputc(ch, test2);
    }

    fclose(test1);
    fclose(test2);
    
    return 0;
}