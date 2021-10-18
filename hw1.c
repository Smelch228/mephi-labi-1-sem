#include <stdio.h>  //Перевернуть строку

int len(char s[]) {
    int i = 0;
    while (s[i] != '\0') {
        ++i;
    }
    return i;
}

void reverse(char s[]) {
    int length = len(s);
    char temp;
    int j = length - 1;
    for(int i = 0; i < j; i++, j--) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

int main() {
    char s1[100];
    scanf("%[^\n]s", s1);
    reverse(s1);
    printf("%s", s1);
    
    return 0;
}
