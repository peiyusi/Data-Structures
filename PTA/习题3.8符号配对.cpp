#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;
void Print(char ch) {
	if (ch == '(') {
		printf("(-?\n");
	} else if (ch == '[') {
		printf("[-?\n");
	} else if (ch == '{') {
		printf("{-?\n");
	} else if (ch == '/') {
		printf("/*-?\n");
	}
}

int main() {
	char str[1000];
	stack <char> s;
	int flag = 1;
	while(1) {
		gets(str);
		if(str[0] == '.' && str[1] == 0) {
			break;
		}
		int i;
		for (i = 0; str[i]; i++) {
			if (flag == 0) {
			    break;
			}
			if(str[i] == '(' || str[i] == '[' || str[i] == '{') {
				s.push(str[i]);
			} else if (str[i] == '/' && str[i+1] == '*') {
				s.push('/');
				i++;
			} else if (str[i] == ')') {
				if(!s.empty() && s.top() == '(') {
					s.pop();
				} else {
					printf("NO\n");
					flag = 0;
					if (s.empty()) {
						printf("?-)\n");
					} else {
						Print(s.top());
					}
					break;
				}
			} else if (str[i] == ']') {
				if(!s.empty() && s.top() == '[') {
					s.pop();
				} else {
					printf("NO\n");
					flag = 0;
					if (s.empty()) {
						printf("?-]\n");
					} else {
						Print(s.top());
					}
					break;
				}
		    } else if (str[i] == '}') {
				if(!s.empty() && s.top() == '{') {
					s.pop();
				} else {
					printf("NO\n");
					flag = 0;
					if (s.empty()) {
						printf("?-}\n");
					} else {
						Print(s.top());
					}
					break;
				}
			} else if (str[i] == '*' && str[i+1] == '/') {
				i++;
				if (!s.empty() && s.top() == '/') {
					s.pop();
				} else {
					printf("NO\n");
					flag = 0;
					if (s.empty()) {
						printf("?-*/\n");
					} else {
						Print(s.top());
					}
					break;
				}
			}
		}
	}
	if (flag && s.empty()) {
		printf("YES\n");
	} else if (flag) {
		printf("NO\n");
		Print(s.top());
	}
	
	
	return 0;
}
