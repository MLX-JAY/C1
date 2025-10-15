#include <stdio.h>
typedef struct 
{
    int deg;
    float coef[30];
} poly ;
poly initpoly ()
{
    poly p;
    p.deg=0;
    p.coef[0]=0;
    return p;
}
void addpoly (poly *p,int i ,float x)
{
    p->coef[i]=x;
    if (i>p->deg)
    {
        p->deg=i;
    }

}
float horner (poly p,int i,int x)
{
    if (i==p.deg)
    {
        return p.coef[i];
    }
    else 
    {
        return (p.coef[i]+horner (p,i+1,x)*x);
    }
}
poly derive ( poly p)
{
    for (int i=0;i<=p.deg;i++)
    {
        p.coef[i]=p.coef[i+1]*(i+1);
    }
    if (p.deg!=0)
    {
        p.deg=p.deg-1;
    }
    return p;
}
void main ()
{
    poly p;
    p=initpoly();
    addpoly(&p,3,4);
    addpoly(&p,2,3);
    addpoly(&p,1,2);
    addpoly(&p,0,1);
    printf ("%.2f %.2f %.2f\n",derive(p).coef[0],derive(p).coef[1],derive(p).coef[2]);
}