#ifndef LOCATION_H
#define LOCATION_H

typedef struct _Location{
    int x;
    int y;
} Location;

void initLocation(Location* L, int x, int y){
    (*L).x = x;
    L->y = y;
}

#endif