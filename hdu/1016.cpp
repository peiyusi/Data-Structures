#include &lt;iostream&gt;
#include &lt;string.h&gt;
#include &lt;math.h&gt;
using namespace std;

int n;
int circle[20], visited[20];

int isPrime(int n)
{
    int temp = sqrt(n);
    for (int i = 2; i &lt; temp + 1; i++)
    {
        if (n % i == 0) {
            return 0;
        }
    }

    return 1;
}
void dfs(int depth)
{
    if (depth == n &amp;&amp; isPrime(circle[depth - 1] + 1)) {
        for (int i = 0; i &lt; n - 1; i++) {
            cout &lt;&lt; circle[i] &lt;&lt; &quot; &quot;;
        }
        cout &lt;&lt; circle[n -1];
        cout &lt;&lt; endl;
        return;
    }

    for (int i = 2; i &lt;= n; i++) {
        if (isPrime(i + circle[depth - 1]) &amp;&amp; !visited[i]) {
            visited[i] = 1;
            circle[depth] = i;
            dfs(depth + 1);
            visited[i] = 0;
        }
    }
}

int main()
{
    int count = 1;
    while (cin &gt;&gt; n)
    {
        memset(circle, 0, n);
        memset(visited, 0, n);
        circle[0] = 1;
        cout &lt;&lt; &quot;Case &quot; &lt;&lt; count &lt;&lt;&quot;:\n&quot;;
        dfs(1);
        cout &lt;&lt; endl;
        count++;
    }


    return 0;
}