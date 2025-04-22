/* 
Big Endian and Little Endian
While we are on the topic of memory, it's worth knowing about "endianness". Endianness is the order in which bytes are stored in memory. The two most common formats are big endian and little endian.

Big Endian
In a big-endian system, the most significant byte is stored first, at the lowest memory address. The "most significant byte" is just a fancy way of saying "the biggest part of the number".

Let’s say you have the hexadecimal number 0x12345678. Here’s how it would be stored in big-endian format:

<-lower address || higher address->
        0x12 0x34 0x56 0x78
most significant || least significant
The most significant byte (0x12) is stored at the lowest memory address.

Little Endian
In a little-endian system, the least significant byte (the "smallest" part of the number) is stored first, at the lowest memory address. This is the format used by most modern computers.

Using the same number 0x12345678, here’s how it would be stored in little-endian format:

<-lower address || higher address->
        0x78 0x56 0x34 0x12
least significant || most significant 
Here, the least significant byte (0x78) is stored first.

*/