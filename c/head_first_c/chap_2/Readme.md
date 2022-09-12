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
To understand what pointers are, you’ll need to dig into the memory of the computer.  
Every time you declare a variable, the computer creates space for it somewhere in memory. If you declare a variable inside a function like main(), the computer will store it in a section of memory called the **stack**. If a variable is declared outside any function, it will be stored in the **globals** section of memory.  
```
int y = 4;

int main(){
    int x = 4;
    return 0;
}
```
The computer might allocate, say, memory location 4,100,000 in the stack for the x variable. If you assign the number 4 to the variable, the computer will store 4 at location 4,100,000.  

If you want to find out the memory address of the variable, you can use the **&** operator:  
```
printf("x is stored at %p\n", &x);
%p: is used to format address  
&x: is d address of x  
```
The address of the variable tells you where to find the variable in memory. That’s why an address is also called a pointer, because it points to the variable in memory.  
When you call a function, you don’t send the variable as an argument, just its value.  
**Instead of passing the value of the variable (by copy), pass its location.**  

Q: Why are local variables stored in the stack and globals stored somewhere else?
A: Local and global variables are used differently. You will only ever get one copy of a global variable, but if you write a function that calls itself, you might get very many instances of the same local variable.  

## Pointers make it easier to share memory
This is one of the main reasons for using pointers—to let functions
share memory. The data created by one function can be modified by
another function, so long as it knows where to find it in memory.  

## Using memory pointers
There are three things you need to know in order to use pointers to read and write data.  
1. Get the address of a variable  
You can find where a variable is stored in memory using the `&` operator:  
```
int = 4;
printf("x lives at %p\n", &x);
```
d **%p** format will print out d **loctation in hex** (base 16) format.  
**&** will find the **address** of d location.  
Once you’ve got the address of a variable, you may want to store it
somewhere. To do that, you will need a **pointer variable**. A pointer
variable is just a variable that stores a memory address. When you
declare a pointer variable, you need to say what kind of data is stored
at the address it will point to:  
```
int *address_of_x = &x;
```
2. Read the contents of an address.  
When you have a memory address, you will want to read the data that’s stored there.   
You do that with the `*` operator:
```
int value_stored = *address_of_x;
```
The `*` and `&` operators are opposites. The `&` operator takes a piece
of data and tells you where it’s stored. The `*` operator takes an
address and tells you what’s stored there. Because pointers are
sometimes called references, the `*` operator is said to dereference
a pointer.

3. Change the contents of an address.  
If you have a pointer variable and you want to change the data
at the address where the variable’s pointing, you can just use the `*`
operator again. But this time you need to use it on the left side of
an assignment:
```
*address_of_x = 99;
```
Example
```
#include <stdio.h>  
void go_south_east(int *lat, int *lon) {
    *lat = *lat - 1;
    *lon = *lon - 1;
}

int main() {
    int latitude = 32;
    int longitude = -64;

    go_south_east(&latitude, &longitude);

    printf("Avast! Now at: [%i, %i]\n", latitude, longitude);

    return 0;
}
```
## The code works.
Because the function takes pointer arguments, it’s able to update the original latitude and longitude variables. That means that you now know how to create functions that not only return values, but can also update any memory locations that are passed to them.  

### Bullet Points
Variables are allocated storage in memory.  
Local variables live in the stack. 
Global variables live in the globals section.  

Pointers are just variables that store memory addresses.  
e.g int *pointer = &address  
The & operator finds the address of a variable.  
The * operator can read the contents of a memory address.  
The * operator can also set the contents of a memory address.  

Q: Why do I have to print out pointers using the `%p` format string?   
A: You don’t have to use the `%p` string. On most modern machines, you can use
`%li` —although the compiler may give you a warning if you do.  

## How do you pass a string to a function?
You know how to pass simple values as arguments to functions, but what
if you want to send something more complex to a function, like a string?
If you remember from the last chapter, strings in C are actually arrays of
characters. That means if you want to pass a string to a function, you can
do it like this:  
```
#include <stdio.h>

void fortune_cookie(char msg[]) {
    printf("Message reads: %s\n", msg);
}


int main() {
    char quote[] = "Cookies make you fat";
    
    fortune_cookie(quote);
}
```
The msg argument is defined like an array, but because you won’t know how long the string will be, the msg argument doesn’t include a length. That seems straightforward, but there’s something a little strange going on…  

C has an operator called `sizeof` that can tell you how many bytes of space something takes in memory. You can either call it with a data type or with a piece of data:  
`sizeof(int)` On most machines, this will return the value 4.  
`sizeof("Turtles!")` This will return 9, which is 8 characters plus the \0 end character.  
But a strange thing happens if you look at the length of the string you’ve passed in the function:
```
void fortune_cookie(char msg[]){
    printf("Message reads: %s\n", msg);
    printf("msg occupies %i bytes\n", sizeof(msg));
}
```
8??? And on some machines, this might even say 4! What gives?  
Instead of displaying the full length of the string, the code returns
just 4 or 8 bytes. What’s happened? Why does it think the string
we passed in is shorter?  

Why do you think sizeof(msg) is shorter than the length of the whole string? What is msg? Why would it return different sizes on different machines?  


