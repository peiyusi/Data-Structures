#include <stdio.h>
int a[1000000];

int main() {
	int A;
	int N;
	int i, j, t, flag;
	scanf("%d", &A);
	scanf("%d", &N);
	if (N==0) {
		printf("0\n");
	} else {
		flag = 0;
		for (i = N, j = 0; i >= 1; i--, j++) {
			t = A * i + flag;
			flag = t / 10;
			a[j] = t % 10;
		}
		if (flag > 0) {
			a[j] = flag;
			j++;
		}
		for (i = j-1; i >= 0; i--) {
			printf("%d", a[i]);
		}
	}
	
	return 0;
}

