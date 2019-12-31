#include &lt;iostream&gt;
using namespace std;

int LCM(int a, int b) {
    if (b == 0) {
        return a;
    }
    return LCM(b, a % b);
}

int main() {
    int N, n, num, x;
    cin &gt;&gt; N;
    while (N--) {
        num = 0;
        cin &gt;&gt; n &gt;&gt; num;
        for (int i = 0; i &lt; n - 1; i++) {
            cin &gt;&gt; x;
            num = num / LCM(num, x) * x;
        }
        cout &lt;&lt; num &lt;&lt; endl;
    }

    return 0;
}