#include <stdio.h>
#include "myheader.h"
#include "myheader.h"

 
#ifdef SOMETHING

printf("This is something that should be printed\n");

#endif

int main(){
	print("I want this to be printed\n");
	return 0;	
}
