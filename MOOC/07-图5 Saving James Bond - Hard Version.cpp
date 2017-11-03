#include <iostream>
#include <math.h>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

int n, m;
#define MINLEN 42.5

struct GNode {
	int x;
	int y;
}LGraph[101];
bool answer = false;
bool visited[101] = {false};
int path[101] = {-1};

bool isSave(int x) {
	if ((LGraph[x].x - m <= -50) || (LGraph[x].x + m >= 50) 
	    || (LGraph[x].y - m <= -50) || (LGraph[x].y + m >= 50))
	    return true;
	return false;
}

bool jump(int x, int y) {
	int x1 = pow(LGraph[x].x - LGraph[y].x, 2);
	int x2 = pow(LGraph[x].y - LGraph[y].y, 2);
	int r = m * m;
	if (x1 + x2 <= r) return true;
	return false;
}

int firstJump(int x) {
	int x1 = pow(LGraph[x].x, 2);
	int x2 = pow(LGraph[x].y, 2);
	int r = (m + 7.5) * (m + 7.5);
	if (x1 + x2 <= r) {
		return x1 + x2;
	}
	return 0;
}

bool cmp(int a, int b) {
	return firstJump(a) < firstJump(b);
}

void bfs() {
	int b[101], last, step, tail;
    queue<int> q;
	step = 2;	
	for (int i = 0; i < n; i++) {
		b[i] = i;
	}
	sort(b, b + n, cmp);
    for (int i = 0; i < n; i++) {
    	if (firstJump(b[i])) {
    		q.push(b[i]);
    		visited[b[i]] = true;
    		last = b[i];
		}
	}	
	while (!q.empty()) {
		int p = q.front();
		q.pop();
		if (isSave(p)) {
			int k = 1;
			stack<int> s;
			cout << step << endl;
			while (k < step) {
				s.push(p);
				p = path[p];
				k++;
			}
			while (!s.empty()) {
				p = s.top();
				s.pop();
				cout << LGraph[p].x << " " << LGraph[p].y << endl;
			}
			return;
		}
		for (int i = 0; i < n; i++) {
			if (!visited[i] && jump(p, i)) {
				q.push(i);
				path[i] = p;
				visited[i] = true;
				tail = i;
			}
		}
		if (last == p) {
			step++;
			last = tail;
		}
	}
	if (q.empty()) {
			cout << "0" << endl;
		}	
}


int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> LGraph[i].x >> LGraph[i].y;
 	}
	if (m >= MINLEN) {
		cout << "1" << endl;
		return 0;
	}
	bfs();
	return 0;
}
