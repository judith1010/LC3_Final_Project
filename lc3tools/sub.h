if (operands == O_RRI) 
{
    /* Check or read immediate range (error in first pass
    prevents execution of second, so never fails). */
    (void)read_val (o3, &val, 5);
    val *= -1; //negate the operand to be subtracted
    write_value (0x1020 | (r1 << 9) | (r2 << 6) | (val & 0x1F));
} 
else if (r2 == r3) //if being subtracted from self
{           
    int temp;
    for (int i=0; i<8; i++){
        if (i != r1 && i != r2)
        {
            temp = i;
            break;
        }
    } 
    write_value (0x3000 | (temp << 9) | (0x1 & 0x1FF));  // ST temp, #1 
    write_value (inst.ccode | (0xE01));                    // BR nzp 1
    write_value (0x0C0); //stored value of temp1 in this line in assembly
    write_value (0x5020 | (temp << 9) | (temp << 6) | (0 & 0x1F)); // and temp 0
    write_value (0x1000 | (temp << 9) | (temp << 6) | r2);  // add temp, temp, r2
    write_value (0x903F | (temp << 9) | (temp << 6)); //negate temp
    write_value (0x1020 | (temp << 9) | (temp << 6) | (1 & 0x1F));
    write_value (0x1000 | (r1 << 9) | (r2 << 6) | temp); //subtract
    write_value (0x2000 | (temp << 9) | (-7 & 0x1FF));        //restore temp
} 
else
{
    write_value (0x903F | (r3 << 9) | (r3 << 6)); //negate the operand to be subtracted
    write_value (0x1020 | (r3 << 9) | (r3 << 6) | (1 & 0x1F));
    write_value (0x1000 | (r1 << 9) | (r2 << 6) | r3); //subtract
    if (r1 != r3) //change r3 back to original value only if that's not where the result is stored
    {
        write_value (0x903F | (r3 << 9) | (r3 << 6));  
        write_value (0x1020 | (r3 << 9) | (r3 << 6) | (1 & 0x1F));
        write_value (0x1020 | (r1 << 9) | (r1 << 6) | (0 & 0x1F)); //set cc appropriately 
    }
}
        