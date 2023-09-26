//---------------------------------------------------------
// Juni Ejere
// CS2315 Algorithms 
// CodeGuessing.c
//---------------------------------------------------------

#include <stdio.h>
#include <stdbool.h>

int main()
{
	int n;
	printf("This program can read your mind!\n"
	"------------------------------------------------------------------------------------------------------\n"
	"Rules: \n1. The user will think of a secret code and this program will try to guess it."
	"\n2. Enter an integer to represent the size of the code. We will call this n."
	"\n3. This code must be made up of binary digits, meaning every digit is either a 0 or a 1."
	"\n4. The program will output a guess. Respond with how many positions in the guess are correct."
	"\n    (Example: Ex. Secret Code = 01011; Guess = 11001; User will input 3 because the "
	"\n     two strings have the same bits in the second, third, and fifth positions.)"
	"\n5. The program will have up to n guesses to reveal the code to you."
	"\n\n***Make sure you write down your code and track the number of positions correct very carefully!***"
	"\nLet's Play >:)"
	"\n------------------------------------------------------------------------------------------------------\n"
	"\n\nEnter an integer n to represent the size of the string: ");
	scanf("%d", &n);
	bool secretCode[n+1];
	int positions;
	
	//initializing secretCode
	for(int i = 1; i <= n; i++)
	{
		secretCode[i] = false;
	}
	
	printf("\n\nFirst guess: ");
	for(int i = 1; i <= n; i++)
	{
		printf("%d",secretCode[i]);
	}
	printf("\nHow many positions are correct? ");
	scanf("%d", &positions);
	
	if(positions == n) //first guess is correct, terminates the program
	{
		printf("\n\nHa! I guessed your code :)");
	}
			
	else
	{
		bool testCode[n+1]; //iterates through each spot and tests if that spot is in the secret code
		bool placeHolder[n+1]; //holds the value of the first guess while each spot is tested
		int testPositions; //holds the number of positions correct that the user inputs while testing
		int formula = (n-positions+1); //if a tested spot is correct, the user will input this amount of positions
		int spot = 1; //holds the value of the spot being tested in the while loop
		int notCorrectCount = 0; //shows how many incorrect spots have been found. There are (n-positions) incorrect spots. if all have been found, the while loop will terminate
		int correctCount = 0; //shows how many correct spots have been found. there are (positions) correct spots. if all have been found, the while loop will terminate
		
		bool holdsPositionsIncorrect[n+1]; //holds the incorrect spots
		bool holdsPositionsCorrect[n+1];//holds the correct spots
		for(int it1 = 1; it1 <= n; it1++) //initializes; when a spot is correct it will be changed to true, the rest are false
		{
			holdsPositionsCorrect[it1] = false;
		}
		 
		for(int it1 = 1; it1 <= n; it1++) //initializes; when a spot is incorrect it will be changed to false, the rest are true
		{
			holdsPositionsIncorrect[it1] = true;
		}
		
		
		for(int hold = 1; hold <= n; hold++) //initializes the placeholder to the first guess
			{
				placeHolder[hold] = secretCode[hold];
			}
				
		//loops through. will terminate either when all of the spots have been tested, or the correct spots have been found
		while(spot <= n && notCorrectCount != (n-positions) && correctCount != positions)
		{
			//RESETS VALUE OF TEST CODE
			for(int reset = 1; reset <= n; reset++)
			{
				testCode[reset] = placeHolder[reset];
			}
			
			for(int alter = 1; alter<=n; alter++) //changes every other spot except the one being tested
			{
				if(alter != spot)
				{
					testCode[alter] = !( testCode[alter] );
				}
			}
			
			
			printf("\nNext guess: ");
			for(int display = 1; display <= n; display++) //prints tester guess 
			{
				printf("%d", testCode[display]);
			}
			
			printf("\nHow many positions are correct? ");
			scanf("%d", &testPositions);
			
			
		    if(testPositions != formula) //if the spot is not correct, save the spot and increment the number of incorrect spots found
			{
				holdsPositionsIncorrect[spot] = false;
				notCorrectCount++;
			}
			else //if the spot is correct correct, save the spot and increment the number of correct spots found
			{
				holdsPositionsCorrect[spot] = true;
				correctCount++;
			}
			
			spot++;		//goes to the next spot
		}
		
		
		//AFTER THE WHILE LOOP HAS TERMINATED
		
		if(correctCount == positions) // we found the number of correct spots first, uses values of holdsPositionsCorrect
		{
			for(int i = 1; i <= n; i++)
			{
				if(!holdsPositionsCorrect[i]) //if not a correct spot, flip it
				{
					secretCode[i] = (!secretCode[i]);
				}
			}
		}
		
		else //we found the number of incorrect spots first, uses values of holdsPositionsIncorrect
		{
			for(int i = 1; i <= n; i++)
			{
				if(!holdsPositionsIncorrect[i]) //if not an incorrect spot flip it
				{
					secretCode[i] = (!secretCode[i]);
				}
			}
		}
		
		//Reveals secret code to the user
		printf("\n\nIt is time for the big reveal. \nDRUMROLL PLEASE!!"
		"\nYour secret code is................ ");
		for(int i = 1; i <= n; i++)
		{
			printf("%d",secretCode[i]);
		}
		printf("!!\nThanks for playing :)\n");
		
	}
			
		
	
	
}
