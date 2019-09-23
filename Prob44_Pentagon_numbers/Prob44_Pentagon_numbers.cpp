// Prob44_Pentagon_numbers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

constexpr auto maxn = 10000;;

int main()
{
	unsigned long int P[maxn];
	unsigned long int sum, diff;
	int i,j, pentagonal,cursor, stilllooking = 1;
	for (i = 1; i < maxn; i++)
		P[i] = i * (3 * i - 1) / 2;
	for(i = 1; stilllooking && i < maxn - 1; i++)
		for (j = i + 1; stilllooking && j < maxn; j++)
		{
			sum = P[i] + P[j];
			diff = abs( (long) P[j] - (long) P[i]);
			pentagonal = 1; //true
			cursor = 1;
			while (P[cursor] < diff) cursor++;
			pentagonal = pentagonal && P[cursor] == diff;
			cursor = j;
			while (pentagonal && P[cursor] < sum && cursor < maxn) cursor++;
			pentagonal = pentagonal && P[cursor] == sum;
			if (pentagonal)
			{
				printf("\n[%ld] %ld [%ld] %ld Sum = %ld Diff = %ld", i, P[i], j, P[j], sum, diff);
				stilllooking = 0;
			}
		}
	printf("\nHello World!");
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
