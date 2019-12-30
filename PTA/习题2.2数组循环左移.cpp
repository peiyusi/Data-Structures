/*同理， 右移：Reverse(arr, 0, n - 1 - m); Reverse(arr, n - m, n - 1); Reverse(arr, 0, n-1);*/ 

#include <stdio.h>

void Reverse(int a[], int start, int end)
{
	int i, j, temp;
	for (i = start, j = end; i < j; i++, j--) {
		temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
}

int main()
{
	int a[100], n, m, i;
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	m %= n;
	Reverse(a, 0, m - 1);
	Reverse(a, m, n - 1);
	Reverse(a, 0, n - 1);
	
	printf("%d", a[0]);	
	for (i = 1; i < n; i++) {
		printf(" %d", a[i]);
	}
	
	return 0;
}

/* 解法二，用辅助数组
void LeftShift(int a[], int n, int m)
{
	int s[m], i, j = 0;
	for (i = 0; i < m; i++) {
		s[i] = a[i];
	}
	for (i = 0; i < n - m; i++) {
		a[i] = a[i + m];
	}
	while (i < n) {
		a[i++] = s[j++];
	}
} 
*/



