#include <string.h>
#include "binary_search.h"

int binary_search(const char words[MAX_WORDS][MAX_WORD_LENGTH], const char *target, int totalWords) {
    int left = 0;
    int right = totalWords - 1;
    
    while (left <= right) {
        int middle = left + (right - left) / 2;
        int cmp = strcmp(words[middle], target);

        if (cmp == 0) {
            return middle;
        } else if (cmp < 0) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }
    
    return -1; // Word not found
}

int linear_search(const char words[MAX_WORDS][MAX_WORD_LENGTH], const char *target, int totalWords) {
    for (int i = 0; i < totalWords; i++) {
        if (strcasecmp(words[i], target) == 0) {
            return i;
        }
    }
    return -1; // Word not found
}

int case_insensitive_binary_search(const char words[MAX_WORDS][MAX_WORD_LENGTH], const char *target, int totalWords) {
    for (int i = 0; i < totalWords; i++) {
        if (strcasecmp(words[i], target) == 0) {
            return i;
        }
    }
    return -1; // Word not found
}
