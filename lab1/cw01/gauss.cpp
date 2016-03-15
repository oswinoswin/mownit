//Maria Uchwat
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<iostream>
using namespace std;
 
#define mat_elem(a, y, x, n) (a + ((y) * (n) + (x)))

double licz(int i, int j){
	if( i == 0 ) return 1.0; //indeksowanie od 0
	else return 1.0/(i + j + 1);
}
 
void swap_row(double *a, double *b, int r1, int r2, int n)
{
	double tmp, *p1, *p2;
	int i;
 
	if (r1 == r2) return;
	for (i = 0; i < n; i++) {
		p1 = mat_elem(a, r1, i, n);
		p2 = mat_elem(a, r2, i, n);
		tmp = *p1, *p1 = *p2, *p2 = tmp;
	}
	tmp = b[r1], b[r1] = b[r2], b[r2] = tmp;
}
 
void gauss_eliminate(double *a, double *b, double *x, int n)
{
#define A(y, x) (*mat_elem(a, y, x, n))
	int j, col, row, max_row,dia;
	double max, tmp;
 
	for (dia = 0; dia < n; dia++) {
		max_row = dia, max = A(dia, dia);
 
		for (row = dia + 1; row < n; row++)
			if ((tmp = fabs(A(row, dia))) > max)
				max_row = row, max = tmp;
 
		swap_row(a, b, dia, max_row, n);
 
		for (row = dia + 1; row < n; row++) {
			tmp = A(row, dia) / A(dia, dia);
			for (col = dia+1; col < n; col++)
				A(row, col) -= tmp * A(dia, col);
			A(row, dia) = 0;
			b[row] -= tmp * b[dia];
		}
	}
	for (row = n - 1; row >= 0; row--) {
		tmp = b[row];
		for (j = n - 1; j > row; j--)
			tmp -= x[j] * A(row, j);
		x[row] = tmp / A(row, row);
	}
#undef A
}

void licz_b(double *a, double *b, double *x, int n){
	for(int j=0; j<n; j++){
		b[j] = 0 ;
		for(int i=0; i<n; i++){
			b[j] += a[i + j*n] *x[i];
		} 
	}
}

void wypisz_wektor(double *w, int n){
	for(int i=0; i<n; i++)
		printf("%.6f ",w[i]);
	cout<<endl;
}

void wypisz_macierz(double *a, int n){


	for(int i=0; i<n; i++){
		for(int j=0; j < n; j++){
			printf("%.6f ",a[n*i + j]);
		}
		printf("\n");
	}
}

void norma(double *x, double *b, int n){
	//max z wart bezwzględnej różnicy
	//albo suma kwa
	cout<<"odległość wektorow:"<<endl;
	double max, tmp;
	max = tmp = 0;
	for( int i=0; i<n; i++){
		tmp = fabs(x[i] - b[i]);
		if(tmp> max ) max = tmp;
	}
	cout<<max<<endl;
}

 
int main(void)
{
	int n = 9;
	//cin>>n;
	printf("Rozmiar układu: %d, precyzja obliczen: double\n",n);
	//wyliczanie macierzy A
	double a[n*n];
	for(int j=0; j<n; j++){
		for(int i=0; i < n; i++){
			a[j*n + i] = licz(i,j);
			}
	}
	printf("Macierz A:\n");
	wypisz_macierz(a,n);
	double x[] = {-1, 1, 1, 1, -1, 1, 1, -1, 1, -1, 1, -1, 1, -1, 1};
	printf("Ustalone x:\n");
	wypisz_wektor(x,n);
	double b[n];
	double x1[n];
	licz_b(a,b,x,n);
	printf("Wyliczone b:\n");
	wypisz_wektor(b,n);

	gauss_eliminate(a, b, x1, n);
	printf("Rozwiazanie wyznaczone metoda Gaussa:\n");
	wypisz_wektor(x1,n);
	norma(x1,x,n);
 
	return 0;
}
