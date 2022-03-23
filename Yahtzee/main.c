#include "yahtzee.h"

int main(void) {
	//Changing scorecard variables
	int ones = 0, twos = 0, threes = 0, fours = 0, fives = 0, sixes = 0, sum = 0, bonus = 0, 
		tOfAKind = 0, fOfAKind = 0, fullHouse = 0, smStr = 0, lgStr = 0, yahtz = 0, chance = 0;

	//Changing dice Variables
	int die1 = 0, die2 = 0, die3 = 0, die4 = 0, die5 = 0;

	srand(time(NULL));

	rollDie(&die1);
	printf("%d", die1);
	rollDie(&die2);
	printf("%d", die2);
	rollDie(&die3);	
	printf("%d", die3);
	rollDie(&die4);
	printf("%d", die4);
	rollDie(&die5);
	printf("%d", die5);

	//Dice Array
	int diceArr[5] = { die1, die2, die3, die4, die5 };


	calcOnes(diceArr, &ones);
	calcTwos(diceArr, &twos);
	calcThrees(diceArr, &threes);
	calcFours(diceArr, &fours);
	calcFives(diceArr, &fives);
	calcSixes(diceArr, &sixes);
	calcSum(ones, twos, threes, fours, fives, sixes, &sum);
	calcBonus(sum, &bonus);
	displayScoreCard(ones, twos, threes, fours, fives, sixes, sum, bonus, tOfAKind, fOfAKind, fullHouse, smStr, lgStr, yahtz, chance, die1, die2, die3, die4, die5);



	

}