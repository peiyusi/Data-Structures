#include &lt;iostream&gt;
#include &lt;cstdio&gt;
#include &lt;algorithm&gt;

using namespace std;

struct element {
    double sum;
    int index;
};

bool sum_cmp(struct element a, struct element b) {
    return a.sum &gt; b.sum;
}

bool index_cmp(struct element a, struct element b) {
    return a.index &gt; b.index;
}

int main() {
    struct element e[200];
    int N, M, K;
    while (cin &gt;&gt; N &gt;&gt; M &gt;&gt; K) {
        for (int i = 1; i &lt;= M; i++) {
            scanf(&quot;%lf&quot;, &amp;e[i].sum);
            e[i].index = i;
        }   

        double temp;
        for (int i = 2; i &lt;= N; i++) {
            for (int j = 1; j &lt;= M; j++) {
                scanf(&quot;%lf&quot;, &amp;temp);
                e[j].sum += temp;
            }   
        }   
    
        sort(e + 1, e + M + 1, sum_cmp);
        sort(e + 1, e + K + 1, index_cmp);
    
        cout &lt;&lt; e[1].index; 
        for (int i = 2; i &lt;= K; i++) {
            cout &lt;&lt; &quot; &quot; &lt;&lt; e[i].index;
        }   
        cout &lt;&lt; endl;
    }   

    return 0;
}