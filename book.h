/***********************************************************************
* Header File:
*    Book
* Author:
*    Weston Dransfield
* Summary: 
*    definition of book class
************************************************************************/

#ifndef BOOK
#define BOOK

#include <iostream>
#include <string>
#include <vector>

enum Genre {
	ADVENTURE, BIOGRAPHY, FANTASY, FICTION, HISTORICAL_FICTION, MYSTERY, NON_FICTION, POETRY, SCI_FI
};


class Book {
public:
	//Constructor to initialize a book with a genre as a paramater
	Book(Genre genre);

	Book(Genre genre, std::string title, std::string author)
	{
		genres.push_back(genre);
		this->title = title;
		this->author = author;
	}

	Book();

	//Get the title of the book
	std::string getTitle();

	//set the title
	void setTitle(std::string title);

	//get the genres
	Genre getGenre(int index);

	//set the genre
	void setGenre(Genre genre);

	//get the author
	std::string getAuthor();

	//set the author
	void setAuthor(std::string author);

	//get the number of genres
	int getNumGenres() 
	{
		return genres.size();
	}
	
private:
	//vector to store the genres of the book
	std::vector<Genre> genres;

	//title of the book
	std::string title;

	//author name
	std::string author;
};

#endif