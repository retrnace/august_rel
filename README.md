# august coding challenge 

You have an array of 3 bytes integers in memory, like the following:

0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00

The sequence above represents 3 numbers:

0x010203
0x040506
0x000000

The format is big endian.

The assignment is to write some C code that takes a pointer to such a sequence of
3-bytes integers and returns the sum of all of them.
The sequence is always terminated with three consecutive zeros.

The function has to take a generic pointer in memory.

I expect you to code this in C, compile it and prove somehow that it works.
The input vector I provided can be used for testing but obviously the routine has
to work for arbitrary lengths.

