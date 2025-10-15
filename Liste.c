#include <stdio.h>
#include <stdlib.h>
typedef int elet ;
typedef struct cellule
{
    elet info;
    struct cellule * suiv;
} *liste ;
liste  initliste ()
{
    return NULL;
}
void affichage (liste l)
{
    while (l!=NULL)
    {
        printf("%d\n",l->info);
        l=l->suiv;
    }
}
int nombreOcc (liste l,elet k)
{
    int occ=0;
    while (l!=NULL)
    {
        if (l->info==k)
        {
            occ++;
        }
        l=l->suiv;
    }
    return occ;
}
int longeur (liste l)
{
    int longe=0;
    while (l!=NULL)
    {
        longe++;
        l=l->suiv;
    }
    return longe;
}
elet nombreMax (liste l)
{
    if (l==NULL)
    {
        printf("la liste est vide");
        return -1;
    }
    int max=l->info;
    l=l->suiv;
    while (l!=NULL)
    {
        if ( l->info>max)
        {
            max=l->info;
        }
        l=l->suiv;
    }
    return max;
}
liste adressMax (liste l)
{
    if (l==NULL)
    {
        return NULL;
    }
    int max=l->info;
    liste adressM=l;
    l=l->suiv;
    while (l!=NULL)
    {
        if ( l->info>max)
        {
            max=l->info;
            adressM=l;
        }
        l=l->suiv;
    }
    return adressM;
}
elet nombreDernier (liste l)
{
    if (l==NULL)
    {
        printf("la liste est vide");
        return -1;
    }
    while (l->suiv!=NULL)
    {
        l=l->suiv;
    }
    return l->info;
}
liste nombreDernierAdress (liste l)
{
    if (l==NULL)
    {
        return NULL;
    }
    while (l->suiv!=NULL)
    {
        l=l->suiv;
    }
    return l;
}
liste addQueu (liste l,elet k)
{
    liste p=initliste();
    p=(liste)malloc(sizeof(struct cellule));
    p->info=k;
    p->suiv=NULL;
    if ( l==NULL)
    {
        return p;
    }
    else 
    {
        liste p2=l;
        while (l->suiv!=NULL)
        {
            l=l->suiv;
        }
        l->suiv=p;
        return p2;
    }
   
}
liste randomListe (int n)
{
    liste l=initliste();
    for (int i=0;i<n;i++)
    {
        l=addQueu (l,(elet)rand()%10);
    }
    return l;
}
int recherche (liste l,elet k)
{
    while (l!=NULL)
    {
        if(l->info==k)
        {
            return 1;
        }
        l=l->suiv;
    }
    return 0;
}
liste adressNombre (liste l,elet k)
{
    while (l!=NULL)
    {
        if (l->info==k)
        {
            return l;
        }
        l=l->suiv;   
    }
    return NULL;
}
int existePos (liste l, int n)
{
    while (n>=0 && l!=NULL)
    {
        l=l->suiv;
        n--;
    }
    if (n>=0)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}
int adressPostion (liste l, int n)
{
    while (n>=0 && l!=NULL)
    {
        l=l->suiv;
        n--;
    }
    if (n==0)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}
liste addTete ( liste l,elet k)
{
    liste p=initliste();
    p=(liste)malloc(sizeof(struct cellule));
    p->info=k;
    p->suiv=l;
    return p;
}
void main ()
{
    liste tete = initliste();
    tete = randomListe(10);
    printf("Liste aleatoire : ");
    affichage(tete);

    liste tete2 = initliste();
    tete2 = addQueu(tete2, 3);
    tete2 = addQueu(tete2, 4);
    tete2 = addQueu(tete2, 5);
    tete2 = addQueu(tete2, 3);
    tete2 = addQueu(tete2, 6);

    printf("\nListe 2 : ");
    affichage(tete2);

    printf("recherche(5) = %d\n", recherche(tete2, 5));
    printf("longueur = %d\n", longeur(tete2));
    printf("max = %d\n", nombreMax(tete2));
    printf("dernier = %d\n", nombreDernier(tete2));
    printf("occurrences(3) = %d\n", nombreOcc(tete2, 3));

}