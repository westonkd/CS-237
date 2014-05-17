/*************************************************************************
* 
*************************************************************************/

#include <iostream>
#include "predicate.h"

using namespace std;

/**************************************************************
* The Predicate class is an abstract base class with pure 
* abstract functions (per the =0 suffix).
***************************************************************/
class Has : public Predicate
{

};

/**************************************************************
* Is this Predicate true for the given x and y?
***************************************************************/
bool isTrue(int x, int y) {
  return true;
}

/**************************************************************
* Is this Predicate false for the given x and y?
***************************************************************/
bool isFalse(int x, int y) {
  return true;
}

/**************************************************************
* Is this Predicate true for all x for all y
* in the supplied sets?
***************************************************************/
bool forAllForAll(int setX[], int sizeX, int setY[], int sizeY) 
{
  return true;
}

/**************************************************************
* Is this Predicate true for all x for some y
* in the supplied sets?
***************************************************************/
bool forAllForSome(int setX[], int sizeX, int setY[], int sizeY) 
{
  return true;
}

/**************************************************************
* Is this Predicate true for some x for all y
* in the supplied sets?
***************************************************************/
bool forSomeForAll(int setX[], int sizeX, int setY[], int sizeY) 
{
  return true;
}

/**************************************************************
* Is this Predicate true for some x for some y
* in the supplied sets?
***************************************************************/
bool forSomeForSome(int setX[], int sizeX, int setY[], int sizeY)
{
  return true;
}



int main() {
return 0;
}