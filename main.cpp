#include <iostream>
#include <stdio.h>
#include <malloc.h>
#include <conio.h>

using namespace std;

struct drzewo_bin
{
	int i;
	char tresc[100];
	struct drzewo_bin * ojciec, * l_syn, * p_brat;
};

struct drzewo_bin * create();
void add_new_element(int *i,int rozm,char napis[100],struct drzewo_bin * tree);
struct drzewo_bin * szukaj(int e, struct drzewo_bin * t);
struct drzewo_bin * szukaj_brata(int e,struct drzewo_bin * brat);

int main()
{
	int il_awarii,k,k_ty,i,j;
	struct drzewo_bin * drzewo = create();
	drzewo->tresc = "Satelita nie dziala";
	drzewo->i = 0;
	struct drzewo_bin * pomoc;
	int * tab;
	char * awaria;

	cin >> il_awarii;
	for( i = 0 ; i < il_awarii ; i++ )
	{
        awaria = new char(100);
        cin.get();
        cin.getline(awaria,100);
		cin >> k;
		tab = (int*)malloc(k*sizeof(int));
		for( j = 0 ; j < k ; j++ )
		{
			cout << "nr. wezla : ";
			cin >> tab[j];
		}

		cout << "TEST 1" << endl;
		add_new_element(tab,k,awaria,drzewo);
	}

    /*for( i = 0 ; i <= k ; i++ )
    {
        if(i == 0 )
            cout << "komunikat o awari wezel 0 : " << drzewo->tresc << endl;
        else
        {
            pomoc = szukaj(tab[i-1],drzewo);
            if(pomoc != NULL)
                cout << "komunikat o awari wezel " << pomoc->i << " : " << pomoc->tresc << endl;
            else
                cout << "NULL" << endl;
        }
    }*/

    pomoc = szukaj(0,drzewo);
    cout << "komunikat o awari wezel " << drzewo->i << " : " << pomoc->tresc << endl;

    pomoc = szukaj(1,drzewo);
    cout << "komunikat o awari wezel " << pomoc->i << " : " << pomoc->tresc << endl;

    pomoc = szukaj(2,drzewo);
    cout << "komunikat o awari wezel " << pomoc->i << " : " << pomoc->tresc << endl;

    pomoc = szukaj(3,drzewo);
    cout << "komunikat o awari wezel " << pomoc->i << " : " << pomoc->tresc << endl;

    pomoc = szukaj(4,drzewo);
    cout << "komunikat o awari wezel " << pomoc->i << " : " << pomoc->tresc << endl;

    return 0;
}

struct drzewo_bin * create()
{
	struct drzewo_bin * pom = new(struct drzewo_bin);
	pom->l_syn = NULL;
	pom->p_brat = NULL;
	return pom;
};

void add_new_element(int *i,int rozm,char napis[100],struct drzewo_bin * tree)
{
	int j;
	struct drzewo_bin * pom, * pom1 = tree;
	for( j = 0 ; j < rozm ; j++ )
	{
		if(pom1->l_syn == NULL)
		{
			pom = create();
			pom1->l_syn = pom;
			pom->ojciec = pom1;
			pom->i = i[j];
			pom1 = pom;
		}
		else
		{
			if(pom1->l_syn->i != i[j])
            {
                pom = szukaj_brata(i[j],pom1->l_syn);
                pom->p_brat = create();
                pom->p_brat->ojciec = pom1;
                pom->p_brat->i = i[j];
                pom1 = pom->p_brat;
            }
            else
            {
                pom1 = pom1->l_syn;
            }
		}
		if(j == rozm-1)
        {
            pom1->tresc = napis;
        }
	}
}

struct drzewo_bin * szukaj_brata(int e,struct drzewo_bin * brat)
{
    if(brat->p_brat == NULL)
        return brat;
    if(brat->p_brat->i == e)
        return brat;
    else
        return szukaj_brata(e,brat->p_brat);
};

struct drzewo_bin * szukaj(int e, struct drzewo_bin * t)
{
	struct drzewo_bin * pom;
	if (t==NULL)
		return NULL;
	if (t->i==e)
		return t;
	pom = szukaj(e,t->l_syn);
	if(pom!=NULL)
		return pom;
	else
		return szukaj(e,t->p_brat);
};

