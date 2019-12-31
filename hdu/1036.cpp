#include &lt;stdio.h&gt;

char times[15];
int flag = 1;

int main() {
    int n, t, avg;
    double d;
    scanf(&quot;%d %lf&quot;, &amp;n, &amp;d);
    while (scanf(&quot;%d&quot;, &amp;t) != EOF) {
        flag = 1;
        avg = 0;
        int i;
        for (i = 0; i &lt; n; i++) {
            scanf(&quot;%s&quot;, times); 
            if (times[0] == '-') {
                flag = 0;  
            } else {
                int h = (times[0] - '0') * 3600;
                int mm = ((times[2] - '0') * 10 + (times[3] - '0')) * 60;    
                int ss = (times[5] - '0') * 10 + (times[6] - '0'); 
    
                avg += (h + mm + ss);
            }   
        }   
        if (!flag) { 
            printf(&quot;%3d: -\n&quot;, t); 
        } else {
            avg = (int)((double)avg / d + 0.5);
            printf(&quot;%3d: %d:%02d min/km\n&quot;, t, avg/60, avg%60);
        }   

    }   
    
    return 0;
}