/*************************************************************************
* 
*************************************************************************/

#include <iostream>
#include "predicate.h"
#include "book.h"

using namespace std;

/**************************************************************
* The Predicate class is an abstract base class with pure 
* abstract functions (per the =0 suffix).
***************************************************************/
class IsOfGenre : public Predicate
{
public:

	bool isGenre(int GenreX, int GenreY);

    bool isTrue(int x, int y) {
    	return isGenre(x,y);
    }

    bool isFalse(int x, int y)
    {
    	return !isGenre(x,y);
    }

	bool forAllForAll(int setX[], int sizeX, int setY[], int sizeY);

	bool forAllForSome(int setX[], int sizeX, int setY[], int sizeY);

	bool forSomeForAll(int setX[], int sizeX, int setY[], int sizeY);

	bool forSomeForSome(int setX[], int sizeX, int setY[], int sizeY);
};
