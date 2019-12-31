#include &lt;iostream&gt;

using namespace std;

int a[1000];

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition (int a[], int first, int last) {
    int pivot = a[last];
    int i = first - 1;
    for (int j = first; j &lt;= last - 1; j++) {
        if (a[j] &lt;= pivot) {
            i++;
            swap(&amp;a[i], &amp;a[j]);
        }
    }
    swap(&amp;a[i + 1], &amp;a[last]);

    return i + 1;
}

void quicksort(int a[], int first, int last) {
    if (first &lt; last) {
        int pi = partition(a, first, last);
        quicksort(a, first, pi - 1);
        quicksort(a, pi + 1, last);
    }
}


int main() {
    int T, N;
    cin &gt;&gt; T;
    while (T--) {
        cin &gt;&gt; N;
        for (int i = 0; i &lt; N; i++) {
            cin &gt;&gt; a[i];
        }
        quicksort(a, 0, N - 1);
        cout &lt;&lt; a[0];
        for (int i = 1; i &lt; N; i++) {
            cout &lt;&lt; &quot; &quot; &lt;&lt; a[i];
        }
        cout &lt;&lt; endl;
    }
    return 0;
}