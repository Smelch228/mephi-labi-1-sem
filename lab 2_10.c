#include <stdio.h>
#include <math.h>

int fact (int num) {    //Функция вычисления факториала
    int res = 1;
    for(int i = 1; i <= num; i++) {
        res = res * i;
    }
    return res;
}

float solve(float x, int a, float eps) {
    float sum, current, prev, temp;
    int i = 1;  //Для (a - i)
    int f = 2;  //Для знаменателя
    float start = 1 + a * x;
    float second = (a * (a - 1) * x * x) / 2;
    sum = start + second;
    temp = a * (a - 1) * x * x;  //Временная переменная для числителя, чтобы каждый раз не вычислять всё
    current = second;
        do {
            i++;
            f++;
            temp = temp * (a - i) * x;
            prev = current;
            current = temp / fact(f);
            sum += current;
        } while(fabsf(current - prev) > eps);
    return (sum);
    }

int main() {
    float x, eps;
    int a;
    printf("Input x:\n");
    scanf("%f", &x);
    printf("Input a:\n");
    scanf("%d", &a);
    printf("Input eps:\n");
    scanf("%f", &eps);

    printf("Result of sum:  %f", solve(x, a, eps));


    return 0;
}
