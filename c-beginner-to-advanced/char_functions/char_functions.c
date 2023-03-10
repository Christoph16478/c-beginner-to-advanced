#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define _CRT_SECURE_NO_WARNINGS

void convertCase(FILE* fptr, const char* path);

int main(int argc, char* argv[])
{
    // solution 2
    /* File pointer to hold reference of input file */
    FILE* fPtr = NULL;
    char path[100];
    printf("Enter path of source file: ");
    scanf_s("%s", path);
    fPtr = fopen_s(&fPtr, path, "r");
    /* fopen() return NULL if unable to open file in given mode. */
    if (fPtr == NULL)
    {
        /* Unable to open file hence exit */
        printf("\nUnable to open file.\n");
        printf("Please check whether file exists and you have read privilege.\n");
        exit(EXIT_FAILURE);
    }
    convertCase(fPtr, path);

    // solution 1
    FILE* fp = NULL;
    char ch = '\0';
    int wrd = 1, charctr = 1;
    if (argc == 1)
        fp = stdin;
    else if (argc == 2) {
        if ((fp = fopen_s(&fp, argv[1], "r")) == NULL) {
            fprintf(stderr, "Can't open %s\n", argv[1]);
            exit(EXIT_FAILURE);
        }
    }
    else {
        fprintf(stderr, "Usage: %s [filename]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    ch = getc(fp);
    while (ch != EOF) {
        if (ch == ' ' || ch == '\n') {
            wrd++;
        }
        else {
            charctr++;
        }

        ch = getc(fp);
    }
    printf("\n The number of words in the file are : %d\n", wrd);
    printf(" The number of characters in the file is : %d\n\n", charctr);
    fclose(fp);
    return 0;
}

void convertCase(FILE* fptr, const char* path)
{
    FILE* dest = NULL;
    char ch = '\0';
    // Temporary file to store result
    dest = fopen_s(&dest, "temp.txt", "w");
    // If unable to create temporary file
    if (dest == NULL)
    {
        printf("Unable to create temporary file.");
        fclose(fptr);
        exit(EXIT_FAILURE);
    }
    /* Repeat till end of file. */
    while ((ch = fgetc(fptr)) != EOF)
    {
        /*
         * If current character is uppercase then toggle
         * it to lowercase and vice versa.
         */
        if (isupper(ch))
            ch = tolower(ch);
        else if (islower(ch))
            ch = toupper(ch);

        // Print toggled character to destination file.
        fputc(ch, dest);
    }
    /* Close all files to release resource */
    fclose(fptr);
    fclose(dest);
    /* Delete original source file */
    remove(path);
    /* Rename temporary file as original file */
    rename("temp.txt", path);
}
