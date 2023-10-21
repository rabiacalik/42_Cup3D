
#include <stdio.h>
#include <math.h>

/*
    ORNEK

    (x, y) konumumuz (3, 2) olsun
    ve bu acinin yonunu, saat yonunun tersine 30 derece
    dondurmek isteyelim. bu hesaplamayı radyan cinsinden hesaplamamiz gerekli

    30 derece = pi / 6 radyana esittir

    ---------------------------------------------------

    bir matrisi dondurmemiz icin onu "donusum matrisiyle carpmamız gerek"

    donusum matrisi =
    [ cos(a)  -  sin[a] ]    --->   x ekseni etrafinda donusu temsil eder
    [ sin(a)  +  cos(a) ]    --->   y ekseni etrafinda donusu temsil eder
*/

int main()
{
    double angle = 30.0; //acımız (derece cinsinden)
    double PI =  3.14; // pi sayisi
    double radian = angle * PI / 180.0;

    //baslangic vektoru
    double x = 3.0;
    double y = 2.0;

    // donusum matrisi
    double cos_a = cos(radian); // cos(a) = cos(pi/6) = cos(30)
    double sin_a = sin(radian);

    // vektoru dondurme islemi
    double x_prime = (x * cos_a) - (y * sin_a);
    double y_prime = (x * sin_a) + (y * cos_a);

    printf("baslangic vektoru  = (%.2f, %.2f)\n", x, y);
    printf("dondurulmus vektor = (%.2f, %.2f)\n", x_prime, y_prime); 
}