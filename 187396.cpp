// 187396.cpp: определяет точку входа для приложения.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void menu(void); // menu

int radky(); // dostavame cislo radku

float sloupci(); // dostavame cislo sloupcu

float* matice(int x, int y); // dostavame matice

void maticeVzor(float* pt, int x, int y); // ukazka matice

float* soucet(float* m1, float* m2, int x, int y); //scitani, vytvori novou matici a vraci ukazatel na ni

float* odecet(float* m1, float* m2, int x, int y); // odecitani, podobne jak scitani

void transponace(float* m, int x, int y); // transponovani




int main()
{
    

    int choice;
    menu();
    while (choice = radky())
    {
        switch (choice)
        {
        case 1:
        {
            printf("scitani\n");
            printf("velikost:\nradku: ");
            int x, y;
            x = radky();
            printf("sloupcu: ");
            y = radky();
            if (x <= 5, y <= 5)
            {
                // naplnujeme macici 
                printf("\nmatice 1\n");
                float* pm1 = matice(x, y);
                printf("\nmatice2\n");
                float* pm2 = matice(x, y);

                //ukazka matic
                printf("\nmatice 1\n");
                maticeVzor(pm1, x, y);
                printf("\nmatice 2\n");
                maticeVzor(pm2, x, y);

                // volani funkce souctu a ukazka vysledku
                float* sum_m = soucet(pm1, pm2, x, y);
                printf("\nvysledek:\n");
                maticeVzor(sum_m, x, y);
            }
            else
            {
                printf("max 5, opakujte:\n");
                while (getchar() != '\n')
                    continue;

            }
            break;
        }
        case 2:
        {
            printf("\nodecitani\n");
            printf("velikost matice:\nradky: ");
            int x, y;
            x = radky();
            printf("sloupcy: ");
            y = radky();
            if (x <= 5, y <= 5)
            {
                // napnujeme macici 
                printf("\nmatice1\n");
                float* pm1 = matice(x, y);
                printf("\nmatice2\n");
                float* pm2 = matice(x, y);

                //ukazka matic
                printf("\nmatice1\n");
                maticeVzor(pm1, x, y);
                printf("\nmatice2\n");
                maticeVzor(pm2, x, y);

                // volani funkce odecitani a ukazka vysledku
                float* div_m = odecet(pm1, pm2, x, y);
                printf("\nvysledek\n");
                maticeVzor(div_m, x, y);
            }
            else
            {
                printf("max 5, opakujte:\n");
                while (getchar() != '\n')
                   continue;
            }
            break;
        }
        case 3:
        {
            printf("\ntransponace\n");
            printf("velikost matice:\nradky: ");
            int x, y;
            x = radky();
            printf("sloupci: ");
            y = radky();
            if (x <= 5, y <= 5)
            {
                // napnujeme macici
                printf("\nmatice:\n");
                float* pm = matice(x, y);
                maticeVzor(pm, x, y);

                // volani funkce transponovani a ukazka vysledku
                transponace(pm, x, y);
                printf("\nvysledek\n");
                maticeVzor(pm, x, y);
            }
            else
            {
                printf("max 5, opakujte:\n");
                while (getchar() != '\n')
                    continue;
            }
            break;
        }
        default: printf("spatna volba\n");
        }
        menu();
    }
    return 0;
}
// menu
void menu(void)
{
    printf("zvolte operace:\n");
    printf("1) scitani\n2) odecitani\n3) transponovani\n");
}
// dostavame cislo radku
int radky()
{
    int n;
    while (scanf("%d", &n) != 1)
    {
        printf("plati jen cisla, opakujte:\n");
        while (getchar() != '\n')
        continue;
    }
    return n;
}

float sloupci() // dostavame sloupcy
{
    float n;
    while (scanf("%f", &n) != 1)
    {
        printf("plati jen cisla, opakujte:\n");
        while (getchar() != '\n')
        continue;
    }
    return n;
}

float* matice(int x, int y) // dostavame matice
{
    float* pd;
    pd = (float*)malloc(x * y * sizeof(float));
    printf("zadejte cisla matice\n");

    for (int i = 0; i < x; i++)
    {
        printf("radek%d:\n", i + 1);
        for (int k = 0; k < y; k++)
        {
            printf("#%d: ", k + 1);
            *(pd + i * y + k) = sloupci();//omezujeme zadavan9 cisel v radek podle poctu sloupcu
        }
    }
    return pd;
}
// ukazka matic
void maticeVzor(float* pt, int x, int y)
{
    FILE *M = fopen("matice.txt", "a");
    for (int i = 0; i < x; i++)
    {
        for (int k = 0; k < y; k++)
            fprintf(M, "%.2f\t", *(pt + i * y + k));
            fclose(M);
        for (int k = 0; k < y; k++)
            printf("%.2f\t", *(pt + i * y + k));
            printf("\n");
           
       
    }
}
// scitani
float* soucet(float* m1, float* m2, int x, int y)
{
    float* sum = (float*)malloc(x * y * sizeof(float));

    for (int i = 0; i < x; i++)
        for (int k = 0; k < y; k++)
        *(sum + i * y + k) = *(m1 + i * y + k) + *(m2 + i * y + k);
        return sum;
}
// odecitani
float* odecet(float* m1, float* m2, int x, int y)
{
    float* sum = (float*)malloc(x * y * sizeof(float));

    for (int i = 0; i < x; i++)
    for (int k = 0; k < y; k++)
        *(sum + i * y + k) = *(m1 + i * y + k) - *(m2 + i * y + k);
        return sum;
}
// transponace
void transponace(float* m, int x, int y)
{
    for (int i = 0; i < x; i++)
    for (int k = i; k < (y > x ? x : y); k++)
     {
         float temp;
         temp = *(m + i * y + k);
         *(m + i * y + k) = *(m + k * y + i);
         *(m + k * y + i) = temp;
     }
}

