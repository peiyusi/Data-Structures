#include <stdio.h>

void getSum(int a, int n)
{
	if (a == 0 || n == 0) {
		printf("0");
		return;
	} 
	
	int arr[100000];
	int i, j, c = 0, t; 
	for (i = n, j = 0; i > 0; i--, j++) {
		t = a * i + c;
		arr[j] = t % 10;
		c = t / 10;
	}
	if (c > 0) {
		arr[j++] = c;
	} 
	
	while (j--) {
		printf("%d", arr[j]);	
	}
}

int main()
{
	int a, n;
	scanf("%d %d", &a, &n);
	getSum(a, n);
}
