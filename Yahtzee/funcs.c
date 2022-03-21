#include "yahtzee.h"

void displayMenu(void) {
	printf("1. Game Rules\n2. Play Yahtzee\n3. Exit\n");
}

void displayRules(void) {
	//Written rules
	printf("The scorecard used for Yahtzee is composed of two sections. A upper section and a lower section.\n");
	printf("A total of thirteen boxes or thirteen scoring combinations are divided amongst the sections.The upper\n");
	printf("section consists of boxes that are scored by summing the value of the dice matching the faces of the box.\n");
	printf("If a player rolls four 3's, then the score placed in the 3's box is the sum of the dice which is 12. Once\n");
	printf("a player has chosen to score a box, it may not be changedand the combination is no longer in play for future\n");
	printf("rounds.If the sum of the scores in the upper section is greater than or equal to 63, then 35 more points are\n");
	printf("added to the players overall score as a bonus.The lower section contains a number of poker like combinations.\n");
	printf("See the table provided below:\n\n");
	
	//Table of ways to score
	printf("|     Name     |     Combination     |     Score     |\n");
	printf("|--------------|---------------------|---------------|\n");
	printf("| Three-of-a-  |Three dice with same |  Sum of all 5 |\n");
	printf("|    kind      |         face        |  face values  |\n");
	printf("|--------------|---------------------|---------------|\n");
	printf("|  Four-of-a-  | Four dice with same |  Sum of all 5 |\n");
	printf("|    kind      |         face        |  face values  |\n");
	printf("|--------------|---------------------|---------------|\n");
	printf("|  Full House  |One pair and 3 of a  |       25      |\n");
	printf("|              |         kind        |               |\n");
	printf("|--------------|---------------------|---------------|\n");
	printf("|     Small    | A sequence of four  |       30      |\n");
	printf("|   Straight   |         dice        |               |\n");
	printf("|--------------|---------------------|---------------|\n");
	printf("|     Large    | A sequence of five  |       40      |\n");
	printf("|   Straight   |         dice        |               |\n");
	printf("|--------------|---------------------|---------------|\n");
	printf("|   Yahtzee    | Five dice with same |       50      |\n");
	printf("|              |        face         |               |\n");
	printf("|--------------|---------------------|---------------|\n");
	printf("|    Chance    | A sequence of four  | Sum of all 5  |\n");
	printf("|              |         dice        |  face values  |\n");
	printf("|--------------|---------------------|---------------|\n");

	system("pause");
	system("cls");
}

int validateMenu(void) { //Gets option and makes sure it is valid
	int num = 0, opt = 0;

	do {
		displayMenu();
		scanf("%d", &num);
		opt = num;
		
	} while (opt < RULES || opt > EXIT);

	return opt;
}

void rollDie(int *die) {

	srand(time(NULL));

	*die = (rand() % 6) + 1;
}

void displayScoreCard(int ones, int twos, int threes, int fours, int fives, int sixes, int sum, int bonus, int tOfAKind, int fOfAKind, int fullHouse, int smStr, int lgStr, int yahtz, int chance, int die1, int die2, int die3, int die4, int die5) {

	printf("|------------------------------|\n");
	printf("|    Player 1 Auto Scorecard   |\n");
	printf("|--------------|---------------|\n");
	printf("|     Kind     |     Score     |\n");
	printf("|--------------|---------------|\n");
	printf("|     Ones     |       %d       |\n", ones);
	printf("|--------------|---------------|\n");
	printf("|     Twos     |       %d       |\n", twos);
	printf("|--------------|---------------|\n");
	printf("|     Threes   |       %d       |\n", threes);
	printf("|--------------|---------------|\n");
	printf("|     Fours    |       %d       |\n", fours);
	printf("|--------------|---------------|\n");
	printf("|     Fives    |       %d       |\n", fives);
	printf("|--------------|---------------|\n");
	printf("|     Sixes    |       %d       |\n", sixes);
	printf("|------------- |---------------|\n");
	printf("|     Sum      |       %d       |\n", sum);
	printf("|--------------|---------------|\n");
	printf("|    Bonus     |       %d       |\n", bonus);
	printf("|--------------|---------------|\n");
	printf("| Three-of-a-  |       %d       |\n", tOfAKind);
	printf("|    kind      |               |\n");
	printf("|--------------|---------------|\n");
	printf("|  Four-of-a-  |       %d       |\n", fOfAKind);
	printf("|    kind      |               |\n");
	printf("|--------------|---------------|\n");
	printf("|  Full House  |       %d       |\n", fullHouse);
	printf("|--------------|---------------|\n");
	printf("|     Small    |       %d       |\n", smStr);
	printf("|   Straight   |               |\n");
	printf("|--------------|---------------|\n");
	printf("|     Large    |       %d       |\n", lgStr);
	printf("|   Straight   |               |\n");
	printf("|------------- |---------------|\n");
	printf("|   Yahtzee    |       %d       |\n", yahtz);
	printf("|--------------|---------------|\n");
	printf("|    Chance    |       %d       |\n", chance);
	printf("|------------------------------|\n");
	printf("|  Die 1 |  Die 2 |  Die 3 |  Die 4 |  Die 5 |\n");
	printf("|--------|--------|--------|--------|--------|\n");
	printf("|   %d    |   %d    |   %d    |   %d    |   %d    |\n", die1, die2, die3, die4, die5);
	printf("|--------------------------------------------|\n");

}

//Create functions that iterate through diceArray then returns true or false for set scores (full house, sm str) 
//create functions for the scores that vary that return the sums at that moment in the loop.

void calcOnes(int diceArr[], int* ones) {

	for (int i = 0; i < 5; i++) {
		if (diceArr[i] == 1) {
			*ones++;
		}
	}

}
void calcTwos(int diceArr[], int* twos) {
	int counter = 0;
	for (int i = 0; i < 5; i++) {
		if (diceArr[i] == 2) {
			counter++;
		}

	}
	*twos = counter * 2;
}


void calcThrees(int diceArr[], int* threes) {
	int counter = 0;
	for (int i = 0; i < 5; i++) {
		if (diceArr[i] == 2) {
			counter++;
		}

	}
	*threes = counter * 2;

}
void calcFours(int diceArr[], int* fours) {
	int counter = 0;
	for (int i = 0; i < 5; i++) {
		if (diceArr[i] == 2) {
			counter++;
		}

	}
	*fours = counter * 2;
}
void calcFives(int diceArr[], int* fives) {
	int counter = 0;
	for (int i = 0; i < 5; i++) {
		if (diceArr[i] == 2) {
			counter++;
		}

	}
	*fives = counter * 2;
}
void calcSixes(int diceArr[], int* sixes) {
	int counter = 0;
	for (int i = 0; i < 5; i++) {
		if (diceArr[i] == 2) {
			counter++;
		}

	}
	*sixes = counter * 2;
}
void calcSum(int ones, int twos, int threes, int fours, int fives, int sixes, int* sum) {
	*sum = ones + twos + threes + fours + fives + sixes;
}
void calcBonus(int sum, int* bonus) {
	if (sum >= 35) {
		*bonus = 35;
	}
	else {
		*bonus = 0;
	}
}
void calcThreeOfAKind(int diceArr[], int* tOfAKind);
void calcFourOfAKind(int diceArr[], int* fOfAKind);
void calcFullHouse(int diceArr[], int* fullHouse);
void calcSmStr(int diceArr[], int* smStr);
void calcLgStr(int diceArr[], int* lgStr);
void calcYahtzee(int diceArr[], int* yahtzee);
void sumChance(int diceArr[], int* chance);