#include <stdio.h>

int main() {
	int K, i, ThisSum, MaxSum, flag, front, rear, flag_max, maybe_front;
	scanf("%d", &K);
	int a[K];
	ThisSum = flag = front = rear = flag_max = maybe_front = 0;
	MaxSum = -1;
	for (i = 0; i < K; i++) {
		scanf("%d", &a[i]);
	}
	for (i = 0; i < K; i++) {
		ThisSum += a[i];
		if (ThisSum > MaxSum) {
			flag_max = 1;
			if (flag == 0) {
				front = maybe_front;
				flag = 1;
			}
			MaxSum = ThisSum;
			rear = i;
		} else if (ThisSum < 0) {
			ThisSum = 0;
			maybe_front = i + 1;
			flag = 0;
		}		
	}
	if (flag_max == 0) {
		printf("0 %d %d", a[0], a[K-1]);
	} else {
		printf("%d %d %d", MaxSum, a[front], a[rear]);
	}
	
	return 0;
}
