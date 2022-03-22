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
	int num = 0;
	for (int i = 0; i < 5; i++) {
		if (diceArr[i] == 1) {
			num++;
		}
	}
	*ones = num;

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
		if (diceArr[i] == 3) {
			counter++;
		}

	}
	*threes = counter * 3;

}
void calcFours(int diceArr[], int* fours) {
	int counter = 0;
	for (int i = 0; i < 5; i++) {
		if (diceArr[i] == 4) {
			counter++;
		}

	}
	*fours = counter * 4;
}
void calcFives(int diceArr[], int* fives) {
	int counter = 0;
	for (int i = 0; i < 5; i++) {
		if (diceArr[i] == 5) {
			counter++;
		}

	}
	*fives = counter * 5;
}
void calcSixes(int diceArr[], int* sixes) {
	int counter = 0;
	for (int i = 0; i < 5; i++) {
		if (diceArr[i] == 6) {
			counter++;
		}

	}
	*sixes = counter * 6;
}
void calcSum(int ones, int twos, int threes, int fours, int fives, int sixes, int* sum) {
	*sum = ones + twos + threes + fours + fives + sixes;
}
void calcBonus(int sum, int* bonus) {
	int theBonus = 0;
	if (sum >= 35) {
		theBonus = 35;
	}
	else {
		theBonus = 0;
	}
	*bonus = theBonus;
}


int addArr(int diceArr[]) {
	int total = 0;
	for (int i = 0; i < 4; i++) {
		total = diceArr[i] + diceArr[i + 1];
	}

	return total;
}

void calcThreeOfAKind(int diceArr[], int* tOfAKind) {
	bool present;
	
	for (int i = 0; i < 5; i++) {
		for (j = i; j < 14; j++) {
			if (diceArr[i] == diceArr[j + 1]) {
				present = true;
			}
			else {
				present = false;
			}
		}
	}
	if (present == true) {
		*tOfAKind = addArr(diceArr);
	}
}
void calcFourOfAKind(int diceArr[], int* fOfAKind) {
	int tempArr[] = diceArr;
	sort(tempArr, 5);
	if (tempArr[0] == tempArr[1] && tempArr[1] == tempArr[2] && tempArr[2] == tempArr[3]) {
			*fOfAKind == addArr(tempArr);
	}
	else if (tempArr[1] == tempArr[2] && tempArr[2] == tempArr[3] && tempArr[3] == tempArr[4]) {
		*fOfAKind = addArr(tempArr);
	}
	else {
		*fOfAKind = 0;
	}
}
void calcFullHouse(int diceArr[], int* fullHouse) {
	int tempArr[] = diceArr;
	sort(tempArr, 5);
	if (tempArr[1] == tempArr[2] && tempArr[3] == tempArr[4] && tempArr[4] == tempArr[5]) {
		*fullHouse = 25;
	}
	else if (tempArr[1] == tempArr[2] && tempArr[2] == tempArr[3] && tempArr[4] == tempArr[5]) {
		*fullHouse = 25;
	}
	else {
		*fullHouse = 0;
	}
}
void calcSmStr(int diceArr[], int* smStr) {
	int tempArr[] = diceArr;
	sort(tempArr, 5);
	if (tempArr[1] == tempArr[0] + 1 && tempArr[2] == tempArr[1] + 1 && tempArr[3] == tempArr[2] + 1) {
		*smStr = 30;
	}
	else {
		*smStr = 0;
	}
}
void calcLgStr(int diceArr[], int* lgStr) {
	int tempArr[] = diceArr;
	sort(tempArr, 5);
	if (tempArr[1] == tempArr[0] + 1 && tempArr[2] == tempArr[1] + 1 && tempArr[3] == tempArr[2] + 1 && tempArr[4] == tempArr[3] + 1) {
		*lgStr = 40;
	}
	else {
		*lgStr = 0;
	}
}
void calcYahtzee(int diceArr[], int* yahtzee) {
	int passes = 1;
	for (int i = 0; i <= 4; i++) {
		if (diceArr[i] == diceArr[i + 1]) {
			passes++;
		}
		else {
			*yahtzee = 0;
		}
	}
	if (passes == 4) {
		*yahtzee = 50;
	}
}


void sumChance(int diceArr[], int* chance) {
	*chance = addArr(diceArr);
}

int* sort(int list[], int size) {
	int index = 0, temp = 0, passes = 0;

	for (passes = 1; passes < size; ++passes)
	{
		for (index = 0; index < size - passes; ++index)
		{
			if (list[index] > list[index + 1])
			{
				temp = list[index];
				list[index] = list[index + 1];
				list[index + 1] = temp;
			}
		}
	}

	return list;
}

void updateScores(int diceArr[], int ones, int twos, int threes, int fours, int fives, int sixes, int sum, int bonus, int tOfAKind, int fOfAKind, int fullHouse, int smStr, int lgStr, int yahtz, int chance, int die1, int die2, int die3, int die4, int die5) {
	calcOnes(diceArr, ones);
	calcTwos(diceArr, twos);
	calcThrees(diceArr, threes);
	calcFours(diceArr, fours);
	calcFives(diceArr, fives);
	calcSixes(diceArr, sixes);
	calcSum(ones, twos, threes, fours, fives, sixes, &sum);
	calcBonus(sum, &bonus);
	calcThreeOfAKind(diceArr, tOfAKind);
	calcFourOfAKind(diceArr, fOfAKind);
	calcFullHouse(diceArr, fullHouse);
	calcSmStr(diceArr, smStr);
	calcLgStr(diceArr, lgStr);
	calcYahtzee(diceArr, yahtzee);
	s`umChance(diceArr, chance);
	displayScoreCard(ones, twos, threes, fours, fives, sixes, sum, bonus, tOfAKind, fOfAKind, fullHouse, smStr, lgStr, yahtz, chance, die1, die2, die3, die4, die5);
}