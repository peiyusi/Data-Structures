#include &lt;iostream&gt;
#include &lt;cstdio&gt;

using namespace std;

int main()
{
    cout &lt;&lt; &quot;n e\n&quot;;
    cout &lt;&lt; &quot;- -----------\n&quot;;
    cout &lt;&lt; &quot;0 1\n&quot;;
    int n, a;
    double e;
    n = 1; a = 1; e = 1;
    while (n != 10)
    {
        a *= n;
        e += 1.0 / a;
        if (n == 1)
        {
            cout &lt;&lt; &quot;1 2\n&quot;;
        }
        else if (n == 2)
        {
            cout &lt;&lt; &quot;2 2.5\n&quot;;
        }
        else
        {
            printf(&quot;%d %.9f\n&quot;, n, e);
        }

        n++;
    }

    return 0;
}