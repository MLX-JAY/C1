#include <stdio.h>
#include <stdlib.h>
typedef int elet ;
typedef struct
{
    int nbrM ;
    int nbrC; 
    elet *tab;
} ensemble ;
ensemble initensemble (int n)
{
    ensemble p;
    p.nbrM=n;
    p.nbrC=0;
    p.tab=calloc(n,sizeof(elet));
    return p;
}
void initensembleA (ensemble *p, int n)
{
    p->nbrM=0;
    p->nbrC=0;
    p->tab=(elet *)malloc(n*sizeof(elet));
}
void delete ( ensemble *e)
{
    elet *t=e->tab;
    free(t);
    e->tab=NULL;
}
int appartient ( ensemble e, elet k)
{
    int i=0;
    while (i<e.nbrC)
    {
        if (*(e.tab+i)==k)
        {
            return 1;
        }
    }
    return 0;
}
void add ( ensemble *e, elet k)
{
    if (e->nbrC<e->nbrM-1)
    {
        *(e->tab+e->nbrC)=k;
        e->nbrC++;
    }
}
ensemble sansrep (ensemble e1)
{
    ensemble e2=initensemble(e1.nbrM);
    for ( int i=0;i<e1.nbrC;i++)
    {
        if (appartient(e2,*(e1.tab+i)))
        {
            add(&e2,e1.tab[i]);
        }
    }
}
ensemble inter (ensemble e1,ensemble e2)
{
    ensemble e3=initensemble(e1.nbrM>e2.nbrM?e1.nbrM:e2.nbrM);
    for (int i=0;i<e3.nbrC;i++)
    {
        if (appartient(e2,*(e3.tab+i))&&appartient(e1,*(e3.tab+i)))
        {
            add(&e3,e3.tab[i]);
        }
    }
}