#include <stdio.h>

void Reverse(int *arr, int BEGIN, int END) {
	int temp;
	for (; BEGIN < END; BEGIN++, END--) {
		temp = arr[BEGIN]; arr[BEGIN] = arr[END]; arr[END] = temp; 
	} 
}

void LeftShift(int *arr, int n, int m) {
	m %= n;
	Reverse(arr, 0, m-1);  /*Í¬Àí£¬ ÓÒÒÆ£ºReverse(arr, 0, n - 1 - m); Reverse(arr, n - m, n - 1); Reverse(arr, 0, n-1);*/ 
	Reverse(arr, m, n-1);
	Reverse(arr, 0, n-1);
} 
int main() {
	int n, m, i;
	scanf("%d", &n);
	scanf("%d", &m);
	int a[n];
	for(i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	} 
	LeftShift(a, n, m);
	for(i = 0; i < n-1; i++) {
		printf("%d ", a[i]);
	}
	printf("%d", a[n-1]);
	
	return 0;
}


