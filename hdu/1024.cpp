#include &lt;iostream&gt;
#include &lt;cstdlib&gt;
#include &lt;climits&gt;
#include &lt;algorithm&gt;
using namespace std;

int dp(int *numbers, int m, int n) {
    int maxSum;
    int *curr = (int *)calloc(n + 1, sizeof(int));
    int *pre = (int *)calloc(n + 1, sizeof(int));
    numbers = numbers - 1;
    int j = 0;    
    for (int i = 1; i &lt;= m; i++) {
        maxSum = INT_MIN;
        for (j = i; j &lt;= n; j++) {
            curr[j] = max(curr[j-1], pre[j-1]) + numbers[j];
            pre[j-1] = maxSum;
            maxSum = max(maxSum, curr[j]);
        }   
        pre[j-1] = maxSum;
    }   
    
    free(curr);
    free(pre);

    return maxSum;
}
int main() {
   int m, n;
   while (cin &gt;&gt; m &gt;&gt; n) {
       int numbers[n];
       for (int i = 0; i &lt; n; i++) {
           cin &gt;&gt; numbers[i];
       }   
       cout &lt;&lt; dp(numbers, m, n) &lt;&lt; endl;
   }   

   return 0;
}