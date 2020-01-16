void hanoiRecursive(char a, char b, char c, int n)  //汉诺塔递归实现, a,b,c分别为起始、辅助、终点, n为盘子数 
{
	if (n > 0) {
		hanoiRecursive(a, c, b, n - 1);
		printf("%c->%c\n", a, c);                  //n = 1, 此时a终于有一个可以直接移向c的圆盘 
		hanoiRecursive(b, a, c, n - 1);	
	}
}
