#include &lt;iostream&gt;
#include &lt;cstring&gt;

using namespace std;

int n, m, num;
char mp[100][100];
int visited[100][100];
int spx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int spy[8] = {1, 0, -1, 0, -1, 1, 1, -1};

int check(int x, int y) {
    if (x &lt; 0 || y &lt; 0 || x &gt;= n || y &gt;= m) {
        return 0;
    } else {
        return 1;
    }   
}

void DFS(int x, int y) {
    if (!check(x, y)) {
        return;
    }   
    visited[x][y] = 1;
    for (int i = 0; i &lt; 8; i++) {
        int nx = x + spx[i];
        int ny = y + spy[i];
        if (visited[nx][ny] == 0 &amp;&amp; mp[nx][ny] == '@') {
            DFS(nx, ny);
        }   
    }   
}

int main() {
    while (cin &gt;&gt; n &gt;&gt; m, n) {
        num = 0;
        for (int k = 0; k &lt; n; k++) {
            for (int l = 0; l &lt; m; l++) {
                cin &gt;&gt; mp[k][l];
                visited[k][l] = 0;
            }   
        }   
        for (int i = 0; i &lt; n; ++i) {
            for (int j = 0; j &lt; m; ++j) {
                if (visited[i][j] == 0 &amp;&amp; mp[i][j] == '@') {
                    num++;
                    DFS(i, j); 
                }   
            }   
        }
        cout &lt;&lt; num &lt;&lt; endl;
    }

    return 0;
}
    