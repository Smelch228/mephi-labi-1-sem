#include <stdio.h>
#include "my_string.h"

int main() {
    char s[100];
    char temp[20];
    char new[100];
    char charToRemove;
    scanf("%[^\n]s", s);
    char* token = my_strtok(s, " \t");
    my_strcpy(temp, token);
    charToRemove = temp[len(temp) - 1];
    removeChar(temp, charToRemove);
    my_strcpy(new, temp);
    my_strcat(new, " ");

    while(token != NULL) {
        token = my_strtok(NULL, " \t");
        if (token == NULL) {
            break;
        }
        my_strcpy(temp, token);
        charToRemove = temp[len(temp) - 1];
        removeChar(temp, charToRemove);
        my_strcat(new, temp);
        my_strcat(new, " ");
    }

    printf("New string: %s\n", new);
    return 0;
}
