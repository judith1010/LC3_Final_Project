
if (operands == O_RRI) 
{
    /* Check or read immediate range (error in first pass 
    prevents execution of second, so never fails). */
    (void)read_val (o3, &val, 5);

    int temp;
    for (int i=0; i<7; i++){
        if (i != r1 && i != r2){
            temp = i;
            break; 
        }
    }

    write_value (0x3000 | (temp << 9) | (0x1 & 0x1FF));  // ST temp, #1 
    write_value (inst.ccode | (0xE01));                    // BR nzp 1
    write_value (0x000); //stored value of temp in this line in assembly 
    int lines = 2;

    if (val < 0)
    {
        write_value (0x5020 | (r1 << 9) | (r1 << 6) | (0 & 0x1F));
        lines++;
        write_value (0x903F | (r2 << 9) | (r2 << 6));  
        lines++;
        write_value (0x1020 | (r2 << 9) | (r2 << 6) | (1 & 0x1F));
        lines++;
        for (int i=0; i < abs(val); i++)
        {
            write_value (0x1000 | (r1 << 9) | (r1 << 6) | r2);
            lines++;
        }
        if (r1 != r2) //change r2 back to original value only if that's not where the result is stored
        {
            write_value (0x903F | (r2 << 9) | (r2 << 6));
            lines++;  
            write_value (0x1020 | (r2 << 9) | (r2 << 6) | (1 & 0x1F));
            lines++;
            write_value (0x1020 | (r1 << 9) | (r1 << 6) | (0 & 0x1F)); //set cc appropriately
            lines++;
        }  
    }
    else{
        write_value (0x5020 | (r1 << 9) | (r1 << 6) | (0 & 0x1F));
        lines++;
        for (int i=0; i < val; i++)
        {
            write_value (0x1000 | (r1 << 9) | (r1 << 6) | r2);
            lines++;
        }
    }
    write_value (0x2000 | (temp << 9) | (-lines & 0x1FF));        //restore temp
} 
else
{
    int temp1;
    for (int i=0; i<8; i++){
        if (i != r1 && i != r2 && i != r3)
        {
            temp1 = i;
            break;
        }
    } 
    int temp2;
    for (int i=0; i<8; i++){
        if (i != r1 && i != r2 && i != r3 && i != temp1)
        {
            temp2 = i;
            break;
        }
    }
    int temp3;
    for (int i=0; i<8; i++){
        if (i != r1 && i != r2 && i != r3 && i != temp1 && i != temp2)
        {
            temp3 = i;
            break;
        }
    }
    write_value (0x3000 | (temp1 << 9) | (0x1 & 0x1FF));  // ST temp1, #1 
    write_value (inst.ccode | (0xE01));                    // BR nzp 1
    write_value (0x000); //stored value of temp1 in this line in assembly 
    write_value (0x3000 | (temp2 << 9) | (0x1 & 0x1FF));  // ST temp2, #1 
    write_value (inst.ccode | (0xE01));                    // BR nzp 1
    write_value (0x000); //stored value of temp2 in this line in assembly 
    write_value (0x3000 | (temp3 << 9) | (0x1 & 0x1FF));  // ST temp3, #1 
    write_value (inst.ccode | (0xE01));                    // BR nzp 1
    write_value (0x000); //stored value of temp3 in this line in assembly 
    write_value (0x5020 | (temp1 << 9) | (temp1 << 6) | (0 & 0x1F)); // and temp1 0
    write_value (0x1000 | (temp1 << 9) | (temp1 << 6) | r2);  // add temp1, temp1, r2
    write_value (inst.ccode | (0x0414));                         // brz to end 
    write_value (0x5020 | (temp2 << 9) | (temp2 << 6) | (0 & 0x1F)); // and temp2 0
    write_value (0x1000 | (temp2 << 9) | (temp2 << 6) | r3);  // add temp2, temp2, r3
    write_value (inst.ccode | (0x0411));                        // brz to end 
    write_value (0x5020 | (temp3 << 9) | (temp3 << 6) | (0 & 0x1F)); // and temp3 0
    write_value (0x1020 | (temp1 << 9) | (temp1 << 6) | (0 & 0x1F));  // add temp1, temp1, #0
    write_value (inst.ccode | (0x205));                         // brp 5  
    write_value (0x903F | (temp1 << 9) | (temp1 << 6));       // not temp1 
    write_value (0x1020 | (temp1 << 9) | (temp1 << 6) | (1 & 0x1F));  // add temp1, temp1, #1
    write_value (0x1020 | (temp2 << 9) | (temp2 << 6) | (0 & 0x1F));  // add temp2, temp2, #0
    write_value (inst.ccode | (0x602));                         // brzp 2 
    write_value (0x1020 | (temp3 << 9) | (temp3 << 6) | (1 & 0x1F));  // add temp3, temp3, #1
    write_value (0x5020 | (r1 << 9) | (r1 << 6) | (0 & 0x1F));  // r1 = 0
    write_value (0x1000 | (r1 << 9) | (r1 << 6) | temp2);          // add r1 r1 temp2 
    write_value (0x1020 | (temp1 << 9) | (temp1 << 6) | (-1 & 0x1F));  // add temp1 temp1 #-1
    write_value (inst.ccode | (0x3FD));                         // brp #-3 
    write_value (0x1020 | (temp3 << 9) | (temp3 << 6) | (0 & 0x1F));  // add temp3, temp3, #0
    write_value (inst.ccode | (0xC02));                         // brnz 2 
    write_value (0x903F | (r1 << 9) | (r1 << 6));       // not r1 
    write_value (0x1020 | (r1 << 9) | (r1 << 6) | (1 & 0x1F));  // add r1, r1, #1
    write_value (inst.ccode | (0xE01));                    // BR nzp 1
    write_value (0x5020 | (r1 << 9) | (r1 << 6) | (0 & 0x1F));  // r1 = 0
    write_value (0x2000 | (temp1 << 9) | (-32 & 0x1FF));        //restore temp1
    write_value (0x2000 | (temp2 << 9) | (-30 & 0x1FF));        //restore temp2
    write_value (0x2000 | (temp3 << 9) | (-28 & 0x1FF));        //restore temp3
}