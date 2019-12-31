#include &lt;iostream&gt;

using namespace std;

int nums[15];
int results[15];

int t, n, flag;

void DFS(int depth, int sum, int pos) {
    if (sum == t) {
        flag = 1;
        for (int i = 0; i &lt; depth; i++) {
            if (!i) {
                cout &lt;&lt; results[i];
            } else {
                cout &lt;&lt; &quot;+&quot; &lt;&lt; results[i];
            }
        }
        cout &lt;&lt; endl;
        return;
    }
    if (pos &gt;= n) {
        return;
    }
    if (sum &gt; t) {
        return;
    }
    results[depth] = nums[pos];
    DFS(depth + 1, sum + nums[pos], pos + 1);
    while (pos + 1 &lt; n &amp;&amp; nums[pos] == nums[pos + 1]) {
        pos++;
    }
    DFS(depth, sum, pos + 1);
}

int main() {
    while (cin &gt;&gt; t &gt;&gt; n, t) {
        flag = 0;
        for (int i = 0; i &lt; n; i++) {
            cin &gt;&gt; nums[i];
        }
        cout &lt;&lt; &quot;Sums of &quot; &lt;&lt; t &lt;&lt; &quot;:\n&quot;;
        DFS(0, 0, 0);
        if (!flag) {
            cout &lt;&lt; &quot;NONE&quot; &lt;&lt; endl;
        }
    }

    return 0;
}