#include <stdio.h>
#include <locale.h>
#include <math.h>
#define M_PI 3.14159265358979323846

double f1(double x) {
    if (x <= 3) 
    {
        return x * x - 3 * x + 9;
    }
    else 
    {
        return 1.0 / (x * x * x + 3);
    }
}
double f2(double x) 
{
    return x * exp(sin(x * x));
}
void task1()
{
    double x;
    int choice;
    char repeat;

    do {
        printf("Задание 1: Вычисления для двух функций\n\n");
        printf("Введите значение x: ");
        scanf("%lf", &x);
        printf("----------------------------------------\n");
        double fa = f1(x);
        double fb = f2(x);

        printf("\n");
        printf("f1(x)=%lf , f2(x)=%lf\n\n", f1(x), f2(x));
        printf("----------------------------------------\n");

        printf("Дополнительные расчеты для введенного x:\n");
        printf("Произведение: %lf\n", f1(x) * f2(x));
        printf("Разность квадратов: %lf\n", (f1(x) * f1(x)) - (f2(x) * f2(x)));
        printf("Удвоенная сумма: %lf\n\n", 2 * (f1(x) + f2(x)));
        printf("----------------------------------------\n");

        printf("___МЕНЮ ВЫБОРА___\n");
        printf("1. Вычислить значение первой функции f1(x)\n");
        printf("2. Вычислить значение второй функции f2(x)\n");
        printf("3. Вычислить произведение\n");
        printf("4. Вычислить разность квадратов\n");
        printf("5. Вычислить удвоенную сумму\n");
        printf("Выберите пункт меню (1-5): ");

        scanf("%d", &choice);
        printf("\nРезультат выбора\n");
        switch (choice)
        {
        case 1:
            printf("f1(x) = %lf\n", fa);
            break;
        case 2:
            printf("f2(x) = %lf\n", fb);
            break;
        case 3:
            printf("Произведение = %lf\n", fa * fb);
            break;
        case 4:
            printf("Разность квадратов = %lf\n", (fa * fa) - (fb * fb));
            break;
        case 5:
            printf("Удвоенная сумма = %lf\n", 2 * (fa + fb));
            break;
        default:
            printf("Неверный выбор пункта меню!\n");
            break;
        }

        printf("\nПродолжить работу? (y - да, n - нет): ");
        scanf(" %c", &repeat);
        printf("\n----------------------------------------\n\n");

    } while (repeat == 'y' || repeat == 'Y');
}

double sin_n(double x, int N) 
{
    double sum = 0.0;
    double term = x;

    for (int k = 1; k <= N; k++) 
    {
        if (k > 1) 
        {
            int idx = 2 * k - 1;
            term = -term * x * x / ((idx - 1) * idx);
        }
        sum += term;
    }
    return sum;
}
double sin_eps(double x, double eps) 
{
    double sum = 0.0;
    double term = x;
    int k = 1;

    while (fabs(term) > eps && k < 1000) 
    {
        sum += term;
        k++;
        int idx = 2 * k - 1;
        term = -term * x * x / ((idx - 1) * idx);
    }
    return sum;
}
void task2()
{
    double x;
    double eps;
    int maxN;

    printf("Задание 2: Вычисление sin(x) тремя способами\n\n");

    printf("Введите значение x (в радианах, например, 0.7854): ");
    scanf("%lf", &x);

    printf("Введите максимальное N для таблицы (например, 20): ");
    scanf("%d", &maxN);

    printf("Введите точность eps (например, 0.000001): ");
    scanf("%lf", &eps);

    double res_lib = sin(x);
    double res_eps = sin_eps(x, eps);

    printf("\n___Сравнение основных результатов___\n");
    printf("Стандартная библиотека sin(x) : %.10f\n", res_lib);
    printf("Через точность eps (%g)       : %.10f (отклонение: %.10e)\n\n", eps, res_eps, fabs(res_lib - res_eps));
    printf("Таблица сходимости (число членов ряда N):\n\n");
    printf(" N |    sin_N    |   отклонение\n");

    for (int n = 1; n <= maxN; n++)
    {
        double val = sin_n(x, n);
        double deviation = res_lib - val;

        printf("%2d | %11.4f | %+11.4e\n", n, val, deviation);
    }
    printf("\n----------------------------------------\n\n");
}

void task3()
{
    char sym;
    int a, b, h, choice;

    printf("Задание 3\n\n");

    printf("Введите символ для построения фигуры: ");
    scanf(" %c", &sym);

    printf("Введите высоту: ");
    scanf("%d", &h);

    printf("Введите верхнее основание: ");
    scanf("%d", &a);

    do {
        printf("\n_________МЕНЮ ВЫБОРА_________\n");
        printf("1) Рассчитать площадь\n");
        printf("2) Вывести определение фигуры\n");
        printf("3) Нарисовать фигуру\n");
        printf("4) Выход\n");
        printf("Выберите операцию (1-4): ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            b = 2 * a;
            int s = (a + b) / 2 * h;
            printf("\nПлощадь трапеции равна: S = (a+b) / 2 * h = %d\n", s);
            break;

        case 2:
            printf("Трапеция — это четырёхугольник, у которого две стороны параллельны, а две другие не параллельны.\nПараллельные стороны называют основаниями, а непараллельные — боковыми сторонами.\n");
            break;

        case 3:
            printf("\n");
            for (int i = 0; i < h; i++)
            {
                // Вывод отступа слева
                for (int s = 0; s < h - 1 - i; s++)
                {
                    printf(" ");
                }

                // Общая ширина текущей строки
                int width = a + 2 * i;

                for (int j = 0; j < width; j++)
                {
                    if (i == 0 || i == h - 1 || j == 0 || j == width - 1)
                    {
                        printf("%c", sym);
                    }
                    else
                    {
                        printf(" ");
                    }
                }
                printf("\n");
            }
            break;

        case 4:
            printf("\nЗавершение работы программы.\n");
            break;
        }

    } while (choice != 4);
}

void main() 
{
    setlocale(LC_ALL, "ru_RU.UTF-8");

    task1();
    task2();
    task3();

}