#include &lt;iostream&gt;
using namespace std;
int numbers[101][101];

void Catalan() {
    int c, s, len;
    numbers[1][0] = 1;
    numbers[1][1] = 1;
    numbers[2][0] = 1;
    numbers[2][1] = 2;
    len = 1;
    for (int i = 3; i &lt; 101; i++) {
        c = 0;
        for (int j = 1; j &lt;= len; j++) {
            s = numbers[i-1][j] * (4 * i - 2) + c;
            c = s / 10;
            numbers[i][j] = s % 10;
        }

        while (c) {
            numbers[i][++len] = c % 10;
            c /= 10;
        }

        for (int j = len; j &gt; 0; j--) {
            s = numbers[i][j] + c * 10;
            numbers[i][j] = s / (i + 1);
            c = s % (i + 1);
        }

        while (!numbers[i][len]) {
            len--;
        }

        numbers[i][0] = len;
    }
}


int main() {
    int N;
    Catalan();
    while (cin &gt;&gt; N) {
        for (int i = numbers[N][0]; i &gt; 0; i--) {
            cout &lt;&lt; numbers[N][i];
        }
        cout &lt;&lt; endl;
    }

    return 0;
}