#include <stdio.h>
#include <string.h>

int len(char s[]) {
    int i = 0;
    while (s[i] != '\0') {
        ++i;
    }
    return i;
}

void removeChar(char * str, char charToRemove){
    int i, j;
    int length = len(str);
    for(i = 0; i < length; i++) {
        if(str[i] == charToRemove) {
            for(j = i; j < length; j++) {
                str[j] = str[j+1];
            }
            length--;
            i--;
        }
    }
}

int main() {
    char s[100];
    char temp[20];
    char new[100];
    char charToRemove;
    scanf("%[^\n]s", s);
    char* token = strtok(s, " ");
    strcpy(temp, token);
    charToRemove = temp[len(temp) - 1];
    removeChar(temp, charToRemove);
    strcpy(new, temp);
    strcat(new, " ");

    while(token != NULL) {
        token = strtok(NULL, " ");
        if (token == NULL) {
            break;
        }
        strcpy(temp, token);
        charToRemove = temp[len(temp) - 1];
        removeChar(temp, charToRemove);
        strcat(new, temp);
        strcat(new, " ");
    }

    printf("New string: %s\n", new);
    return 0;
}
