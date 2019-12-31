#include &lt;iostream&gt;

using namespace std;

int main() {
    int a, b, c;
    int n;
    cin &gt;&gt; n;
    while (n--) {
        cin &gt;&gt; a &gt;&gt; b &gt;&gt; c;
        int i;
        for (i = 1000; i &lt;= 9999; i++) {
            if ((i % a == 0) &amp;&amp; ((i + 1) % b == 0) &amp;&amp; ((i + 2) % c == 0)) {
                cout &lt;&lt; i &lt;&lt; endl;
                break;
            }       
        }       
        if (i == 10000) {
            cout &lt;&lt; &quot;Impossible&quot; &lt;&lt; endl;
        }       
    }       


    return 0;
}