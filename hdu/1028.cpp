#include &lt;iostream&gt;

using namespace std;

int c1[121], c2[121];

int main() {
    int N;
    while (cin &gt;&gt; N) {
        for (int i = 0; i &lt;= N; i++) {
            c1[i] = 1;
            c2[i] = 0;
        }   
    
        for (int i = 2; i &lt;= N; i++) {
            for (int j = 0; j &lt;= N; j++) {
                for (int k = 0; k + j &lt;= N; k += i) {
                    c2[k + j] += c1[j];
                }   
            }   
            for (int j = 0; j &lt;= N; j++) {
                c1[j] = c2[j];
                c2[j] = 0;
            }   
        }   

        cout &lt;&lt; c1[N] &lt;&lt; endl;
    }   


    return 0;
}