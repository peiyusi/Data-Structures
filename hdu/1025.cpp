#include&lt;cstdio&gt;
int road[500010];
int lt[500010];
int lis;
void binary_search(int l,int r,int in){
    if(r-l==1) {
        if(lt[l]&gt;in) lt[l]=in;
        else{
            lt[l+1]=in;
            if(l+1&gt;lis) lis++;
        }
        return;
    }
    int mid=(r+l)/2;
    if(lt[mid]==in) return;
    if(lt[mid]&gt;in) binary_search(l,mid,in);
    else binary_search(mid,r,in);
    
}
int main(){
    int n;
    int i;
    int tcase=1;
    int a,b;
    while(scanf(&quot;%d&quot;,&amp;n)!=EOF){
        for(i=1;i&lt;=n;i++){ 
            scanf(&quot;%d %d&quot;,&amp;a,&amp;b);
            road[a]=b;
        }
        lis=1;
        lt[1]=road[1];
        for(i=2;i&lt;=n;i++)
            binary_search(1,lis+1,road[i]);
        printf(&quot;Case %d:\n&quot;,tcase++);
        printf(&quot;My king, at most %d &quot;,lis);
        if(lis&gt;1) printf(&quot;roads can be built.\n\n&quot;);
        else printf(&quot;road can be built.\n\n&quot;);

    }
    return 0;
}
