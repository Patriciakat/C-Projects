// By Patriciakat 2022
// A program that finds the longest word in each line from a text file

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void findLongestWord(FILE *myFile, FILE *outFile);

int main(int argc, char *argv[])
{
    FILE *myFile, *outFile;

    myFile = fopen(argv[1], "r");
    outFile = fopen(argv[2], "w");

    if (myFile == NULL)
    {
        printf("Error in opening file");
        return (-1);
    }

    findLongestWord(myFile, outFile);

        fclose(myFile);

    return 0;
}

void findLongestWord(FILE *myFile, FILE *outFile)
{
    int maxLength = 0;
    int whileCounter = 0;
    
    char *longestWord;
    char *token;
    char *sentence = (char *)malloc(257 * sizeof(char)); 
    while (fgets(sentence, 257, myFile) != NULL)   // last two symbols are not letters
    {
        sentence[strlen(sentence) - 1] = '\0';
        if (strlen(sentence) == 255)
        {   
            while (fgetc(myFile) != '\n')
            {
                if (feof(myFile))
                {
                    break;
                }
            }
        }
        // algorithm to find the longest word
        token = strtok(sentence, " ");
        while (token != NULL)
        {
            if (strlen(token) > maxLength)
            {
                longestWord[255];
                maxLength = strlen(token);
                strcpy(longestWord, token);
            }
            token = strtok(NULL, " ");
        }
        
        fprintf(outFile, "%s\n", longestWord);
        maxLength = 0;
    }
        free(sentence);
}
