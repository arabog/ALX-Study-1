# Structs, Unions, and Bitfields
Take a look at this example. Here you have two functions that both need the same set of data,
because they are both dealing with the same real-world thing:
```
<!-- Both of these functions take the same set of parameters. -->
/* Print out the catalog entry */
<!-- “const char *” just means you’regoing to pass string literals. -->
void catalog(const char *name, const char *species, int teeth, int age)
{
printf("%s is a %s with %i teeth. He is %i\n", name, species, teeth, age);
}

/* Print the label for the tank */
void label(const char *name, const char *species, int teeth, int age)
{
printf("Name:%s\nSpecies:%s\n%i years old, %i teeth\n", name, species, teeth, age);
}
```
But even though you’re just passing four pieces of data, the code’s starting to look a little
messy:
```
You are passing the same four pieces of data twice.
There’s only one fish, but you’re passing four pieces of data.

int main()
{
catalog("Snappy", "Piranha", 69, 4);
label("Snappy", "Piranha", 69, 4);
return 0;
}
```
What can you do to avoid passing around lots and lots of data if you’re really only
using it to describe a single thing?  

## Create your own structured data types with a struct
If you have a set of data that you need to bundle together into
a single thing, then you can use a struct. The word struct is
short for structured data type. A struct will let you take
all of those different pieces of data into the code and wrap them
up into one large new data type, like this:
```
struct fish {
          const char *name;
          const char *species;
          int teeth;
          int age;
};
```
This will create a new custom data type that is made up of a
collection of other pieces of data. In fact, it’s a little bit like an
array, except:  
It’s fixed length.  
The pieces of data inside the struct are given names.  

But once you’ve defined what your new struct looks like, how do you
create pieces of data that use it? Well, it’s quite similar to creating a new
array. You just need to make sure the individual pieces of data are in the
order that they are defined in the struct:
```
struct fish snappy = {"Snappy", "Piranha", 69, 4};

“struct fish” is the data type.
“snappy” is the variable name.

"Snappy": This is the name.
"Piranha": This is the species.
69: This is the number of teeth.
4: This is Snappy’s age.
```
Q: Hey, wait a minute. What’s that const char thing again?
A: const char * is used for strings that you don’t want to change. That means
it’s often used to record string literals.  

Q: OK. So does this struct store the string?  
A: In this case, no. The struct here just stores a pointer to a string. That means it’s just recording an address, and the string lives somewhere else in memory.    

Q: But you can store the whole string in there if you want?
A: Yes, if you define a char array in the string, like char name[20];.  

## Just give them the fish
Now, instead of having to pass around a whole collection of
individual pieces of data to the functions, you can just pass your
new custom piece of data:
```
/* Print out the catalog entry */
void catalog(struct fish f)
{
printf("%s is a %s with %i teeth. He is %i\n", name, species, teeth, age);
}

/* Print the label for the tank */
void label(struct fish f)
{
printf("Name:%s\nSpecies:%s\n%i years old, %i teeth\n", name, species, teeth, age);
}
```
Looks a lot simpler, doesn’t it? Not only does it mean the
functions now only need a single piece of data, but the code that
calls them is easier to read:
```
struct fish snappy = {"Snappy", "Piranhan", 69, 4};
calalog(snappy);
label(snappy);
```

## Read a struct’s fields with the “.” operator
Because a struct’s a little like an array, you might think you
can read its fields like an array:
```
struct fish snappy = {"Snappy", "piranha", 69, 4};

<!-- If snappy was a pointer to an array, you would access the first field like this. -->
printf("Name = %s\n", snappy[0]);
<!-- You get an error if you try to read a struct field like it’s an array. -->
```
But you can’t. Even though a struct stores fields like an array,
the only way to access them is by name. You can do this using
the “.” operator. If you’ve used another language, like JavaScript
or Ruby, this will look familiar:
```
struct fish snappy = {"Snappy", "piranha", 69, 4};
printf("Name = %s\n", snappy.name);
```
Q: An array variable is just a pointer to the array. Is a
struct variable a pointer to a struct?
A: No, a struct variable is a name for the struct itself.

## Structs In Memory Up Close
When you define a struct, you’re not telling the computer to
create anything in memory. You’re just giving it a template for
how you want a new type of data to look.
```
struct fish {
const char *name;
const char *species;
int teeth;
int age;
};
```
But when you define a new variable, the computer will need to
create some space in memory for an instance of the struct.
That space in memory will need to be big enough to contain all of
the fields within the struct.

So what do you think happens when you assign a struct to another
variable? Well, the computer will create a brand-new copy of the
struct. That means it will need to allocate another piece of memory
of the same size, and then copy over each of the fields.
```
struct fish snappy = {"Snappy", "Piranha", 69, 4};
struct fish gnasher = snappy;
```
**Remember: when you’re assigning struct variables, you are telling the computer to copy data.**  
**The assignment copies the pointers to strings, not the strings themselves.**  
When you assign one struct to another, the contents of the struct will be copied. But if, as here, that includes pointers, the assignment will just copy the pointer values. That means the name and species fields of gnasher and snappy both point to the same strings.  

## Can you put one struct inside another?
Remember that when you define a struct, you’re actually creating a new data type. C gives us lots of built-in data types like ints and shorts, but a struct lets us combine existing types together so that you can describe more complex objects to the computer.  
But if a struct creates a data type from existing data types, that means you can also create structs from other structs. To see how this works, let’s look at an example.  
```
<!-- These are things our fish likes. -->
struct preferences {
          const char *food;
          float exercise_hours;
}

struct fish {
          const char *name;
          const char *species;
          int teeth;
          int age;

          /* This is a new field
          This is a struct inside a struct. This is called nesting
          Our new field is called “care,” but it will contain fields defined by the “preferences” struct.
          */
          struct preference care;
}
```
You can then create variables using the same array-like code as before, but now you can include the data for one struct inside another:
```
struct fish snappy = {"Snappy", "Piranha", 69, 4, {"Meat", 7.5}};

Once you’ve combined structs together, you can access the
fields using a chain of “.” operators:

printf("Snappy likes to eat %s", snappy.care.food);
printf("Snappy likes to exercise for %f hours", snappy.care.exercise_hours);
```
## You can give your struct a proper name using typedef.
When you create variables for built-in data types, you can use simple short
names like int or double, but so far, every time you’ve created a variable
containing a struct you’ve had to include the struct keyword.
```
struct cell_phone {
int cell_no;
const char *wallpaper;
float minutes_of_charge;
};

struct cell_phone p = {5557879, "sinatra.png", 1.35};
```
But C allows you to create an alias for any struct that
you create. If you add the word typedef before the struct
keyword, and a type name after the closing brace, you can call
the new type whatever you like:
```
typedef struct cell_phone { // typedef means you are going to give the struct type a new name.
int cell_no;
const char *wallpaper;
float minutes_of_charge;
} phone; // hone will become an alias for "struct cell_phone"

Now, when the compiler sees “phone,” it will treat it like “struct cell_phone.”
phone p = {5557879, "sinatra.png", 1.35};
```
typedefs can shorten your code and make it
easier to read. Let’s see what your code will look
like if you start to add typedefs to it…

## What should I call my new type?
If you use typedef to create an alias for a struct, you will need to decide what your alias will be. The alias is just the name of your type. That means there are two names to think about: the name of the struct (struct cell_phone) and the name of the type (phone). Why have two names? You usually don’t need both. The compiler is quite happy for you to skip the struct name, like this:
```
typedef struct {
int cell_no;
const char *wallpaper;
float minutes_of_charge;
} phone;  // This is the alias.

phone p = {5557879, "s.png", 1.35};
```
## Bullet Points
```
A struct is a data type made from a sequence of other data types.
struct fields are stored in memory in the same order they appear in the code.
structs are/have fixed length.
You can nest structs.
struct fields are accessed by name, using the <struct>.<field name> syntax (aka dot notation).
typedef creates an alias for a data type.
If you use typedef with a struct, then you can skip giving the struct a name.
```
## How do you update a struct?
A struct is really just a bundle of variables, grouped together and
treated like a single piece of data. You’ve already seen how to create
a struct object, and how to access its values using dot notation.
But how do you change the value of a struct that already exists?
Well, you can change the fields just like any other variable:
```
This creates a struct.
fish snappy = {"Snappy", "piranha", 69, 4};

This reads the value of the name field.
printf("Hello %s\n", snappy.name);

This sets the value of the teeth field
snappy.teeth = 68;
```
That means if you look at this piece of code, you should be able to
work out what it does, right?
```
#include <stdio.h>

typedef struct {
const char *name;
const char *species;
int age;
} turtle;

void happy_birthday(turtle t)
{
t.age = t.age + 1;
printf("Happy Birthday %s! You are now %i years old!\n",
t.name, t.age);
}

int main()
{
turtle myrtle = {"Myrtle", "Leatherback sea turtle", 99};
happy_birthday(myrtle);
printf("%s's age is now %i\n", myrtle.name, myrtle.age);
return 0;
}
```
**But there’s something odd about this code…**  

## The code is cloning the turtle
Let’s take a closer look at the code that called the happy_birthday() function:
```
void happy_birthday(turtle t)
{
...
}

<!-- This is the turtle (myrtle) that we are passing to the function. -->
happy_birthday(myrtle);
<!-- The myrtle struct will be copied to this parameter. -->
```

In C, parameters are passed to functions by value. That
means that when you call a function, the values you pass into
it are assigned to the parameters. So in this code, it’s almost as
if you had written something like this:
```
turtle t = myrtle;
```
But remember: when you assign structs in C, the values are copied. When you call the function, the parameter t will contain a copy of the myrtle struct. It’s as if the function has a clone of the original turtle. So the code inside the function does update the age of the turtle, but it’s a different turtle.  
What happens when the function returns? The t parameter disappears, and the rest of the code in main() uses the myrtle struct. But the value of myrtle was never
changed by the code. It was always a completely separate piece of data.  

**So what do you do if you want pass a struct to a function that needs to update it?**  

## You need a pointer to the struct
When you passed a variable to the scanf() function, you couldn’t
pass the variable itself to scanf(); you had to pass a pointer:
```
scanf("%f", &length_of_run);
```
Why did you do that? Because if you tell the scanf() function where the variable lives in memory, then the function will be able to update the data stored at that place in memory, which means it can update the variable.  
And you can do just the same with structs. If you want a function to update a struct variable, you can’t just pass the struct as a parameter because that will simply send a copy of the data to the function. Instead, you can pass the address of the struct:
```
(turtle *t) // This means “Someone is going to give me a pointer to a struct. Remember: an address is a pointer

void happy_birthday(turtle *t) 
{
...
}

happy_birthday(&myrtle);
(&myrtle) //This means you will pass the address of the myrtle variable to the function.

That is:
#include <stdio.h>


typedef struct {
const char *name;
const char *species;
int age;
} turtle;

void happy_birthday(turtle *t)
{
(*t).age = (*t).age + 1;
printf("Happy Birthday %s! You are now %i years old!\n", (*t).name, (*t).age);
}

int main()
{
turtle myrtle = {"Myrtle", "Leatherback sea turtle", 99};
happy_birthday(&myrtle);
printf("%s's age is now %i\n", myrtle.name, myrtle.age);
return 0;
}
```

## (*t).age vs. *t.age
So why did you need to make sure that *t was wrapped in
parentheses? It’s because the two expressions, (*t).age
and *t.age, are very different.
```
(*t).age = *t.age

(*t).age: I am the age of the turtle pointed to by t.
If t is a pointer to a turtle struct, then this is the age of the turtle

*t.age: I am the contents of the memory location given by t.age.
If t is a pointer to a turtle struct, then this expression is wrong.
```
So the expression *t.age is really the same as *(t.age). It means “the contents of the memory location given by t.age.” But t.age isn’t a memory location.  

**So be careful with your parentheses when using structs—parentheses really matter.**  

By passing a pointer to the struct, you allowed the function to update the original data rather than taking a local copy.

# t->age means (*t).age
So, t->age means, “The age field in the struct that t
points to,” That means you can also write the function like this:
```
void happy_birthday(turtle *a)
{
a->age = a->age + 1;
printf("Happy Birthday %s! You are now %i years old!\n", a->name, a->age");
}
```
Q: Why isn’t *t.age just read as (*t).age?
A: Because the computer evaluates the dot operator before it evaluates the *.  

**pointer->field is the same as (*pointer).field.**  

## Sometimes the same type of thing needs different types of data
structs enable you to model more complex things from the real
world. But there are pieces of data that don’t have a single data type. 

So if you want to record, say, a quantity of something, and that
quantity might be a count, a weight, or a volume, how would you
do that? Well, you could create several fields with a struct, like this:
```
typedef struct {
...
short count;
float weight;
float volume;
...
} fruit;
```
But there are a few reasons why this is not a good idea:
```
It will take up more space in memory.
Someone might set more than one value.
There’s nothing called “quantity.”
```
It would be really useful if you could specify something called
quantity in a data type and then decide for each particular piece
of data whether you are going to record a count, a weight, or a
volume against it.  
**In C, you can do just that by using a union.**  

## A union lets you reuse memory space
Every time you create an instance of a struct, the computer
will lay out the fields in memory, one after the other:
```
| char *name | int age | float weight |

char *name: This is a char pointer to the name.
int age: This is space for the age as an int.
float weight: This is a float to store the weight.

Dog d = {"Biff", 2, 98.5};
```
A union is different. A union will use the space for just one
of the fields in its definition. So, if you have a union called
quantity, with fields called count, weight, and volume,
the computer will give the union enough space for its largest
field, and then leave it up to you which value you will store in
there. Whether you set the count, weight, or volume field,
the data will go into the same space in memory:
```
quantity (might be a float or a short);

If a float takes 4 bytes, and a short takes 2, then this space will be 4 bytes long
A union looks like a struct, but it uses the union keyword.

typedef union {
<!-- 
Each of these fields will be stored in the same space. 
These are all different types, but they’re all quantities.
-->
short count;
float weight;
float volume;
} quantity;
```
## How do you use a union?
When you declare a union variable, there are a few ways of setting its value.

## C89 style for the first field
If the union is going to store a value for the first field,
then you can use C89 notation. To give the union a
value for its first field, just wrap the value in braces:
```
quantity q = {4}; // This means the quantity is a count of 4
```
## Designated initializers set other values
A designated initializer sets a union field value by
name, like this:
```
quantity q = {.weight=1.5};  // This will set the union for a floating-point weight value.
```
## Set the value with dot notation
The third way of setting a union value is by creating the
variable on one line, and setting a field value on another
line:
```
quantity q;
q.volume = 3.7;
```
**Remember:** whichever way you set the union’s value, there will only ever be one piece of data stored. The union just gives you a way of creating a variable that supports several different data types.  

Q: Why is a union always set to the size of the largest field?  
A: The computer needs to make sure that a union is always the same size. The only way it can do that is by making sure it is large enough to contain any of the fields.  

Q: Why does the C89 notation only set the first field? Why not set it to the first float if I pass it a float value?   
A: To avoid ambiguity. If you had, say, a float and a double field, should the computer store {2.1} as a float or a double? By always storing the value in the first field, you know exactly how the data will be initialized.  

**Yes, designated initializers can be used to set the initial values of fields in structs as well.**  
They can be very useful if you have a struct that contains a large
number of fields and you initially just want to set a few of them. It’s
also a good way of making your code more readable:
```
typedef struct {
const char *color;
int gears;
int height;
} bike;

// This will set the gears and the height fields, but won’t set the color field.

bike b = {.height=17, .gears=21};
```

## unions are often used with structs
Once you’ve created a union, you’ve created a new data type. That means you can use its values anywhere you would use another data type like an int or a struct. For example, you can combine them with structs:
```
typedef struct {
const char *name;
const char *country;
quantity amount;
} fruit_order;
```
And you can access the values in the struct/union combination using the dot or -> notation you used before:
```
It’s .amount because that’s the name of the struct quantity variable.

fruit_order apples = {"apples", "England", .amount.weight=4.2};

printf("This order contains %2.2f lbs of %s\n", apples.amount.weight, apples.name);
This will print “This order contains 4.20 lbs of apples.”
stops at 257
```
