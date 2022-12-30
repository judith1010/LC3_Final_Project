/* LOAD RANDOM MEMORY: load the specified register 
   with the contents of a random memoey address */ 

srand(time(NULL));
int r = rand() % 512;
r -= 256;

write_value (0x2000 | (r1 << 9) | (r & 0x1FF));