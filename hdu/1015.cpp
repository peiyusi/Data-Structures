#include &lt;iostream&gt;
#include &lt;string.h&gt;
#include &lt;algorithm&gt;
#include &lt;cstdio&gt;
using namespace std;

char str[12], order[5];
int visited[12], flag, len, target;

bool cmp(const char&amp; a, const char&amp; b)
{
    return a &gt; b;
}

int cal()
{
    int v, w, x, y, z;
    v = order[0] - 'A' + 1;
    w = order[1] - 'A' + 1;
    x = order[2] - 'A' + 1;
    y = order[3] - 'A' + 1;
    z = order[4] - 'A' + 1;
    if (v - w*w + x*x*x - y*y*y*y + z*z*z*z*z == target)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void dfs(int depth)
{
    if (depth == 5) {
        if (cal()) {
            flag = 1;
        }
        return;
    }

    for (int i = 0; i &lt; len; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            order[depth] = str[i];
            dfs(depth + 1);
            if (flag) {
                return;
            }
            visited[i] = 0;
        }
    }
}
int main()
{
    while (cin &gt;&gt; target &gt;&gt; str)
    {
        if (target == 0 &amp;&amp; !strcmp(str, &quot;END&quot;))
        {
            break;
        }
        flag = 0;
        len = strlen(str);
        memset(visited, 0, sizeof(visited));
        sort(str, str + len, cmp);
        dfs(0);
        if (flag)
        {
            order[5] = '\0';
            puts(order);
        }
        else
        {
            cout &lt;&lt; &quot;no solution&quot; &lt;&lt; endl;
        }
    }

    return 0;
}