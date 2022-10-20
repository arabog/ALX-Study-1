/*
#include <stdio.h>  
void go_south_east(int lat, int lon) {
    
    // When the go_south_east() function changes the value of lon, 
    // the function is just changing its local copy
    
    lat = lat - 1;
    lon = lon + 1;
}

int main() {
    int latitude = 32;
    int longitude = -64;

    go_south_east(latitude, longitude);

    printf("Avast! Now at: [%i, %i]\n", latitude, longitude);

    return 0;
}
*/


#include <stdio.h>

void go_south_east(int *lat, int *lon){ /*int *lat/*lon is used to store pter/address*/
    *lat = *lat - 1;
    *lon = *lon + 1;
}

int main(){
    int latitude = 32;
    int longitude = -64;

    go_south_east(&latitude, &longitude);

    printf("Avast! Now at: [%i, %i]\n", latitude, longitude);
}
