#include <stdio.h>
struct Node{
	int tag;		//标记节点是第几次进栈
	int num;
};
//先序遍历对应进栈顺序，中序遍历对应出栈顺序；
//后序遍历与中序遍历不同的是节点出栈后要马上再入栈（tag做第二次入栈标记），等右儿子遍历完后再出栈;
//具体实现上，每次中序遍历的pop时，如果栈顶是标记过的节点（tag=2），循环弹出；如果没有标记过（tag=1），做标记，即弹出再压栈）
//栈顶tag=2的节点对应中序遍历中已弹出的节点；循环弹出后碰到的第一个tag=1的节点才对应中序遍历当前pop的节点
int main() {
	int n;
	scanf("%d", &n);
	int flag = 0;
	struct Node stack[30];	
	int size = 0;			//栈元素大小，指向栈顶的下一个位置
	for (int i = 0; i < 2 * n; ++i) {
		char s[10];
		scanf("%s", s);
		if (s[1] == 'u') {		//push
			scanf("%d", &stack[size].num);		//入栈
			stack[size].tag = 1;				//标记第一次入栈
			++size;
		}
		else {					//pop
			while (size > 0 && stack[size - 1].tag == 2) {	//循环弹出栈顶tag=2的节点
				if (flag)
					printf(" ");
				flag = 1;
				printf("%d", stack[--size].num);
			}
			if (size > 0)		//将中序遍历中应该要弹出的节点弹出再压栈，做标记即可
				stack[size - 1].tag = 2;
		}
	}
	while (size) {				//将栈中剩余节点依次弹出
		if (flag) {
			printf(" ");
		}
		flag = 1;
		printf("%d", stack[--size].num);
	}
	return 0;
}
