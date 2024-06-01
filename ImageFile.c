#include<stdio.h>

int main()
{
    FILE *input = NULL;
    FILE *output = NULL;
    unsigned char buffer[1024];
    size_t bytesRead;		//size_t is unsigned integer type used to represent the size of objects in bytes.

    input = fopen("12.jpg","rb");
    output = fopen("folder1/img.jpg","wb");

    while ((bytesRead = fread(buffer,1,sizeof(buffer),input))>0)
    {
        fwrite(buffer,1,bytesRead,output);
    }

    
    printf(buffer);
    
    fclose(input);
    fclose(output);
    return 0;
}