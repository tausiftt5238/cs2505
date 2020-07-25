struct _Location {        // declare type globally
   int X, Y;
};

typedef struct _Location Location;  // alias a type name

void initLocation(Location* L, int x, int y) {

   (*L).X = x;    // alternative:  L->X = x;
   L-> Y = y;       // I prefer this one;
}
