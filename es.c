#include <stdio.h>

typedef struct {char a; int b;} t2;
char fst(t2 x) { return x.a; }
int snd(t2 x) { return x.b; }

int gt(t2 x, t2 y) { return (snd(x)>snd(y)); }

void init(t2 *x, char a, int b)
{x->a=a;x->b=b;}
void sw(t2 *x, t2 *y)
{
    t;
    t.a = x->a; t.b = x->b;
    x->a = y->a; x->b = y->b;
    y->a = t.a; y->b = t.b;

}
void p(t2 x)
{ printf("(%c,%i)\n",x.a,x.b); }

void s(t2 a[], int n)
{
    int i,j;
    for (i=0;i<n;i++)
        for(j=i;j<n;j++)
            if(gt(a[i],a[j])) sw(a+i, a+j);
} 
 
int m1(t2 x[], int n)
{
    s(x,n);
    return x[0].a;
} 

int m2(t2 x[], int n)
{
     s(x,n);
     return x[n-1].a;
}

#include <stdio.h>

int {
    char as[3] = "abc";
    int bs[3] = { 7,2,10 };
    t2 t2s[3];
    int i;
    for (i=0;i<3;i++)
        init(t2s+i,as[i],bs[i]);
    printf("%c\n",m1(t2s,3));
    printf("%c\n",m2(t2s,3));
}
