#include &lt;iostream&gt;
#include &lt;cstdio&gt;

using namespace std;

int main() {
    int T, Y, N;
    cin &gt;&gt; T;
    while (T--) {
        cin &gt;&gt; Y &gt;&gt; N;
        int count = 0;
        if ((Y % 4 == 0 &amp;&amp; Y % 100 != 0) || Y % 400 == 0) {
            count = 1;
        }   
        while (count != N) {
            Y++;
            if ((Y % 4 == 0 &amp;&amp; Y % 100 != 0) || Y % 400 == 0) count++;
        }   
        cout &lt;&lt; Y &lt;&lt; endl;
    }   
    return 0;
}