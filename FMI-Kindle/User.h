#pragma once
#include"Book.h"
#include<cstring>
#include<iostream>
#include<fstream>
#pragma warning (disable: 4996)

class User {
	char* username;
	char* password;
	BookID* readBooks;
	BookID* writtenBooks;
	size_t readCount;
	size_t writtenCount;
public:
	User();
	User(const char*, const char*);
	User(const char*, const char*,size_t,size_t,const BookID*,const BookID*);
	User(const User&);
	User& operator=(const User&);
	~User();
	const char* getUsername() const;
	const char* getPassword() const;
	void read(const BookID);
	void write(const BookID);
	void viewPage(const Book&, size_t) const;
	void comment(Book&, const Comment&);
	void readComments(const Book&) const;
	void addPage(Book&, const char*);
	void deletePage(Book&);
	void changePage(Book&, const Page&);
	void changeTitle(Book&,const char*);
	void rateBook(Book&, const Rating&);
	void saveUser(std::ofstream&) const;
private:
	void free();
	void copy(const User&);
};