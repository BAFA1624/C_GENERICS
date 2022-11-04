#include <stdarg.h>
#include <stdio.h>

#define GEN_LINE( type, fn ) ( type : ( fn ) )

/*#define my_print( x ) \
    _Generic( ( x ), GEN_LINE( int, printf( "%d\n", x ) ),                     \
              GEN_LINE( char, printf( "%c\n", x ) ),                           \
              GEN_LINE( float, printf( "%f\n", x ) ),                          \
              GEN_LINE( test_struct,                                           \
                        printf( "a = %d, b = %c, c = %f\n", x.a, x.b, x.c ) ), \
              GEN_LINE( default, printf( "Unknown type." ) ) )*/

// Formatter incorrectly handles _Generic in current version
// clang-format off

#define FORMAT_SPEC(x) \
    _Generic( (x), \
            int: "%d\n", \
            char: "%c\n", \
            float: "%f\n" )

#define MY_PRINT( x ) (printf(FORMAT_SPEC(x), x))

// test_struct: PRINT_FUNC( "a = %d, b = %c, c = %f\n", x.a, x.b, x.c ) \

// clang-format on

typedef struct TEST_STRUCT
{
    int   a;
    char  b;
    float c;
} test_struct;

int
main() {
    int   a = 5;
    char  b = 'c';
    float c = 3.14;

    /*test_struct d = {
        .a = 5,
        .b = 'c',
        .c = 3.14,
    };*/

    MY_PRINT( a );
    MY_PRINT( b );
    MY_PRINT( c );
}
