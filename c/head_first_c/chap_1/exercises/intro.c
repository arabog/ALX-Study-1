int card_count = 11;    //cr8 an integer variable and set it to 11

if (card_count > 10)    // is d count more than 10?
    puts("The deck is hot. Increase bet."); //if so, display a msg on d command prompt.


int c = 10;             // cr8 an integer variable and set it to 10

while(c > 0) {          // as long as d value is +ve 
    puts("I must not write code in class"); //display a message
    c = c - 1;          // and decrease d count
}                       // ds is d end of code dt shd be repeated

/* Assume name shorter than 20 chars*/      // ds is a comment
char ex[20];            // cr8 an array of 20 xters

puts("Enter boyfriend's name: ");   // display a msg on d screen
scanf("%19s", ex);                  //store wt d user enters into d array

printf("Dear %s. \n\n\t You're history.\n", ex);     // display a msg including d text entered


char suit = "H";                // cr8 a xter variable; store d letter H

switch(suit) {                  // look at d value of d variable
    case 'C':                   // Is it C?
        puts("Clubs");          // if so, display d word Clubs
        break;                  // dn skip past d other checks

    case "D":                   // is it D?
        puts("Diamond");        // if so, display d word Diamond
        break;                  // dn skip past d other checks

    case "H":                   // is it H?
        puts("Hearts");         // if so, display d word Hearts
        break;                  // dn skip past d other checks

    default:                    // odawise
        puts("Spades");         // display d word 'Spades'
}                               // ds is d end of d tests

