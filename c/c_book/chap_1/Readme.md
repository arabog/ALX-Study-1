## The form of a C program
The language permits separate compilation, where the parts of a complete program can be kept in one or more source files and compiled independently of each other. The idea is that the compilation process will produce files which can then be linked together using whatever link editor or loader that your system provides.  

The reason for C's approach is historical and rather interesting. It is supposed to speed things up: the idea is that compiling a program into relocatable object code is slow and expensive in terms of resources; compiling is hard work. Using the loader to bind together a number of object code modules should simply be a matter of sorting out the absolute addresses of each item in the modules when combined into a complete program. This should be relatively inexpensive. The expansion of the idea to arrange for the loader to scan libraries of object modules, and select the ones that are needed, is an obvious one. The benefit is that if you change one small part of a program then the expense of recompiling all of it may be avoided; only the module that was affected has to be recompiled.  

For C, the work that has to be done by the loader is not large and the approach is a sensible one.  
![c1](c1.png?raw=true "c1")

This technique is important in C, where it is common to find all but the smallest of programs constructed from a number of separate source files. Furthermore, the extensive use that C makes of libraries means that even trivial programs pass through the loader, although that might not be obvious at the first glance or to the newcomer.  

## Functions
A C program is built up from a collection of items such as functions and what we could loosely call global variables. The rules are described in the Standard using the term linkage. For the moment we only need to concern ourselves with **external linkage** and **no linkage**. Items with external linkage are those that are accessible throughout the program (library functions are a good example); items with no linkage are also widely used but their accessibility is much more restricted. Variables used inside functions are usually ‘local’ to the function; they have no linkage.  

In a hosted environment there is one function whose name is special; it's the one called main.  
```
#include <stdio.h>
/*
* Tell the compiler that we intend
* to use a function called show_message.
* It has no arguments and returns no value
* This is the "declaration".
*
*/
it tells the compiler that show_message is a function which takes no arguments and returns no values.
void show_message(void);
/*
* Another function, but this includes the body of
* the function. This is a "definition".
*/

main(){
    int count;
    count = 0;

    while(count < 10){
        show_message();
        count = count + 1;
    }

    exit(0);
}

/*
* The body of the simple function.
* This is now a "definition".
*/

void show_message(void){
    printf("hello\n");
}
```
### Layout and comment
C allows you to put space, tab or newline characters practically
anywhere in the program without any special effect on the meaning of the program. All of those three characters are the same as far as the compiler is concerned and are called collectively white space, because they just move the printing position without causing any ‘visible’ printing on an output device. White space can occur practically anywhere in a program except in the middle of identifiers, strings, or character constants. An identifier is simply the name of a function or some other object.  

Comment is introduced to a C program by the pair of characters /*.

C compiler used to have two phases: the preprocessor, followed by the real
compiler. The preprocessor was a macro processor, whose job was to perform
simple textual manipulation of the program before passing the modified text on to be compiled. The preprocessor rapidly became seen as an essential aspect of the compiler and so has now been defined as part of the language and cannot be
bypassed.  

Any line whose first visible character is a # is a preprocessor
directive. In Example above, the preprocessor directive` #include` causes the line containing it to be replaced completely by the contents of another file. In this case the filename is found between the < and > brackets. This is a widely used technique to incorporate the text of standard header files into your program without having to go through the effort of typing it all yourself. The `<stdio.h>` file is an important one, containing the
necessary information that allows you to use the standard library for input and
output.  

## Define statements
Another of the preprocessor's talents which is widely exploited is the #define
statement. It is used like this:
```
#define IDENTIFIER  replacement
```
which says that the name represented by IDENTIFIER will be replaced by the text of replacement whenever IDENTIFIER occurs in the program text. Invariably, the identifier is a name in upper-case; this is a stylistic convention that helps the reader to understand what is going on. The replacement part can be any text at all remember the preprocessor doesn't know C, it just works on text. The most common use of the statement is to declare names for constant numbers:
```
#define     PI              3.141592
#define     SECS_PER_MIN    60
#define     MINS_PER_HOUR   60
#define     HOURS_PER_DAY   24
```
and to use them like this
```
circumf = 2*PI*radius;
if(timer >= SECS_PER_MIN){
    mins = mins + 1;
    timer = timer - SECS_PER_MIN;
}
```
`#define` statements are typically used to give names for constants. By convention, the names are in upper case (capitalized).  

The distinction between a declaration and a definition is that the former
simply describes the type of the function and any arguments that it might take, the latter is where the body of a function is provided.  

By declaring show_message before it is used, the compiler is able to check that it is used correctly. The declaration describes three important things about the function: its name, its type, and the number and type of its arguments. The void show_message( part indicates that it is a function and that it returns a value of type void. The second use of void is in the declaration of the function's argument list, (void) , which indicates that there are no arguments to this function.  

C simply uses functions with the type of the function's return value specified when the function is defined. In the example, the function show_message doesn't return a value so we specify that its type is void. 
```
void show_message()
```
void means "I don't want to do anything with any value this function might or might not return”.  
The type of the function is void , its name is show_message. The parentheses ()
following the function name are needed to let the compiler know that at this point we are talking about a function and not something else. If the function did take any arguments, then their names would be put between the parentheses. This one doesn't take any, which is made explicit by putting void between the parentheses. 
```
void show_message(void){
    printf("hello\n");
}
```
The statement inside show_message is a call of the library function printf . printf is used to format and print things. printf takes one or more arguments, whose values are passed forward from the point of the call into the function itself. In this case the argument is a string. The contents of the string are interpreted by printf and used to control the way the values of the other arguments are printed.  

## Summary
Declarations are used to introduce the name of a function, its return type and the type (if any) of its arguments.  
A function definition is a declaration with the body of the function given too.  
A function returning no value should have its type declared as void . For example, void func(/* list of arguments */);  
A function taking no arguments should be declared with void as its argument list. For example, void func(void);  

## Strings
In C, strings are a sequence of characters surrounded by quote marks:
"like this".  

Because a string is a single element, a bit like an identifier, it is not allowed to continue across a line—although space or tab characters are permitted inside a string.  
"This is a valid string"  
"This has a newline in it  
and is NOT a valid string"  
To get a very long string there are two things that you can do. You could take
advantage of the fact that absolutely everywhere in a C program, the sequence
‘backslash end-of-line’ disappears totally.  
"This would not be valid but doesn't have \  
a newline in it as far as the compiler is concerned"  

The other thing you could do is to to use the string joining feature, which says that two adjacent strings are considered to be just one.  
"All this " "comes out as "  
"just one string"  

Back to the example. The sequence ‘ \n ’ in the string is an example of an escape sequence which in this case represents ‘newline’. Printf simply prints the contents of the string on the program's output file, so the output will read ‘hello’, followed by a new line.  

## The main function
The function is not declared to be void . There is a good reason for this: it returns a proper value. The most important thing about main is that it is the first function to be called.  

The default type of functions is int, so it is common to see them used in this way. An equivalent declaration for main would have been `int main(){}`  

You can't use the same feature to get a default type for variables because their types must be provided explicitly.  


pg31
