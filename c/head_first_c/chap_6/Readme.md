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
