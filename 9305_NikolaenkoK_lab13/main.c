#include <stdio.h>
#include <stdlib.h>

struct MacAdress
{
    unsigned char byte1 : 8,
                  byte2 : 8,
                  byte3 : 8,
                  byte4 : 8,
                  byte5 : 8,
                  byte6 : 8;
}MacA;


int main()
{
    struct MacAdress kod;
    int x1,x2,x3,x4,x5,x6;

    /*examples of manufacturer codes*/
    printf("company_id |         Organization        |\n");
    printf("  6A.9D.A4 |      Global Reach Technology|\n");
    printf("  3A.78.CA |               SoundTalks NV |\n");
    printf("  3A.F5.21 |                BSG Wireless |\n");
    printf("  4A.C0.3F | WUHAN HIKSTORAGE TECHNOLOGY |\n");
    printf("  DA.A1.19 |                      Google |\n");

    /*entering the first MAC address*/
    printf("\nEnter Mac adress:\n");
    scanf("%X.%X.%X.%X.%X.%X", &x1, &x2, &x3, &x4, &x5, &x6);
    kod.byte1 = x1;
    kod.byte2 = x2;
    kod.byte3 = x3;
    kod.byte4 = x4;
    kod.byte5 = x5;
    kod.byte6 = x6;
    printf("\nEnter Mac address:\n%X.%X.%X.%X.%X.%X\n", kod.byte1, kod.byte2, kod.byte3, kod.byte4, kod.byte5, kod.byte6);

    /*convert the manufacturer's code*/
    kod.byte1 &= 'AF';
    kod.byte2 |= '3A';
    kod.byte3 ^= 'DC';
    printf("\nChanged Mac address:\n%X.%X.%X.%X.%X.%X\n", kod.byte1, kod.byte2, kod.byte3, kod.byte4, kod.byte5, kod.byte6);

    return 0;
}
