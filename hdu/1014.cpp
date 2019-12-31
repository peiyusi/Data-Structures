#include &lt;iostream&gt;
#include &lt;cstdio&gt;
using namespace std;

int main()
{
    int S, M;
    while (cin &gt;&gt; S &gt;&gt; M) {
        int seed = 0;
        int flag = 1;
        for (int i = 1; i &lt;= M; i++) {
           seed = (seed + S) % M;
           if (seed == 0) {
               if (i != M)
                   flag = 0;
               break;
           }
        }

        if (flag)
            printf(&quot;%10d%10d    Good Choice\n\n&quot;, S, M);
        else
            printf(&quot;%10d%10d    Bad Choice\n\n&quot;, S, M);
    }

    return 0;
}