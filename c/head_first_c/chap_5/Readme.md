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

stops at 227