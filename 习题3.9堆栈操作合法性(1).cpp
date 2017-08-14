#include <bits/stdc++.h>

using namespace std;

int main() {
    char str[1000];
    stack <char> s;
    int N, M, flag;
    cin >> N >> M;
	getchar(); 
    while (N--) {
    	while (!s.empty()) {
    		s.pop();
		}
		flag = 1;
    	int i, len, sum;
    	sum = 0;
    	gets(str);
    	len = strlen(str);
    	for (i = 0; i < len; ++i) {
    		if (str[i] == 'S') {
    			s.push(str[i]);
    			sum++;
    			if (sum > M) {
    				printf("NO\n");
    				flag = 0;
    				break;
				}
			} else {
				if (s.empty()) {
					printf("NO\n");
					flag = 0;
					break;
				} else {
					s.pop();
					sum--;
				}
			}
		}
		if (flag && s.empty()) {
			printf("YES\n");
		} else if (flag && !s.empty()) {
			printf("NO\n");
		}
	}
	return 0;
}
