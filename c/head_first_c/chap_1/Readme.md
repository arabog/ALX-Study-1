# Chap 1: Getting Started With C
## C is a language for small, fast programs
The C language is designed to create small, fast programs. It’s lower-level than 
most other languages; that means it creates code that’s a lot closer to what 
machines really understand.  

## The way C works
Computers really only understand one language: machine code, a binary stream 
of 1s and 0s. You convert your C code into machine code with the aid of a 
compiler.  

1. Source e.g rocks.c   
You start off by creating a source file. The source file contains human-readable 
C code.  

2. Compile  e.g gcc rocks.c -o rocks
You run your source code through a compiler. The compiler checks for errors, and 
once it’s happy, it compiles the source code.      

3. Output e.g rocks  
The compiler creates a new file called an **executable**. This file contains machine 
code, a stream of 1s and 0s that the computer understands. And that’s the program you
can run.    

C is used where speed, space, and portability are important. Most operating systems 
are written in C. Most other computer languages are also written in C. And most game 
software is written in C.  

There are three C standards that you may stumble across. ANSI C is from the late 1980s 
and is used for the oldest code. A lot of things were fixed up in the C99 standard from 
1999. And some cool new language features were added in the current standard, C11, 
released in 2011. The differences between the different versions aren’t huge, and we’ll 
point them out along the way.  

## But what does a complete C program look like?
To create a full program, you need to enter your code into a C source file. C source 
files can be created by any text editor, and their filenames usually end with .c.  

1. C programs normally begin with a comment.  
The comment describes the purpose of the code in the file, and might 
include some license or copyright information. There’s no absolute need
to include a comment here—or anywhere else in the file—but it’s good
practice and what most C programmers will expect to find.
```
/*
* Program to calculate the number of cards in the shoe.
* This code is released under the Vegas Public License.
* (c)2014, The College Blackjack Team.
*/
```

2. Next comes the include section.  
C is a very, very small language and it can do almost nothing without 
the use of external libraries. You will need to tell the compiler what 
external code to use by including header files for the relevant libraries.  
The header you will see more than any other is stdio.h. The stdio
library contains code that allows you to read and write data from and
to the terminal.  
```
# include <stdio.h>
```
3. The last thing you find in a source file are the functions.  
All C code runs inside functions. The most important function you will
find in any C program is called the main() function. The main() function
is the starting point for all of the code in your program.
```
int main() {    //ds is d return type. it shd alw be int for d main() fxn
    int decks;
    puts("Enter a number of decks");

    scanf("%i", &decks);

    if (decks < 1) {
        puts("That is not a valid number of decks");
        return 1;
    }

    printf("There are %i cards\n", (decks * 52));
    return 0;
}
```
The main() Function Up Close  
The computer will start running your program from the main()
function. The name is important: if you don’t have a function called main(),
your program won’t be able to start.  

The main() function has a return type of int. So what does this mean?  
Well, when the computer runs your program, it will need to have some way of
deciding if the program ran successfully or not. It does this by checking the return
value of the main() function. If you tell your main() function to return 0, this
means that the program was successful. If you tell it to return any other value,
this means that there was a problem.  

The function name comes after the return type. That’s followed by the function
parameters if there are any. Finally, we have the function body. The function body
must be surrounded by braces.  

The printf() function is used to display formatted output. It
replaces format characters with the values of variables, like this:  
```
printf("%s says the is %i", "Ben", 21);

d 1st parameter, %s, will be inserted as a string
d 2nd parameter, %i, will be inserted as an integer

1st parameter, Ben
2nd parameter, 21
```
You can include as many parameters as you like when you call the printf()
function, but make sure you have a matching % format character for each one.  
```
scanf("%2s", card_name); Enter 2 xters for d card name

atoi(card_name);    atoi() converts d text to a number
```

## But how do you run the program?
C is a compiled language. That means the computer will not interpret the code
directly. Instead, you will need to convert—or compile—the human-readable
source code into machine-readable machine code.  
To compile the code, you need a program called a compiler. One of the
most popular C compilers is the GNU Compiler Collection or gcc. gcc is
available on a lot of operating systems, and it can compile lots of languages
other than C. Best of all, it’s completely free. 
Here’s how you can compile and run the program using gcc.  

Compile with gcc cards.c -o cards at a command
prompt or terminal.
```
gcc cards.c -o cards    ds means compile card.c to a file called cards
```
Run by typing cards on Windows, or ./cards on Mac and
Linux machines.
```
./cards
```
You can compile and run your code on most machines using this trick:  
`gcc zork.c -o zork && ./zork`  

This command will run the new program only if it compiles
successfully. If there’s a problem with the compile, it will skip running
the program and simply display the errors on the screen.  

Q: Why do I have to prefix the program with ./ when I run it on Linux and the Mac?  
A: On Unix-style operating systems, programs are run only if you specify the directory where
they live or if their directory is listed in the PATH environment variable.  

Q: Wait, I don’t get it. When we ask the user what the name
of the card is, we’re using an array of characters. An array of
characters???? Why? Can’t we use a string or something???  
A: The C language doesn’t support strings out of the box.  
C is more low-level than most other languages, so instead
of strings, it normally uses something similar: an array of
single characters. If you’ve programmed in other languages,
you’ve probably met an array before. An array is just a list of
things given a single name. So card_name is just a variable
name you use to refer to the list of characters entered at
the command prompt. You defined card_name to be a
two-character array, so you can refer to the first and second
character as char_name[0] and char_name[1]. To see
how this works, let’s take a deeper dive into the computer’s
memory and see how C handles text…  

## Strings Way Up Close
Strings are just character arrays. When C sees a string like this:
s = "Shatner"  
it reads it like it was just an array of separate characters:  
s = {'S', 'h', 'a', 't', 'n', 'e', 'r'}  <!-- This is how you define an array in C.   -->

Each of the characters in the string is just an element in an array, which is
why you can refer to the individual characters in the string by using an index,
like s[0] and s[1].  

Don’t fall off the end of the string
But what happens when C wants to read the contents of the string? Say
it wants to print it out. Now, in a lot of languages, the computer keeps
pretty close track of the size of an array, but C is more low-level than most
languages and can’t always work out exactly how long an array is. If C is going
to display a string on the screen, it needs to know when it gets to the end of
the character array. And it does this by adding a sentinel character.  
The sentinel character is an additional character at the end of the string that
has the value \0. Whenever the computer needs to read the contents of the
string, it goes through the elements of the character array one at a time, until
it reaches \0. That means that when the computer sees this:  
s = "Shatner"  
it actually stores it in memory like this: S h a t n e r \0
\0 is d ASCII character with value 0. C coders often call this the NULL xter.  

That’s why in our code we had to define the card_name variable like this:  
char card_name[3];  
The card_name string is only ever going to record one or two characters, but because
strings end in a sentinel character we have to allow for an extra character in the array.  

Q: Does it matter if I use single quotes or double quotes?
A: Yes. Single quotes are used for individual characters, but double quotes are always used for strings.

Q:  Are there any differences between string literals and character arrays?
A: Only one: string literals are constant.

Q: What does that mean?
A: It means that you can’t change the individual characters once they are created.

Q: What will happen if I try?
A: It depends on the compiler, but gcc
will usually display a bus error.

Q: A bus error? What the heck’s a
bus error?
A: C will store string literals in memory
in a different way. A bus error just means
that your program can’t update that piece
of memory.

## Two types of command
So far, every command you’ve seen has fallen into one of the following two categories.  

Do something
Most of the commands in C are statements. Simple statements are actions;
they do things and they tell us things. You’ve met statements that define
variables, read input from the keyboard, or display data to the screen.
`split_hand(); This is a simple statement.`  
Sometimes you group statements together to create block statements. Block
statements are groups of commands surrounded by braces.  

## Do something only if something is true
Control statements such as if check a condition before running the code:
```
if (value_of_hand <= 16)    This is the condition.
    hit();  Run this statement if the condition is true.
else
    stand();    Run this statement if the condition is false.
```
if statements typically need to do more than one thing when a
condition is true, so they are often used with block statements:
```
if (dealer_card == 6) {
    double_down(); BOTH of these commands will run if the condition is true.
    hit();          The commands are grouped inside a single block statement.
}
if (countdown == 0)
    do_this_thing();
```
The if condition runs a single statement. So what if you
want to run several statements in an if ? If you wrap a list of
statements in braces, C will treat them as though they were just
one statement:
```
if (x == 2) {
    call_whitehouse()
    sell_oil();
    x = 0;
}
```
## && checks if two conditions are true
The and operator (&&) evaluates to true, only if both conditions given to it are
true.
```
if ((dealer_up_card == 6) && (hand == 11)) Both of these conditions need to be
    double_down();                          true for this piece of code to run.
```
The and operator is efficient: if the first condition is false, then the computer
won’t bother evaluating the second condition. It knows that if the first condition
is false, then the whole condition must be false.  

## || checks if one of two conditions is true
The or operator (||) evaluates to true, if either condition given to
it is true.
```
               Either can be true
                   \        /
if (cupcakes_in_fridge || chips_on_table)
    eat_food();
```
If the first condition is true, the computer won’t bother evaluating the second condition. It knows that if the first condition is true, the whole condition must be true.  

## ! flips the value of a condition
! is the not operator. It reverses the value of a condition.  

In C, boolean values are represented by numbers. To C, the number 0 is the value for false. But what’s the value for true? Anything that is not equal to 0 is treated as true.
So there is nothing wrong in writing C code like this:
```
int people_moshing = 34;
if (people_moshing)
    take_off_glasses();
```
In fact, C programs often use this as a shorthand way of checking if something is not 0.

The code works. By combining multiple conditions with a boolean
operator, you check for a range of values rather than a single value.
You now have the basic structure in place for a card counter.