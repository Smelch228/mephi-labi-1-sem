//
// Created by Smelch on 14.11.2021.
//

#ifndef TEST_MY_STRING_H
#define TEST_MY_STRING_H

#include <stdbool.h>

char* my_strcpy(char* destination, const char* source);
void removeChar(char * str, char charToRemove);
int len(char s[]);
char* my_strcat(char* destination, const char* source);
bool is_delim(char c, char *delim);
char* my_strtok(char* s, char* delim);

#endif //TEST_MY_STRING_H
