#include &lt;iostream&gt;

using namespace std;

int main() {
    int T;
    cin &gt;&gt; T;
    for (int i = 0; i &lt; T; i++) {
        int N;
        cin &gt;&gt; N;
        int a[N];
        int thisSum = 0;
        int start = 0;
        int end = 0;
        int temp = 0;
        for (int j = 0; j &lt; N; j++) {
            cin &gt;&gt; a[j];
        }
        int maxSum = a[0];
        for (int k = 0; k &lt; N; k++) {
            thisSum += a[k];
            if (maxSum &lt; thisSum) {
                maxSum = thisSum;
                end = k;
                start = temp;
            }
            if (thisSum &lt; 0) {
                thisSum = 0;
                temp = k + 1;
            }

        }
        cout &lt;&lt; &quot;Case &quot; &lt;&lt; i + 1 &lt;&lt;&quot;:&quot; &lt;&lt; endl;
        cout &lt;&lt; maxSum &lt;&lt; &quot; &quot; &lt;&lt; start + 1 &lt;&lt; &quot; &quot; &lt;&lt; end + 1 &lt;&lt; endl;
        if (i != T - 1) {
            cout &lt;&lt; endl;
        }
    }
    return 0;
}