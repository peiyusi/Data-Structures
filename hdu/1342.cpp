#include &lt;iostream&gt;

using namespace std;

int results[10];
int numbers[15];
int k;

void DFS(int num, int pos) {
    if (num == 7) {
        for (int i = 1; i &lt; num; i++) {
            if (i == 1) {
                cout &lt;&lt; results[1]; 
            } else {
                cout &lt;&lt; &quot; &quot; &lt;&lt; results[i];
            }   
        }   
        cout &lt;&lt; endl;
        return;
    }   
    if (pos &gt; k) {
        return;
    }   
    results[num] = numbers[pos];
    DFS(num + 1, pos + 1); 
    DFS(num, pos + 1); 
}

int main() {
    int flag = 0;
    while (cin &gt;&gt; k, k) {
        if (flag != 0) {
            cout &lt;&lt; endl;
        }   
        for (int i = 1; i &lt;= k; i++) {
            cin &gt;&gt; numbers[i];
        }   
        DFS(1, 1); 
        flag++;
    }   

    return 0;
}