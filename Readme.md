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






## Loops

## Arrays

## Strings

## Pointers



<!-- ![cf1](cf1.png?raw=true "cf1") -->
