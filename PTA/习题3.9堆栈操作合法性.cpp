#include <stdio.h>
#include <stdlib.h>

int main()
{
	//freopen("in.txt", "r", stdin);
	int N, M, i, flag, top;
	char str[100];
	scanf("%d %d", &N, &M);
	while (N--) {
		scanf("%s", str);
		i = top = -1;
		flag = 1;
		while (str[++i]) {
			if (str[i] == 'S') {
				if (top == M - 1) {
					flag = 0;
					break;
				}
				top++;
			} else {
				if (top == -1){
					flag = 0;
					break;
				}
				top--;
			}
		}
		if (!flag || top != -1) {
			printf("NO\n");
		} else {
			printf("YES\n");
		}
		top = -1;
	}
	//fclose(stdin);
	
	return 0;
}
