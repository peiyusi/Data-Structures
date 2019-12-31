#include &lt;iostream&gt;
#include &lt;climits&gt;

using namespace std;

int main() {
    int N;
    while (cin &gt;&gt; N, N) {
        int maybe_head = 0, head, tail, sum = 0, flag = 0, maxnum = INT_MIN;
        int List[N];
        for (int i = 0; i &lt; N; i++) {
            cin &gt;&gt; List[i];
            if (List[i] &gt;= 0) {
                flag = 1;
            }
            if (sum &gt;= 0) {
                sum += List[i];
            } else {
                sum = List[i];
                maybe_head = i;
            }
            if (maxnum &lt; sum) {
                maxnum = sum;
                head = maybe_head;
                tail = i;
            }
        }

        if (!flag) {
            cout &lt;&lt; &quot;0 &quot; &lt;&lt; List[0] &lt;&lt; &quot; &quot; &lt;&lt; List[N - 1] &lt;&lt; endl;
        } else {
            cout &lt;&lt; maxnum &lt;&lt; &quot; &quot; &lt;&lt; List[head] &lt;&lt; &quot; &quot; &lt;&lt; List[tail] &lt;&lt; endl;
        }

    }

    return 0;

}