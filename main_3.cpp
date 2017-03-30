#include <iostream>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

void depression(int tab[][2],int n,int position,int solei,int *prix,int record);

using namespace std;

int main()
{
	int n,m,i,j;
	int koszt = 100000000;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		cin >> m ;
		int tablica[m][2];
		for(j=0;j<m;j++)
		{
			scanf("%d%d",&tablica[j][0],&tablica[j][1]);
		}
	depression(tablica,m,0,0,&koszt,0);
	if(koszt==100000000)
		cout << "DEPRESJA" << endl;
	else
		cout << koszt << endl;
	koszt = 100000000;
	}
	return 0;
}


void depression(int tab[][2],int n,int position,int solei,int *prix,int record)
{
	if(solei == 0 && *prix > record && record > 0)
	{
			(*prix) = record;
			return;
	}
	if(position!=n && record <=*prix)
	{
		depression(tab,n,position+1,solei,prix,record);
		depression(tab,n,position+1,solei+tab[position][0],prix,record+tab[position][1]);
		return;
	}
	else
		return;
}//depresja
