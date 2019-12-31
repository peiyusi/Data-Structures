#include &lt;iostream&gt;
#include &lt;cstring&gt;
#include &lt;algorithm&gt;
int a[501];
int b[501];
int dp[501];
using namespace std;
int main() {
    int N, m, n;
    cin &gt;&gt; N;
    while (N--) {
       memset(dp, 0, sizeof(dp));
       cin &gt;&gt; m;
       for (int k = 1; k &lt;= m; k++) {
           cin &gt;&gt; a[k];
       }
       cin &gt;&gt; n;
       for (int k = 1; k &lt;= n; k++) {
           cin &gt;&gt; b[k];
       }
       for (int i = 1; i &lt;= m; i++) {
           int maxx = 0;
           for (int j = 1; j &lt;= n; j++) {
               if (a[i] == b[j]) {
                   dp[j] = maxx + 1;
               } else if (a[i] &gt; b[j]) {
                   maxx = max(maxx, dp[j]);
               }
           }
       }
       cout &lt;&lt; * max_element(dp, dp+501);
       if (N != 0) {
           cout &lt;&lt; &quot;\n\n&quot;;
       } else {
           cout &lt;&lt; &quot;\n&quot;;
       }
    }

    return 0;
}