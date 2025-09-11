#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "Design.h"
#include "Array.h"
#define Flag 1

int main()
{
	MainTitle("° Array Operations °");

	char sel[3];

	printf("Enter size of array : ");
	scanf("%s", sel);

	int n = atoi(sel);
	RESET_Color();

	int arr[n + 1];
	arr[n] = 0;
	free(sel);
	while (1)
	{
		MainTitle("° Array Operations °");
		
		printf("Select operation :\n\n");
		printf(" 1. Auto Initialize\n");
		printf(" 2. Enter Values\n");
		printf(" 3. Update\n");
		printf(" 4. Delete\n");
		printf(" 5. Insert\n");
		printf(" 6. Search\n");
		printf(" 7. Sort Array\n");
		printf(" 8. Reverse Array\n");
		printf(" 9. Rotate\n");
		printf("10. Display Array\n");

		printf("\nSelect : ");
		scanf("%s", sel);

		int select = atoi(sel);

		MainTitle("° Array Operations °");

		switch (select)
		{
		case 1:
			Initialize(n, arr);
			break;
		case 2:
			Entry(n, arr);
			break;
		case 3:
			display(n, arr, Flag);
			updation(arr);
			break;
		case 4:
			display(n, arr, Flag);
			deletion(n, arr);
			break;
		case 5:
			display(n - 1, arr, Flag);
			insertion(n + 1, arr);
			break;
		case 6:
			Searching(n, arr);
			break;
		case 7:
			sortion(n, arr);
			break;
		case 8:
			ReverseArr(n, arr);
			break;
		case 9:
			rotate(n, arr);
			break;
		case 10:
			display(n, arr, !Flag);
			break;
		}
		if (select == 11)
			break;
	}

	clearScreen();
	printf("Done");
	return 0;
}