/* ZERO: zero out all eight registers */
for (int i=0; i<8; i++)
    write_value (0x5020 | (i << 9) | (i << 6) | (0 & 0x1F));