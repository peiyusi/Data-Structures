#include &lt;iostream&gt;

using namespace std;

int main() {
    int N;
    while (cin &gt;&gt; N) {
        for (int i = 2; i * i &lt;= N; i++) {
            if (N % i == 0) {
                N /= i;
                cout &lt;&lt; i &lt;&lt; &quot;*&quot;;
                i = 1;
            }   
        }   
        cout &lt;&lt; N &lt;&lt; endl;
    }   

    return 0;
}