#include <stdio.h>
#include <string.h>

//try while loop: 
//while pointer not a space, keep going add chars to an array 
//once hit a space break out of loop and start on next var


//if find sub in the line, split it up and find the individual compnenents. (registers/imm5)
//then format the new lines of lc3 code that will need 
//write those lines to output file 
//continue looping through lines of asm 
int main(int argc, char *argv[])
{
    FILE *in = fopen("test.asm", "r");
    FILE *out = fopen("test1.asm", "w");

    if (in == NULL)
    {
        printf("ERROR: FILE DOES NOT EXIST!\n");
        return 1; 
    }

    char line[100];
    while(fgets(line, sizeof(line), in)) 
    {
        if (strstr(line, "ADD") != NULL) fputs(line, out);
        if (strstr(line, "SUB") != NULL)
        sub(line);
        // {
        //     fputs("NOT R3, R2\n", out);
        //     fputs("ADD R3, R3, #1\n", out);
        //     fputs("ADD R3, R4, R5\n", out);
        // }
    }

    
}
