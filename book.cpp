/******************************************************
*
******************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum Genre {
	ADVENTURE, BIOGRAPHY, FANTASY, FICTION, HISTORICAL_FICTION, MYSTERY, NON_FICTION, POETRY, SCI_FI
};


class Book {
public:
	Book();
	~Book():

private:
	vector<Genre> genres;
};

Book::Book() {

}

Book::~Book() {

}

int main() {
	return 0;
}