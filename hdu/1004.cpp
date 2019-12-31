#include &lt;iostream&gt;
#include &lt;map&gt;

using namespace std;

int main()
{
    map&lt;string ,int &gt;colors;
    int n;
    while (cin &gt;&gt; n &amp;&amp; n)
    {
        string color, maxcolor;
        for (int i = 0, max = 0; i &lt; n; i++)
        {
            cin &gt;&gt; color;
            ++colors[color];
            if (colors[color] &gt; max) {
                max = colors[color];
                maxcolor = color;
            }
        }

        cout &lt;&lt; maxcolor &lt;&lt; endl;


    }

    return 0;

}
