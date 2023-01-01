/* OR: Bitwise or, supports RRR and RRI formats 
   OR R0, R1, R2 ; R0 <- R1 | R2 
   OR R0, R1, #4 ; R0 <- R1 | 4 
   Relies on De Morgan's Law: A OR B = NOT(NOT(A) AND NOT(B)) */

if (operands == O_RRI) 
{
    /* Check or read immediate range (error in first pass
    prevents execution of second, so never fails). */
    (void)read_val (o3, &val, 5);
    val = ~val; //negates val
    write_value (0x903F | (r1 << 9) | (r2 << 6)); //not r1, r2
    write_value (0x5020 | (r1 << 9) | (r1 << 6) | (val & 0x1F)); //and r1, r1, val
    write_value (0x903F | (r1 << 9) | (r1 << 6)); //not r1, r1
} 
else if (r1 == r3) 
{ 
    write_value (0x903F | (r1 << 9) | (r1 << 6)); //not r1, r1
    write_value (0x903F | (r2 << 9) | (r2 << 6)); //not r2, r2
    write_value (0x5000 | (r1 << 9) | (r1 << 6) | r2); //and r1, r1, r2
    //change r2 back to orig value 
    write_value (0x903F | (r2 << 9) | (r2 << 6)); //not r2, r2
    //last step of or
    write_value (0x903F | (r1 << 9) | (r1 << 6)); //not r1, r1
}
else 
{ 
    write_value (0x903F | (r1 << 9) | (r2 << 6)); //not r1, r2
    write_value (0x903F | (r3 << 9) | (r3 << 6)); //not r3, r3
    write_value (0x5000 | (r1 << 9) | (r1 << 6) | r3); //and r1, r1, r3
    //change r3 back to orig value (r2 is unaffected)
    write_value (0x903F | (r3 << 9) | (r3 << 6)); //not r3, r3
    //last step of or 
    write_value (0x903F | (r1 << 9) | (r1 << 6)); //not r1, r1
}