#include <stdio.h>
#include <stdbool.h>
int main() {
	int num1, num2;
	bool flag; 
	char ch;
	flag = true;
	scanf("%d", &num1);
	while ((ch = getchar()) != '=') {
		scanf("%d", &num2);
		if ((ch == '/') && (num2 == 0)) {
			flag = false; 
		} else {
		    switch (ch) {
			    case '+': num1 += num2; break;
			    case '-': num1 -= num2; break;
			    case '*': num1 *= num2; break;
			    case '/': num1 /= num2; break;
			    default: flag = false;
			}
		}
		if (!flag) {
			break;
		}
	}
	if ( flag ) {
		printf("%d\n", num1);
	} else {
		printf("ERROR\n");
	}
	return 0;
}
