#include "SS.h"
#define Flag 1


//Enter Values
void Entry(int n, int *arr)
{
	BG_Color(18);
	TEXT_Color(RED);

	printf(".....................................");
	printf("\n\nEnter Elements of Array :-\n");

	for (int i = 0; i < n; i++)
	{
		printf("Enter Element %2d : ", i + 1);
		scanf("%d", &arr[i]);
	}
}

void Initialize(int n, int *arr)
{
	for (int i = 0; i < n; i++)
		arr[i] = 6 * i * i + i + 1;
}

//Insert Element
void insertion(int n, int *arr)
{
	int c, d;

	BG_Color(18);
	TEXT_Color(RED);

	printf("Element You want to Insert : ");
	scanf("%d", &d);
	printf("Insert in Element No.      : ");
	scanf("%d", &c);

	for (int i = n - 1; i > c - 1; i--)
	{
		arr[i] = arr[i - 1];
	}
	arr[c - 1] = d;
}

//Update an element position
void updation(int *arr)
{
	int a;

	BG_Color(18);
	TEXT_Color(RED);

	printf("Element No. You want to Update  : ");
	scanf("%d", &a);
	printf("Element You want to insert      : ");
	scanf("%d", &arr[a - 1]);
}

//Delete an element
void deletion(int n, int *arr)
{
	int c;

label3:
	BG_Color(18);
	TEXT_Color(RED);

	printf("Search Element You want to delete : ");
	scanf("%d", &c);

	c = Search_Lin(n, arr, !Flag, c);

	if (c == -1)
	{
		printf("\aError : Item not found.\nPlease try again.\n\n");
		goto label3;
	}
	else
	{
		for (int i = c - 1; i < n - 1; i++)
		{
			arr[i] = arr[i + 1];
		}
	}
}

// Reverse array
void ReverseArr(int n, int *a)
{
	for (int i = 0; i < n / 2; i++)
	{
		swap(&a[i], &a[n - i - 1]);
	}
}

//Sort array
void sortion(int n, int *arr)
{
	BG_Color(18);
	TEXT_Color(RED);

	Sort_Quick(arr, 0, n-1);
}

// Sorted Display
void Sort_Dp(int n, int *arr)
{
	printf("Sorted Array :- \n\n");

	for (int i = 0, j = n - 1; i < n; j--, i++)
	{
		if (!i)
			printf("  Ascending -           Descending -\n\n");
		printf("Element %2d = %3d      ", i + 1, arr[i]);
		printf("Element %2d = %3d\n", i + 1, arr[j]);
	}
}

//Display array
void display(int n, int *arr, int flag)
{
	int i;

	if (!flag)
		goto label1;
	else
		goto label2;

label1:
	for (i = 5; i > 0; i--)
	{
	label2:
		
		MainTitle("° Array Operations °");

		for (int j = 0; j < n - 1 + 1; j++)
		{
			printf("Element %2d : %3d\n", j + 1, arr[j]);
		}
		if (flag)
		{
			printf("\n");
			return;
		}
		printf("\n\t   Countdown = %d\n", i);
		sleep(1);
		clearScreen();
	}
}

void Searching(int n, int *arr)
{
	int item;
	printf("Enter Number to Search : ");
	scanf("%d", &item);
	item = Search_Lin(n, arr, !Flag, item);
	if (item == -1)
		printf("Item not found.");
	else
		printf("Found at position %d.\n", item);
	sleep(2);
}

void rotate(int n, int *arr)
{
	int m = arr[n-1];
	for(int i = n-1; i > 0; i--)
	    arr[i] = arr[i-1];
	arr[0] = m;
}