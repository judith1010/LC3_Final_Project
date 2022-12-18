#include <stdio.h>
#include <string.h>

int foundOp(char opcode[], char line[])
{
    for (int i=0; i<strlen(line)-3; i++)
    {
        if (line[i] == opcode[0] && line[i+1] == opcode[1] && line[i+2] == opcode[3])
        return 1;
    }
    return 0;
}


int main(void)
{
    FILE *ptr;
    FILE *out;

    ptr = fopen("../text.txt","r");
    out = fopen("../new.txt", "w");

    
    //fscanf(ptr,"%s", &t);
    //fprintf(out,"%s",t);

    if (ptr == NULL)
    {
        printf("ERROR OPENING FILE");
        return 1;
    }

    char line[100];
    while(fgets(line, sizeof(line), ptr)) 
    {
        printf("%s", line);
        //fputs(line, out);
        if (foundOp("ADD", line))
        fputs(line, out);
    }
}