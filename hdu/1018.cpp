#include &lt;iostream&gt;
#include &lt;cmath&gt;
using namespace std;

int main() {

    int n, number;
    double factorialnumber;
    cin &gt;&gt; n;
    while (n--) {
        factorialnumber = 0;
        cin &gt;&gt; number;
        for (int i = 1; i &lt;= number; i++) {
           factorialnumber += log10((double)i);
        }
        cout &lt;&lt; (int)factorialnumber + 1 &lt;&lt; endl;

    }

    return 0;
}