#include <stdio.h>

int main() {
	int K, i, ThisSum, MaxSum;
	scanf("%d", &K);
	int a[K];
	ThisSum = MaxSum = 0;
	for (i = 0; i < K; i++) {
		scanf("%d", &a[i]);
		ThisSum += a[i];
		if (ThisSum > MaxSum) {
			MaxSum = ThisSum;
		}
		if (ThisSum < 0) {
			ThisSum = 0;
		}
	}
	printf("%d\n", MaxSum);
	return 0;
} 
