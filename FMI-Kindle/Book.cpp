#include"Book.h"


// struct Comment
Comment::Comment() {
	comment = nullptr;
	author = nullptr;
}
Comment::Comment(const char* comment,const char* author) {
	this->comment = new char[strlen(comment) + 1];
	strcpy(this->comment,comment);

	this->author = new char[strlen(author) + 1];
	strcpy(this->author,author);
}

Comment::Comment(const Comment& temp) {
	copy(temp);
}
Comment& Comment::operator=(const Comment& temp) {
	if (this != &temp)
	{
		free();
		copy(temp);
	}
	return *this;
}
Comment::~Comment() {
	free();
}
void Comment::free() {
	delete[] comment;
	delete[] author;
}
void Comment::copy(const Comment& temp) {
	comment = new char[strlen(temp.comment) + 1];
	strcpy(comment, temp.comment);

	author = new char[strlen(temp.author) + 1];
	strcpy(author, temp.author);
}

// struct Page
Page::Page() {
	text = nullptr;
	number = 0;
}
Page::Page(const char* txt, size_t num) {
	text = new char[strlen(txt) + 1];
	strcpy(text, txt);
	number = num;
}
Page::Page(const Page& temp) {
	copy(temp);
}
Page& Page::operator=(const Page& temp) {
	if (this != &temp)
	{
		free();
		copy(temp);
	}
	return *this;
}
Page::~Page() {
	free();
}
void Page::free() {
	delete[] text;
}
void Page::copy(const Page& temp) {
	text = new char[strlen(temp.text) + 1];
	strcpy(text, temp.text);

	number = temp.number;
}

//class Book
Book::Book() {
	title = nullptr;
	authorName = nullptr;
	ratings = nullptr;
	pages = nullptr;
	comments = nullptr;
	pagesCount = 0;
	commentsCount = 0;
	ratingsCount = 0;
	id.id = 0;

}
Book::Book(const char* name, const char* aName, const Page* page ,size_t pCount,int id) {
	title = new char[strlen(name) + 1];
	strcpy(title, name);

	authorName = new char[strlen(aName) + 1];
	strcpy(authorName, aName);

	pages = new Page[pCount];
	for (int i = 0; i < pCount; i++) {
		pages[i] = page[i];
	}

	pagesCount = pCount;
	ratings = nullptr;
	comments = nullptr;
	commentsCount = 0;
	ratingsCount = 0;
	this->id.id = id;
}
Book::Book(const char* bookN, const char* authorN, size_t ratingC, size_t pageC, size_t commentC, const BookID id, const Rating* rating, const Page* page, const Comment* comm) {
	title = new char[strlen(bookN) + 1];
	strcpy(title, bookN);

	authorName = new char[strlen(authorN) + 1];
	strcpy(authorName, authorN);

	ratingsCount = ratingC;
	pagesCount = pageC;
	commentsCount = commentC;
	this->id = id;

	ratings = new Rating[ratingC];
	for (int i = 0; i < ratingC; i++) {
		ratings[i] = rating[i];
	}

	comments = new Comment[commentC];
	for (int i = 0; i < commentC; i++) {
		comments[i] = comm[i];
	}

	pages = new Page[pageC];
	for (int i = 0; i < pageC; i++) {
		pages[i] = page[i];
	}
}
Book::Book(const Book& temp) {
	copy(temp);

}
Book& Book::operator=(const Book& temp) {
	if (this != &temp)
	{
		free();
		copy(temp);
	}
	return *this;
}
Book::~Book() {
	free();
}

void Book::free() {
	delete[] title;
	delete[] authorName;
	delete[] pages;
	delete[] comments;
	delete[] ratings;

}
void Book::copy(const Book& temp) {
	title = new char[strlen(temp.title) + 1];
	strcpy(title, temp.title);
	authorName = new char[strlen(temp.authorName) + 1];
	strcpy(authorName, temp.authorName);

	pages = new Page[temp.pagesCount];
	pagesCount = temp.pagesCount;
	for (int i = 0; i < pagesCount; i++)
		pages[i] = temp.pages[i];
	
	comments = new Comment[temp.commentsCount];
	commentsCount = temp.commentsCount;
	for (int i = 0; i < commentsCount; i++)
		comments[i] = temp.comments[i];

	ratings = new Rating[temp.ratingsCount];
	ratingsCount = temp.ratingsCount;
	for (int i = 0; i < ratingsCount; i++)
		ratings[i] = temp.ratings[i];

	this->id.id = temp.id.id;

}

const char* Book::getPage(size_t page) const{
	if (page > pagesCount || page < 1)
		return "error";

	return pages[page - 1].text;
}

void Book::addComment(const Comment& temp) {
	commentsCount++;
	Comment* result = new Comment[commentsCount];
	for (int i = 0; i < commentsCount - 1; i++)
	{
		result[i] = comments[i];
	}
	result[commentsCount - 1] = temp;
	delete[] comments;
	comments = result;
}

const char* Book::getTitle() const {
	return title;
}

void Book::showComments() const {
	for (int i = 0; i < commentsCount; i++)
	{
		std::cout << comments[i].author << ": " << comments[i].comment << std::endl;
	}
	if (commentsCount == 0)
		std::cout << "no comments" << std::endl;
}

const BookID Book::getID() const {
	return id;
}

void Book::addPage(const char* temp) {

	Page* result = new Page[pagesCount + 1];
	for (int i = 0; i < pagesCount; i++)
	{
		result[i] = pages[i];
	}
	
	Page tmp(temp, pagesCount + 1);
	result[pagesCount] = tmp;
	pagesCount++;
	delete[] pages;
	pages = result;
}
void Book::deletePage() {
	pagesCount--;
}
void Book::editPage(const Page& temp) {
	for (int i = 0; i < pagesCount; i++)
	{
		if (temp.number == pages[i].number)
		{
			pages[i] = temp;
			break;
		}
	}
}
void Book::editTitle(const char* newTitle) {
	delete[] title;
	title = new char[strlen(newTitle) + 1];
	strcpy(title, newTitle);
}

void Book::addRating(const Rating& temp) {
	bool flag = true;

	for (int i = 0; i < ratingsCount; i++)
	{
		if (strcmp(ratings[i].author, temp.author) == 0)
		{
			ratings[i] = temp;
			flag = false;
			break;
		}
	}

	if (flag == true)
	{
		Rating* result = new Rating[ratingsCount + 1];
		for (int j = 0; j < ratingsCount; j++)
		{
			result[j] = ratings[j];
		}
		result[ratingsCount] = temp;
		ratingsCount++;
		delete[] ratings;
		ratings = result;
	}
}

void Book::print() const {
	for (int i = 0; i < pagesCount; i++) {
		std::cout << "page" << i + 1 << ": " << pages[i].text << std::endl;
	}
}

void Book::showRatings() const {
	for (int i = 0; i < ratingsCount; i++)
	{
		std::cout << ratings[i].author << ": " << ratings[i].rating << " / 10" << std::endl;
	}
	if (ratingsCount == 0)
		std::cout << "no ratings" << std::endl;
}

void Book::saveBook(std::ofstream& out) const {
	out << title;
	out << std::endl;
	out << authorName;
	out << std::endl;
	out << ratingsCount << " " << commentsCount << " " << pagesCount;
	out << std::endl;
	out << id.id;
	out << std::endl;

	for (int i = 0; i < ratingsCount; i++) {
		out << ratings[i].rating << std::endl << ratings[i].author << std::endl;
	}

	for (int i = 0; i < pagesCount; i++) {
		out << pages[i].number << std::endl << pages[i].text << std::endl;
	}

	for (int i = 0; i < commentsCount; i++) {
		out << comments[i].author << std::endl << comments[i].comment << std::endl;
	}
}

//BookID

bool BookID::operator==(const BookID& temp) {
	if (id = temp.id)
		return true;
	else
		return false;
}

// Rating

Rating::Rating() {
	rating = -1;
	author = nullptr;
}
Rating::Rating(int rate, const char* authorName) {
	rating = rate;
	author = new char[strlen(authorName) + 1];
	strcpy(author, authorName);
}
Rating::Rating(const Rating& temp) {
	copy(temp);
}
Rating& Rating::operator=(const Rating& temp) {
	if (this != &temp)
	{
		free();
		copy(temp);
	}
	return *this;
}
Rating::~Rating() {
	free();
}

void Rating::copy(const Rating& temp) {
	author = new char[strlen(temp.author) + 1];
	strcpy(author, temp.author);
	rating = temp.rating;
}
void Rating::free() {
	delete[] author;
}