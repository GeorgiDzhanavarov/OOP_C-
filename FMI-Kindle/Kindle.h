#pragma once
#include"Book.h"
#include"User.h"
#include <cstring>
#include<iostream>
#include<fstream>
#pragma warning (disable: 4996)

class Kindle {
private:
	User* users;
	Book* allBooks;
	size_t usersCount;
	size_t booksCount;
public:
	Kindle();
	Kindle(const Kindle&);
	Kindle& operator=(const Kindle&);
	~Kindle();
	void addUser(const User&);
	void addBook(const Book&);
	 User* findUser(const char* name,const char* pass) const;
	 void view() const;
	 void printBook(const char*) const;
	 const BookID& getID(const char*) const;
	 Book& findBook(const char* title) const;
	 void showComments(const char*) const;
	 void showRatings(const char*) const;
	 void printPage(const char*, int ) const;
	 bool freeID(int id) const;
	 void save() const;
	 bool isUserCorrect(const char*,const char*) const;
private:
	void free();
	void copy(const Kindle&);
};