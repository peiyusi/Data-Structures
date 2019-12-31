#include &lt;iostream&gt;

using namespace std;
int N, M, T, sx, sy, ex, ey;
char maze[6][6];
const int moved[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
bool mark[6][6], flag = false;

int abs(int x)
{
    return x &lt; 0 ? -x : x;
}

int Dis(int x, int y)
{
    return abs(x - ex) + abs(y - ey);
}

void DFS(int x, int y, int step)
{
    if (flag) return;
    if (maze[x][y] == 'D' &amp;&amp; step == T)
    {
        flag = true;
        return;
    }
    if (step &gt;= T)
    {
        return;
    }
    int dis = T - step - Dis(x, y);
    if (dis &lt; 0 || dis % 2) return;
    for (int i = 0; i &lt; 4; i++)
    {
        int tx = x + moved[i][0];
        int ty = y + moved[i][1];
        if (tx &gt;= 0 &amp;&amp; tx &lt; N &amp;&amp; ty &gt;= 0 &amp;&amp; ty &lt; M &amp;&amp; maze[tx][ty] != 'X' &amp;&amp; 
        !mark[tx][ty])
        {
            mark[tx][ty] = true;
            DFS(tx, ty, step + 1);
            mark[tx][ty] = false;
        }
    }
}


int main()
{
    while (cin &gt;&gt; N &gt;&gt; M &gt;&gt; T, N || M || T)
    {
        flag = false;
        int xnum = 0;
        for (int i = 0; i &lt; N; i++)
        {
            for (int j = 0; j &lt; M; j++)
            {
                cin &gt;&gt; maze[i][j];
                mark[i][j] = false;
                if (maze[i][j] == 'D') {
                    ex = i;
                    ey = j;
                }
                if (maze[i][j] == 'S') {
                    sx = i;
                    sy = j;
                    mark[i][j] = true;
                }
                if (maze[i][j] == 'X') {
                    xnum++;
                }
            }
        }
        
        if (N * M - xnum &gt; T)
        {
            DFS(sx, sy, 0);
        }

        if (flag)
        {
            cout &lt;&lt; &quot;YES&quot; &lt;&lt; endl;
        } else{
            cout &lt;&lt; &quot;NO&quot; &lt;&lt; endl;
        }
        
    }
    return 0;
}    
