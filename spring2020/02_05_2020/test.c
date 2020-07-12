#include <stdio.h> // needed for printf, fprintf, scanf, fscanf
/*
If you want to compile this code:
```gcc test.c -o run``` 
run is just my executable's name
if you want to run the code:
```./run```
*/

int main(){
	// fopen(param1, param2), over here, param1 is the address to your input file
	// in my case, I'm using input.txt. In this case, the file needs to be in the same directory.
	// I could've written something like /home/user/documents/input.txt
	// In that case, it'd open a input.txt file that is available at the address /home/user/documents.
	// "r" specifies that the file will be opened in R-ead mode.
	FILE *f = fopen("input.txt", "r");	
	// Same as read, but in this case we are specifying that it will be opened in the W-rite mode.
	FILE *o = fopen("output.txt", "w");
	// In C, the concept of String doesn't exist. we use Character array, i'm declaring character array of the size 100. the variable is named str in this case. 
	char str[100];
	//both scanf and fscanf returns the number of variables they have read.
	// for example, scanf("%d %d", &a, &b) will return 2. 
	// in our case, it's reading one variable called str, thus will return 1.
	// if it failed to read anything (it's at the end of the file), it will stop.
	// This is a nice way to make sure you are reading everything.
	// you can also use EOF to decide the end of file (look it up online).
	// Another thing to notice here is, fscanf(param1, param2, param3) uses, param1 as the file it wants to read, param2 as the format specifier, param3 as the string it's going to store its' value to.
	// One thing I forgot to mention, usually scanf/fscanf needs & before the variable, but for string (character arrays), you don't need that.
	while(fscanf(f, "%s",str) == 1){
		// Format is same as fscanf, fprintf also takes param1 as the file it wants to write to.
		fprintf(o, "%s\n", str);
	}
	// Always remember to close the file, SPECIALLY if you opened it to write.
	fclose(f); 
	fclose(o);
	return 0;

}
