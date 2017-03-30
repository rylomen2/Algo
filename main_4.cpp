#include <iostream>
#include <malloc.h>
#include <stdio.h>
#include <string>

using namespace std;


struct List * create(int n);
void BubbleSort(struct List * lista);

struct List
{
	int * time[2];
	int n,roz_tab;
};

int main()
{
	//ZMIENNE
	int i,j,dni,prelekcje,rg,rm,zg,zm,akt_godz = 0;
	char smiec[100];
	scanf("%d",&dni);
	scanf("%d",&prelekcje);
	struct List * lista;
	for( j = 0 ; j < dni ; j++ )
	{
		if(j != 0)
		{
			scanf("%d",&prelekcje);
		}
		if(prelekcje!=0)
		{
			lista = create(prelekcje);
			for( i = 0 ; i < prelekcje ; i++ ) //POBIERANIE DANYCH
			{
				scanf("%d:%d-%d:%d",&rg,&rm,&zg,&zm);
				gets(smiec);
					lista->time[0][i] = (rg*2)+(rm/30);
					lista->time[1][i] = (zg*2)+(zm/30);
					lista->n++;
			}

			BubbleSort(lista);//SORTOWANIE

			//ZLICZANIE PRELEKCJI
			for( i = 0 ; i < lista->roz_tab ; i++ )
			{
				if(lista->time[0][i] == lista->time[1][i])
				{
					prelekcje--;
				}
				else
				{
					if(akt_godz >= lista->time[1][i])
						prelekcje--;
					if(i == 0)
						akt_godz = lista->time[0][i]+1;
					else
					{
						if(lista->time[0][i] == lista->time[0][i-1])
						{
							akt_godz++;
						}
						else
						{
							if(lista->time[0][i] > lista->time[0][i-1])	akt_godz = lista->time[0][i]+1;
						}
					}
				}
			}
		}
		printf("%d\n",prelekcje);
		akt_godz = 0;
	}
	if( dni == 0) printf("0\n");
    return 0;
}


struct List * create(int n)
{
	struct List * pom = (struct List *)malloc(sizeof(struct List));
	for(int i = 0 ; i < 2 ; i++ )
		pom->time[i] = (int*)malloc(n*sizeof(int));
	pom->n = 0;
	pom->roz_tab = n;
	return pom;
};


void BubbleSort(struct List * lista)
{
	int i,j,pom;
	for( i = lista->roz_tab-1 ; i > 0 ; i-- )
	{
		for( j = 0 ; j < i ; j++ )
		{
			if(lista->time[0][j] > lista->time[0][j+1])
			{
				//ZAMIANA GODZIN ROZPOCZECIA
				pom = lista->time[0][j];
				lista->time[0][j] = lista->time[0][j+1];
				lista->time[0][j+1] = pom;
				//ZAMIANA GODZIN ZAKONCZENIA
				pom = lista->time[1][j];
				lista->time[1][j] = lista->time[1][j+1];
				lista->time[1][j+1] = pom;
			}
			else
			{
				if(lista->time[0][j] == lista->time[0][j+1])
				{
					if(lista->time[1][j] > lista->time[1][j+1])
					{
						//ZAMIANA GODZIN ZAKONCZENIA
						pom = lista->time[1][j];
						lista->time[1][j] = lista->time[1][j+1];
						lista->time[1][j+1] = pom;
					}
				}
			}
		}
	}
}

