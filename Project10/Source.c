#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#define ROW 9
#define COL 9
#include <locale.h>
int main() 
{
    setlocale(LC_ALL, "RUS");
    char symbol;
    int s1, s2, s3;

    printf("Введите символ: ");
    scanf(" %c", &symbol);
    printf("Введите сторону 1: ");
    scanf("%d", &s1);
    printf("Введите сторону 2: ");
    scanf("%d", &s2);
    printf("Введите сторону 3: ");
    scanf("%d", &s3);

    DZ(symbol, s1, s2, s3);
   // Task();
   // Task1();
   // Task1_1();
   // Task3();   
}

int Task() {
    printf("Таблица Пифагора:\n\n");
    printf("    |");
    for (int i = 1; i <= 10; i++) {
        printf("%4d", i);
    }
    printf("\n----+----------------------------------------\n");
    for (int i = 1; i <= 10; i++) {
        printf("%2d  |", i);
        for (int j = 1; j <= 10; j++) {
            printf("%4d", i * j);
        }
        printf("\n");
    }
    return 0;
}
int Task1() {
    int  row, col;
    printf("Левый нижний треугольник таблицы Пифагора:\n\n");
    for (row = 1;row <= ROW;row++) {
        printf("%2d |", row);
        for (col = 1;col <= COL;col++) {
            printf("%4d |", col);
        }
        printf("\n");
    }
    return 0;
}
int Task1_1() {
    int row, col;
    int n = 5;
    printf("Вариант 10:\n\n");
    for (row = 0; row < n; row++) {
        for (col = 0; col <= row; col++) {
            printf("%2d ", row - col);
        }
        printf("\n");
    }

    return 0;
}
int Task3() {
    char num[100];
    char choice;
    do {
        printf("Введите число: ");
        scanf("%s", num);
        int len = strlen(num);
        int c3 = 0, clast = 0, ceven = 0, cgt5 = 0, sodd = 0, sge7 = 0, pn0 = 0, s2ndlast = 0;
        int sadj = 0, s1 = 0, s2 = 0, spos[2] = { 0 };
        int last = num[len - 1] - '0';
        int d[100];
        for (int i = 0;i < len;i++) {
            d[i] = num[i] - '0';
            if (d[i] == 3)c3++;
            if (d[i] == last)clast++;
            if (d[i] % 2 == 0)ceven++;
            if (d[i] > 5)cgt5++;
            if (d[i] % 2)sodd += d[i];
            if (d[i] >= 7) sge7 += d[i];
            if (d[i] != 0) pn0 *= d[i];
            if (i < len - 1 && d[i] % 2 == 0) s2ndlast += d[i];
            if (i < len - 1 && d[i] == d[i + 1]) sadj = 1;
            if (i < len / 2) s1 += d[i];
            if (i >= len - len / 2) s2 += d[i];
            spos[(len - i) % 2] += d[i];
        }
        printf("\n1) Цифр 3: %d\n", c3);
        printf("2) Последняя цифра %d повторяется: %d раз\n", last, clast);
        printf("3) Четных цифр: %d\n", ceven);
        printf("4) Цифр > 5: %d\n", cgt5);
        printf("5) Сумма нечетных: %d\n", sodd);
        printf("6) Сумма >= 7: %d\n", sge7);
        printf("7) Произведение (без 0): %d\n", pn0);
        printf("8) 2-я * предпоследняя: %d\n", len >= 2 ? d[1] * d[len - 2] : 0);
        printf("9) Сумма четных (без посл): %d\n", s2ndlast);
        printf("10) Есть одинаковые рядом: %s\n", sadj ? "да" : "нет");
        printf("11) Суммы половин: %d и %d - %s\n", s1, s2, s1 == s2 ? "равны" : "не равны");
        printf("12) Произведение сумм четных(%d) и нечетных(%d) разрядов: %d\n", spos[0], spos[1], spos[0] * spos[1]);

        printf("\nПродолжить? (y/n): ");
        while (getchar() != '\n');
        choice = getchar();
    } while (choice == 'y' || choice == 'Y');

    return 0;
}

int DZ(char symbol, int s1, int s2, int s3) {
    int width = s1 + s3 - s2;
    int height = s1 + s3 - s2;

    printf("\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int in1 = (i < s1&& j < s1);
            int in2 = (i >= s2 && i < s2 + s3 && j >= s2 && j < s2 + s3);
            int inWhite = (i >= s1 - s2 && i < s1&& j >= s1 - s2 && j < s1);

            if (inWhite) {
                printf("  ");
            }
            else if (in1 || in2) {
                printf("%c ", symbol);
            }
            else {
                printf("  ");
            }
        }
        printf("\n");
    }
    return 0;
}

