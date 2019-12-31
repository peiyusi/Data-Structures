#include &lt;iostream&gt;
#include &lt;string&gt;
using namespace std;

int main() {
    string s;
    int N, count;
    cin &gt;&gt; N;
    count = 1;
    while (N--) {
        cin &gt;&gt; s;
        for (int i = 1; i &lt;= s.size(); i++) {
            if (s[i - 1] != s[i]) {
                if (count != 1) {
                    cout &lt;&lt; count;
                }
                cout &lt;&lt; s[i - 1];
                count = 1;
                continue;
            }
            count++;
        }
        cout &lt;&lt; endl;

    }

    return 0;
}