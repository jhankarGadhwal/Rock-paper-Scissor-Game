#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Rock paper Scissor Game

int generateRandomNumber(int n)
    {
	srand(time(NULL)); //srand takes seed as an input and is defined inside stdlib.h
	return rand()%n;
	}

int greater(char char1, char char2){
	//for rock paper scissors- returns 1 if c1>c2 and 0 otherwise. if c1==C2 it will return -1
	if (char1 == char2)
	{
	return -1;
	}
	else if((char1 == 'r')&&(char2 == 's'))
	{
		return 1;
	}
	else if((char2 == 'r')&&(char1 == 's'))
	{
		return 0;
	}
	if((char1 == 'p')&&(char2 == 'r'))
	{
		return 1;
	}
	else if((char2 == 'p')&&(char1 == 'r'))
	{
		return 0;
	}
	if((char1 == 's')&&(char2 == 'p'))
	{
		return 1;
	}
	else if((char2 == 's')&&(char1 == 'p'))
	{
		return 0;
	}
}
int main()
{
	int playerScore = 0, compScore = 0, temp;
	char playerChar, compChar;
	char dict[] ={'r', 'p', 's'};
	printf("Wel-come to the Rock, Paper, Scissors....\n");
	for (int i = 0; i < 3; i++)
	{
		//Take player 1's input
		printf("Player 1's Turn:\n");
		printf("Choose 1 for Rock, 2 for Paper and 3 for Scissors \n");
		scanf("%d", &temp);
		getchar();
		playerChar = dict[temp-1];
		printf("You chose %c\n\n", playerChar);
		
		//Generate cmputer's input
		printf("Computer's Turn:\n");
		printf("Chose 1 for Rock, 2 for Paper and 3 for Scissors \n");
		temp = generateRandomNumber(3) +1;
		compChar = dict[temp-1];
		printf("CPU chose %c\n", compChar);
		
		//compare the scores
		if(greater(compChar, playerChar) == 1)
		{
			compScore += 1;
			printf("CPU Got it!\n");
		}
		
		else if(greater(compChar, playerChar) == -1)
		{
			compScore += 1;
			playerScore += 1;
			printf("Its a draw!\n");
        }
	    else
	    {
	    	playerScore += 1;
	    	printf("You Got it!\n");
		}
		printf("You: %d\n CPU: %d\n\n", playerScore, compScore);
    }
	if(playerScore > compScore)
	{
	printf("You win the game\n");
    }
    else if(playerScore < compScore)
	{
	printf("CPU win the game\n");
    }
    else
    {
	printf("Its a draw\n");
    }
	return 0;
}

