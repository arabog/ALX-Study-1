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