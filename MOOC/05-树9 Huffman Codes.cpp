#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;
#define MAXSIZE 64
int nodenum;
int c[64];
char f[64];
typedef struct TNode* HuffTree;
struct TNode
{
    HuffTree left;
    HuffTree right;
    int freq;
};

struct heap
{
    HuffTree* data;
    int size;
    int capacity;
};
typedef struct heap* Minheap;

Minheap CreatHeap()
{
    Minheap H = new struct heap;
    H->data = new HuffTree[MAXSIZE];
    H->size = 0;
    H->capacity = MAXSIZE;
    H->data[0] = new struct TNode;
    H->data[0]->freq = -1;
    return H;
}
bool Insert( Minheap H, HuffTree f )
{
    int i;
    if ( H->size == H->capacity ){
        printf("minheap is full");
        return false;
    }
    i = ++H->size;
    for ( ; H->data[i/2]->freq > f->freq; i/=2 )
        H->data[i] = H->data[i/2];
    H->data[i] = f;
    return true;
}
bool IsEmpty( Minheap H )
{
    return (H->size == 0);
}

HuffTree DeleteMin( Minheap H )
{
    int Parent, Child;
    HuffTree MinItem, X;

    if ( IsEmpty(H) ) {
        printf("minheap is empty");
    }

    MinItem = H->data[1];
    X = H->data[H->size--];
    for( Parent=1; Parent*2<=H->size; Parent=Child ) {
        Child = Parent * 2;
        if( (Child!=H->size) && (H->data[Child]->freq > H->data[Child+1]->freq) )
            Child++;
        if( X->freq <= H->data[Child]->freq ) break;
        else
            H->data[Parent] = H->data[Child];
    }
    H->data[Parent] = X;

    return MinItem;
}
HuffTree HuffmanTree()
{
    Minheap h = CreatHeap();
    for(int i=0; i<nodenum; i++)
    {

        HuffTree f = new struct TNode;
        f->freq = c[i];
        f->left = NULL;
        f->right = NULL;
        if(!Insert(h,f))
                break;
    }
    for(;;)
    {
        if(h->size == 1) break;
        HuffTree f = new struct TNode;
        f->left = DeleteMin(h);
        f->right = DeleteMin(h);
        f->freq = f->left->freq + f->right->freq;
        Insert(h,f);//printf("fleft=%d,fright=%d,ffreq=%d\n",f->left->freq,f->right->freq,f->freq);
    }
    return DeleteMin(h);
}
int WPL(HuffTree tree,int depth)
{
    if((!tree->left)&&(!tree->right))
    {
        //printf("depth:%d,leaf->freq:%d\n",depth,tree->freq);
        return depth*(tree->freq);
    }
    else
    {
        //printf("depth:%d,tree->freq:%d\n",depth,tree->freq);
        return WPL(tree->left,depth+1)+WPL(tree->right,depth+1);
    }
}

bool check(HuffTree tree,string s)
{
    bool flag = false;
    HuffTree p = tree;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='0')
        {
            if(!p->left)
            {
                p->left = new TNode;
                p->left->left = NULL;
                p->left->right = NULL;
                p = p->left;
                flag=true;
            }
            else
            {
                p = p->left;
            }
        }
        else if(s[i]=='1')
        {
            if(!p->right)
            {
                p->right = new TNode;
                p->right->left = NULL;
                p->right->right = NULL;
                p = p->right;
                flag=true;
            }
            else
            {
                p = p->right;
            }
        }
    }
    return flag;
}

int main()
{
    int case_;
    cin>>nodenum;
    for(int i=0;i<nodenum;i++)
    {
        cin>>f[i]>>c[i];
    }
    HuffTree tree = HuffmanTree();
    int wpl = WPL(tree, 0);
    cin>>case_;
    for(int j=0;j<case_;j++)
    {
        HuffTree root = new TNode;
        root->left = NULL;
        root->right = NULL;
        int s_wpl=0;
        string judge="";
        for(int i=0;i<nodenum;i++)
        {
            char ch;
            string s;
            cin>>ch>>s;
            if(s.size()>nodenum-1){
                    judge="No";
                    break;
            }
            s_wpl += s.size()*c[i];
            if(!check(root,s)) judge="No";
        }
        if(judge.empty()&&s_wpl==wpl)judge = "Yes";
        else judge="No";
        cout<<judge<<endl;
    }




    return 0;
}


