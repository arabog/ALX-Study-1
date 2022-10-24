#include <stdio.h>
#include <stdlib.h>



typedef struct island { 
          char *name;         
          char *opens;           
          char *closes;          

          struct island *next; 
} island;


island amity = {"Amity", "09:00", "17:00", NULL};
island craggy = {"Craggy", "09:00", "17:00", NULL};
island isla_nublar = {"Isla Nublar", "09:00", "17:00", NULL};
island shutter = {"Shutter", "09:00", "17:00", NULL};

amity.next = &craggy;
craggy.next = &isla_nublar;
isla_nublar.next = &shutter;
island skull = {"Skull", "09:00", "17:00", NULL};
isla_nublar.next = &skull;
skull.next = &shutter;

display(&amity);

void display(island *start)
{
          island *i = start;

          //for (; : You don’t need any extra code at the start of the loop
          // i != NULL; You need to keep looping until d current island has no next value.
          // i->next: At the end of each loop, skip to the next island.
          for (; i != NULL; i = i->next) {
                    printf("Name: %s open: %s-%s\n", i->name, i->opens, i->closes);
          }
}
