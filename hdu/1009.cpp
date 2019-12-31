#include &lt;iostream&gt;
#include &lt;algorithm&gt;
#include &lt;stdio.h&gt;

using namespace std;

struct Node
{
    double J;
    double F;
    double multi;
} node[1001];

bool cmp(const Node &amp;x, const Node &amp;y)
{
    return x.multi &gt; y.multi;
}

int main()
{
    int M, N;
    while (cin &gt;&gt; M &gt;&gt; N, M + 1 || N + 1)
    {

        double max = 0;
        for (int i = 0; i &lt; N; i++)
        {
            cin &gt;&gt; node[i].J &gt;&gt; node[i].F;
            node[i].multi = node[i].J / node[i].F;
        }

        sort(node, node+N, cmp);

        for (int i = 0; i &lt; N; i++)
        {
            if (M &gt; node[i].F)
            {
                M -= node[i].F;
                max += node[i].J;
            } else {
                max += node[i].multi * M;
                break;
            }
        }


        printf(&quot;%.3f\n&quot;, max);
    }

    return 0;
}