#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define SUCCESS 0
#define ERROR -1
#define OUTPUT_NAME "output.txt"
#define MAX_BUF_SIZE 1024
#define MAX_WORD_SIZE 46 /*based on the longest english word in the major dictionary.*/
#define MAX(x,y) ((x) > (y) ? (x) : (y)) /*macro that return the bigger value*/

/*count the size of the biggest word in the line and the number of words in the line for dynamically allocate memory for sentence.*/
void countWordsAndMaxWordSize(char* line, unsigned int len, unsigned int* biggestWord, unsigned int* numberOfWords); 

/*seperate the words in a spcified line and fill the spcified dynamic array.*/
void getWordsFromLine(char* line, char** wordsInLine, unsigned int lineLen);

/*compare the origin word to the given vocabulary and decide which word to write to the output file.*/
int compareToVocabulary(char* originWord, FILE* vocabularyFile, FILE* outputFile);

/*seperate lines from the vocabulary.csv file by ',' character to 2 words.*/
int getSeparatedLineFromVocabulary(char* line, char* firstWord, char* secondWord);


int main(int argc, char* argv[])
{
	int i = 0;
	int lineLengh = 0;

	FILE* scenario = NULL;
	FILE* vocabulary = NULL;
	FILE* output = NULL;

	char** wordsInLine = NULL;
	char line[MAX_BUF_SIZE];

	unsigned int wordSize = 0;
	unsigned int numberOfWords = 0;

	/*check if the user insert 2 files*/
	if ( argc != 3 )
	{
		printf("ERROR: Too few arguments.\nUsage: ReplaceSynonyms.exe <File.txt> <Vocabulary.csv>\n"); 
		system("pause");
		return ERROR;
	}
	if ( strstr(argv[1], ".txt") == NULL )
	{
		printf("%s\nERROR: You must insert text file <File.txt> to use the program!\nUsage: ReplaceSynonyms.exe <File.txt> <Vocabulary.csv>\n", argv[2]);
		system("pause");
		return ERROR;
	}
	if ( strstr(argv[2], ".csv") == NULL )
	{
		printf("ERROR: You must insert csv file <Vocabulary.csv> to use the program!\nUsage: ReplaceSynonyms.exe <File.txt> <Vocabulary.csv>\n");
		system("pause");
		return ERROR;
	}
	scenario = fopen(argv[1], "r");
	if ( scenario == NULL )
	{
		printf("ERROR: %s couldn't open.\n", argv[2]);
		system("pause");
		return ERROR;
	}
	vocabulary = fopen(argv[2], "r");
	if ( vocabulary == NULL )
	{
		printf("ERROR: %s couldn't open.\n", argv[3]);
		system("pause");
		return ERROR;
	}
	output = fopen(OUTPUT_NAME, "w");
	if ( output == NULL )
	{
		printf("ERROR: %s couldn't open.\n", OUTPUT_NAME);
		system("pause");
		return ERROR;
	}

	while ( fgets(line, MAX_BUF_SIZE, scenario) != NULL )
	{
		lineLengh = strlen(line);
		if ( fgetc(scenario) == EOF )
			lineLengh++;
		else
			fseek(scenario, -1, SEEK_CUR);
		countWordsAndMaxWordSize(line, lineLengh, &wordSize, &numberOfWords);
		if ( numberOfWords == 0 )
			printf("Empty line.\n");
		else if ( numberOfWords == 1 )
			printf("%s\n", line);
		else
		{
			wordsInLine = (char**)malloc(sizeof(char*) * numberOfWords);
			for( i = 0 ; i < numberOfWords ; i++ )
			{
				*(wordsInLine + i) = (char*)malloc(sizeof(char) * (wordSize+1));
			}
			getWordsFromLine(line, wordsInLine, lineLengh);
			for ( i = 0 ; i < numberOfWords ; i++ )
			{
				compareToVocabulary( *(wordsInLine + i), vocabulary, output );
			}
			fputc('\n', output);

		}
	}
	
	fclose(scenario);
	fclose(vocabulary);
	fclose(output);
	
	system("pause");
	return SUCCESS;
}

void countWordsAndMaxWordSize(char* line, unsigned int len, unsigned int* biggestWord, unsigned int* numberOfWords)
{
	int i;
	int countWords = 1;
	int countWordMaxLen = 0;
	int biggerWord = 0;

	if ( len == 0 )
		return;

	for ( i = 0 ; i < len ; i++ )
	{
		if ( isspace(line[i]) && line[i] != '\n' )
		{
			countWords++;
			biggerWord = MAX(biggerWord, countWordMaxLen);
			countWordMaxLen = 0;
		}
		else
			countWordMaxLen++;
	}

	biggerWord = MAX(biggerWord, countWordMaxLen);
	*biggestWord = biggerWord;
	*numberOfWords = countWords;
}

void getWordsFromLine(char* line, char** wordsInLine, unsigned int lineLen)
{
	int word_index = 0;
	int letter_index = 0;
	int char_index = 0;

	while(char_index < lineLen)
	{
		if ( isspace(line[char_index]) != 0 )
		{
			wordsInLine[word_index][letter_index] = '\0';
			char_index++;
			word_index++;
			letter_index = 0;
		}
		else
		{
			wordsInLine[word_index][letter_index] = line[char_index];
			char_index++;
			letter_index++;
		}
	}
}

int compareToVocabulary(char* originWord, FILE* vocabularyFile, FILE* outputFile)
{
	char firstWordInVocabulary[MAX_WORD_SIZE];
	char secondWordInVocabulary[MAX_WORD_SIZE];
	char line[MAX_BUF_SIZE];

	int flag = 1;

	while ( fgets(line, MAX_BUF_SIZE, vocabularyFile) != NULL )
	{
		
		if ( getSeparatedLineFromVocabulary(line, firstWordInVocabulary, secondWordInVocabulary) == -1 )
			return ERROR;

		if ( strcmp(firstWordInVocabulary, originWord) == 0 )
		{
			fprintf(outputFile, "%s", secondWordInVocabulary);
			fputc(' ', outputFile);
			flag = 0;
		}
	}
	fseek(vocabularyFile, 0, SEEK_SET);
	if ( flag == 1 )
	{
		fprintf(outputFile, "%s ", originWord);
	}
	
}

int getSeparatedLineFromVocabulary(char* line, char* firstWord, char* secondWord)
{
	int i = 0;
	int j = 0;
	int len;
	
	len = strlen(line);
	
	while ( line[i] != ',' )
	{
		if ( line[i] == EOF || line[i] == '\n' || i == MAX_WORD_SIZE )
		{
			{
				printf("It seems like the vocabulary file that you have chosen is not a legal 'CSV' file\nUsage: ReplaceSynonyms.exe <File.txt> <Vocabulary.csv>\n");
				system("pause");
				return ERROR;
			}
		}
		if( isalpha(line[i]) != 0 )
		{
			firstWord[i] = line[i];
			i++;
		}
	}
	firstWord[i] = '\0';
	i++;

	while ( i <= len )
	{
		secondWord[j] = line[i];
		i++;
		j++;
	}
	secondWord[j-2] = '\0'; // To override the \n from the second word.
	return SUCCESS;
}