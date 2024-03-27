#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

// Function prototypes
void encrypt(char* text, int shift);
void decrypt(char* text, int shift);

int main() {
    char operation[10];
    int shift;
    char text[1024]; 

    printf("Enter shift value: ");
    scanf("%d", &shift);
    printf("Enter operation (encrypt or decrypt): ");
    scanf("%s", operation);
    printf("Enter text: ");
    while (getchar() != '\n');
    fgets(text, sizeof(text), stdin); 


    text[strcspn(text, "\n")] = 0;

    if (strcmp(operation, "encrypt") == 0) {
        encrypt(text, shift);
        printf("Encrypted text: %s\n", text);
    } else if (strcmp(operation, "decrypt") == 0) {
        decrypt(text, shift);
        printf("Decrypted text: %s\n", text);
    } else {
        printf("Invalid operation.\n");
    }

    return 0;
}

void encrypt(char* text, int shift) {
    int i = 0;
    while (text[i] != '\0') {
        if (isalpha(text[i])) {
            char base = islower(text[i]) ? 'a' : 'A';
            
            int offset = (text[i] - base + shift) % ALPHABET_SIZE;
            if (offset < 0) offset += ALPHABET_SIZE;
            text[i] = offset + base;
        }
        i++;
    }
}

void decrypt(char* text, int shift) {
    encrypt(text, -shift); 
}

