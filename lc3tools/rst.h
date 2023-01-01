/* RESET: resets specified register to 0 */

write_value (0x5020 | (r1 << 9) | (r1 << 6) | (0 & 0x1F)); //and r1, r1, #0
