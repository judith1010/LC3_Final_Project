#include <stdio.h>
#include <string.h>


//REMOVE ALL WHITESPACE FROM LINE AND SPLIT IT UP THAT WAY 
//HAVE TO TAKE LABELS INTO ACCOUNT
int main(int argc, char *argv[])
{
    FILE *in = fopen(argv[1], "r");
    FILE *out = fopen(argv[2], "w");

    if (in == NULL)
    {
        printf("ERROR: FILE DOES NOT EXIST!\n");
        return 1; 
    }

    char line[100];
    while(fgets(line, sizeof(line), in)) 
    {
      //if its a sub
        if (strstr(line, "ADD") != NULL) fputs(line, out);
        if (strstr(line, "SUB") != NULL)
        {
            fputs("NOT R3, R2\n", out);
            fputs("ADD R3, R3, #1\n", out);
            fputs("ADD R3, R4, R5\n", out);
        }
    }

    
}
