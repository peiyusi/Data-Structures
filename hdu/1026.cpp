#include &lt;iostream&gt;
#include &lt;queue&gt;

using namespace std;

int N, M;

char maze[105][105];
int visited[105][105];
int dir[105][105];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

struct Node {
    int x;
    int y;
    int step;
    friend bool operator &lt; (Node n1, Node n2)
    {
        return n1.step &gt; n2.step;
    }
};

int judge(int x, int y) {
    if (x &lt; 1 || y &lt; 1 || x &gt; N || y &gt; M) {
        return 1;
    } else if (visited[x][y]) {
        return 1;
    } else if (maze[x][y] == 'X') {
        return 1;
    } else {
        return 0;
    }
}

int bfs(int x, int y) {
    priority_queue &lt;Node&gt; q;
    Node cur, next;
    cur.x = x;
    cur.y = y;
    cur.step = 0;
    visited[x][y] = 1;
    q.push(cur);
    while (!q.empty()) {
        cur = q.top();
        q.pop();
        if (cur.x == N &amp;&amp; cur.y == M) {
            return cur.step;
        }
        int nx, ny;
        for (int i = 0; i &lt; 4; i++) {
            nx = cur.x + dx[i];
            ny = cur.y + dy[i];
            if (judge(nx, ny)) continue;
            next.x = nx;
            next.y = ny;
            visited[nx][ny] = 1;
            dir[nx][ny] = i;
            if ('1' &lt;= maze[nx][ny] &amp;&amp; maze[nx][ny] &lt;= '9') {
                int hp = maze[nx][ny] - '0';
                next.step = cur.step + hp + 1;
            } else {
                next.step = cur.step + 1;
            }
            q.push(next);
        }
    }
    return 0;
}


int main() {
    while (cin &gt;&gt; N &gt;&gt; M) {
        for (int i = 1; i &lt;= N; i++) {
            for (int j = 1; j &lt;= M; j++) {
                cin &gt;&gt; maze[i][j];
                visited[i][j] = 0;
            }
        }
        int step = bfs(1, 1);
        if (step) {
            Node way[10000];
            int cx = N, cy = M;
            for (int i = step; i &gt;= 0; i--) {
                way[i].x = cx;
                way[i].y = cy;
                if ('1' &lt;= maze[cx][cy] &amp;&amp; maze[cx][cy] &lt;= '9') {
                    int hp = maze[cx][cy] - '0';
                    for (int j = 1; j &lt;= hp; j++) {
                        way[i-j].x = cx;
                        way[i-j].y = cy;
                    }
                    i -= hp;
                }
                switch(dir[cx][cy]) {
                    case 0: cy--; break;
                    case 1: cx--; break;
                    case 2: cy++; break;
                    case 3: cx++; break;
                    default: break;
    }

            }
            cout &lt;&lt; &quot;It takes &quot; &lt;&lt; step &lt;&lt; &quot; seconds to reach the target position, let me show you the way.&quot; &lt;&lt; endl;
            for (int i = 1; i &lt;= step; i++) {
                cout &lt;&lt; i &lt;&lt; &quot;s:(&quot; &lt;&lt; way[i-1].x-1 &lt;&lt; ',' &lt;&lt; way[i-1].y-1 &lt;&lt; &quot;)-&gt;(&quot; &lt;&lt; way[i].x-1 &lt;&lt; ',' &lt;&lt; way[i].y-1 &lt;&lt; ')' &lt;&lt; endl;
                if ('1' &lt;= maze[way[i].x][way[i].y] &amp;&amp; maze[way[i].x][way[i].y] &lt;= '9') {
                    int hp = maze[way[i].x][way[i].y] - '0';
                    for (int j = 1; j &lt;= hp; j++) {
                        cout &lt;&lt; i + j &lt;&lt; &quot;s:FIGHT AT (&quot; &lt;&lt; way[i+j].x-1 &lt;&lt; ',' &lt;&lt; way[i+j].y-1 &lt;&lt; ')' &lt;&lt; endl;
                    }
                    i += hp;
                }
            }
        } else {
            cout &lt;&lt; &quot;God please help our poor hero.&quot; &lt;&lt; endl;
        }
        cout &lt;&lt; &quot;FINISH&quot; &lt;&lt; endl;
    }

    return 0;
}