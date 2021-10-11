#include <stdio.h>

int getCountOfDigits(int num) {
    int count = (num == 0) ? 1 : 0;
    while (num != 0) {
        count++;
        num /= 10;
    }
    return count;
}

void solve(int num, int count) {
    if(num < 0) {
        printf("-");
        num = -num;
    }
    int pow = 1;
    for(int i = 1; i < count; i++) {
        pow *= 10;
    }

    for (int i = 0; i < count; i++) {
        int temp = num / pow;
        if (temp == 0) {
            printf("1");
        } else {
            printf("%d", temp);
        }
        num %= pow;
        pow /= 10;
    }
}

int main() {
    printf("Input your number:\n");
    int num;
    scanf("%d", &num);
    if (num == 0) {
        printf("1");
        return 0;
    }
    switch (getCountOfDigits(num)) {
        case 1:
            printf("%d", num);
            break;
        default:
            solve(num, getCountOfDigits(num));
            break;
    }
    return 0;
}
