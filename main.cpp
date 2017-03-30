#include <iostream>
#include <malloc.h>


using namespace std;


int main()
{
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	char *liczba = (char*) malloc(sizeof(char)*(n));
	cin >> liczba;
	//POROWNANIE
	int liczba1=0,przejscie=0,i,j;
	for(j=1;j<=n;j++)
	{
		for(i=1;i<=j;i++)
		{
			liczba1+=((liczba[n+i-j-1]-48)*(liczba[n-i]-48));
		}//Petla for odpowiadajoca za mnozenie "kolumnami"
		if((j==1)&&((liczba1-10*(liczba1/10)!=5)&&(liczba1-10*(liczba1/10)!=6))) {cout << 1; return 0;}
		if(((liczba1+przejscie)-10*((liczba1+przejscie)/10))!=(liczba[n-j])-48) {cout << j ; return 0;}
		liczba1+=przejscie;
		przejscie=liczba1/10;
		liczba1=0;
	}//Petla for ktora chodzi po elementach tablicy
	cout << "OK";
	return 0;
}
