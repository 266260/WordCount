#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int countCharacters(FILE *file) {
    int count = 0;
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        count++;
    }
    return count;
}

int countWords(FILE *file) {
    int count = 0;
    int inWord = 0;
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        if (isalnum(ch)) {
            if (!inWord) {
                count++;
                inWord = 1;
            }
        } else {
            inWord = 0;
        }
    }
    return count;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s [-c | -w] input_file_name\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[2], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    int count;
    if (argv[1][1] == 'c') {
        count = countCharacters(file);
        printf("×Ö·ûÊý£º%d\n", count);
    } else if (argv[1][1] == 'w') {
        count = countWords(file);
        printf("µ¥´ÊÊý£º%d\n", count);
    } else {
        printf("Invalid parameter. Use -c for character count or -w for word count.\n");
        return 1;
    }

    fclose(file);
    return 0;
}
