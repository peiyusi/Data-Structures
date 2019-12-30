#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	char str[100];
	
	for (int i = 0; i < N; i++) {
		cin >> str;
		int top = 0;
		int flag = 1;
		for (int j = 0; str[j]; j++) {
			if (str[j] == 'S') {
				top++; 
				if (top > M) {
					flag = 0;
				}
			} else {
				if (top == 0) {
					flag = 0;
				}
				top--;
			}
		}
		if (top != 0 || flag == 0) {
			printf("NO\n");
		}else {
			printf("YES\n");
		}
	}
	
	return 0;
}
