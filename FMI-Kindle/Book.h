#pragma once
#include<cstring>
#include<iostream>
#include<fstream>
#pragma warning (disable: 4996)

struct Comment {
	char* comment;
	char* author;

	Comment();
	Comment(const char*,const char*);
	Comment(const Comment&);
	Comment& operator=(const Comment&);
	~Comment();
	void free();
	void copy(const Comment&);
};

struct Page {
	char* text;
	size_t number;

	Page();
	Page(const char*, size_t);
	Page(const Page&);
	Page& operator=(const Page&);
	~Page();
	void free();
	void copy(const Page&);
};

struct BookID {
	size_t id;
	bool operator==(const BookID&);
};

struct Rating {
	int rating;
	char* author;

	Rating();
	Rating(int, const char*);
	Rating(const Rating&);
	Rating& operator=(const Rating&);
	~Rating();
private:
	void copy(const Rating&);
	void free();

};

class Book {
private:
	char* title;
	char* authorName;
	Rating* ratings;
	Page* pages;
	Comment* comments;
	size_t pagesCount;
	size_t commentsCount;
	size_t ratingsCount;
	BookID id;
public:
	Book();
	Book(const char*, const char*, const Page*, size_t, int);
	Book(const char*, const char*, size_t, size_t,size_t,const BookID,const Rating*,const Page*,const Comment*);
	Book(const Book&);
	Book& operator=(const Book&);
	~Book();
	const char* getPage(size_t) const;
	void addComment(const Comment&);
	const char* getTitle() const;
	const BookID getID() const;
	void showComments() const;
	void addPage(const char*);
	void deletePage();
	void editPage(const Page&);
	void editTitle(const char*);
	void addRating(const Rating&);
	void print() const;
	void showRatings() const;
	void saveBook(std::ofstream&) const;
private:
	void free();
	void copy(const Book&);

};
