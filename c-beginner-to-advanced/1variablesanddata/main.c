#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(int argc, char** argv)
{
    printf("=====================\n");
    printf("VARIABLE CALCULATIONS\n");
    printf("=====================\n\n");

    float a0 = 5.0f;
    float b0 = 2.0f;
    float c0 = 1.0f;
    // addition
    c0 += a0;
    printf("%f\n", c0);
    // subtraction
    c0 -= a0;
    printf("%f\n", c0);
    // multiplication
    c0 *= a0;
    printf("%f\n", c0);
    // division
    c0 /= a0;
    printf("%f\n", c0);
    b0 = b0 + 1;
    printf("%f\n", b0);
    b0 += 1;
    printf("%f\n", b0);
    b0++; // b = b + 1; equals b += 1; equals b++

    float a5 = 5.0;
    float b5 = 2.0;
    float c5;
    // addition
    c5 = a5 + b5;
    printf("%f\n", c5);
    // subtraction
    c5 = a5 - b5;
    printf("%f\n", c5);
    // multiplication
    c5 = a5 * b5;
    printf("%f\n", c5);
    // division
    c5 = a5 / b5;
    printf("%f\n\n\n", c5);

    printf("=================\n");
    printf("PRIMARY DATATYPES\n");
    printf("=================\n\n");

    // sources: https://en.wikipedia.org/wiki/C_data_types\n")
    //          https://www.tutorialspoint.com/cprogramming/c_data_types.htm\n")
    //          https://www.naukri.com/learning/articles/data-types-in-c-programming-with-examples/\n\n")

    printf("integer types\n");
    printf("-------------\n\n");

    printf("---- char ----\n");
    char character_A = 'A';
    printf("Character: %d\n", character_A);
    printf("Character: %c\n", character_A);
    char character_Z = character_A + 25;
    printf("Character: %d\n", character_Z);
    printf("Character: %c\n", character_Z);
    char character_variable = 'x'; // declaration and initialization is definition
    printf("Variable character_variable %c has size %lu byte\n", character_variable, sizeof(character_variable));
    printf("char range: %d, %d\n\n", CHAR_MIN, CHAR_MAX); // -128 to 127 or 0 to 255

    printf("---- signed char ----\n");
    signed char signed_character_variable = 't'; // equal to char
    printf("Variable signed_character_variable %u has size %lu byte\n", signed_character_variable, sizeof(signed_character_variable));
    printf("signed char range %d, %d\n\n", SCHAR_MIN, SCHAR_MAX); // -127 to 127

    printf("---- unsigned char ----\n");
    unsigned char unsigned_character_variable = 'a';
    printf("Variable unsigned_character_variable %u has size %lu byte\n", unsigned_character_variable, sizeof(unsigned_character_variable));
    printf("unsigned char range %u\n\n", UCHAR_MAX); // 0 to 255

    printf("---- int ----\n");
    int var_integer; // declaration
    var_integer = 3500; // initialization
    printf("Variable var_integer %d has size %lu byte\n", var_integer, sizeof(var_integer));
    printf("int range: %d, %d\n\n", INT_MIN, INT_MAX); // -32768 to 32767 or -2147483648 to 2147483647

    printf("---- long int ----\n");
    long int var_long_int = 280000;
    printf("Variable var_long_int %li has size %lu byte\n", var_long_int, sizeof(var_long_int));
    printf("int range: %d, %d\n\n", INT_MIN, INT_MAX); // -2147483647 to 2147483647

    printf("---- long long int ----\n");
    long long int var_long_long_int_integer = 4000000000000;
    printf("Variable var_long_long_int_integer %lli has size %lu byte\n", var_long_long_int_integer, sizeof(var_long_long_int_integer));
    printf("int range: %lli, %lli\n\n", INT_MIN, INT_MAX); // -(2^63) to (2^63)-1

    printf("---- signed long int ----\n");
    signed long int var_sig_long_int = -21474836;
    printf("Variable var_sig_long_int %u has size %lu byte\n", var_sig_long_int, sizeof(var_sig_long_int));
    printf("unsigned int range: %d\n\n", UINT_MAX); // -2147483647 to 2147483647

    printf("---- unsigned long int ----\n");
    unsigned long int var_unsig_long_int = 65534;
    printf("Variable var_unsig_long_int %lu has size %lu byte\n", var_unsig_long_int, sizeof(var_unsig_long_int));
    printf("unsigned int range: %lu\n\n", UINT_MAX); // 0 to 65535 or 0 to 4294967295

    printf("---- unsigned longlong int ----\n");
    unsigned long long int var_unsig_long_long_int = 294967295;
    printf("Variable var_unsig_long_long_int %llu has size %lu byte\n", var_unsig_long_long_int, sizeof(var_unsig_long_long_int));
    printf("unsigned int range: %d\n\n", UINT_MAX); // 0 to 65535 or 0 to 4294967295

    printf("---- signed int ----\n");
    signed int var_sig_int = 65534;
    printf("Variable var_sig_int %li has size %lu byte\n", var_sig_int, sizeof(var_sig_int));
    printf("unsigned int range: %d\n\n", UINT_MAX); // 0 to 65535 or 0 to 4294967295

    printf("---- unsigned int ----\n");
    unsigned int var_unsig_int = 429496729;
    printf("Variable var_unsig_int %u has size %lu byte\n", var_unsig_int, sizeof(var_unsig_int));
    printf("unsigned int range: %d\n\n", UINT_MAX); // 0 to 65535 or 0 to 4294967295

    printf("---- signed short int ----\n");
    signed short int var_signed_short_int = 655;
    printf("Variable var_signed_short_int %hd has size %lu byte\n", var_signed_short_int, sizeof(var_signed_short_int));
    printf("unsigned int range: %d\n\n", UINT_MAX); // 0 to 65535 or 0 to 4294967295

    printf("---- unsigned short int ----\n");
    unsigned short int var_unsig_short_int = 350;
    printf("Variable var_unsig_short_int %hu has size %lu byte\n", var_unsig_short_int, sizeof(var_unsig_short_int));
    printf("unsigned int range: %d\n\n", UINT_MAX); // 0 to 65535 or 0 to 4294967295

    printf("---- short int ----\n");
    short int short_int_variable = 12500;
    printf("Variable short_int_variable %hd has size %lu byte\n", short_int_variable, sizeof(short_int_variable));
    printf("short int range: %hd, %d\n\n", SHRT_MIN, SHRT_MAX); // -32768 to 32767

    printf("---- short ----\n");
    short short_variable = 12;
    printf("Variable short_variable %d has size %lu byte\n", short_variable, sizeof(short_variable));
    printf("short int range: %d, %d\n\n", SHRT_MIN, SHRT_MAX); // -32768 to 32767

    printf("---- unsigned short ----\n");
    unsigned short unsigned_short_variable = 3456;
    printf("Variable unsigned_short_variable %hu has size %lu byte\n", unsigned_short_variable, sizeof(unsigned_short_variable));
    printf("unsigned short int range: %d\n\n", USHRT_MAX); // 65535

    printf("---- long ----\n");
    long long_variable = 34500;
    printf("Variable long_variable %ll has size %lu byte\n", long_variable, sizeof(long_variable));
    printf("long int range: %d, %d\n\n", LONG_MIN, LONG_MAX); // -9223372036854775808, 9223372036854775807

    printf("---- signed long ----\n");
    signed long signed_long_variable = -244;
    printf("Variable signed_long_variable %llu has size %lu byte\n", signed_long_variable, sizeof(signed_long_variable));
    printf("unsigned long int range: %d, %d\n\n", LONG_MIN, LONG_MAX); // -9223372036854775808, 18446744073709551615

    printf("---- unsigned long ----\n");
    unsigned long unsigned_long_variable = 445;
    printf("Variable unsigned_long_variable %llu has size %lu byte\n", unsigned_long_variable, sizeof(unsigned_long_variable));
    printf("unsigned long int range: %s\n\n", ULONG_MAX); //

    printf("floating point type\n");
    printf("-------------------\n\n");

    printf("---- float ----\n");
    double a2 = 0.3;
    double b2 = 0.2;
    double c2 = a2 - b2;
    double d2 = 0.1;
    printf("a2: %.35lf\n", a2);
    printf("b2: %.35lf\n", b2);
    printf("c2: %.35lf\n", c2);
    printf("d2: %.35lf\n", d2);
    double e2 = 0.5;
    printf("e2: %.35lf\n", e2);
    float var_float = 2.0f;
    printf("Variable var_float %f has size %lu byte\n", var_float, sizeof(var_float));
    printf("float range: %d, %d\n\n", FLT_MIN, FLT_MAX); // 1.2E-38 to 3.4E+38

    printf("---- double ----\n");
    double var_double = 97.88;
    printf("Variable var_double %lf has size %lu byte\n", var_double, sizeof(var_double));
    printf("bytes range: %d\n\n", DBL_MAX); // 2.3E-308 to 1.7E+308

    printf("---- long double ----\n");
    long double var_double_long = 3.14e+2;
    printf("Variable var_double_long %Lf has size %lu byte\n", var_double_long, sizeof(var_double_long));
    printf("bytes range: %d\n\n", DBL_MAX); // 3.4E-4932 to 1.1E+4932

    return 0;
}
