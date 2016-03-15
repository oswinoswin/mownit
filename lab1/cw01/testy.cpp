#include <cstdio>
#include <vector>
#include<iostream>
using namespace std;

vector<double> wczytaj_wektor(int n){
		vector<double> v;
		v.reserve(n);
		double tmp;
		for(int i=0; i<n; i++){
			cin>>tmp;
			v.push_back(tmp);
		}
		return v;
}

double licz(int i, int j){
	double a;
	if( i == 1 ) a = 1;
	else 
		a = 1.0/(i + j - 1.0);
	return a;
}

vector<double> wylicz_A( int n ){
	vector<double> A;
	A.reserve( n );
	for(int i=1; i<n; i++){
		for(int j=1; j<n; j++){
			cout<<licz(i,j)<<" ";
		} 
		cout<<endl;
	}
	return A;
}

void wypisz_wektor( vector<double> v){
	 for( size_t i = 1; i < v.size(); i++ )
         cout<<v[ i ]<<" ";
}

void wypisz_macierz(vector<double> v, int n){ //macierz kwadratowa o wymiarze n
	for(int i=1; i<n; i++){
		for(int j=1; j<n; j++){
			cout<< v[ i ]<<" ";
		}
		cout<<endl;
	}
}


int main()
{
    int n;
    cin >> n;
    vector<double> A = wylicz_A(n);
    cout<< A [ 3 ]<<" ";
    cout<<licz(2,1);
    wypisz_wektor(A);
    return 0;
}

