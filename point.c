#include <stdio.h>
#include <math.h>
typedef struct 
{
    char idf;
    float x;
    float y;
} point;
typedef struct
{
    int nbs;
    point tab[10];
}ligne;
point initpoint (char lettre , int x, int y)
{
    point p;
    p.idf = lettre;
    p.x = x;
    p.y = y;
    return p;
}
ligne initligne ()
{
    ligne l;
    l.nbs = 0;
    return l;
}
void addpoint (ligne *l, point p)
{
    l->tab[l->nbs]=p;
    l->nbs++;
}
void affichage (ligne l)
{
    for (int i=0;i<l.nbs;i++)
    {
        printf("%c %2.f %2.f\n",l.tab[i].idf,l.tab[i].x,l.tab[i].y);
    }
}
void longeur (ligne l)
{
    float sommel=0;
    float longeur =0;
    for (int i=0;i<l.nbs-1;i++)
    {
        longeur = sqrt((l.tab[i+1].x-l.tab[i].x)*(l.tab[i+1].x-l.tab[i].x)+(l.tab[i+1].y-l.tab[i].y)*(l.tab[i+1].y-l.tab[i].y));
        printf("longeur %2.f\n",longeur);
        sommel+=longeur;
    }
    printf("ligne %2.f \n",sommel);
}
void longeurP (ligne l)
{
    float sommel=0;
    float longeur =0;
    for (int i=0;i<l.nbs-1;i++)
    {
        longeur = sqrt(pow(((l.tab)+i)->x-((l.tab)+i+1)->x,2)+pow((l.tab+i)->y-(l.tab+i+1)->y,2));
        printf("longeur %2.f\n",longeur);
        sommel+=longeur;
    }
    printf("ligne %2.f \n",sommel);

}
float longeurR (ligne l,int nbr)
{
    if (nbr<=1)
    {
        return 0;
    }
    else
    {
        return sqrtf((l.tab[nbr-1-1+1].x-l.tab[nbr-1-1].x)*(l.tab[nbr-1-1+1].x-l.tab[nbr-1-1].x)+(l.tab[nbr-1-1+1].y-l.tab[nbr-1-1].y)*(l.tab[nbr-1-1+1].y-l.tab[nbr-1-1].y))+longeurR(l,nbr-1);
    }
}
void afficheR (ligne l)
{
    for (int i=0;i<l.nbs;i++)
    {
        printf("%c %2.f %2.f\n",(l.tab+i)->idf,(l.tab+i)->x,(l.tab+i)->y);
    }
}
void affichage_recursif (ligne l,int i)
{
    if (i<l.nbs)
    {
        printf("%c %2.f %2.f\n",l.tab[i].idf,l.tab[i].x,l.tab[i].y);
        affichage_recursif (l,i+1);
    }
}
int longeurA (ligne l)
{
    int somme=0;
    for (int i=0;i<l.nbs-1;i++)
    {
        somme+=sqrt(pow(((l.tab)+i)->x-((l.tab)+i+1)->x,2)+pow((l.tab+i)->y-(l.tab+i+1)->y,2));
    }
    return somme;
}
void lePLusGrand (ligne l1,ligne l2)
{
    int p1=longeurA(l1);
    int p2=longeurA(l2);
    printf ("le plus grand est : ");
    p1>p2? printf ("la ligne 1\n"):printf ("ligne 2\n");
}
void main ()
{
    point A = initpoint('A', 2.1, 5);
    point B = initpoint('B', 3.5, 7);
    point C = initpoint('C', 5.0, 8.5);
    point D = initpoint('D', 0, 0.5);
    point E = initpoint('E', 1.5, 1.1);
    point F = initpoint('F', 2.5, 3);
    point G = initpoint('G', 5.5, 4.6);
    ligne l = initligne();
    ligne m = initligne();
    addpoint(&l, A);
    addpoint(&l, B);
    addpoint(&l, C);
    addpoint(&m, D);
    addpoint(&m, E);
    addpoint(&m, F);
    addpoint(&m, G);
    affichage_recursif(l,0);
    affichage_recursif(m,0);
    printf("ligne %2.f \n",longeurR(l,l.nbs));
    printf("ligne %2.f \n",longeurR(m,m.nbs));
    lePLusGrand(l,m);

}