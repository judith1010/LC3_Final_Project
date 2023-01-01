/* LOAD RANDOM MEMORY: load the specified register 
   with the contents of a random memoey address

   ** Because the random PC offset is generated at compile time, 
   returning to this intruction via branching will yield the 
   exact same instruction every time. To get a new random memory 
   location the program must be recompiled. */ 

srand(clock());
int r = rand() % 512;
//make sure r is between -256 and 255 to be a pc offset
r -= 256;

write_value (0x2000 | (r1 << 9) | (r & 0x1FF));     //LD r1 r 