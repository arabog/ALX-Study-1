# Memory and Pointers
If you really want to kick butt with C, you need to understand
how C handles memory. The C language gives you a lot more control over how your program uses the computer’s memory. In this chapter, you’ll strip back the covers and see exactly what happens when
you read and write variables. You’ll learn how arrays work and you’ll see how mastering pointers and memory addressing is key to becoming a kick-ass C programmer.  

## C code includes pointers
Pointers are one of the most fundamental things to understand in the C programming language. So what’s a pointer? **A pointer is just the address of a piece of data in memory.** It's the location of the information/data. 

Pointers are used in C for a couple of reasons.  
1. Instead of passing around a whole copy of the data, you can just pass a pointer.    
2. You might want two pieces of code to work on the same piece of data rather than a separate copy.  

**The trick to learning how to use C pointers is to go slowly.**  

## Digging into memory
