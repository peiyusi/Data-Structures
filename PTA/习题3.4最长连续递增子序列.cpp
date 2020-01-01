#include <stdio.h>

void GetAndPrintSequence(int a[], int n)
{
	a[n] = -99999;        //巧妙的设置哨兵，使得最后一次一定会更新！ 
	int i, len, maxLen, start, isStart;
	start = isStart = 0;
	len = maxLen = 1;
	
	for (i = 0; i < n; i++) {
		if (a[i] < a[i + 1]) {
			len++;
		} else {
			if (len > maxLen) {
				maxLen = len;
				start = isStart;
			}
			isStart = i + 1;
			len = 1;
		}
	}
	
	printf("%d", a[start]);
	for (i = 1; i < maxLen; i++) {
		printf(" %d", a[start + i]);
	}	
} 

int main()
{
	int a[100001];  //多开辟一个空间放置哨兵 
	int n, i;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	GetAndPrintSequence(a, n);
	
	return 0;
}
