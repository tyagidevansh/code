#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char s[100];

    printf("Enter string: ");
    fgets(s, sizeof(s), stdin);

    printf("Original string: %s", s);

    for (int i = 0; s[i] != '\0'; i++) {
        if ((i == 0 || s[i - 1] == ' ') && isalpha(s[i])) {
            s[i] = toupper(s[i]);
        }
    }

    printf("Modified string: %s", s);

    return 0;
}
