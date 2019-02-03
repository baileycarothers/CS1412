#include <stdio.h>

int main(void)
{
	int n;

	printf("Please enter how many digits are in the array: ");
	scanf("%d", &n);

	int a[n];
	printf("Enter %d numbers separated by spaces: ", n);
	for(int i=0;i<n;i++)
		scanf("%d", &a[i]);

	printf("You entered the numbers: ");
	for(int j=0;j<n;j++)
		printf("%d\t", a[j]);

	return 0;
};