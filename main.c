#include <stdio.h>
typedef struct 
{
    int jour;
    int mois;
    int annee;
} Date;
typedef Date* ptrdate;
ptrdate tabdate ()
{
    Date date[5];
    for (int i=0;i<5;i++)
    {
        scanf("%d/%d/%d",&date[i].jour,&date[i].mois,&date[i].annee);
    }
        return date;
}
void affiche1 (ptrdate p)
{
    
}
int main ()
{
    Date date;
    date.jour = 1;
    date.mois = 1;
    date.annee = 2000;
    ptrdate p1=&date;
    printf("%d/%d/%d \n",date.jour,date.mois,date.annee);
    printf("%d/%d/%d\n",p1->jour,p1->mois,p1->annee);

}