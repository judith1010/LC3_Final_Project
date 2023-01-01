#include <stdio.h>

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
    // opcode_t op;
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
    
    reset(r1);
    
    printf("TEST\nRST R0 TEST");
    printf("Line %d: %d\n", 0, test_output[0]==0x5020); //FIX ME
    printf("END TEST\n\n");
}

void subtract(int r1, int r2, int r3, int val, operands_t operands, inst_t inst, char o3[]) {
    #include "sub.h"
}

void test_sub_rrr() { 
    int r1 = 0;
    int r2 = 1;
    int r3 = 2;
    int val = 0;
    char o3[] = "#3"; //CHANGE ME
    idx = 0;
    operands_t operands = O_RRR;
    inst_t inst;
    inst.ccode = CC_;

    subtract(r1, r2, r3, val, operands, inst, o3);

    printf("TEST\nSUB R0, R1, R2\n");
    printf("Line %d: %d\n", 0, test_output[0]==0x94BF); 
    printf("Line %d: %d\n", 1, test_output[1]==0x14A1); 
    printf("Line %d: %d\n", 2, test_output[2]==0x1042); 
    printf("Line %d: %d\n", 3, test_output[3]==0x94BF); 
    printf("Line %d: %d\n", 4, test_output[4]==0x14A1); 
    printf("Line %d: %d\n", 5, test_output[5]==0x1020); 
    printf("END TEST\n\n");
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

    subtract(r1, r2, r3, val, operands, inst, o3);

    printf("TEST\nSUB R0, R1, #3\n");
    printf("Line %d: %d\n", 0, test_output[0]==0x107D); 
    printf("END TEST\n\n");
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
     
    multiply(r1, r2, r3, val, operands, inst, o3);

    printf("TEST\nMLT R0, R1, R2\n");
    printf("Line %d: %d\n", 0, test_output[0]==0x3601);
    printf("Line %d: %d\n", 1, test_output[1]==0x0E01);
    printf("Line %d: %d\n", 2, test_output[2]==0x0000);
    printf("Line %d: %d\n", 3, test_output[3]==0x3801);
    printf("Line %d: %d\n", 4, test_output[4]==0x0E01);
    printf("Line %d: %d\n", 5, test_output[5]==0x0000);
    printf("Line %d: %d\n", 6, test_output[6]==0x3A01);
    printf("Line %d: %d\n", 7, test_output[7]==0x0E01);
    printf("Line %d: %d\n", 8, test_output[8]==0x0000);
    printf("Line %d: %d\n", 9, test_output[9]==0x56E0);
    printf("Line %d: %d\n", 10, test_output[10]==0x16C1);
    printf("Line %d: %d\n", 11, test_output[11]==0x0414);
    printf("Line %d: %d\n", 12, test_output[12]==0x5920);
    printf("Line %d: %d\n", 13, test_output[13]==0x1902);
    printf("Line %d: %d\n", 14, test_output[14]==0x0411);
    printf("Line %d: %d\n", 15, test_output[15]==0x5B60);
    printf("Line %d: %d\n", 16, test_output[16]==0x16E0);
    printf("Line %d: %d\n", 17, test_output[17]==0x0205);
    printf("Line %d: %d\n", 18, test_output[18]==0x96FF);
    printf("Line %d: %d\n", 19, test_output[19]==0x16E1);
    printf("Line %d: %d\n", 20, test_output[20]==0x1920);
    printf("Line %d: %d\n", 21, test_output[21]==0x0602);
    printf("Line %d: %d\n", 22, test_output[22]==0x1B61);
    printf("Line %d: %d\n", 23, test_output[23]==0x5020);
    printf("Line %d: %d\n", 24, test_output[24]==0x1004);
    printf("Line %d: %d\n", 25, test_output[25]==0x16FF);
    printf("Line %d: %d\n", 26, test_output[26]==0x03FD);
    printf("Line %d: %d\n", 27, test_output[27]==0x1B60);
    printf("Line %d: %d\n", 28, test_output[28]==0x0C02);
    printf("Line %d: %d\n", 29, test_output[29]==0x903F);
    printf("Line %d: %d\n", 30, test_output[30]==0x1021);
    printf("Line %d: %d\n", 31, test_output[31]==0x0E01);
    printf("Line %d: %d\n", 32, test_output[32]==0x5020);
    printf("Line %d: %d\n", 33, test_output[33]==0x27E0);
    printf("Line %d: %d\n", 34, test_output[34]==0x29E2);
    printf("Line %d: %d\n", 35, test_output[35]==0x2BE4);
    printf("END TEST\n\n");
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
     
    multiply(r1, r2, r3, val, operands, inst, o3);

    printf("TEST\nMLT R0, R1, #3\n");
    printf("Line %d: %d\n", 0, test_output[0]==0x3401);
    printf("Line %d: %d\n", 1, test_output[1]==0x0E01);
    printf("Line %d: %d\n", 2, test_output[2]==0x0000);
    printf("Line %d: %d\n", 3, test_output[3]==0x5020);
    printf("Line %d: %d\n", 4, test_output[4]==0x1001);
    printf("Line %d: %d\n", 5, test_output[5]==0x1001);
    printf("Line %d: %d\n", 6, test_output[6]==0x1001);
    printf("Line %d: %d\n", 7, test_output[7]==0x25FA);
    printf("END TEST\n\n");
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

    or(r1, r2, r3, val, operands, inst, o3);

    printf("TEST\nOR R0, R1, R2\n");
    printf("Line %d: %d\n", 0, test_output[0]==0x907F); 
    printf("Line %d: %d\n", 1, test_output[1]==0x94BF); 
    printf("Line %d: %d\n", 2, test_output[2]==0x5002); 
    printf("Line %d: %d\n", 3, test_output[3]==0x94BF); 
    printf("Line %d: %d\n", 4, test_output[4]==0x903F); 
    printf("END TEST\n\n");
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

    or(r1, r2, r3, val, operands, inst, o3);

    printf("TEST\nOR R0, R1, #3\n");
    printf("Line %d: %d\n", 0, test_output[0]==0x907F); 
    printf("Line %d: %d\n", 1, test_output[1]==0x503C); 
    printf("Line %d: %d\n", 2, test_output[2]==0x903F); 
    printf("END TEST\n\n");
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

    zer(r1, r2, r3, val, operands, inst, o3);

    printf("TEST\nZER\n");
    printf("Line %d: %d\n", 0, test_output[0]==0x5020); 
    printf("Line %d: %d\n", 1, test_output[1]==0x5260); 
    printf("Line %d: %d\n", 2, test_output[2]==0x54A0); 
    printf("Line %d: %d\n", 3, test_output[3]==0x56E0); 
    printf("Line %d: %d\n", 4, test_output[4]==0x5920); 
    printf("Line %d: %d\n", 5, test_output[5]==0x5B60); 
    printf("Line %d: %d\n", 6, test_output[6]==0x5DA0); 
    printf("Line %d: %d\n", 7, test_output[7]==0x5FE0); 
    printf("END TEST\n\n");
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
     
    sq(r1, r2, r3, val, operands, inst, o3);

    printf("TEST\nSQ R0, R1\n");
    printf("Line %d: %d\n", 0, test_output[0]==0x3401);
    printf("Line %d: %d\n", 1, test_output[1]==0x0E01);
    printf("Line %d: %d\n", 2, test_output[2]==0x0000);
    printf("Line %d: %d\n", 3, test_output[3]==0x3601);
    printf("Line %d: %d\n", 4, test_output[4]==0x0E01);
    printf("Line %d: %d\n", 5, test_output[5]==0x0000);
    printf("Line %d: %d\n", 6, test_output[6]==0x3801);
    printf("Line %d: %d\n", 7, test_output[7]==0x0E01);
    printf("Line %d: %d\n", 8, test_output[8]==0x0000);
    printf("Line %d: %d\n", 9, test_output[9]==0x54A0);
    printf("Line %d: %d\n", 10, test_output[10]==0x1481);
    printf("Line %d: %d\n", 11, test_output[11]==0x0414);
    printf("Line %d: %d\n", 12, test_output[12]==0x56E0);
    printf("Line %d: %d\n", 13, test_output[13]==0x16C1);
    printf("Line %d: %d\n", 14, test_output[14]==0x0411);
    printf("Line %d: %d\n", 15, test_output[15]==0x5920);
    printf("Line %d: %d\n", 16, test_output[16]==0x14A0);
    printf("Line %d: %d\n", 17, test_output[17]==0x0205);
    printf("Line %d: %d\n", 18, test_output[18]==0x94BF);
    printf("Line %d: %d\n", 19, test_output[19]==0x14A1);
    printf("Line %d: %d\n", 20, test_output[20]==0x16E0);
    printf("Line %d: %d\n", 21, test_output[21]==0x0602);
    printf("Line %d: %d\n", 22, test_output[22]==0x1921);
    printf("Line %d: %d\n", 23, test_output[23]==0x5020);
    printf("Line %d: %d\n", 24, test_output[24]==0x1003);
    printf("Line %d: %d\n", 25, test_output[25]==0x14BF);
    printf("Line %d: %d\n", 26, test_output[26]==0x03FD);
    printf("Line %d: %d\n", 27, test_output[27]==0x1920);
    printf("Line %d: %d\n", 28, test_output[28]==0x0C02);
    printf("Line %d: %d\n", 29, test_output[29]==0x903F);
    printf("Line %d: %d\n", 30, test_output[30]==0x1021);
    printf("Line %d: %d\n", 31, test_output[31]==0x0E01);
    printf("Line %d: %d\n", 32, test_output[32]==0x5020);
    printf("Line %d: %d\n", 33, test_output[33]==0x25E0);
    printf("Line %d: %d\n", 34, test_output[34]==0x27E2);
    printf("Line %d: %d\n", 35, test_output[35]==0x29E4);
    printf("END TEST\n\n");
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

    //LRM CAN'T BE TESTED B/C IT INVOLVES RANDOM NUMBERS
}