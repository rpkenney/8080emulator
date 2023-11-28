#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*    
    codebuffer is a valid pointer to 8080 assembly code    
    pc is the current offset into the code    

    returns the number of bytes of the op    
*/ 
int disassemble(unsigned char *codebuffer, int pc)
{
    unsigned char *code = &codebuffer[pc];
    int opbytes = 1;
    printf ("%04x %02X", pc, *code);
    switch (*code)
    {
        
    }
    printf("\n");
    return 0;
}

int main(void)
{

    FILE *fp;

    fp = fopen("../data/invaders.h", "rb");

    fseek(fp, 0, SEEK_END);
    long fsize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    unsigned char *buffer = malloc( fsize );
    fread(buffer, fsize, 1, fp);

    for(int i = 0; i < fsize; i++)
    {
        disassemble(buffer, i);
    }
    fclose(fp);
    free(buffer);

    return 0;
}