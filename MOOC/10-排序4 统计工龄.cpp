#include <stdio.h>

int main() {
	int N, i, count[100005], age[51] = {0};
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &count[i]);
		age[count[i]]++;
	}
	
	for (i = 0; i < 51; i++) {
		if (age[i] != 0) {
			printf("%d:%d\n", i, age[i]);
		}
	}
	return 0;
}
