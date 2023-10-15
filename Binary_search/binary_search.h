#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#define MAX_WORD_LENGTH 50
#define MAX_WORDS 300

int binary_search(const char words[MAX_WORDS][MAX_WORD_LENGTH], const char *target, int totalWords);
int linear_search(const char words[MAX_WORDS][MAX_WORD_LENGTH], const char *target, int totalWords);
int case_insensitive_binary_search(const char words[MAX_WORDS][MAX_WORD_LENGTH], const char *target, int totalWords);

#endif
