#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000

typedef struct {
    char word[50];
    int frequency;
} WordFrequency;

void convertToLowercase(char *str) {
    while (*str) {
        *str = tolower(*str);
        str++;
    }
}

int isDelimiter(char ch) {
    return ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r' || ch == '.' || ch == ',' || ch == ':' || ch == ';' || ch == '!' || ch == '?' || ch == '(' || ch == ')';
}

int isWordInList(WordFrequency *list, int size, char *word) {
    for (int i = 0; i < size; i++) {
        if (strcmp(list[i].word, word) == 0) {
            return i;
        }
    }
    return -1;
}

void insertWordToList(WordFrequency *list, int size, char *word) {
    strcpy(list[size].word, word);
    list[size].frequency = 1;
}

void updateWordFrequency(WordFrequency *list, int index) {
    list[index].frequency++;
}

int compareWordFrequency(const void *a, const void *b) {
    WordFrequency *word1 = (WordFrequency *)a;
    WordFrequency *word2 = (WordFrequency *)b;

    if (word1->frequency > word2->frequency) {
        return -1;
    } else if (word1->frequency < word2->frequency) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char filename[100];
    char word[50];
    WordFrequency wordList[MAX_WORDS];
    int wordCount = 0;

    printf("Enter the filename: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }

    while (fscanf(file, "%s", word) == 1) {
        convertToLowercase(word);

        if (!isDelimiter(word[0])) {
            int index = isWordInList(wordList, wordCount, word);
            if (index == -1) {
                if (wordCount < MAX_WORDS) {
                    insertWordToList(wordList, wordCount, word);
                    wordCount++;
                }
            } else {
                updateWordFrequency(wordList, index);
            }
        }
    }

    fclose(file);

    qsort(wordList, wordCount, sizeof(WordFrequency), compareWordFrequency);

    printf("The 10 most used words in the text are:\n");
    for (int i = 0; i < 10 && i < wordCount; i++) {
        printf("%s - %d occurrences\n", wordList[i].word, wordList[i].frequency);
    }

    return 0;
}
