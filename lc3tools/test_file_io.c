#include <stdio.h>

int main(void)
{
    FILE *ptr;
    FILE *out;

    ptr = fopen("../text.txt","r");
    out = fopen("../new.txt", "a");

    
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
        char check[] = "jus";
        int count = 0;
        for (int i=0; i<3; i++)
        {
            if (line[i] == check[i])
            {
                count++;
            }
        }
        if (count == 3) fputs(line, out);
    }
}