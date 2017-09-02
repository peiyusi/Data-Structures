#include <stdio.h>

int Max( int a[], int n) {
	int i;
	int ThisSum, MaxSum;
	
	ThisSum = 0;
	MaxSum = 0;
	
	for (i = 0; i < n; i++) {
		ThisSum += a[i];
		if (ThisSum > MaxSum) {
			MaxSum = ThisSum;
		} else if (ThisSum < 0) {
			ThisSum = 0;
		}
	}
	
	return MaxSum;
}

int main() {
	int i;
	int a[100000];
	int K;
	scanf("%d", &K);
	for (i = 0; i < K; i++) {
		scanf("%d", &a[i]);
	}
	printf("%d\n", Max(a, K));
	return 0;
}
