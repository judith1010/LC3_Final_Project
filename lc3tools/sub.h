/* SUBTRACTION: Subtracts two numbers, supports RRR and RRI formats
   SUB R0, R1, R2 ; R0 <- R1 - R2
   SUB R0, R1, #2 ; R0 <- R1 - 2 */

if (operands == O_RRI) 
{
    /* Check or read immediate range (error in first pass
    prevents execution of second, so never fails). */
    (void)read_val (o3, &val, 5);
    val *= -1; //negate the operand to be subtracted
    write_value (0x1020 | (r1 << 9) | (r2 << 6) | (val & 0x1F)); //add r1, r2, val
} 
else if (r2 == r3) //if being subtracted from self, answer is 0
{           
   write_value (0x5020 | (r1 << 9) | (r1 << 6) | (0 & 0x1F)); //and r1, r1, o
} 
else
{
    write_value (0x903F | (r3 << 9) | (r3 << 6)); //not r3, r3
    write_value (0x1020 | (r3 << 9) | (r3 << 6) | (1 & 0x1F)); //add, r3, r3, #1
    write_value (0x1000 | (r1 << 9) | (r2 << 6) | r3); //add r1, r2, r3

    //change r3 back to original value only if that's not where the result is stored
    if (r1 != r3) 
    {
        write_value (0x903F | (r3 << 9) | (r3 << 6));  //not r3, r3
        write_value (0x1020 | (r3 << 9) | (r3 << 6) | (1 & 0x1F)); //add, r3, r3, #1
        //set cc appropriately 
        write_value (0x1020 | (r1 << 9) | (r1 << 6) | (0 & 0x1F)); //add r1, r1, 0
    }
}
        