/***********************************************************************
* Implementation File:
*    Book
* Author:
*    Weston Dransfield
* Summary: 
*    member functions of Book class
************************************************************************/

#include "book.h"

using namespace std;


/******************************************************
* Constructor to that sets the genre of a book
******************************************************/
Book::Book(Genre genre)
{
	//add the given genre to the book
	genres.push_back(genre);
}


/******************************************************
* default constructor initializes author and title
* to unknown
******************************************************/
Book::Book()
{
	//set the author and titles to defaults
	author = "unknown";
	title = "unknown";
}

/******************************************************
* sets the author
******************************************************/
void Book::setAuthor(std::string author)
{
	this->author = author;
}

/******************************************************
* gets the author
******************************************************/
std::string Book::getAuthor()
{
	return author;
}

/******************************************************
* sets the genre
******************************************************/
void Book::setGenre(Genre genre)
{
	//add the genre to the list
	genres.push_back(genre);
}

/******************************************************
* gets the genre
******************************************************/
Genre Book::getGenre(int index) 
{
		//make sure the index is in bounds
	if (index < genres.size()) 
	{
		return genres[index];
	}
}

/******************************************************
* sets the title
******************************************************/
void Book::setTitle(std::string title)
{
	this->title = title;
}

/******************************************************
* gets the title
******************************************************/
std::string Book::getTitle() 
{
	return title;
}
