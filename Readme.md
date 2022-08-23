https://www.freecodecamp.org/news/the-c-beginners-handbook/?inf_contact_key=23bf5265a3651c14888725bce7f1c3fc3a5186b0959d36194e900cf71a9c9586

# The C Beginner's Handbook:   
# Learn C Programming Language basics in just a few hours

## Introduction to C
C is a compiled programming language, like Go, Java, Swift or Rust. Other popular programming language like Python, Ruby or JavaScript are interpreted. The difference is consistent: a compiled language generates a binary file that can be directly executed and distributed.  

C is not garbage collected. This means we have to manage memory ourselves. It's a complex task and one that requires a lot of attention to prevent bugs.  

I want to introduce the first C program now, which we'll call "Hello, World!"  
```
hello.c  

#include <stdio.h>  

int main(void) {
    printf("Hello, World!");
}
```

Let's describe the program source code: we first import the stdio library (the name stands for standard input-output library). This library gives us access to input/output functions.  

C is a very small language at its core, and anything that's not part of the core is provided by libraries.  

`stdio` is the library that provides the `printf()` function.

This function is wrapped into a `main()` function. The `main()` function is the entry point of any C program.  

**A function is a routine that takes one or more arguments, and returns a single value.**  

In the case of main(), the function gets no arguments, and returns an integer. We identify that using the `void` keyword for the argument, and the `int` keyword for the return value.  

The function has a body, which is wrapped in curly braces, {}. Inside the body we have all the code that the function needs to perform its operations.  

The printf() function is written differently, as you can see. It has no return value defined, and we pass a string, wrapped in double quotes. We didn't specify the type of the argument.  

That's because this is a function invocation. Somewhere, inside the stdio library, printf is defined as  
`int printf(const char *format, ...)`;  

You don't need to understand what this means now, but in short, this is the definition. And when we call printf("Hello, World!"), that's where the function is run.

The main() function we defined above:  
```
    #include <stdio.h>

    int main(void) {
        printf("Hello, World!");
    }
```

will be run by the operating system when the program is executed.

### How do we execute a C program?
As mentioned, C is a compiled language. To run the program we must first compile it. Any Linux or macOS computer already comes with a C compiler built-in.   

In any case, when you open the terminal window you can type `gcc`, and this command should return an error saying that you didn't specify any file.  

That's good. It means the C compiler is there, and we can start using it.  

Now save the code above into a hello.c file. *see file hello.c*

Now type `gcc hello.c -o hello`  
The program should give you no errors but it should have generated a `hello` executable (inside ur directory). Now type  

`./hello` to run it.  

![c1](c1.png?raw=true "c1")

I prepend `./` to the program name to tell the terminal that the command is in the current folder.  

Now if you call `ls -al hello`, you can see that the program is only 16KB in size:  

![c2](c2.png?raw=true "c2")

This is one of the pros of C: it's highly optimized, and this is also one of the reasons it's this good for embedded devices that have a very limited amount of resources.  


## Variables and types
C is a statically typed language.

This means that any variable has an associated type, and this type is known at compilation time. When you create a variable in C, you have to specify the type of a variable at the declaration.
In this example we initialize a variable age with type int:

`int age;`

You can also initialize a variable at declaration, specifying the initial value:  
`int age = 37;`

Once you declare a variable, you are then able to use it in your program code. You can change its value at any time, using the `=` operator for example, like in age = 100; (provided the new value is of the same type).  

In this case:  
```
#include <stdio.h>

int main(void) {
    int age = 0;
    age = 37.2;
    printf("%u", age);
}
```
the compiler will raise a warning at compile time, and will convert the decimal number to an integer value. The C built-in data types are `int`, `char`, `short`, `long`, `float`, `double`, `long double`.  

### Integer numbers
C provides us the following types to define integer values:  
char  
int  
short  
long  

Most of the time, you'll likely use an `int` to store an integer. But in some cases, you might want to choose one of the other 3 options.  

The char type is commonly used to store letters of the ASCII chart, but it can be used to hold small integers from -128 to 127.   
`char` takes at least 1 byte.  
`int` takes at least 2 bytes.   
`short` takes at least 2 bytes.   
`long` takes at least 4 bytes.  

As you can see, we are not guaranteed the same values for different environments. We only have an indication. The problem is that the exact numbers that can be stored in each data type depends on the implementation and the architecture.  

We're guaranteed that short is not longer than int. And we're guaranteed long is not shorter than int.  

### Unsigned integers
For all the above data types, we can prepend unsigned to start the range at 0, instead of a negative number. This might make sense in many cases.

`unsigned char` will range from 0 to at least 255  
`unsigned int` will range from 0 to at least 65,535  
`unsigned short` will range from 0 to at least 65,535  
`unsigned long` will range from 0 to at least 4,294,967,295  

### The problem with overflow
Given all those limits, a question might come up: how can we make sure our numbers do not exceed the limit? And what happens if we do exceed the limit?  

If you have an unsigned int number at 255, and you increment it, you'll get 256 in return. As expected. If you have an unsigned char number at 255, and you increment it, you'll get 0 in return. It resets starting from the initial possible value.  

If you have a unsigned char number at 255 and you add 10 to it, you'll get the number 9:  

```
#include <stdio.h>

int main(void) {
    unsigned char j = 255;
    j = j + 10;
    printf("%u", j); //9
}

```
If you don't have a signed value, the behavior is undefined. It will basically give you a huge number which can vary, like in this case:  

```
#include <stdio.h>

int main(void) {
  char j = 127;
  j = j + 10;
  printf("%u", j); /* 4294967177 */
}
```

In other words, C does not protect you from going over the limits of a type. You need to take care of this yourself.  

### Warnings when declaring the wrong type

When you declare the variable and initialize it with the wrong value, the gcc compiler (the one you're probably using) should warn you:  

```
#include <stdio.h>

int main(void) {
  char j = 1000;
}
```
And it also warns you in direct assignments:  

```
#include <stdio.h>

int main(void) {
  char j;
  j = 1000;
}

```
But not if you increase the number using, for example, +=:  

```
#include <stdio.h>

int main(void) {
  char j = 0;
  j += 1000;
}
```
### Floating point numbers
Floating point types can represent a much larger set of values than integers can, and can also represent fractions, something that integers can't do.  

Using floating point numbers, we represent numbers as decimal numbers times powers of 10.  

You might see floating point numbers written as  
1.29e-3  
-2.3e+5  

The following types:  
float  
double  
long double  
are used to represent numbers with decimal points (floating point types). All can represent both positive and negative numbers.  

The minimum requirements for any C implementation is that float can represent a range between 10^-37 and 10^+37, and is typically implemented using 32 bits. double can represent a bigger set of numbers. long double can hold even more numbers.  

The exact figures, as with integer values, depend on the implementation.  

On a modern Mac, a float is represented in 32 bits, and has a precision of 24 significant bits. 8 bits are used to encode the exponent.  

A double number is represented in 64 bits, with a precision of 53 significant bits. 11 bits are used to encode the exponent.  

The type long double is represented in 80 bits, has a precision of 64 significant bits. 15 bits are used to encode the exponent.  


On your specific computer, how can you determine the specific size of the types? You can write a program to do that:  


```
#include <stdio.h>

int main(void) {
    printf("char size: %lu bytes\n", sizeof(char));
    printf("int size: %lu bytes\n", sizeof(int));
    printf("short size: %lu bytes\n", sizeof(short));
    printf("long size: %lu bytes\n", sizeof(long));
    printf("float size: %lu bytes\n", sizeof(float));
    printf("double size: %lu bytes\n", sizeof(double));
    printf("long double size: %lu bytes\n", sizeof(long double));
}
```
it prints out:  
```
char size: 1 bytes
int size: 4 bytes
short size: 2 bytes
long size: 8 bytes
float size: 4 bytes
double size: 8 bytes
long double size: 16 bytes
```

## Constants
A constant is declared similarly to variables, except it is prepended with the `const` keyword, and you always need to specify a value.  
`const int age = 32;`

This is perfectly valid C, although it is common to declare constants uppercase, like this: `const int AGE = 37;`

It's just a convention, but one that can greatly help you while reading or writing a C program as it improves readability. Uppercase name means constant, lowercase name means variable.  

Another way to define constants is by using this syntax:  
`#define AGE 37`

In this case, you don't need to add a `type`, and you don't also need the `=` equal sign, and you omit the `semicolon` at the end.  

The C compiler will infer the type from the value specified, at compile time.  

## Operators
Operators
C offers us a wide variety of operators that we can use to operate on data.

In particular, we can identify various groups of operators:  
arithmetic operators  
comparison operators  
logical operators  
compound assignment operators  
bitwise operators  
pointer operators  
structure operators  
miscellaneous operators  

I am keeping bitwise operators, structure operators and pointer operators out of this list, to keep things simpler.  

### Arithmetic operators
In this macro group I am going to separate binary operators and unary operators.  

Binary operators work using two operands:  
```
OPERATOR	    NAME	        EXAMPLE  
    =	    Assignment	        a = b  
    +	    Addition	          a + b  
    -	    Subtraction	        a - b  
    *	    Multiplication	    a * b  
    /	    Division	          a / b  
    %	    Modulo	            a % b  
```

Unary operators only take one operand:  
```
OPERATOR	        NAME	    EXAMPLE  
    +	        Unary plus	    +a  
    -	        Unary minus	    -a  
    ++	        Increment	    a++ or ++a  
    --	        Decrement	    a-- or --a  
```

The difference between a++ and ++a is that a++ increments the a variable after using it. ++a increments the a variable before using it.  

For example:  
int a = 2;  
int b;  
```
b = a++   b is 2, a is 3  
b = ++a   b is 4, a is 4
```

### Comparison operators
```
OPERATOR	        NAME	              EXAMPLE  
    ==	    Equal operator	          a == b
    !=	    Not equal operator	      a != b
    >	    Bigger than	                a > b
    <	    Less than	                  a < b
    >=	    Bigger than or equal to	  a >= b
    <=	    Less than or equal to	    a <= b
```

### Logical operators
```
!       NOT       (example: !a)  
&&      AND       (example: a && b)  
||      OR        (example: a || b)  
```

Compound assignment operators  
Those operators are useful to perform an assignment and at the same time perform an arithmetic operation:

```
OPERATOR	        NAME	                EXAMPLE
+=	        Addition assignment	        a += b
-=	        Subtraction assignment	    a -= b
*=	        Multiplication assignment	  a *= b
/=	        Division assignment	        a /= b
%=	        Modulo assignment	          a %= b
```

### The ternary operator
The ternary operator is the only operator in C that works with 3 operands, and it’s a short way to express conditionals.  

Example:  
a ? b : c

If a is evaluated to true, then the b statement is executed, otherwise c is.  

Similar to if/else conditional.  

### sizeof
The sizeof operator returns the size of the operand you pass. You can pass a variable, or even a type.  

Example usage:  
```
#include <stdio.h>

int main(void) {
  int age = 37;
  printf("%ld\n", sizeof(age));
  printf("%ld", sizeof(int));
}
```

### Operator precedence
Suppose we have this operation:

int a = 2;  
int b = 4;  
int c = b + a * a / b - a;  
What's the value of c?  

There is a set of rules that help us solve this puzzle. In order, from less precedence to more precedence, we have:  
the = assignment operator  
the + and - binary operators  
the * and / operators  
the + and - unary operators  

Operators also have an associativity rule, which is always left to right except for the unary operators and the assignment.  

int c = b + a * a / b - a;  
We first execute a * a / b, which, due to being left-to-right, we can separate into a * a and the result / b  

In all cases, however, I want to make sure you realize you can use parentheses to make any similar expression easier to read and comprehend.  

Parentheses have higher priority over anything else.  

The above example expression can be rewritten as:  
int c = b + ((a * a) / b) - a;  


## Conditionals
Any programming language provides the programmers the ability to perform choices. C provides us 2 ways to do so.

The first is the if statement, with its else helper, and the second is the switch statement.

**if**    
In an if statement, you can check for a condition to be true, and then execute the block provided in the curly brackets:
```
int a = 1;

if (a == 1) {
  /* do something */
}
```

You can append an else block to execute a different block if the original condition turns out to be false:

```
int a = 1;

if (a == 2) {
  /* do something */
} else {
  /* do something else */
}
```

Beware of one common source of bugs - always use the comparison operator == in comparisons, and not the assignment operator =. If you don't, the if conditional check will always be true, unless the argument is 0, for example if you do:

```
int a = 0;

if (a = 0) {
  /* never invoked */
}
```

Why does this happen? Because the conditional check will look for a boolean result (the result of a comparison), and the 0 number always equates to a false value. Everything else is true, including negative numbers.  

You can have multiple else blocks by stacking together multiple if statements:  

```
int a = 1;

if (a == 2) {
  /* do something */
} else if (a == 1) {
  /* do something else */
} else {
  /* do something else again */
}
```

**switch**  
If you need to do too many if / else / if blocks to perform a check, perhaps because you need to check the exact value of a variable, then switch can be very useful to you.  

You can provide a variable as condition, and a series of case entry points for each value you expect:  

```
int a = 1;

switch (a) {
  case 0:
    /* do something */
    break;
  case 1:
    /* do something else */
    break;
  case 2:
    /* do something else */
    break;
}
```

We need a break keyword at the end of each case to avoid the next case being executed when the one before ends. This "cascade" effect can be useful in some creative ways.  

You can add a "catch-all" case at the end, labeled default:  

```
int a = 1;

switch (a) {
  case 0:
    /* do something */
    break;
  case 1:
    /* do something else */
    break;
  case 2:
    /* do something else */
    break;
  default:
    /* handle all the other cases */
    break;
}
```

## Loops
C offers us three ways to perform a loop: for loops, while loops and do while loops. They all allow you to iterate over arrays, but with a few differences.  

**For loops**  
The first and probably most common way to perform a loop is for loops.

Using the `for` keyword we can define the rules of the loop up front, and then provide the block that is going to be executed repeatedly.  

```
for (int i = 0; i <= 10; i++) {
  /* instructions to be repeated */
  printf("%u ", i);
}
```
The (int i = 0; i <= 10; i++) block contains 3 parts of the looping details:  
the initial condition (int i = 0)  
the test (i <= 10)  
the increment (i++)  

We first define a loop variable, in this case named i. i is a common variable name to be used for loops, along with j for nested loops (a loop inside another loop). It's just a convention.  

The variable is initialized at the 0 value, and the first iteration is done. Then it is incremented as the increment part says (i++ in this case, incrementing by 1), and all the cycle repeats until you get to the number 10.  

Loops can also start from a high number, and go a lower number, like this:

```
for (int i = 10; i > 0; i--) {
  /* instructions to be repeated */
}
```

You can also increment the loop variable by 2 or another value:

```
for (int i = 0; i < 1000; i = i + 30) {
  /* instructions to be repeated */
}
```

**While loops**    
Instead of defining all the loop data up front when you start the loop, like you do in the for loop, using while you just check for a condition:

```
while (i < 10) {

}
```

This assumes that i is already defined and initialized with a value.  
And this loop will be an infinite loop unless you increment the i variable at some point inside the loop.   

This is what you need for a "correct" while loop:

```
int i = 0;  //init

while (i < 10) {  //conditn
  /* do something */

  i++;  //incre-/decre-ment
}
```
**Do while loops**    
While loops are great, but there might be times when you need to do one particular thing: you want to always execute a block, and then maybe repeat it. This is done using the do while keyword.   

```
int i = 0;

do {
  /* do something */

  i++;
} while (i < 10);
```

The block that contains the `/* do something */` comment is always executed at least once, regardless of the condition check at the bottom. Then, until `i` is less than 10, we'll repeat the block.  

**Breaking out of a loop using break**    
In all the C loops we have a way to break out of a loop at any point  in time, immediately, regardless of the conditions set for the loop. This is done using the break keyword.  
Having this option to break out of a loop is particularly interesting for while loops (and do while too), because we can create seemingly infinite loops that end when a  condition occurs. You define this inside the loop block:  
```
int i = 0;

while (1) {
  /* do something */

  i++;

  if (i == 10) break;
}
```

## Arrays
An array is a variable that stores multiple values. Every value in the array, in C, must have the same type. This means you will have arrays of int values, arrays of double values, and more.  

You can define an array of int values like this:  
`int prices[5];`

You must always specify the size of the array. C does not provide dynamic arrays out of the box (you have to use a data structure like a linked list for that).  

You can use a constant to define the size:  
const int SIZE = 5;  
int prices[SIZE];  

You can initialize an array at definition time, like this:  
`int prices[5] = { 1, 2, 3, 4, 5 };  `

But you can also assign a value after the definition, in this way:  

```
int prices[5];

prices[0] = 1;
prices[1] = 2;
prices[2] = 3;
prices[3] = 4;
prices[4] = 5;
```

Or, more practical, using a loop:  
```
int prices[5];

for(int i = 0; i < 5; i++) {
  prices[i] = i + 1;
}
```

And you can reference an item in the array by using square brackets after the array variable name, adding an integer to determine the index value.   

```
prices[0]; /* array item value: 1 */
prices[1]; /* array item value: 2 */
```

Array indexes start from 0, so an array with 5 items, like the prices array above, will have items ranging from prices[0] to prices[4].  


## Strings
In C, strings are one special kind of array: a string is an array of char values:  
`char name[7];`  

It is commonly used to store letters of the ASCII chart. A string can be initialized like you initialize a normal array:  
```
char name[7] = { "F", "l", "a", "v", "i", "o" };
```

Or more conveniently with a string literal (also called string constant), a sequence of characters enclosed in double quotes:  
```
char name[7] = "Flavio";
```
You can print a string via printf() using %s:
```
printf("%s", name);
```
Do you notice how "Flavio" is 6 chars long, but I defined an array of length 7? Why? This is because the `last character` in a string must be a  `0 value, the string terminator`, and we must make space for it.  

This is important to keep in mind especially when manipulating strings.  

Speaking of manipulating strings, there's one important standard library that is provided by C: `string.h`.  

This library is essential because it abstracts many of the low level details of working with strings, and provides us with a set of useful functions.  

You can load the library in your program by adding on top:  
```
#include <string.h>
```
And once you do that, you have access to:  

```
strcpy() to copy a string over another string
strcat() to append a string to another string
strcmp() to compare two strings for equality
strncmp() to compare the first n characters of two strings
strlen() to calculate the length of a string
```

## Pointers  
Pointers are one of the most confusing/challenging parts of C, in my opinion.  
**A pointer is the address of a block of memory that contains a variable.**  

When you declare an integer number like this:  
```
int age = 37;
```
We can use the `&` operator to get the value of the address in memory of a variable:  
```
printf("%p", &age); /* 0x7ffeef7dcb9c */
```

I used the %p format specified in printf() to print the address value.

We can assign the address to a variable:

```
int *address = &age;
```
Using int *address in the declaration, we are not declaring an integer variable, but rather a pointer to an integer.   

We can use the pointer operator * to get the value of the variable an address is pointing to:  
```
int age = 37;
int *address = &age;
printf("%u", *address); /* 37 */
```

This time we are using the pointer operator again, but since it's not a declaration this time it means "the value of the variable this pointer points to".    

In this example we declare an age variable, and we use a pointer to initialize the value:  
```
int age;
int *address = &age;
*address = 37;
printf("%u", *address);
```

When working with C, you'll find that a lot of things are built on top of this simple concept. So make sure you familiarize with it a bit by running the above examples on your own.  

Pointers are a great opportunity because they force us to think about memory addresses and how data is organized.    

Arrays are one example. When you declare an array:
```
int prices[3] = { 5, 4, 3 };
```
The prices variable is actually a pointer to the first item of the array. You can get the value of the first item using this printf() function in this case:
```
printf("%u", *prices); /* 5 */
```
The cool thing is that we can get the second item by adding 1 to the prices pointer:
```
printf("%u", *(prices + 1)); /* 4 */
```
And so on for all the other values.  
We can also do many nice string manipulation operations, since strings are arrays under the hood.  

We also have many more applications, including passing the reference of an object or a function around to avoid consuming more resources to copy it.  

## Functions



## Input and Output


## Variable scope



## Static variables

## Global variables


<!-- ![cf1](cf1.png?raw=true "cf1") -->
