#include <stdio.h>
#include <stdlib.h>
int main() {
    char card_name[3];
    int count = 0;

    while(card_name[0] != 'X') {
        puts("Enter the card_name: ");
        scanf("%2s", card_name); //wtever d input is weda num or alphabets, is d card name

        int val = 0;
        
        switch(card_name[0]) {
            case 'K':
            case 'Q':
            case 'J':
                val = 10;
                break;
        
            case 'A':
                val = 11;
                break;

            case 'X':
                continue; // 'break' wouldn’t break us out of the loop, because we're inside a switch statement. We need a 'continue' to go back and check the loop condition again;
        
            default:
                val = atoi(card_name);

                if(val < 1 || val > 10) {
                    puts("I don't understand that value!");
                    continue; // U need anoda continue here bcos u want to keep looping
                }
        }

        if ((val > 2) && (val < 7)) {
            count++;
        }else if(val == 10) {
            count--;
        }

        printf("Current count: %i\n", count);
    }

    return 0;
}

