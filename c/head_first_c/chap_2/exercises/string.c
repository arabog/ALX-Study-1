#include <stdio.h>

void fortune_cookie(char msg[]) {
    // printf("Message reads: %s\n", msg);

    putchar("Message reads: %s\n", msg);

    putchar("\n"):

    printf("msg occupies %i byte\n", sizeof(msg));
}


int main() {
    char quote[] = "Cookies make you fat";

    fortune_cookie(quote);
}