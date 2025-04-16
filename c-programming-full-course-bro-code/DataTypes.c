#include <stdbool.h>

int main(){

    char a = 'C'; // single charactor  %c
    char b[] = "Bro"; // array of charactor  %s

    float c = 3.141592; // 4 bytes (32 bits of precision) 6-7 digits  %f
    double d = 3.141592653589793; // 8 bytes (64 bits of precision) 15-16 digits  %lf

    bool e = true; // 1 byte (true or false)  %d

    char f = 100; // 1 byte (-128 to +127)  %d or %c, actually uses an integer to refer to a certain charactor according to ASCII
    unsigned char g = 255; // 1 byte (0 to +255)  %d or %c, actually uses 0 and positive integers to refer to the charactors as the last line does

    short int h = 32767; // 2 bytes (-32768 to +32767)  %d
    unsigned short int i = 65535; // 2 bytes (0 to +65535)  %d

    int j = 2147483647; // 4 bytes (-2147483648 to +2147483647)  %d
    unsigned int k = 4294967295; // 4 bytes (0 to +4294967295)  %u

    long long int l = 9223372036854775807; // 8 bytes (-9 quintillion to +9 quintillion)  %lld
    unsigned long long int m = 18446744073709551615; // 8 bytes (0 to +18 quintillion)  %llu
}