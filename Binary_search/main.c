#include <stdio.h>
#include <string.h>
#include <time.h>
#include "binary_search.h"

#define WORDS_FILE "sorted_words.txt"

void displayMenu() {
    printf("Welcome to the Word Search Program2131!\n");
    printf("Options:\n");
    printf("1. Binary Search\n");
    printf("2. Linear Search\n");
    printf("3. Case-Insensitive Binary Search\n");
    printf("4. Exit the program\n");
    printf("Enter the number of your choice: ");
}

int main() {
    char target[MAX_WORD_LENGTH];
    int index;

    // Open the file to count the total number of words
    FILE *wordFile = fopen(WORDS_FILE, "r");
    int totalWords = 0;
    char words[MAX_WORDS][MAX_WORD_LENGTH]; // Declare words array
    char word[MAX_WORD_LENGTH];

    while (fscanf(wordFile, "%s", word) != EOF) {
        totalWords++;
        if (totalWords <= MAX_WORDS) {
            strcpy(words[totalWords - 1], word);
        } else {
            printf("Warning: Too many words in the file. Some words were not loaded.\n");
        }
    }

    fclose(wordFile);

    printf("Total number of words in the file: %d\n", totalWords);

    while (1) {
        displayMenu();

        int choice;
        scanf("%d", &choice);

        if (choice == 4) {
            printf("Exiting the program.\n");
            break;
        } else if (choice >= 1 && choice <= 3) {
            printf("Enter a word to search: ");
            scanf("%s", target);

            clock_t start_time = clock();
            switch (choice) {
                case 1:
                    index = binary_search(words, target, totalWords);
                    break;
                case 2:
                    index = linear_search(words, target, totalWords);
                    break;
                case 3:
                    index = case_insensitive_binary_search(words, target, totalWords);
                    break;
                default:
                    index = -1;
            }
            clock_t end_time = clock();
            double search_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

            if (index != -1) {
                printf("Word '%s' is found at line %d.\n", target, index + 1);
            } else {
                printf("Word '%s' is not found.\n");

                // Suggest similar words
                printf("Similar words in the file: ");
                for (int i = 0; i < totalWords; i++) {
                    if (strstr(words[i], target) != NULL || strstr(target, words[i]) != NULL) {
                        printf("%s ", words[i]);
                    }
                }
                printf("\n");
            }

            printf("Search time: %.4f seconds\n", search_time);
        } else {
            printf("Invalid choice. Please enter 1, 2, 3, or 4.\n");
        }
    }

    return 0;
}
