#include &lt;iostream&gt;

using namespace std;

int main() {
    int n, d, u, count;
    while (cin &gt;&gt; n &gt;&gt; u &gt;&gt; d, n) {
        count = 0;
        for (; ;) {
           if (n &lt;= 0) {
               break;
           }   
           n -= u;
           count++;
           if (n &lt;= 0) {
               break;
           }   
           n += d;
           count++;
        }   
        cout &lt;&lt; count &lt;&lt; endl;
    }   



    return 0;
}