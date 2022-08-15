https://www.freecodecamp.org/news/the-c-beginners-handbook/?inf_contact_key=23bf5265a3651c14888725bce7f1c3fc3a5186b0959d36194e900cf71a9c9586

# The C Beginner's Handbook: Learn C Programming Language basics in just a few hours

## Introduction to C
C is a compiled programming language, like Go, Java, Swift or Rust. Other popular programming language like Python, Ruby or JavaScript are interpreted. The difference is consistent: a compiled language generates a binary file that can be directly executed and distributed.  

C is not garbage collected. This means we have to manage memory ourselves. It's a complex task and one that requires a lot of attention to prevent bugs.  

I want to introduce the first C program now, which we'll call "Hello, World!"  
hello.c  

#include <stdio.h>  

int main(void) {
    printf("Hello, World!");
}

Let's describe the program source code: we first import the stdio library (the name stands for standard input-output library). This library gives us access to input/output functions.  

C is a very small language at its core, and anything that's not part of the core is provided by libraries.  

`stdio` is the library that provides the `printf()` function.

This function is wrapped into a `main()` function. The `main()` function is the entry point of any C program.  

A function is a routine that takes one or more arguments, and returns a single value.  

In the case of main(), the function gets no arguments, and returns an integer. We identify that using the void keyword for the argument, and the int keyword for the return value.  

The function has a body, which is wrapped in curly braces. Inside the body we have all the code that the function needs to perform its operations.  

The printf() function is written differently, as you can see. It has no return value defined, and we pass a string, wrapped in double quotes. We didn't specify the type of the argument.  

That's because this is a function invocation. Somewhere, inside the stdio library, printf is defined as  
`int printf(const char *format, ...)`;  

You don't need to understand what this means now, but in short, this is the definition. And when we call printf("Hello, World!");, that's where the function is run.

The main() function we defined above:  
    #include <stdio.h>

    int main(void) {
        printf("Hello, World!");
    }

will be run by the operating system when the program is executed.

### How do we execute a C program?
As mentioned, C is a compiled language. To run the program we must first compile it. Any Linux or macOS computer already comes with a C compiler built-in.   

In any case, when you open the terminal window you can type `gcc`, and this command should return an error saying that you didn't specify any file.  

That's good. It means the C compiler is there, and we can start using it.  

Now save the code above into a hello.c file. *see file hello.c*

Now type `gcc hello.c -o hello`  
The program should give you no errors but it should have generated a hello executable. Now type  

`./hello` to run it.  

![c1](c1.png?raw=true "c1")

I prepend ./ to the program name to tell the terminal that the command is in the current folder.  

Now if you call `ls -al hello`, you can see that the program is only 16KB in size:  

![c2](c2.png?raw=true "c2")

This is one of the pros of C: it's highly optimized, and this is also one of the reasons it's this good for embedded devices that have a very limited amount of resources.  

![cf1](cf1.png?raw=true "cf1")


## Variables and types
C is a statically typed language.

