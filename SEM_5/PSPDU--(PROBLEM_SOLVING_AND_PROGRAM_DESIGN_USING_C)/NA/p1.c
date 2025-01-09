#include <stdio.h>
#include <string.h>

void generatePlural(const char *noun, char *plural) {
    int len = strlen(noun);

    if (noun[len - 1] == 'y' && len > 1 && strchr("aeiou", noun[len - 2]) == NULL) {
        strncpy(plural, noun, len - 1);
        plural[len - 1] = '\0';
        strcat(plural, "ies");
    } else if (noun[len - 1] == 's' || 
               (len > 1 && strcmp(&noun[len - 2], "ch") == 0) || 
               (len > 1 && strcmp(&noun[len - 2], "sh") == 0)) {
        strcpy(plural, noun);
        strcat(plural, "es");
    } else {
        strcpy(plural, noun);
        strcat(plural, "s");
    }
}

int main() {
    char noun[50], plural[50];
    printf("Enter a noun: ");
    scanf("%s", noun);

    generatePlural(noun, plural);
    printf("Plural: %s\n", plural);

    return 0;
}
