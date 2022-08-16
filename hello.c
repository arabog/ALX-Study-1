// 1.
// #include <stdio.h>

// int main(void) {
//     printf("Hello, World!");
// }

// to run d code:
// gcc hello.c -o lang
// ./lang

// 2. 
// #include <stdio.h>

// int main(void) {
//     unsigned char j = 255;
//     j = j + 10;
//     printf("%u", j); //9
// }


// 3.
// #include <stdio.h>

// int main(void) {
//   char j = 127;
//   j = j + 10;
//   printf("%u", j); /* 4294967177 */
// }


// 4.
// #include <stdio.h>

// int main(void) {
//     char j = 1000;
// }

// hello.c:36:14: warning: overflow in conversion from ‘int’ to ‘char’ changes value from ‘1000’ to ‘-24’ [-Woverflow]

// 5.
// #include <stdio.h>

// int main(void) {
//     char j = 0;
//     j += 1000;
//     // printf("%u", j);
// }

// 6.
// #include <stdio.h>

// int main(void) {
//     printf("char size: %lu bytes\n", sizeof(char));
//     printf("int size: %lu bytes\n", sizeof(int));
//     printf("short size: %lu bytes\n", sizeof(short));
//     printf("long size: %lu bytes\n", sizeof(long));
//     printf("float size: %lu bytes\n", sizeof(float));
//     printf("double size: %lu bytes\n", sizeof(double));
//     printf("long double size: %lu bytes\n", sizeof(long double));
// }

// 7. 
// Another way to define constants is by using this syntax:  
// #include <stdio.h>

// #define AGE 37

// int main(void) {
//     printf("%u", AGE);
// }

// 8.  
#include <stdio.h>

int main(void) {
    int age = 37;
    printf("%ld\n", sizeof(age));

    printf("%ld", sizeof(int));
}


