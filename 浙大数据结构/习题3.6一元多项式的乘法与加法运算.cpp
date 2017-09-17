#include<stdio.h>
#include<stdlib.h>

typedef struct Polynomial
{
    int coef;
    int exp;
    struct Polynomial *next;
} Poly, *pPoly;

int AppendNode(int coef, int exp, pPoly *rear)
{
    pPoly temp;

    temp = (pPoly)malloc(sizeof(Poly));
    temp->coef = coef;
    temp->exp = exp;
    temp->next = NULL;
    (*rear)->next = temp;
    (*rear) = temp;

    return 0;
}

pPoly ReadPoly(void)
{
    pPoly p,rear;
    int n,coef,exp;

    p = (pPoly)malloc(sizeof(Poly));
    rear = p;

    scanf("%d",&n);
    while (n--)
    {
        scanf("%d",&coef);
        scanf("%d",&exp);
        AppendNode(coef,exp,&rear);
    }
    rear = p;
    p = p->next;
    free(rear);

    return p;
}

int CompareExp(int exp1, int exp2)
{
    int result;
    if (exp1 > exp2)
    {
        result = 1;
    }
    else if (exp1 < exp2)
    {
        result = 2;
    }
    else
    {
        result = 0;
    }
    return result;
}

pPoly AddPolynomial(pPoly p1,pPoly p2)
{
    pPoly result,rear;
    result = (pPoly)malloc(sizeof(Poly));
    result->next = NULL;
    rear = result;
    int comp,sum;

    while (p1 && p2 )
    {
        comp = CompareExp(p1->exp, p2->exp);
        switch (comp)
        {
            case 0:
                sum = p1->coef + p2->coef;
                if (sum)
                    AppendNode(sum,p1->exp,&rear);
                p1 = p1->next;
                p2 = p2->next;
                break;
            case 1:
                AppendNode(p1->coef,p1->exp,&rear);
                p1 = p1->next;
                break;
            case 2:
                AppendNode(p2->coef,p2->exp,&rear);
                p2 = p2->next;
                break;
        }
    }
    if (p1)
    {
        while (p1)
        {
            AppendNode(p1->coef,p1->exp,&rear);
            p1 = p1->next;
        }
    }
    if (p2)
    {
        while (p2)
        {
            AppendNode(p2->coef,p2->exp,&rear);
            p2 = p2->next;
        }
    }

    rear = result;
    result = result->next;
    free(rear);
    return result;
}

pPoly MultPolynomial(pPoly t1,pPoly t2)
{
    pPoly rear,result,temp,p1,p2;
    int coef,exp;

    result = (pPoly)malloc(sizeof(Poly));
    result->next = NULL;
    rear = result;

    if (!t1 || !t2)
    {
        return NULL;
    }

    //先令结果有值(然后再 插入后面的结果)
    for (temp = t2; temp != NULL; temp = temp->next)
    {
        if (t1->coef * temp->coef)
            AppendNode(t1->coef * temp->coef,t1->exp + temp->exp,&rear);
    }
    //p1的第一项已经处理过
    for (p1 = t1->next; p1 != NULL; p1 = p1->next)
    {
        for (p2 = t2; p2 != NULL; p2 = p2->next)
        {
            coef = p1->coef * p2->coef;
            exp = p1->exp + p2->exp;

            temp = result;
            while (temp->next->exp > exp && temp->next->next != NULL)
                temp = temp->next;

            if (temp->next->exp == exp)
            {
                temp->next->coef += coef;
                if (temp->next->coef == 0)
                {
                    rear = temp->next;
                    temp->next = rear->next;
                    free(rear);
                }
            }
            else if (temp->next->exp < exp)
            {
                rear = (pPoly)malloc(sizeof(Poly));
                rear->coef = coef;
                rear->exp = exp;
                rear->next = temp->next;
                temp->next = rear;
            }
            else
            {
                rear = (pPoly)malloc(sizeof(Poly));
                rear->coef = coef;
                rear->exp = exp;
                rear->next = NULL;

                temp->next->next = rear;
            }
        }
    }
    temp = result;
    result = result->next;
    free(temp);
    return result;
}

void PrintResult(pPoly result)
{
    if (!result)
    {
        printf("0 0");
    }
    else
    {
        while (result)
        {
            if (result->next)
            {
                printf("%d %d ",result->coef,result->exp);
            }
            else
            {
                printf("%d %d",result->coef,result->exp);
            }
            result = result->next;
        }
    }
    printf("\n");
    return ;
}



int main()
{
    pPoly p1,p2,result,mult;

    p1 = ReadPoly();
    p2 = ReadPoly();

    mult = MultPolynomial(p1,p2);
    PrintResult(mult);

    result = AddPolynomial(p1,p2);
    PrintResult(result);

    return 0;
}
