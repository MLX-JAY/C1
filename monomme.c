#include <stdio.h>
typedef struct 
{
    int degre;
    float coef;
} monomme;
typedef struct 
{
    int nbsmax;
    int nbs;
    monomme *tab;
} poly;

poly initpoly (int nbsmax)
{
    poly p;
    p.nbsmax = nbsmax;
    p.nbs = 0;
    p.tab = malloc(nbsmax*sizeof(monomme));
    return p;
}
void freepoly (poly *p)
{
    free((*p).tab);
    (*p).tab = NULL;
}
int findmono (monomme m,poly p)
{
    int found=0;
    int droite=p.nbs;
    int gauche=0;
    int i=0;
    while (droite>gauche && found!=1)
    {
        i=(droite+gauche)/2;
        if ((p.tab+i)->degre==m.degre)
        {
            found=1;
        }

        if (m.degre<(p.tab +i)->degre)
        {
            droite=i-1;
        }
        else
        {
            gauche=i+1;
        }
    }
}
typedef monomme* pmonomme ;
pmonomme findmonoR (monomme m,poly p,int droite,int gauche)
{
    int i=(droite+gauche)/2;
        if (droite<gauche)
        {
            return NULL;
        }
        if ((p.tab+i)->degre==m.degre && (p.tab +i)->coef==m.coef)
        {
            return (p.tab +i);
        }

        if (m.degre<(p.tab +i)->degre)
        {
            findmonoR(m,p,i-1,gauche);
        }
        else
        {
            findmonoR(m,p,droite,i+1);
        }
}