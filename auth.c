#include <stdio.h>
#include <string.h>

int authenticateUser() {
    char username[30], password[30];
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    return strcmp(username, "admin") == 0 && strcmp(password, "admin123") == 0;
}