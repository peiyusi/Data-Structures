#include <stdio.h>
struct LNode{
	int data;
	int k;
}s[100001];

int main() {
	int n;
	int i, j;
	int max = 1, a;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &s[i].data);
		s[i].k = 1;
	}
	for (i = 0; i < n-1; i++) {
		for (j = i + 1; j < n; j++) {
			if (s[j].data > s[j-1].data) {
				s[i].k++;
			} else {
				break;
			}
		}
	}
	for (i = 0; i < n; i++) {
		if (s[i].k > max) {
			max = s[i].k;
			a = i;
		}
	}
	for (i = a; i < a + max-1; i++) {
		printf("%d ", s[i].data);
	}
	printf("%d\n", s[a+max-1].data);
	
	return 0;
}
