/*This yahtzee will replicate the online version given in the directions. 
-Have a table that gives the different options on every roll. 
-The table must be updated after each roll. 
-Choose to hold die or pick the die you want rolled agian
*/




#ifndef YAHTZEE

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>


#define RULES 1
#define YAHTZEE 2
#define EXIT 3

void displayMenu(void);
void displayRules(void);
int menuChoice(void);
int validateMenu(void);
void rollDie(int *die);
void displayScoreCard(int ones, int twos, int threes, int fours, int fives, int sixes, int sum, int bonus, int tOfAKind, int fOfAKind, int fullHouse, int smStr, int lgStr, int yahtz, int chance, int die1, int die2, int die3, int die4, int die5);
void calcOnes(int diceArr[], int* ones);
void calcTwos(int diceArr[], int* twos);
void calcThrees(int diceArr[], int* threes);
void calcFours(int diceArr[], int* fours);
void calcFives(int diceArr[], int* fives);
void calcSixes(int diceArr[], int* sixes);
void calcSum(int ones, int twos, int threes, int fours, int fives, int sixes, int *sum); 
void calcBonus(int sum, int *bonus);
void calcThreeOfAKind(int diceArr[], int* tOfAKind);
void calcFourOfAKind(int diceArr[], int* fOfAKind);
void calcFullHouse(int diceArr[], int* fullHouse);
void calcSmStr(int diceArr[], int* smStr);
void calcLgStr(int diceArr[], int* lgStr);
void calcYahtzee(int diceArr[], int* yahtzee);
void sumChance(int diceArr[], int* chance);



#endif // !YAHTZEE

