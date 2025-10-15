#include <stdio.h>
#include <stdlib.h>
typedef int Tele;
typedef struct 
{
    int nbrM;
    int nbr;
    Tele *tab;
} ensemble;
ensemble allocM (int n)
{
    ensemble p;
    p.nbr=0;
    p.nbrM=n;
    p.tab=calloc(n,sizeof(Tele));
    return p;
}
void ajouter (ensemble *p,Tele x)
{
    if (p->nbr<p->nbrM)
    {
        *(p->tab+p->nbr)=x;
        p->nbr++;
    }
}
void affichage (ensemble p)
{
    printf ("le nombre d element est %d et le max est %d \n et les elements sont : ",p.nbr,p.nbrM);
    for (int i=0;i<p.nbr;i++)
    {
        printf ("%d,",*(p.tab+p.nbr));
    }
    printf ("\n");
}
void inclus (ensemble p1, ensemble p2)
{
    if (p1.nbr>=p2.nbr)
    {
        int continu=1;
        int i=0;
        int temp;
        int continu1=1;
        int k=0;
        while (continu1 && k<p2.nbr)
            {
                continu1=1;
                temp=p2.tab[k];
                while (continu && i<p1.nbr)
                {
                    
                    if (temp==p1.tab[i])
                    {
                        continu=0;
                        continu1=0;
                    }
                    i++;
                }
                if ( continu==0)
                {
                    break;
                }
                k++;
                i=0;  
            }
        if ( continu1==1)
        {
            printf ("l ensemble est inclu \n");
        }
        else 
        {
            printf ("l enemble ne st pas inclu");
        }
    }
}