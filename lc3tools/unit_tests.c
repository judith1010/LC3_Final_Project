#include <stdio.h>

int inst_out[250];
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
    idx = 0;
    #include "reset.h"
}

void test_rst() {
    int r1 = 0;
    
    reset(r1);
    
    printf("RST R0 TEST\n");
    printf("Line %d: %d\n", 0, inst_out[0]==0x5260); //FIX ME
    printf("END TEST\n");
}

void subtract(int r1, int r2, int r3) {
    idx = 0;
    #include "sub.h"
}

void test_sub_rrr() { 
    int r1 = 0;
    int r2 = 1;
    int r3 = 2;
    operands_t operand = O_RRR;
    subtract(r1, r2, r3);

    printf("SUB R0, R1, R2 TEST\n");
    printf("Line %d: %d\n", 0, inst_out[0]==0x92FF); //FIX ME
    printf("Line %d: %d\n", 1, inst_out[1]==0x1261); //FIX ME
    printf("Line %d: %d\n", 2, inst_out[2]==0x1242); //FIX ME
    printf("END TEST\n");
}

void multiply(int r1, int r2, int r3, int val, operands_t operands, inst_t inst, char o3[]) {
    idx = 0;
    #include "mlt.h"
}

void test_mlt_rrr() {
    int r1 = 1;
    int r2 = 2;
    int r3 = 3;
    int val = 0;
    char o3[] = "#2"; //CHANGE ME

    operands_t operands = O_RRR;

    inst_t inst;
    inst.ccode = CC_;
     
    multiply(r1, r2, r3, val, operands, inst, o3);

    //FIX ALL OF THIS TO MATCH YOUR MLT
    printf("MLT R0, R1, R2 TEST\n");
    printf("Line %d: %d\n", 0, inst_out[0]==0x3002);
    printf("Line %d: %d\n", 1, inst_out[1]==0x3802);
    printf("Line %d: %d\n", 2, inst_out[2]==0x0E02);
    printf("Line %d: %d\n", 3, inst_out[3]==0x0000);
    printf("Line %d: %d\n", 4, inst_out[4]==0x0000);
    printf("Line %d: %d\n", 5, inst_out[5]==0x10A0);
    printf("Line %d: %d\n", 6, inst_out[6]==0x18E0);
    printf("Line %d: %d\n", 7, inst_out[7]==0x5260);
    printf("Line %d: %d\n", 8, inst_out[8]==0x1020);
    printf("Line %d: %d\n", 9, inst_out[9]==0x040A);
    printf("Line %d:: %d\n", 10, inst_out[10]==0x1920);
    printf("Line %d: %d\n", 11, inst_out[11]==0x0408);
    printf("Line %d: %d\n", 12, inst_out[12]==0x0204);
    printf("Line %d: %d\n", 13, inst_out[13]==0x993F);
    printf("Line %d: %d\n", 14, inst_out[14]==0x1921);
    printf("Line %d: %d\n", 15, inst_out[15]==0x903F);
    printf("Line %d: %d\n", 16, inst_out[16]==0x1021);
    printf("Line %d: %d\n", 17, inst_out[17]==0x1240);
    printf("Line %d: %d\n", 18, inst_out[18]==0x193F);
    printf("Line %d: %d\n", 19, inst_out[19]==0x03FD);
    printf("Line %d: %d\n", 20, inst_out[20]==0x21EE);
    printf("Line %d: %d\n", 21, inst_out[21]==0x29EE);
    printf("Line %d: %d\n", 22, inst_out[22]==0x1260);
    printf("END TEST\n");
}



//simplified write_value for testing purposes
void write_value (int val)
{
    inst_out[idx] = val;
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



int main(void) {
    test_mlt_rrr();
}