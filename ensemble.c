#include <stdio.h>
#define N 10
typedef int elet ;
typedef struct 
{
    int nbr ;
    elet tab [N];
} ensemble ;
ensemble initensemble ()
{
    ensemble p;
    p.nbr = 0;
    for (int i=0; i<N; i++)
    {
        p.tab[i] = 0;
    }
    return p;
}
void ajouter (ensemble *p, elet a)
{
    if (p->nbr<N)
    {
        p->tab[p->nbr]=a;
        p->nbr++;
    }
}
void affichage ( ensemble p)
{
    printf ("voici l ensemble { ");
    for (int i=0;i<p.nbr-1;i++)
    {
        printf ("%d ,",p.tab[i]);
    }
    printf ("%d }\n",p.tab[p.nbr-1]);
}
int  recherche (ensemble p, elet k)
{
    for (int i=0 ;i<p.nbr;i++)
    {
        if (p.tab[i]==k)
        {
            return 1;
        }
    }
    return 0;
}
ensemble sansrep (ensemble p1)
{
    ensemble p2=initensemble();
    for (int i=0;i<p1.nbr;i++)
    {
        int add =1;
        int z=0;
        while (add==1 && z<p2.nbr)
        {
            if (p1.tab[i]==p2.tab[z])
            {
                add=0;
            }
            z++;
        }
        if (add==1)
        {
            ajouter (&p2,p1.tab[i]);
        }
    }
    return p2;
}
ensemble unione ( ensemble e1 , ensemble e2)
{
    ensemble e3=sansrep(e1);
    for ( int i=0;i<e2.nbr;i++)
    {
        if (!recherche(e1,e2.tab[i]))
        {
            e3.tab[e3.nbr]=e2.tab[i];
            e3.nbr++;
        }
    }
    return e3;
}
int rechercheT ( ensemble e,elet k)
{
    int gauche=0;
    int droite=e.nbr-1;
    int continu =1;
    int milieu;
    int element;
    while (gauche <droite && continu==1)
    {
        milieu=(droite + gauche )/2;
        element =e.tab[milieu];
        if ( element==k)
        {
            return 1;
        }
        else 
        {
            if (k<element)
            {
                droite=milieu-1;
            }
            else
            {
                gauche=milieu+1;
            }
        }
    }
    return 0;
}
void ajouteT ( ensemble *p,elet x)
{
    int i=0;
    if (!rechercheT(*p,x))
    {
        if (p->nbr<N)
        {
            while (x>p->tab[i] && i <p->nbr)
            {
                i++;
            }
            for (int j=i;j<p->nbr-1;j++)
            {
                p->tab[j+1]=p->tab[j];
            }
            p->tab[i]=x;
        }
    }
}
ensemble sansrepT ( ensemble p)
{
    ensemble e;
    for ( int i=0;i<p.nbr;i++)
    {
        ajouteT ( &e,p.tab[i]);
    }
    return e;
}
void main ()
{
    ensemble p1,p2,p3;
    p1=initensemble();
    p2=initensemble();
    ajouter (&p1,1);
    ajouter (&p1,2);
    ajouter (&p1,3);
    ajouter (&p1,4);
    ajouter (&p2,3);
    ajouter (&p2,4);
    ajouter (&p2,5);
    p3=unione(p1,p2);
    affichage(p1);
    affichage(p2);
    affichage(p3);
}