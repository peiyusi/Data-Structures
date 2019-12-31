#include &lt;iostream&gt;
#include &lt;string&gt;
#include &lt;cstdio&gt;
#include &lt;algorithm&gt;
#include &lt;vector&gt;
#include &lt;stack&gt;
using namespace std;
const int maxn = 100;
char O1[maxn], O2[maxn];
vector&lt;string&gt; vec;

int main() {
    int N, a, b, flag;
    while (cin &gt;&gt; N) {
        stack&lt;char&gt; s;
        a = b = flag = 1;
        scanf(&quot;%s %s&quot;, O1+1, O2+1);
        while (b &lt;= N) {
            if (O1[a] == O2[b]) {
                vec.push_back(&quot;in&quot;);
                vec.push_back(&quot;out&quot;);
                a++;
                b++;
            } else if (!s.empty() &amp;&amp; s.top() == O2[b]) {
                vec.push_back(&quot;out&quot;);
                s.pop();
                b++;
            } else if (a &lt;= N) {
                vec.push_back(&quot;in&quot;);
                s.push(O1[a]);
                a++;
            } else {
                flag = 0;
                break;
            }
        }
        if (flag) {
            cout &lt;&lt; &quot;Yes.&quot; &lt;&lt; endl;
            for (int i = 0; i &lt; vec.size(); i++) {
                cout &lt;&lt; vec[i] &lt;&lt; endl;
            }
        } else {
            cout &lt;&lt; &quot;No.&quot; &lt;&lt; endl;
        }
        cout &lt;&lt; &quot;FINISH&quot; &lt;&lt; endl;
        vec.clear();
    }


    return 0;
}