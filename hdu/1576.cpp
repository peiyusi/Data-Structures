#include &lt;iostream&gt;

using namespace std;

int main() {
    int T, n, A, i;
    long long int B;
    cin &gt;&gt; T;
    while (T--) {
        cin &gt;&gt; n &gt;&gt; B;
        for (i = 0; i &lt;= 10000; i++) {
            if ((B * i - n) % 9973 == 0) {
                break;
            }   
        }   
        cout &lt;&lt; i &lt;&lt; endl;
    }   

  
    return 0;
}
