/***********************************************************************
* Implementation File:
*    IsOfGenre
* Author:
*    Weston Dransfield
* Summary: 
*    member functions of IsOfGenre class
************************************************************************/

#include "pq.h"
#include <iostream>
#include <iomanip>

using namespace std;

bool IsOfGenre::isGenre(int GenreX, int GenreY) 
{
	return GenreX == GenreY;
}

/**************************************************************
* Is this Predicate true for all x for all y
* in the supplied sets?
***************************************************************/
bool IsOfGenre::forAllForAll(int setX[], int sizeX, int setY[], int sizeY) 
{
	for (int i = 0; i < sizeX; i++)
	{
		for (int j = 0; j < sizeY; j++)
		{
			//if we find one that does not match, stop!
			if (!isGenre(setX[i], setY[j]))
				return false;
		}
	}

	//all x for all y was true!
	return true;
}

/**************************************************************
* Is this Predicate true for all x for some y
* in the supplied sets?
***************************************************************/
bool IsOfGenre::forAllForSome(int setX[], int sizeX, int setY[], int sizeY) 
{
	for (int i = 0; i < sizeX; i++)
	{
		for (int j = 0; j < sizeY; j++)
		{
			//if we find one match, we don't need to check more
			if (isGenre(setX[i], setY[j]))
				break;

			//if we made it though all genres with no success
			if (sizeY - 1 == j)
				return false;
		}
	}

	//for all for some is true!
	return true;
}

/**************************************************************
* Is this Predicate true for some x for all y
* in the supplied sets?
***************************************************************/
bool IsOfGenre::forSomeForAll(int setX[], int sizeX, int setY[], int sizeY) 
{
	//var to help us keep track if all ys were true for the given x
	bool trueForAll;

	for (int i = 0; i < sizeX; i++)
	{
		trueForAll = true;

		for (int j = 0; j < sizeY; j++)
		{
			//if we find one y that does not match the x
			if (!isGenre(setX[i], setY[j]))
			{
				trueForAll = false;
			}
		}
		//if one was true for each y
		if (trueForAll)
			return true;
	}

	//we did not find an x for which all ys were true
	return false;
}

/**************************************************************
* Is this Predicate true for some x for some y
* in the supplied sets?
***************************************************************/
bool IsOfGenre::forSomeForSome(int setX[], int sizeX, int setY[], int sizeY)
{
	for (int i = 0; i < sizeX; i++)
	{
		for (int j = 0; j < sizeY; j++)
		{
			//if we have a matching genre
			if (isGenre(setX[i], setY[j]))
				return true;
		}
	}

	//There was not a single x for which a matching y was found
	return false;
}


/**************************************************************
* main
* Here we will test out our nifty new prediacte, IsOfGenre
* and display the results!
***************************************************************/
int main() {
	//our shiney new predicate
	IsOfGenre genreTester;

	//make some books
	Book wayOfKings(FANTASY, "The Way of Kings", "Brandon Sanderson");
	Book theBookThief(HISTORICAL_FICTION, "The Book Thief", "Markus Zusak");
	Book infAndMind(NON_FICTION, "Infinity and the Mind", "Rudy Rucker");
	Book heirToEmpire(SCI_FI, "Heir to the Empire", "Timothy Zahn");

	//create arrays of genres to test against each other
	int genres[5] = {FANTASY, HISTORICAL_FICTION, NON_FICTION, SCI_FI, POETRY};

	int bookGenres[4] = {
		wayOfKings.getGenre(0),
		theBookThief.getGenre(0),
		infAndMind.getGenre(0),
		heirToEmpire.getGenre(0)
	};

	//begin the testing starting with for all for all
	cout << "genreTeser.forAllForAll(bookGenres, 4, genres, 5)\n"
	<< "\texpecting false\n"
	<< "\t" << boolalpha << genreTester.forAllForAll(bookGenres, 4, genres, 5);

	//for all for some
	cout << "\n\ngenreTeser.forAllForSome(bookGenres, 4, genres, 5)\n"
	<< "\texpecting true\n"
	<< "\t" << boolalpha << genreTester.forAllForSome(bookGenres, 4, genres, 5);

	//for all for some
	cout << "\n\ngenreTeser.forAllForSome(bookGenres, 4, genres, 5)\n"
	<< "\texpecting true\n"
	<< "\t" << boolalpha << genreTester.forAllForSome(bookGenres, 4, genres, 5);

	//for some for all
	cout << "\n\ngenreTeser.forSomeForAll(bookGenres, 4, genres, 5)\n"
	<< "\texpecting false\n"
	<< "\t" << boolalpha << genreTester.forSomeForAll(bookGenres, 4, genres, 5);

	//for some for some
	cout << "\n\ngenreTeser.forSomeForSome(bookGenres, 4, genres, 5)\n"
	<< "\texpecting true\n"
	<< "\t" << boolalpha << genreTester.forSomeForSome(bookGenres, 4, genres, 5) << endl;
}
