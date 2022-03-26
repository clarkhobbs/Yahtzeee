#include "yahtzee.h"

int main(void) {
	//Changing scorecard variables
	int ones = 0, twos = 0, threes = 0, fours = 0, fives = 0, sixes = 0, sum = 0, bonus = 0, 
		tOfAKind = 0, fOfAKind = 0, fullHouse = 0, smStr = 0, lgStr = 0, yahtz = 0, chance = 0;

	int total = sum + bonus + tOfAKind + fOfAKind + fullHouse + smStr + lgStr + yahtz + chance;

	//Changing dice Variables
	int die1 = 0, die2 = 0, die3 = 0, die4 = 0, die5 = 0;

	//diehold
	char hold1 = '\0', hold2 = '\0', hold3 = '\0', hold4 = '\0', hold5 = '\0';

	//Number of slots chosen
	int scoresFilledCounter = 0, scoreFillChoice = 0;

	//Different choice that need to be made
	int choice = 0;
	char diceChoice = '\0', tableChoice = '\0';

	//Number of rolls
	int rolls = 1;


	while (choice != EXIT) {
		switch (validateMenu()) {
		case RULES:
			displayRules();
			break;
		case YAHTZEE:
			srand(time(NULL));
			printf("Here is your scorecard!\n");
			for (int j = scoresFilledCounter; j < 13; j++) {
				rolls = 1;
				displayScoreCard(ones, twos, threes, fours, fives, sixes, sum, bonus, tOfAKind, fOfAKind, fullHouse, smStr, lgStr, yahtz, chance, die1, die2, die3, die4, die5);
				system("cls");
				//1st roll
				rollDie(&die1);
				rollDie(&die2);
				rollDie(&die3);
				rollDie(&die4);
				rollDie(&die5);

				//Dice Array
				int diceArr[5] = { die1, die2, die3, die4, die5 };

				printf("Here are the results of your first roll!\n");
				displayScoreCard(ones, twos, threes, fours, fives, sixes, sum, bonus, tOfAKind, fOfAKind, fullHouse, smStr, lgStr, yahtz, chance, die1, die2, die3, die4, die5);

				for (int i = rolls; i < 3; i++) {
					printf("Do you want to lock in a score on the table? y/n: \n");
					scanf(" %c", &tableChoice);
					if (tableChoice == 'y') {
						i = 4;
						committScore(&scoresFilledCounter, &scoreFillChoice);
						if (scoreFillChoice == 1) {
							calcOnes(diceArr, &ones);
						}
						else if (scoreFillChoice == 2) {
							calcTwos(diceArr, &twos);
						}
						else if (scoreFillChoice == 3) {
							calcThrees(diceArr, &threes);
						}
						else if (scoreFillChoice == 4) {
							calcFours(diceArr, &fours);
						}
						else if (scoreFillChoice == 5) {
							calcFives(diceArr, &fives);
						}
						else if (scoreFillChoice == 6) {
							calcSixes(diceArr, &sixes);
						}
						else if (scoreFillChoice == 7) {
							calcThreeOfAKind(diceArr, &tOfAKind);
						}
						else if (scoreFillChoice == 8) {
							calcFourOfAKind(diceArr, &fOfAKind);
						}
						else if (scoreFillChoice == 9) {
							calcFullHouse(diceArr, &fullHouse);
						}
						else if (scoreFillChoice == 10) {
							calcSmStr(diceArr, &smStr);
						}
						else if (scoreFillChoice == 11) {
							calcLgStr(diceArr, &lgStr);
						}
						else if (scoreFillChoice == 12) {
							calcYahtzee(diceArr, &yahtz);
						}
						else if (scoreFillChoice == 13) {
							sumChance(die1, die2, die3, die4, die5, &chance);
						}
						system("cls");
						displayScoreCard(ones, twos, threes, fours, fives, sixes, sum, bonus, tOfAKind, fOfAKind, fullHouse, smStr, lgStr, yahtz, chance, die1, die2, die3, die4, die5);
					}
					else {
						chooseDie(&hold1, &hold2, &hold3, &hold4, &hold5);
						i++;
						if (hold1 == 'y') {
							rollDie(&die1);
							if (hold2 == 'y') {
								rollDie(&die2);
								if (hold3 == 'y') {
									rollDie(&die3);
									if (hold4 == 'y') {
										rollDie(&die4);
										if (hold5 == 'y') {
											rollDie(&die5);
										}
									}
								}
							}
						}
					}
					system("cls");
					if (i != 4) {
						printf("Here are the results of your second roll!\n");
						displayScoreCard(ones, twos, threes, fours, fives, sixes, sum, bonus, tOfAKind, fOfAKind, fullHouse, smStr, lgStr, yahtz, chance, die1, die2, die3, die4, die5);
						printf("Do you want to lock in a score on the table? y/n: \n");
						scanf(" %c", &tableChoice);
						if (tableChoice == 'y') {
							i = 4;
							committScore(&scoresFilledCounter, &scoreFillChoice);
							if (scoreFillChoice == 1) {
								calcOnes(diceArr, &ones);
							}
							else if (scoreFillChoice == 2) {
								calcTwos(diceArr, &twos);
							}
							else if (scoreFillChoice == 3) {
								calcThrees(diceArr, &threes);
							}
							else if (scoreFillChoice == 4) {
								calcFours(diceArr, &fours);
							}
							else if (scoreFillChoice == 5) {
								calcFives(diceArr, &fives);
							}
							else if (scoreFillChoice == 6) {
								calcSixes(diceArr, &sixes);
							}
							else if (scoreFillChoice == 7) {
								calcThreeOfAKind(diceArr, &tOfAKind);
							}
							else if (scoreFillChoice == 8) {
								calcFourOfAKind(diceArr, &fOfAKind);
							}
							else if (scoreFillChoice == 9) {
								calcFullHouse(diceArr, &fullHouse);
							}
							else if (scoreFillChoice == 10) {
								calcSmStr(diceArr, &smStr);
							}
							else if (scoreFillChoice == 11) {
								calcLgStr(diceArr, &lgStr);
							}
							else if (scoreFillChoice == 12) {
								calcYahtzee(diceArr, &yahtz);
							}
							else if (scoreFillChoice == 13) {
								sumChance(die1, die2, die3, die4, die5, &chance);
							}
							system("cls");
							displayScoreCard(ones, twos, threes, fours, fives, sixes, sum, bonus, tOfAKind, fOfAKind, fullHouse, smStr, lgStr, yahtz, chance, die1, die2, die3, die4, die5);
						}
						else {
							chooseDie(&hold1, &hold2, &hold3, &hold4, &hold5);
							i++;
							if (hold1 == 'y') {
								rollDie(&die1);
								if (hold2 == 'y') {
									rollDie(&die2);
									if (hold3 == 'y') {
										rollDie(&die3);
										if (hold4 == 'y') {
											rollDie(&die4);
											if (hold5 == 'y') {
												rollDie(&die5);
											}
										}
									}
								}
							}
						}
						system("cls");
						if (i != 4) {
							printf("Here are the results of your third and final roll!\n");
							displayScoreCard(ones, twos, threes, fours, fives, sixes, sum, bonus, tOfAKind, fOfAKind, fullHouse, smStr, lgStr, yahtz, chance, die1, die2, die3, die4, die5);
							committScore(&scoresFilledCounter, &scoreFillChoice);
							if (scoreFillChoice == 1) {
								calcOnes(diceArr, &ones);
							}
							else if (scoreFillChoice == 2) {
								calcTwos(diceArr, &twos);
							}
							else if (scoreFillChoice == 3) {
								calcThrees(diceArr, &threes);
							}
							else if (scoreFillChoice == 4) {
								calcFours(diceArr, &fours);
							}
							else if (scoreFillChoice == 5) {
								calcFives(diceArr, &fives);
							}
							else if (scoreFillChoice == 6) {
								calcSixes(diceArr, &sixes);
							}
							else if (scoreFillChoice == 7) {
								calcThreeOfAKind(diceArr, &tOfAKind);
							}
							else if (scoreFillChoice == 8) {
								calcFourOfAKind(diceArr, &fOfAKind);
							}
							else if (scoreFillChoice == 9) {
								calcFullHouse(diceArr, &fullHouse);
							}
							else if (scoreFillChoice == 10) {
								calcSmStr(diceArr, &smStr);
							}
							else if (scoreFillChoice == 11) {
								calcLgStr(diceArr, &lgStr);
							}
							else if (scoreFillChoice == 12) {
								calcYahtzee(diceArr, &yahtz);
							}
							else if (scoreFillChoice == 13) {
								sumChance(die1, die2, die3, die4, die5, &chance);
							}
						}
						system("cls");
						displayScoreCard(ones, twos, threes, fours, fives, sixes, sum, bonus, tOfAKind, fOfAKind, fullHouse, smStr, lgStr, yahtz, chance, die1, die2, die3, die4, die5);
						printf("Continue to next series of rolls!\n");
						system("cls");
					}
				}
			}
			printf("You finished with a score of %d!", total);

			break;
		case EXIT:
			choice = EXIT;
			break;
		default:
			validateMenu();
		}
		
	}

	return 0;


}