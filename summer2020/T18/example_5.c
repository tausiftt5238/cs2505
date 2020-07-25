struct _Location {        // declare type globally
   int X, Y;
};

typedef struct _Location Location;  // alias a type name

Location updateLocation(Location Old, Location Move) {

   Location Updated;             // make a local Location object
   Updated.X = Old.X + Move.X;   // compute its members
   Updated.Y = Old.Y + Move.Y;

   return Updated;               // return copy of local object
}
