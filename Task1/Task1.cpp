#include <iostream>
#include <stdio.h>

int Result(float x, float y, float x1, float x2, int factorial)
{
    if (x1 != 0 && x2 != 0)
    {
        printf("\nРезультат решения: x1 = %.2f, x2 = %.2f\n", x1, x2);
    }
    else if (x != 0 && y != 0)
    {
        printf("\nРезультат решения: x = %.2f, y = %.2f\n", x, y);
    }
    else if (factorial != 0) 
    {
        printf("\nРезультат решения: factorial = %d\n", factorial);
    }
    else if (x == 0 && y == 0 && x1 == 0 && x2 == 0 && factorial == 0) 
    {
        printf("\nРезультат решения:  %.2f\n", x1);
    }
    return 0;
}

float TheQuadraticEquation(float a, float b, float c)
{
    printf("Квадратное уравнение (%.2f) * x^2 + (%.2f) * x + (%.2f) = 0", a, b, c);
    float D;
    float x1;
    float x2;
    D = pow(b,2) - 4 * a * c;
    if (D > 0 || D == 0)
    {
        x1 = (-b + sqrt(abs(D))) / (2 * a);
        x2 = (-b - sqrt(abs(D))) / (2 * a);
       Result(0, 0, x1, x2, 0);
    }
    else
    {
       Result(0, 0, 0, 0, 0);
    }
    return 0;
}

float SystemOfTwoLinearEquations(float a1, float b1, float c1, float a2, float b2, float c2) 
{
    float Determinant = a1 * b2 - b1 * a2;
    if (Determinant != 0) 
    {
        float x = (c1 * b2 - b1 * c2) / Determinant;
        float y = (a1 * c2 - c1 * a2) / Determinant;
        Result(x, y, 0, 0, 0);
    }
    else 
    {
        Result(0, 0, 0, 0, 0);
    }
    return 0;
}

int Factorial(int fact) 
{
    int res = 1, i;
    for (i = 2; i <= fact; i++)
        res *= i;
    Result(0, 0, 0, 0, res);
    return 0;
}

void Start() 
{
    bool retry = true;
    while (retry)
    {
        printf("Выберите задачу, которую хотите решить: \n1 - Квадратное уравнение \n2 - Система двух линейных уравнений \n3 - Перестановки (Факториал)\n");
        int number;
        scanf_s("%d", &number);
        if (number == 1)
        {
            bool flag = true;
            printf("Введите коэффициенты a, b и c квадратного уравнения: \n");
            float a;
            float b;
            float c;
            while (flag == true)
            {
                scanf_s("%f", &a);
                if (a == 0)
                {
                    printf("Уравнение не является квадратным, повторите ввод\n");
                }
                else
                {
                    flag = false;
                }
            }
            scanf_s("%f", &b);
            scanf_s("%f", &c);
            TheQuadraticEquation(a, b, c);
            retry = false;
        }
        else if (number == 2)
        {
            float a1;
            float b1;
            float c1;
            float a2;
            float b2;
            float c2;
            printf("Введите коэффициенты 1-го уравнения: \n");
            printf("Введите a1: \n");
            scanf_s("%f", &a1);
            printf("Введите b1: \n");
            scanf_s("%f", &b1);
            printf("Введите c1: \n");
            scanf_s("%f", &c1);
            printf("Введите коэффициенты 2-го уравнения: \n");
            printf("Введите a2: \n");
            scanf_s("%f", &a2);
            printf("Введите b2: \n");
            scanf_s("%f", &b2);
            printf("Введите c2: \n");
            scanf_s("%f", &c2);
            SystemOfTwoLinearEquations(a1, b1, c1, a2, b2, c2);
            retry = false;
        }
        else if (number == 3) 
        {
            int fact;
            printf("Введите факториал\n");
            scanf_s("%d", &fact);
            Factorial(fact);
            retry = false;
        }
        else
        {
            printf("Такой задачи не существует, повторите ввод");
        }
    }
}

int main()
{
    Start();
}
