#include<iostream>
#include<cstdlib>
using namespace std;

double licz(int i, int j){
	return j+i;
}

class vect{
    int *tablica, top;

    
    public: vect(int n){
        tablica = new int[n];
        top = 0;
        cout<<"utworzono kolejkę o rozmiarze 100"<<endl;
    }

    public: void put(int t){
        tablica[top] = t;
        top++;
    }

    public: int get(){
        return tablica[top--];
    }
    public: void print(){
    for( int i=0; i<top; i++) cout << tablica[i] <<" ";
    cout<<endl;

    }
};

class macierz{
	public: double **wiersze, *kolumny;
	public: int m,n;
	
	public: macierz(int m, int n){
			this->m=m;
			this->n=n;
			wiersze = new double*[m];
			for (int i = 0;  i<m; i++){
				kolumny = new double[n];
				wiersze[i] = kolumny;
			}
			for(int i=0; i<m; i++){
				for(int j=0; j<n; j++){
					wiersze[i][j] = licz(i,j);
					cout<<wiersze[i][j]<<" ";
				}
				cout<<endl;
			}
	}
	
	public: void wypisz(){
		cout<<"wypisz macierz"<<endl;
		for(int i=0; i<m; i++){
			for(int j=0; j<n; j++){		
				cout<<this->wiersze[i][j]<<" ";
			}
			cout<<endl;
		}
	}		
};



int main(){
	macierz a(3,3);
	a.wypisz();

     return 0;
}

