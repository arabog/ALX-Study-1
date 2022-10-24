# Data Structures And Dynamic Memory
You could create a struct to represent a single island:
```
typedef struct {
          char *name;
          char *opens;
          char *closes;
} island;
```
**Arrays are fixed length, which means they’re not very flexible. To store a flexible amount of data, you need something more extensible than an array. You need a linked list.**   

## Linked lists are like chains of data
A linked list is an example of an abstract data structure.
It’s called an abstract data structure because a linked list is
general: it can be used to store a lot of different kinds of data.  
**A linked list stores a piece of data, and a link to another piece of data**
In a linked list, as long as you know where the list **starts**, you can
travel along the list of links, from one of piece of data to the next,
until you reach the end of the list.   

## Linked lists allow inserts
That’s another advantage linked lists have over arrays: inserting data is very quick. If you wanted to insert a value into the middle of an array, you would have to shuffle all the pieces of data that follow it along by one.   
So linked lists allow you to store a variable amount of data, and they make it simple to add more data.  

## But how do you create a linked list in C?
## Create a recursive structure
Each one of the structs in the list will need to connect to the one next to it. A struct that contains a link to **another struct of the same type** is called a recursive structure.  

Recursive structures contain pointers to other structures of the same type.

```
typedef struct island { // give d struct a name - island
          char *name;         /* use strings
          char *opens;           for d name
          char *closes;          and opening times */

          struct island *next; // store a pter to d next island in d struct
} island;
```
## N.B: Recursive structures need names.
**If you use the typedef command, you can normally skip giving the struct a proper name. But in a recursive structure, you need to include a pointer to the same type. C syntax won’t let you use the typedef alias, so you need to give the struct a proper name. That’s why the struct here is called struct island.**   

## Create islands in C…
Once you have defined an island data type, you can create
the first set of islands like this:
```
typedef struct island { 
          char *name;         
          char *opens;           
          char *closes;          

          struct island *next; 
} island;

This code will create island structs for each of the islands.

island amity = {"Amity", "09:00", "17:00", NULL};
island craggy = {"Craggy", "09:00", "17:00", NULL};
island isla_nublar = {"Isla Nublar", "09:00", "17:00", NULL};
island shutter = {"Shutter", "09:00", "17:00", NULL};
```
Did you notice that we originally set the next field in each island to NULL? **In C, NULL actually has the value 0, but it’s set aside specially to set pointers to 0.**  

## …and link them together to form a tour
Once you’ve created each island, you can then connect them together:
```
amity.next = &craggy;
craggy.next = &isla_nublar;
isla_nublar.next = &shutter;

You have to be careful to set the next field in each island to the address of the next island. You’ll use struct variables for each of the islands.  
So now you’ve created a complete island tour in C, but what if you want to insert an excursion to Skull Island between Isla Nublar and Shutter Island?  
```
## Inserting values into the list
You can insert islands just like you did earlier, by changing the values
of the pointers between islands:
```
island skull = {"Skull", "09:00", "17:00", NULL};
isla_nublar.next = &skull;
skull.next = &shutter;
```

## Yes, you need some way to create dynamic storage.
All of the programs you’ve written so far have used static storage. Every time you wanted to store something, you’ve added a variable to the code. Those variables have generally been stored in the stack. Remember: the stack is the area of memory set aside for storing local variables.  

**Programs need dynamic storage** 4

## Use the heap for dynamic storage
Most of the memory you’ve been using so far has been in the stack. The stack is the area of memory that’s used for local variables. Each piece of data is stored in a variable, and each variable disappears as soon as you leave its function.  

The trouble is, it’s harder to get more storage on the stack at runtime, and that’s where the heap comes in. The **heap** is the place where a program stores data that will need to be available longer term. It won’t automatically get cleared away, so that means it’s the perfect place to store data structures like our linked list.  

## First, get your memory with malloc()
Imagine your program suddenly finds it has a large amount of data that it needs to store at runtime. This is a bit like asking for a large storage locker for the data, and in C you do that with a function called malloc(). You tell the malloc() function exactly how much memory you need, and it asks the operating system to set that much memory aside in the heap. **The malloc() function then returns a pointer to the new heap space** It allows
you access to the memory, and it can also be used to keep track of the storage that’s been allocated.  

**The malloc() fxn will give u a pter to d space in d heap**  

## Give the memory back when you’re done
The good news about heap memory is that you can keep hold of it for a
really long time. The bad news is…you can keep hold of it for a really
long time.  
When you were just using the stack, you didn’t need to worry about
returning memory; it all happened automatically. Every time you leave a
function, the local storage is freed from the stack.  
The heap is different. Once you’ve asked for space on the heap, it
will never be available for anything else until you tell the C Standard
Library that you’re finished with it. There’s only so much heap memory
available, so if your code keeps asking for more and more heap space,
your program will quickly start to develop memory leaks.  

**A memory leak** happens when a program asks for more and more
memory without releasing the memory it no longer needs. Memory
leaks are among the most common bugs in C programs, and they can be
really hard to track down.  

## Free memory by calling the free() function
The malloc() function allocates space and gives you a pointer to it.
You’ll need to use this pointer to access the data and then, when you’re
finished with the storage, you need to release the memory using the
free() function. It’s a bit like handing your locker key back to the
attendant so that the locker can be reused.  

Every time some part of your code requests heap storage with the
malloc() function, there should be some other part of your code
that hands the storage back with the free() function. When
your program stops running, all of its heap storage will be released
automatically, but it’s always good practice to explicitly call free()
on every piece of dynamic memory you’ve created.  
**Let’s see how malloc() and free() work.**  

## Ask for memory with malloc()…
The function that asks for memory is called malloc() for memory allocation. malloc() takes a single parameter: the number of bytes that you need. Most of the time, you probably don’t know exactly how much memory you need in bytes, so malloc() is almost always used with an operator called sizeof, like this:
```
/* u need to include d stdlib.h header file to pick up d malloc() and free() fxn */
#include <stdlib.h> 

/*ds means "give me enough space to store an island struct"*/
malloc(sizeof(island)); 
```
sizeof tells you how many bytes a particular data type occupies on your system. It might be a struct, or it could be some base data type, like int or double.  

The malloc() function sets aside a chunk of memory
for you, then returns a pointer containing the **start address**. But what kind of pointer will that be? malloc() actually returns a general-purpose pointer, with type void*.
```
//cr8 enough space 4 an island & store d address in variable p
island *p = malloc(sizeof(island));
```
## …and free up the memory with free()
Once you’ve created the memory on the heap, you can use
it for as long as you like. But once you’ve finished, you need
to release the memory using the free() function.  
free() needs to be given the address of the memory that
malloc() created. As long as the library is told where the
chunk of memory starts, it will be able to check its records
to see how much memory to free up. So if you wanted to
free the memory you allocated above, you’d do it like this:
```
//release d memory u allocated from heap address p
free(p);
```
## Oh, no! It’s the out-of-work actors…
The aspiring actors are currently between jobs, so they’ve found some free time in their busy schedules to help you out with the coding. They’ve created a utility function to create a new island struct with a name that you pass to it. The function looks like this:
```
// This is the new function.
island* create(char *name) // The name of the island is passed as a char pointer.
{
          // This will create a new island struct on the heap.
          island *i = malloc(sizeof(island)); 
          // It’s using the malloc() function to create space on the heap.
          // The sizeof operator works out how many bytes are needed.
          
          // These lines set the fields on the new struct.
          i->name = name;
          i->opens = "09:00";
          i->closes = "17:00";
          i->next = NULL;

          // The function returns the address of the new struct.
          return i;
}

The function returns a pointer to the newly created
struct.
Create an array to store an island name.
char name[80];

Ask the user for the name of an island
fgets(name, 80, stdin);

island *p_island0 = create(name);
```
Arrival at second island. Weather good. No wind. Entering
details into new program.
```
Ask the user to enter the name of the second island.
fgets(name, 80, stdin);

This creates the second island.
island *p_island1 = create(name);

This connects the first island to d second island
p_island0->next = p_island1;

This will display the details of the list of islands using the function we created earlier.
display(p_island0);
```
When the code records the name of the island, it doesn’t take a copy of
the whole name string; it just records the address where the name string
lives in memory. Is that important? Where did the name string live? We
can find out by looking at the code that was calling the function:
```
char name[80];
fgets(name, 80, stdin);
island *p_island0 = create(name);
fgets(name, 80, stdin);
island *p_island1 = create(name);
```
The program asks the user for the name of each island, but both times
it uses the name local char array to store the name. That means that
**the two islands share the same name string**. As soon as the local
name variable gets updated with the name of the second island, the
name of the first island changes as well.

The strdup() function can reproduce a complete copy of the string somewhere on the heap.

The strdup() function works out how long the string is, and then
calls the malloc() function to allocate the correct number of
characters on the heap.

It then copies each of the characters to the new space on the heap.

That means that strdup() always creates space on the heap. It can’t create space on the stack because that’s for local variables, and local variables get cleared away too often.   
But because strdup() puts new strings on the heap, that means you must always remember to release their storage with the free() function.  

Let’s fix the code using the strdup() function
You can fix up the original create() function using the
strdup() function, like this:
```
island* create(char *name)
{
island *i = malloc(sizeof(island));
i->name = strdup(name);
i->opens = "09:00";
i->closes = "17:00";
i->next = NULL;
return i;
}
```
You can see that we only need to put the strdup() function on
the name field. Can you figure out why that is?  
It’s because we are setting the opens and closes fields to string
literals. Remember way back when you saw where things were
stored in memory? String literals are stored in a read-only area
of memory set aside for constant values. Because you always
set the opens and closes fields to constant values, you don’t
need to take a defensive copy of them, because they’ll never
change. But you had to take a defensive copy of the name array,
because something might come and update it later.  

Q: If the island struct had a name array rather than a character pointer,
would I need to use strdup() here?  
A: No. Each island struct would store its own copy, so you wouldn’t need to make your own copy.  

Q: So why would I want to use char pointers rather than char arrays in my
data structures?  
A: char pointers won’t limit the amount of space you need to set aside for strings. If you use char arrays, you will need to decide in advance exactly how long your strings might need to be.  

```
island *start = NULL;
island *i = NULL;
island *next = NULL;
char name[80];

for(; fgets(name, 80, stdin) != NULL; i = next) {
          <!-- This creates an island. -->
          next = create(name);

          if (start == NULL)
          <!-- The first time through, start is set to NULL, so set it to the first island. -->
                    start = next;

          if (i != NULL)
                    i->next = next;
}

display(start);

fgets(name, 80, stdin): Read a string from the Standard Input

!= NULL; We’ll keep looping until we don’t get any more strings.

i = next: At the end of each loop, set i to the next island we created.
```
But wait! You’re not done yet. Don’t forget that if you ever
allocate space with the malloc() function, you need to
release the space with the free() function. The program
you’ve written so far creates a linked list of islands in heap
memory using malloc(), but now it’s time to write some code
to release that space once you’re done with it.

```
void release(island *start)
{
island *i = start;
island *next = NULL;
for (; i != NULL; i = next) {
next = i->next; // Set next to point to the next island.
free(i->name); // First, you need to free the name string that you created with strdup().
free(i); // Only after freeing the name should you free the island struct.
}
}

If you’d freed the island first, you might not have been able to reach the name to free it.
```
## Free the memory when you’re done
Now that you have a function to free the linked list, you’ll
need to call it when you’ve finished with it. Your program
only needs to display the contents of the list, so once you’ve
done that, you can release it:
```
display(start);
release(start);
```
Dynamic memory allocation lets you create the memory you need at RUNTIME. And the way you access dynamic heap memory is with malloc() and free().

