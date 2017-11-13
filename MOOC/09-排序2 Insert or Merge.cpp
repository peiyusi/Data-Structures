#include <iostream>
#include <algorithm>
int main() {
	int n, i, count, length, a[100], b[100];
	int flag = 1;
	scanf("%d", &n);
	for (i = 0;i < n;i++)
		scanf("%d", &a[i]);
	for (i = 0;i < n;i++)
		scanf("%d", &b[i]);

	//i从0到n-1遍历，当b[i+1]<b[i]，继续遍历判断a[i] == b[i]
	//不相等，则为归并，否则为插入
	for (i = 1; b[i] >= b[i - 1]; i++);
	count = i;
	for (;i < n && a[i] == b[i];i++);

	if (i == n) {
		printf("Insertion Sort\n");
		std::sort(b, b + count + 1);
		printf("%d", b[0]);
		for (i = 1;i < n;i++)
			printf(" %d", b[i]);
	}

	else {
		printf("Merge Sort\n");
		for (length = 2;flag;length *= 2) {
			//在长度为length片段满足顺序排列的基础上判断length*2
			for (i = length; i < n; i += length * 2) {
				if (b[i - 1] > b[i]) {
					flag = 0;break;
				}
			}
		}
		for (i = 0;i + length <= n;i += length)
			std::sort(b + i, b + i + length);
		std::sort(b + i, b + n);
		printf("%d", b[0]);
		for (i = 1;i < n;i++)
			printf(" %d", b[i]);
		//另一种比较直接的做法是模拟merge过程，每一步都判断是否与b相等
	}
	return 0;
}


