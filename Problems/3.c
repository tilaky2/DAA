#include <stdio.h>

int main() {
    char str[100];

    printf("Enter an uppercase string: ");
    scanf("%s", str);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + ('a' - 'A'); 
        }
    }
    printf("Lowercase string: %s\n", str);

    return 0;
}
