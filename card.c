#include <stdio.h>
#define N 10
typedef int bool;
typedef struct 
{
    int max ;
    bool tab [N+1];
} ensemble ;
ensemble initensemble ()
{
    ensemble p;
    for (int i=0; i<=N; i++) 
    {
        p.tab[i] = 0;
    }
    p.max=-1;
    return p;
}
void ajouter (int a,ensemble *p )
{
    if (a<N)
    {
        p->tab[a]=1;
        if (a>p->max)
        {
            p->max=a;
        }
    }
}
void affichage (ensemble p)
{
    printf ("l'ensemble est { ");
    for (int i=0 ;i<p.max;i++)
    {
        if (p.tab[i])
        {
            printf ("%d ,",i);
        }
    }
    printf ("%d }\n",p.max);
}
int carde (ensemble p)
{
    int somme=0;
    for (int i=0;i<=p.max;i++)
    {
        if (p.tab[i]==1)
        {
            somme++;
        }
    }
    return somme;
}
ensemble unione (ensemble p1, ensemble p2)
{
    ensemble p3=initensemble();
    int max =(p1.max>p2.max)?p1.max:p2.max;
    for (int i=0;i<=max;i++)
    {
        if ((p1.tab[i] || p2.tab[i]))
        {
            p3.tab[i]=1;
        }
    }
    p3.max= max;
    return p3;
}
ensemble diffe (ensemble p1, ensemble p2)
{
    ensemble p3=initensemble();
    for (int i=0;i<=p1.max;i++)
    {
        if (!p2.tab[i] && p1.tab[i])
        {
            p3.tab[i]=1;
        }
    }
    p3.max=p1.max;
    return p3;
}
void main ()
{
    ensemble p1,p2,p3,p4;
    p1=initensemble();
    p2=initensemble();
    ajouter (2,&p1);
    ajouter (3,&p1);
    ajouter (4,&p1);
    ajouter (1,&p2);
    ajouter (3,&p2);
    ajouter (5,&p2);
    p3=unione(p1,p2);
    p4=diffe(p1,p2);
    affichage(p1);
    affichage(p2);
    affichage(p3);
    affichage(p4);
}