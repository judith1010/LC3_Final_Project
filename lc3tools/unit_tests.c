#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

int test_output[250];
int idx = 0;

typedef enum ccode_t ccode_t;
enum ccode_t {
    CC_    = 0,
    CC_P   = 0x0200,
    CC_Z   = 0x0400,
    CC_N   = 0x0800
};

typedef struct inst_t inst_t;
struct inst_t {
    ccode_t  ccode;
};



typedef enum operands_t operands_t;
enum operands_t {
    O_RRR, O_RRI,
    O_RR,  O_RI,  O_RL,
    O_R,   O_I,   O_L,   O_S,
    O_,
    NUM_OPERANDS
};

void reset(int r1) {
    #include "rst.h"
}

void test_rst() {
    int r1 = 0;
    idx = 0;
    int pass = 0;
    
    reset(r1);

    printf("RST RO: ");

    pass += test_output[0]==0x5020;
    if (pass < 1) printf("FAILED\n");
    else printf("PASSED\n");
}

void subtract(int r1, int r2, int r3, int val, operands_t operands, inst_t inst, char o3[]) {
    #include "sub.h"
}

void test_sub_rrr() { 
    int r1 = 0;
    int r2 = 1;
    int r3 = 2;
    int val = 0;
    char o3[] = "#3"; 
    idx = 0;
    operands_t operands = O_RRR;
    inst_t inst;
    inst.ccode = CC_;

    int pass = 0;

    subtract(r1, r2, r3, val, operands, inst, o3);

    printf("SUB R0, R1, R2: ");
    pass += test_output[0]==0x94BF;
    pass += test_output[1]==0x14A1;
    pass += test_output[2]==0x1042;
    pass += test_output[3]==0x94BF;
    pass += test_output[4]==0x14A1;
    pass += test_output[5]==0x1020;

    if (pass < 6) printf("FAILED\n");
    else printf("PASSED\n");

}

void test_sub_rri() { 
    int r1 = 0;
    int r2 = 1;
    int r3 = 0;
    int val = 0;
    char o3[] = "#3"; 
    idx = 0;
    operands_t operands = O_RRI;
    inst_t inst;
    inst.ccode = CC_;

    int pass = 0;

    subtract(r1, r2, r3, val, operands, inst, o3);

    printf("SUB R0, R1, #3: ");

    pass += test_output[0]==0x107D;
    if (pass < 1) printf("FAILED\n");
    else printf("PASSED\n");
}

void multiply(int r1, int r2, int r3, int val, operands_t operands, inst_t inst, char o3[]) 
{
    #include "mlt.h"
}

void test_mlt_rrr() {
    int r1 = 0;
    int r2 = 1;
    int r3 = 2;
    int val = 0;
    char o3[] = "#3"; //CHANGE ME
    idx = 0;
    operands_t operands = O_RRR;
    inst_t inst;
    inst.ccode = CC_;

    int pass = 0;
     
    multiply(r1, r2, r3, val, operands, inst, o3);

    printf("MLT R0, R1, R2: ");
    pass += test_output[0]==0x3601;
    pass += test_output[1]==0x0E01;
    pass += test_output[2]==0x0000;
    pass += test_output[3]==0x3801;
    pass += test_output[4]==0x0E01;
    pass += test_output[5]==0x0000;
    pass += test_output[6]==0x3A01;
    pass += test_output[7]==0x0E01;
    pass += test_output[8]==0x0000;
    pass += test_output[9]==0x56E0;
    pass += test_output[10]==0x16C1;
    pass += test_output[11]==0x0414;
    pass += test_output[12]==0x5920;
    pass += test_output[13]==0x1902;
    pass += test_output[14]==0x0411;
    pass += test_output[15]==0x5B60;
    pass += test_output[16]==0x16E0;
    pass += test_output[17]==0x0205; 
    pass += test_output[18]==0x96FF; 
    pass += test_output[19]==0x16E1;
    pass += test_output[20]==0x1920;
    pass += test_output[21]==0x0602; 
    pass += test_output[22]==0x1B61; 
    pass += test_output[23]==0x5020;
    pass += test_output[24]==0x1004;
    pass += test_output[25]==0x16FF;
    pass += test_output[26]==0x03FD;
    pass += test_output[27]==0x1B60;
    pass += test_output[28]==0x0C02;
    pass += test_output[29]==0x903F;
    pass += test_output[30]==0x1021;
    pass += test_output[31]==0x0E01;
    pass += test_output[32]==0x5020;
    pass += test_output[33]==0x27E0;
    pass += test_output[34]==0x29E2;
    pass += test_output[35]==0x2BE4;

    if (pass < 36) printf("FAILED\n");
    else printf("PASSED\n");
}

void test_mlt_rri() {
    int r1 = 0;
    int r2 = 1;
    int r3 = 2;
    int val = 0;
    char o3[] = "#3"; //CHANGE ME
    idx = 0;
    operands_t operands = O_RRI;
    inst_t inst;
    inst.ccode = CC_;

    int pass = 0; 
     
    multiply(r1, r2, r3, val, operands, inst, o3);

    printf("MLT R0, R1, #3: ");
    pass += test_output[0]==0x3401;
    pass += test_output[1]==0x0E01;
    pass += test_output[2]==0x0000;
    pass += test_output[3]==0x5020;
    pass += test_output[4]==0x1001;
    pass += test_output[5]==0x1001;
    pass += test_output[6]==0x1001;
    pass += test_output[7]==0x25FA;

    if (pass < 8) printf("FAILED\n");
    else printf("PASSED\n");
}


void or(int r1, int r2, int r3, int val, operands_t operands, inst_t inst, char o3[])
{
    #include "or.h"
}

void test_or_rrr() 
{ 
    int r1 = 0;
    int r2 = 1;
    int r3 = 2;
    int val = 0;
    char o3[] = "#3"; 
    idx = 0;
    operands_t operands = O_RRR;
    inst_t inst;
    inst.ccode = CC_;

    int pass = 0;

    or(r1, r2, r3, val, operands, inst, o3);

    printf("OR R0, R1, R2: ");
    pass += test_output[0]==0x907F;
    pass += test_output[1]==0x94BF;
    pass += test_output[2]==0x5002;
    pass += test_output[3]==0x94BF;
    pass += test_output[4]==0x903F;

    if (pass < 5) printf("FAILED\n");
    else printf("PASSED\n");
}


void test_or_rri() 
{ 
    int r1 = 0;
    int r2 = 1;
    int r3 = 2;
    int val = 0;
    char o3[] = "#3"; 
    idx = 0;
    operands_t operands = O_RRI;
    inst_t inst;
    inst.ccode = CC_;

    int pass = 0;

    or(r1, r2, r3, val, operands, inst, o3);

    printf("OR R0, R1, #3: ");
    pass += test_output[0]==0x907F;
    pass += test_output[1]==0x503C;
    pass += test_output[2]==0x903F;

    if (pass < 3) printf("FAILED\n");
    else printf("PASSED\n");
}

void zer(int r1, int r2, int r3, int val, operands_t operands, inst_t inst, char o3[])
{
    #include "zer.h"
}

void test_zer()
{
    int r1 = 0;
    int r2 = 1;
    int r3 = 2;
    int val = 0;
    char o3[] = "#3";
    idx = 0;
    operands_t operands = O_RRR;
    inst_t inst;
    inst.ccode = CC_;

    int pass = 0;

    zer(r1, r2, r3, val, operands, inst, o3);

    printf("ZER: ");
    pass += test_output[0]==0x5020;
    pass += test_output[1]==0x5260;
    pass += test_output[2]==0x54A0;
    pass += test_output[3]==0x56E0;
    pass += test_output[4]==0x5920;
    pass += test_output[5]==0x5B60;
    pass += test_output[6]==0x5DA0;
    pass += test_output[7]==0x5FE0;

    if (pass < 8) printf("FAILED\n");
    else printf("PASSED\n");
}

void sq(int r1, int r2, int r3, int val, operands_t operands, inst_t inst, char o3[])
{
    #include "sq.h"
}

void test_sq_rr()
{
    int r1 = 0;
    int r2 = 1;
    int r3 = 2;
    int val = 0;
    char o3[] = "#3"; 
    idx = 0;
    operands_t operands = O_RRR;
    inst_t inst;
    inst.ccode = CC_;

    int pass = 0;
     
    sq(r1, r2, r3, val, operands, inst, o3);

    printf("MLT R0, R1, R2: ");
    pass += test_output[0]==0x3401;
    pass += test_output[1]==0x0E01;
    pass += test_output[2]==0x0000;
    pass += test_output[3]==0x3601;
    pass += test_output[4]==0x0E01;
    pass += test_output[5]==0x0000;
    pass += test_output[6]==0x3801;
    pass += test_output[7]==0x0E01;
    pass += test_output[8]==0x0000;
    pass += test_output[9]==0x54A0;
    pass += test_output[10]==0x1481;
    pass += test_output[11]==0x0414;
    pass += test_output[12]==0x56E0;
    pass += test_output[13]==0x16C1;
    pass += test_output[14]==0x0411;
    pass += test_output[15]==0x5920;
    pass += test_output[16]==0x14A0;
    pass += test_output[17]==0x0205; 
    pass += test_output[18]==0x94BF; 
    pass += test_output[19]==0x14A1;
    pass += test_output[20]==0x16E0;
    pass += test_output[21]==0x0602; 
    pass += test_output[22]==0x1921; 
    pass += test_output[23]==0x5020;
    pass += test_output[24]==0x1003;
    pass += test_output[25]==0x14BF;
    pass += test_output[26]==0x03FD;
    pass += test_output[27]==0x1920;
    pass += test_output[28]==0x0C02;
    pass += test_output[29]==0x903F;
    pass += test_output[30]==0x1021;
    pass += test_output[31]==0x0E01;
    pass += test_output[32]==0x5020;
    pass += test_output[33]==0x25E0;
    pass += test_output[34]==0x27E2;
    pass += test_output[35]==0x29E4;

    if (pass < 36) printf("FAILED\n");
    else printf("PASSED\n");
}

//simplified write_value for testing purposes
void write_value (int val)
{
    test_output[idx] = val;
    idx++;
}

// simplified read_val for testing purposes
int read_val(const char* s, int* vptr, int bits) {
    char* trash;
    long v;

    if (*s == 'x' || *s == 'X')
	v = strtol (s + 1, &trash, 16);
    else {
	if (*s == '#')
	    s++;
	v = strtol (s, &trash, 10);
    }
    if (0x10000 > v && 0x8000 <= v)
        v |= -65536L;   /* handles 64-bit longs properly */
    if (v < -(1L << (bits - 1)) || v >= (1L << bits)) {
	return -1;
    }
    if ((v & (1UL << (bits - 1))) != 0)
	v |= ~((1UL << bits) - 1);
    *vptr = v;
    return 0;
}



int main(void) 
{
    test_rst();
    test_sub_rrr();
    test_sub_rri();
    test_mlt_rrr();
    test_mlt_rri();
    test_or_rrr();
    test_or_rri();
    test_zer();
    test_sq_rr();

    //LRM CAN'T BE TESTED BECAUSE IT INVOLVES RANDOM NUMBERS
}