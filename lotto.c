/*
Lotto Array		Hugo Standera
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define USERSIZE 6      
#define LOTTOSIZE 7     

int main() 
{
    srand(0); // Seed the random number generator

    // Arrays for each draw and user numbers
    short lotto[LOTTOSIZE], lottoPlus1[LOTTOSIZE], lottoPlus2[LOTTOSIZE];
    short userNumbers[USERSIZE];

    // General variables for the program
    short i, j, userChoice, totalDraws;
    short lowest = 1, highest = 45;			// Range for draw numbers
    short numMatches, bonusMatch;
    char goAgain, plusChoice, c;

    // Generate main lotto draw
    for (i = 0; i < LOTTOSIZE; i++) 
	{
        while (1) 
		{
            short newNumber = (rand() % (highest - lowest + 1)) + lowest;
            short duplicate = 0;

            // Check if the number already exists
            for (j = 0; j < i; j++) 
			{
                if (lotto[j] == newNumber) 
				{
                    duplicate = 1;
                    break;
                }
            }

            // If unique, store it
            if (duplicate == 0) 
			{
                lotto[i] = newNumber;
                break;
            }
        }
    }

    // Generate the lotto plus 1 draw
    for (i = 0; i < LOTTOSIZE; i++) 
	{
        while (1) 
		{
            short newNumber = (rand() % (highest - lowest + 1)) + lowest;
            short duplicate = 0;

            for (j = 0; j < i; j++) 
			{
                if (lottoPlus1[j] == newNumber) 
				{
                    duplicate = 1;
                    break;
                }
            }

            if (duplicate == 0) 
			{
                lottoPlus1[i] = newNumber;
                break;
            }
        }
    }

    // Generate the lotto plus 2 draw
    for (i = 0; i < LOTTOSIZE; i++) 
	{
        while (1) 
		{
            short newNumber = (rand() % (highest - lowest + 1)) + lowest;
            short duplicate = 0;

            for (j = 0; j < i; j++) 
			{
                if (lottoPlus2[j] == newNumber) 
				{
                    duplicate = 1;
                    break;
                }
            }

            if (duplicate == 0) 
			{
                lottoPlus2[i] = newNumber;
                break;
            }
        }
    }

    // Main loop
    while (1) 
	{
        printf("\nWELCOME TO THE LOTTO RESULTS PROGRAMME!\n\n");

        // Input method: manual or quick pick
        while (1) 
		{
            printf("Please choose an input method:\n1. Enter own numbers\n2. Quick pick\n");
            if (scanf("%hd", &userChoice) == 1) 
			{
                if (userChoice == 1 || userChoice == 2) 
				{
                    break;		// Valid choice
                } 
                
				else 
				{
                    printf("Invalid selection. Please try again.\n");
                }
            } 
            
			else 
			{
                printf("Invalid input.\n");
                while ((c = getchar()) != '\n' && c != EOF); // Clear input buffer
            }
        }

        // Manual number entry
        if (userChoice == 1) 
		{
            for (i = 0; i < USERSIZE; i++) 
			{
                while (1) 
				{
                    printf("Enter user number %hd (1-47): ", i + 1);
                    if (scanf("%hd", &userNumbers[i]) == 1) 
					{
                        if (userNumbers[i] >= 1 && userNumbers[i] <= 47) 
						{
                            short duplicate = 0;
                            for (j = 0; j < i; j++) 
							{
                                if (userNumbers[i] == userNumbers[j]) 
								{
                                    duplicate = 1; // Number already entered
                                    break;
                                }
                            }
                            
                            if (duplicate == 0) 
							{
                                break; // Valid number entered
                            } 
                            
							else 
							{
                                printf("Number already entered. Please try again.\n");
                            }
                        } 
                        
						else 
						{
                            printf("Number must be between 1 and 47.\n");
                        }
                    } 
                    
					else 
					{
                        printf("Non-numeric input detected. Please try again.\n");
                        while ((c = getchar()) != '\n' && c != EOF); // Clear buffer
                    }
                }
            }
        }

        // Quick pick
        if (userChoice == 2) 
		{
            for (i = 0; i < USERSIZE; i++) 
			{
                while (1) 
				{
                    short newNumber = (rand() % 47) + 1;
                    short duplicate = 0;

                    for (j = 0; j < i; j++) 
					{
                        if (userNumbers[j] == newNumber) 
						{
                            duplicate = 1;
                            break;
                        }
                    }

                    if (duplicate == 0) 
					{
                        userNumbers[i] = newNumber;
                        break;
                    }
                }
            }
        }

        // Lotto Plus draws option
        while (1) 
		{
		    printf("\nDo you want to check Lotto Plus draws as well? (Y/N): ");
		    getchar();		// Clear leftover newline
		    scanf("%c", &plusChoice); 
		
		    if (plusChoice == 'Y' || plusChoice == 'y') 
		    {
		        totalDraws = 3;
		        break;
		    } 
		    
		    else if (plusChoice == 'N' || plusChoice == 'n') 
		    {
		        totalDraws = 1;
		        break;
		    } 
		    
		    else 
		    {
		        printf("Invalid input. Please enter Y or N.\n");
		        while ((c = getchar()) != '\n' && c != EOF);		// Clear input buffer
		    }
		}

        // Display user and draw numbers
        printf("\nYour numbers are: ");
        for (i = 0; i < USERSIZE; i++) 
		{
            printf("%hd ", userNumbers[i]);
        }
        printf("\n");

        printf("\nMain lotto draw: ");
        for (i = 0; i < LOTTOSIZE; i++) 
		{
            printf("%hd ", lotto[i]);
        }
        printf("\n");

        if (totalDraws == 3) 
		{
            printf("Lotto plus 1 draw: ");
            for (i = 0; i < LOTTOSIZE; i++) 
			{
                printf("%hd ", lottoPlus1[i]);
            }
            printf("\n");

            printf("Lotto plus 2 draw: ");
            for (i = 0; i < LOTTOSIZE; i++) 
			{
                printf("%hd ", lottoPlus2[i]);
            }
            printf("\n");
        }

        // Check main lotto draw
		numMatches = 0;
		bonusMatch = 0;
		
		for (i = 0; i < USERSIZE; i++) 
		{
		    for (j = 0; j < LOTTOSIZE - 1; j++) 
			{
		        if (userNumbers[i] == lotto[j]) 
				{
		            numMatches++;
		        }
		    }
		    
		    if (userNumbers[i] == lotto[6]) 
			{
		        bonusMatch = 1;
		    }
		}
		
		printf("\nResults for the main lotto draw:\n");
		if (numMatches == 6)
		    printf("JACKPOT WINNER!\n");
		    
		else if (numMatches == 5 && bonusMatch)
		
		else if (numMatches == 5)
		    printf("Winner: 5 numbers (Cash Prize)\n");
		    
		else if (numMatches == 4 && bonusMatch)
		    printf("Winner: 4 numbers + bonus (Cash Prize)\n");
		    
		else if (numMatches == 4)
		    printf("Winner: 4 numbers (Cash Prize)\n");
		    
		else if (numMatches == 3 && bonusMatch)
		    printf("Winner: 3 numbers + bonus (Cash Prize)\n");
		    
		else if (numMatches == 3)
		    printf("Winner: 3 numbers (Scratch Card)\n");
		    
		else
		    printf("No prize.\n");
		
		// Check lotto plus draws if selected
		if (totalDraws == 3) 
		{
		    // Lotto plus 1
		    numMatches = 0;
		    bonusMatch = 0;
		    for (i = 0; i < USERSIZE; i++) 
			{
		        for (j = 0; j < LOTTOSIZE - 1; j++) 
				{
		            if (userNumbers[i] == lottoPlus1[j]) 
					{
		                numMatches++;
		            }
		        }
		        
		        if (userNumbers[i] == lottoPlus1[6]) 
				{
		            bonusMatch = 1;
		        }
		    }
		
		    printf("\nResults for the lotto plus 1 draw:\n");
		    if (numMatches == 6)
		        printf("JACKPOT WINNER!\n");
		        
		    else if (numMatches == 5 && bonusMatch)
		        printf("Winner: 5 numbers + bonus (Cash Prize)\n");
		        
		    else if (numMatches == 5)
		        printf("Winner: 5 numbers (Cash Prize)\n");
		        
		    else if (numMatches == 4 && bonusMatch)
		        printf("Winner: 4 numbers + bonus (Cash Prize)\n");
		        
		    else if (numMatches == 4)
		        printf("Winner: 4 numbers (Cash Prize)\n");
		        
		    else if (numMatches == 3 && bonusMatch)
		        printf("Winner: 3 numbers + bonus (Cash Prize)\n");
		        
		    else if (numMatches == 3)
		        printf("Winner: 3 numbers (Scratch Card)\n");
		        
		    else
		        printf("No prize.\n");
		
		    // Lotto plus 2
		    numMatches = 0;
		    bonusMatch = 0;
		    for (i = 0; i < USERSIZE; i++) 
			{
		        for (j = 0; j < LOTTOSIZE - 1; j++) 
				{
		            if (userNumbers[i] == lottoPlus2[j]) 
					{
		                numMatches++;
		            }
		        }
		        
		        if (userNumbers[i] == lottoPlus2[6]) 
				{
		            bonusMatch = 1;
		        }
		    }

		    printf("\nResults for the lotto plus 2 draw:\n");
		    if (numMatches == 6)
		        printf("JACKPOT WINNER!\n");
		        
		    else if (numMatches == 5 && bonusMatch)
		        printf("Winner: 5 numbers + bonus (Cash Prize)\n");
		        
		    else if (numMatches == 5)
		        printf("Winner: 5 numbers (Cash Prize)\n");
		        
		    else if (numMatches == 4 && bonusMatch)
		        printf("Winner: 4 numbers + bonus (Cash Prize)\n");
		        
		    else if (numMatches == 4)
		        printf("Winner: 4 numbers (Cash Prize)\n");
		        
		    else if (numMatches == 3 && bonusMatch)
		        printf("Winner: 3 numbers + bonus (Cash Prize)\n");
		        
		    else if (numMatches == 3)
		        printf("Winner: 3 numbers (Scratch Card)\n");
		        
		    else
		        printf("No prize.\n");
		}
        // Ask if program is to repeat 
        getchar(); // Clear leftover newline
        printf("\nWould you like to check another set of numbers? (Y/N): ");
        scanf("%c", &goAgain);

        if (goAgain != 'Y' && goAgain != 'y') 
		{
            break;
        }
    }

    printf("\nThank you for using my programme, exiting now...\n");
    return 0;
}