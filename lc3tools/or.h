if (operands == O_RRI) 
{
    /* Check or read immediate range (error in first pass
    prevents execution of second, so never fails). */
    (void)read_val (o3, &val, 5);
    val = ~val;
    write_value (0x903F | (r1 << 9) | (r2 << 6));
    write_value (0x5020 | (r1 << 9) | (r1 << 6) | (val & 0x1F));
    write_value (0x903F | (r1 << 9) | (r1 << 6));
} 
else if (r1 == r3) 
{ 
    write_value (0x903F | (r1 << 9) | (r1 << 6)); 
    write_value (0x903F | (r2 << 9) | (r2 << 6));
    write_value (0x5000 | (r1 << 9) | (r1 << 6) | r2);
    write_value (0x903F | (r2 << 9) | (r2 << 6)); //change r2 back to orig value
    write_value (0x903F | (r1 << 9) | (r1 << 6));
}
else 
{ 
    write_value (0x903F | (r1 << 9) | (r2 << 6)); 
    write_value (0x903F | (r3 << 9) | (r3 << 6));
    write_value (0x5000 | (r1 << 9) | (r1 << 6) | r3);
    write_value (0x903F | (r3 << 9) | (r3 << 6)); //change r3 back to orig value
    write_value (0x903F | (r1 << 9) | (r1 << 6));
}