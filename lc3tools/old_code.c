
//SQ
int temp1;
for (int i=0; i<8; i++){
    if (i != r1 && i != r2)
    {
        temp1 = i;
        break;
    }
} 
int temp2;
for (int i=0; i<8; i++){
    if (i != r1 && i != r2 && i != temp1)
    {
        temp2 = i;
        break;
    }
}
write_value (0x3000 | (temp1 << 9) | (0x1 & 0x1FF));  // ST temp1, #1 
write_value (inst.ccode | (0xE01));                    // BR nzp 1
write_value (0x0C0); //stored value of temp1 in this line in assembly 
write_value (0x3000 | (temp2 << 9) | (0x1 & 0x1FF));  // ST temp2, #1 
write_value (inst.ccode | (0xE01));                    // BR nzp 1
write_value (0x0C0); //stored value of temp2 in this line in assembly 
write_value (0x5020 | (temp1 << 9) | (temp1 << 6) | (0 & 0x1F)); // and temp1 0
write_value (0x1000 | (temp1 << 9) | (temp1 << 6) | r2);  // add temp1, temp1, r2
write_value (0x5020 | (temp2 << 9) | (temp2 << 6) | (0 & 0x1F)); // and temp2 0
write_value (0x1000 | (temp2 << 9) | (temp2 << 6) | r2);  // add temp2, temp2, r2
write_value (0x1020 | (temp1 << 9) | (temp1 << 6) | (0 & 0x1F));  // add temp1, temp1, #0
write_value (inst.ccode | (0x602));                         // brzp 2  
write_value (0x903F | (temp1 << 9) | (temp1 << 6));       // not temp1 
write_value (0x1020 | (temp1 << 9) | (temp1 << 6) | (1 & 0x1F));  // add temp1, temp1, #1
write_value (0x5020 | (r1 << 9) | (r1 << 6) | (0 & 0x1F));  // r1 = 0
write_value (0x1000 | (r1 << 9) | (r1 << 6) | temp2);          // add r1 r1 r2 
write_value (0x1020 | (temp1 << 9) | (temp1 << 6) | (-1 & 0x1F));  // add temp_r temp_r #-1
write_value (inst.ccode | (0x3FD));                         // brp #-2 (-3) 
write_value (0x1020 | (r1 << 9) | (r1 << 6) | (0 & 0x1F));  // add r1 r1 0 
//make sure square result is positive
write_value (inst.ccode | (0x602));                         // brzp 2 
write_value (0x903F | (r1 << 9) | (r1 << 6));               // not r1 r1 
write_value (0x1020 | (r1 << 9) | (r1 << 6) | (1 & 0x1F));  // add r1 r1 #1 
write_value (0x2000 | (temp1 << 9) | (-21 & 0x1FF));        //restore temp1
write_value (0x2000 | (temp2 << 9) | (-19 & 0x1FF));        //restore temp2