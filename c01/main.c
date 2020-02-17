#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum FilterAction
{
	HIFIRST,
	LOFIRST
};

void
solution(int number, enum FilterAction action, int pivot)
{

	int position = 1;
	int right = 0;
	int middle = 0;
	int left = 0;
	if (action == LOFIRST)
	{
		// building right
		int temp = number;
		while (temp)
		{
			int check = temp % 10;
			if (check > pivot)
			{
				right += check * position;
				position *= 10;
				printf("Right: %d\n", right);
			}
			temp /= 10;
		}
		//building middle
		temp = number;
		while (temp)
		{
			int check = temp % 10;
			if (check == pivot)
			{
				middle += check * position;
				position *= 10;
				printf("middle: %d\n", middle);
			}
			temp /= 10;
		}
		//building left
		temp = number;
		while (temp)
		{
			int check = temp % 10;
			if (check < pivot)
			{
				left += check * position;
				position *= 10;
				printf("left: %d\n", left);
			}
			temp /= 10;
		}
	}
	else
	{
		int temp = number;
		while (temp)
		{
			int check = temp % 10;
			if (check < pivot)
			{
				right += check * position;
				position *= 10;
				printf("Right: %d\n", right);
			}
			temp /= 10;
		}
		//building middle
		temp = number;
		while (temp)
		{
			int check = temp % 10;
			if (check == pivot)
			{
				middle += check * position;
				position *= 10;
				printf("middle: %d\n", middle);
			}
			temp /= 10;
		}
		//building left
		temp = number;
		while (temp)
		{
			int check = temp % 10;
			if (check > pivot)
			{
				left += check * position;
				position *= 10;
				printf("left: %d\n", left);
			}
			temp /= 10;
		}
	}

	printf("%d\n", left + middle + right);
}

// int main(int argc, char **argv)
// {
// 	int number = atoi(argv[2]);
// 	enum FilterAction action = HIFIRST;
// 	if(!strcmp(argv[1], "LOFIRST")) action = LOFIRST;
// 	int pivot = atoi(argv[3]);
// 	solution(number, action, pivot); 
// 	return 0;
// }
