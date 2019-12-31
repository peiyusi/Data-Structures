#include &lt;iostream&gt;
#include &lt;cstdio&gt;
#include &lt;string&gt;
using namespace std;
string Bigsum(string a, string b)
{
    if (a.length() &lt; b.length()) {
        string temp;
        temp = a;
        a = b;
        b = temp;
    }
    for (int i = a.length() - 1, j = b.length() - 1; i &gt;= 0; i--, j--) {
        a[i] = a[i] + (j &gt;= 0 ? b[j] - '0' : 0);
        if (a[i] - '0' &gt;= 10) {
            a[i] = ((a[i] - '0')% 10) + '0';
            if (i) {
                a[i-1]++;
            } else {
                a = '1' + a;
            }
        }
    }

    return a;
}
int main() {
    string a, b, sum;
    int T;
    cin &gt;&gt; T;
    int count = 1;
    while (T--) {
        cin &gt;&gt; a &gt;&gt; b;
        sum = Bigsum(a, b);
        cout &lt;&lt; &quot;Case &quot; &lt;&lt; count++ &lt;&lt; &quot;:&quot; &lt;&lt; endl;
        cout &lt;&lt; a &lt;&lt; &quot; + &quot; &lt;&lt; b &lt;&lt; &quot; = &quot; &lt;&lt; sum;
        if (T != 0) {
            cout &lt;&lt; &quot;\n\n&quot;;
        } else {
            cout &lt;&lt; &quot;\n&quot;;
        }
    }
    return 0;
}