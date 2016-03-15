#include <cstdio>
#include <ctime>

void czekaj( int iMilisekundy )
{
    clock_t koniec = clock() + iMilisekundy * CLOCKS_PER_SEC / 1000.0;
    while( clock() < koniec ) continue;
   
}

double obliczSekundy( clock_t czas )
{
    return static_cast < double >( czas ) / CLOCKS_PER_SEC;
}

int main()
{
    printf( "Uruchomilem aplikacje. Uplynelo %.4fsek od jej startu.\n", obliczSekundy( clock() ) );
    czekaj( 250 );
    printf( "Uplynelo %.4fsek od startu aplikacji.\n", obliczSekundy( clock() ) );
    czekaj( 150 );
    printf( "Uplynelo %.4fsek od startu aplikacji.\n", obliczSekundy( clock() ) );
    return 0;
}
