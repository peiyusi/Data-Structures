#include <stdio.h>
#include <string.h>
struct Node {
	int num;
};
int pre[30], in[30], post[30];
void solve(int preL, int inL, int postL, int n) {
	int i, L, R, root;
	if (n == 0) return;
	if (n == 1) { post[postL] = pre[preL]; return; };
	root = pre[preL];
	post[postL+n-1] = root;
	for (i = 0; i < n; i++) {
		if (in[(inL + i)] == root) break;
	}
	L = i; R = n-L-1;
	solve(preL+1, inL, postL, L); //对左子树进行递归 
	solve(preL+L+1, inL+L+1, postL+L, R); //对右子树进行递归 
}

int main() {
	int N, i, j, k, size;
	scanf("%d", &N);
	struct Node stack[N];
	size = 0; j = 0; k = 0;
	for (i = 0; i < 2 * N; i++) {
		char s[10];
		scanf("%s", s);
		if (s[1] == 'u') {
			scanf("%d", &pre[k]);
			stack[size].num = pre[k];
			size++; k++;
		} else {
			in[j] = stack[--size].num;
			j++;
		}
	}
	solve (0, 0, 0, N);
	printf("%d", post[0]);
	for (i = 1; i < N; i++) {
		printf(" %d", post[i]);
	}
	return 0;
}
