#include &lt;iostream&gt;

using namespace std;

int a[1000];

int isEqual(int n) {
    for (int i = 1; i &lt; n; i++) {
        if (a[0] != a[i]) {
            return 0;
        }   
    }   
    return 1;
}

int main() {
    int N;
    while (cin &gt;&gt; N, N) {
        for (int i = 0; i &lt; N; i++) {
            cin &gt;&gt; a[i];
        }   
        int count = 0;
        for (; ;) {
            count++;
            int t = a[0] / 2;
            for (int i = 1; i &lt; N; i++) {
                a[i] = a[i] / 2 + t;
                t = a[i] - t;
                a[i] += (a[i] % 2); 
            }   
            a[0] = a[0] / 2 + t;
            a[0] += (a[0] % 2); 
            if (isEqual(N)) {
                break;
            }   
        }   
        cout &lt;&lt; count &lt;&lt; &quot; &quot; &lt;&lt; a[0] &lt;&lt; endl;
    }   

    return 0;
}