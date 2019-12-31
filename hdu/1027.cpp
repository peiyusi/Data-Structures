#include &lt;iostream&gt;
#include &lt;algorithm&gt;

using namespace std;

int a[1010];

void mynext_permutation(int N)
{
    int x1, x2; 
    
    for (int i = N -1; i &gt; 0; i--) {
        if (a[i] &gt; a[i-1]) {
            x1 = i-1;
            x2 = i;
            break;
        }   
    }   
    for (int i = N-1; i &gt; 0; i--) {
        if (a[i] &gt; a[x1]) {
            swap(a[i], a[x1]);
            reverse(a+x2, a+N); 
            break;
        }   
    }   


}

int main() {
    int N, M;
    while (cin &gt;&gt; N &gt;&gt; M) {
        for (int i = 0; i &lt; N; i++) {
            a[i] = (i + 1); 
        }   
        while (--M) {
            mynext_permutation(N);
        }   
        cout &lt;&lt; a[0];
        for (int j = 1; j &lt; N; j++) {
            cout &lt;&lt; &quot; &quot; &lt;&lt; a[j]; 
        }   
        cout &lt;&lt; endl;
    }   

    return 0;
}