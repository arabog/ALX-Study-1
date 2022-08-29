# Chap 1: Getting Started With C
## C is a language for small, fast programs
The C language is designed to create small, fast programs. It’s
lower-level than most other languages; that means it creates code
that’s a lot closer to what machines really understand.  

## The way C works
Computers really only understand one language: machine code, a
binary stream of 1s and 0s. You convert your C code into machine
code with the aid of a compiler.  

1. Source e.g rocks.c   
You start off by creating a source file. The source file 
contains human-readable C code.

2. Compile  e.g gcc rocks.c -o rocks
You run your source code through a compiler.
The compiler checks for errors, and once it’s happy, it compiles the
source code.  

3. Output e.g rocks  
The compiler creates a new file called an **executable**. This
file contains machine code, a stream of 1s and 0s that
the computer understands. And that’s the program you
can run.  

C is used where speed, space, and portability are important. Most
operating systems are written in C. Most other computer languages are
also written in C. And most game software is written in C.  

There are three C standards that you may stumble across. ANSI C is from the late 1980s and is used for the oldest code. A lot of things were fixed up in the C99 standard from 1999. And some cool new language features were added in the current standard, C11, released in 2011. The differences between the different versions aren’t huge, and we’ll point them out along the way.  

