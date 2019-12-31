#include&lt;stdio.h&gt;
#include&lt;string.h&gt;
#include&lt;iostream&gt;
#include&lt;math.h&gt;
#include&lt;map&gt;
#include&lt;set&gt;
#include&lt;vector&gt;
#include&lt;algorithm&gt;
using namespace std;
const double INF = 1e20;
const double pi = acos(-1.);
struct poi
{
    double x,y;
};
poi hehe[100010];
poi QWQ[100010];
double dis(poi a,poi b)
{
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}
bool cmd(poi a,poi b)
{
    if(a.x != b.x)return a.x &lt; b.x;
    else return a.y &lt; b.y;
}
bool cmdy(poi a,poi b)
{
    return a.y&lt;b.y;
}
double lala(int left,int right)
{
    double d=INF;
    int mid=(left+right)/2;
    int i,j,num=0;
    if(left==right) return d;
    if(right-left==1)// 只有两个点
        return dis(hehe[left],hehe[right]);
    double dl=lala(left,mid);//左边的点所有距离
    double dr=lala(mid+1,right);//右边的所有距离
    d=min(dl,dr);
    for(i=left;i&lt;right;i++)
    {
        if(fabs(hehe[mid].x-hehe[i].x)&lt;=d)//从左边到右边，看有没有点到中线距离小于d，符合就有可能最短距离的点在中线各一侧
            QWQ[num++]=hehe[i];
    }
    sort(QWQ,QWQ+num,cmdy);
    for(i=0;i&lt;num;i++)
    {
        for(j=i+1;j&lt;num&amp;&amp;QWQ[j].y-QWQ[i].y&lt;d;j++)
        {
            d=min(d,dis(QWQ[i],QWQ[j]));
        }
    }
    return d;
}
int main()
{
   int n;
   while(scanf(&quot;%d&quot;,&amp;n),n)
   {
       int i;
       for(i=0;i&lt;n;i++)
        scanf(&quot;%lf%lf&quot;,&amp;hehe[i].x,&amp;hehe[i].y);
       sort(hehe,hehe+n,cmd);
       printf(&quot;%.2lf\n&quot;,lala(0,n-1)/2);
   }
    return 0;
}