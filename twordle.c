//Liliana Sanchez
//Project 10
//4-24-2026
#include <stdio.h>
#define NUM_GUESSES 6 
#define WORD_LENGTH 5
int checkWin(char guess[],char word[]);
void getGuesses(int turn, char guess[]);
void getWord(char word[]);
void printCarrot(char guess[],char word[]);
void printGuesses(char word[], int numGuesses, char guesses[][WORD_LENGTH+1]);
void printWin(char word[], int guessesUsed);
int main(){
	
	char guesses[NUM_GUESSES][WORD_LENGTH+1];
	char word[WORD_LENGTH+1];
	getWord(word);
	int won=0;
	
	for(int turn=0; turn< NUM_GUESSES; turn++){
		getGuesses(turn, guesses[turn]);
		printGuesses( word, turn+1,guesses);
			if (checkWin(guesses[turn],word)){
				printWin(word, turn+1);
				won =1;
				break;
			}
	}
	if (!won){
		printf("You lost, better luck next time!\n");
	}
	return 0;
}

void getWord(char word[]){
	FILE* inputFile;
	inputFile= fopen("mystery.txt","r");
		if (inputFile==NULL){
			printf("Error opening file");
		}
	fscanf(inputFile, "%s", word);
	fclose(inputFile);
}

void getGuesses(int turn, char guess[]){
	char temporary[100];
	int length;
	do {
	length = 0;
	if( turn == NUM_GUESSES-1){
		printf("FINAL GUESS : ");
		scanf("%s", temporary);
	}
	else{
	printf("GUESS %d! Enter your guess: ", turn+1);
	scanf("%s", temporary);
	}
	
	for ( int i = 0; temporary[i]!='\0';i++){
		length++;
	}
	if (length != 5){
		printf("Must be exactly 5 letters\n");
	} 
	}while (length != 5);
	for (int i=0;i<5;i++){
		guess[i]=temporary[i];
	}
	guess[5]='\0';
}

int checkWin(char guess[],char word[]){
	for (int i =0; i<WORD_LENGTH;i++){
		if (guess[i]!=word[i]){
		return 0;
		}
	}
	return 1;
}
void printGuesses(char word[], int numGuesses, char guesses[][WORD_LENGTH+1]){
	printf("================================\n");
	for(int guessInd=0; guessInd< numGuesses;guessInd++){
		for(int i =0; i<WORD_LENGTH;i++){
			if(guesses[guessInd][i]==word[i]){
			printf("%c", guesses[guessInd][i] - 32);
		}
		else{
		printf("%c", guesses[guessInd][i]);
		}
	}
	printf("\n");
	
	printCarrot(guesses[guessInd],word);
	printf("\n");
	}
}








 
void printCarrot(char guess[],char word[]){
	for (int i = 0; i < WORD_LENGTH; i++) {
        	if (guess[i] == word[i]) {
            printf(" "); //does not print if in correct spot
        }
        else {
		int found = 0;
		for (int j = 0; j < WORD_LENGTH; j++){
			if (guess[i] == word[j]) {
				found = 1;
			}
		}
		if (found) {
                	printf("^");  // wrong spot but exists
		} else {
                	printf(" ");  // not in word
            }
        }
}
        printf("\n");
}
			
void printWin(char word[], int guessesUsed){
printf("================================\n");
printf("\t\t");
		for(int i=0; i< WORD_LENGTH;i++){
			printf("%c", word[i]-32);
		}
		printf("\n");
		
		printf("\tYou won in %d guesses!\n", guessesUsed);
		printf("\t\tAmazing!\n");
	}
			
	
	
	
		
			

	
	
