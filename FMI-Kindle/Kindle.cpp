#include"Kindle.h"

Kindle::Kindle() {
	users = nullptr;
	allBooks = nullptr;
	usersCount = 0;
	booksCount = 0;
}
Kindle::Kindle(const Kindle& temp) {
	copy(temp);
}
Kindle& Kindle::operator=(const Kindle& temp) {
	if (this != &temp)
	{
		free();
		copy(temp);
	}
	return *this;
}
Kindle::~Kindle() {
	free();
}
void Kindle::free() {
	delete[] users;
	delete[] allBooks;
}
void Kindle::copy(const Kindle& temp) {
	usersCount = temp.usersCount;
	booksCount = temp.booksCount;

	users = new User[usersCount];
	for (int i = 0; i < usersCount; i++)
		users[i] = temp.users[i];

	allBooks = new Book[booksCount];
	for (int i = 0; i < booksCount; i++)
		allBooks[i] = temp.allBooks[i];
}

void Kindle::addUser(const User& temp) {

	User* result = new User[usersCount+1];
	for (int i = 0; i < usersCount; i++)
		result[i] = users[i];
	result[usersCount] = temp;
	usersCount++;
	delete[] users;
	users = result;
}

void Kindle::addBook(const Book& temp) {
	Book* result = new Book[booksCount + 1];

	if (booksCount > 0)
	{
		for (int i = 0; i < booksCount; i++)
		result[i] = allBooks[i];
	}
	
	result[booksCount] = temp;
	booksCount++;

	delete[] allBooks;

	allBooks = result;
}

User* Kindle::findUser(const char* name, const char* pass) const {
	for (int i = 0; i < usersCount; i++)
	{
		if (strcmp(users[i].getUsername(), name) == 0 && strcmp(users[i].getPassword(), pass) == 0)
		{
			return &users[i];
			break;
		}
	}
}

void Kindle::view() const {
	for (int i = 0; i < booksCount; i++) {
		std::cout << allBooks[i].getTitle() << std::endl;
	}
}

void Kindle::printBook(const char* title) const {
	for (int i = 0; i < booksCount; i++) {
		if (strcmp(allBooks[i].getTitle(), title) == 0)
		{
			allBooks[i].print();
			break;
		}
	}
}

const BookID& Kindle::getID(const char* title) const {
	for (int i = 0; i < booksCount; i++) {
		if (strcmp(allBooks[i].getTitle(), title) == 0)
		{
			return allBooks[i].getID();
		}
	}
}


void Kindle::showComments(const char* title) const{
	for (int i = 0; i < booksCount; i++)
	{
		if (strcmp(title, allBooks[i].getTitle()) == 0)
		{
			allBooks[i].showComments();
			break;
		}
	}
}

void Kindle::showRatings(const char* title) const {
	for (int i = 0; i < booksCount; i++)
	{
		if (strcmp(title, allBooks[i].getTitle()) == 0)
		{
			allBooks[i].showRatings();
			break;
		}
	}
}

void Kindle::printPage(const char* title, int num) const {
	for (int i = 0; i < booksCount; i++)
	{
		if (strcmp(title, allBooks[i].getTitle()) == 0)
		{
			std::cout << allBooks[i].getPage(num) << std::endl;
			break;
		}
	}
}

 Book& Kindle::findBook(const char* title) const {
	for (int i = 0; i < booksCount; i++)
	{
		if (strcmp(title, allBooks[i].getTitle()) == 0)
		{
			return allBooks[i];
			break;
		}
	}
}

 bool Kindle::freeID(int id) const {
	 for (int i = 0; i < booksCount; i++)
	 {
		 if (allBooks[i].getID().id == id)
		 {
			std::cout << "already used" << std::endl;
			return false;
		 }
			 
	 }

	 
	 return true;
 }

 void Kindle::save() const {
	 std::ofstream outUser("users.txt", std::ios::out);
	 if (!outUser.is_open())
	 {
		 std::cout << "file Error!" << std::endl;
	 }
	 outUser << usersCount;
	 outUser << std::endl;

	 for (int i = 0; i < usersCount; i++) {
		 users[i].saveUser(outUser);
	 }

	outUser.close();
	std::ofstream outBook("books.txt", std::ios::out);

	if (!outBook.is_open())
	{
		std::cout << "file Error!" << std::endl;
		
	}

	 outBook << std::endl;
	 outBook << booksCount << std::endl;

	 for (int i = 0; i < booksCount; i++) {
		 allBooks[i].saveBook(outBook);
	 }

 }

 bool Kindle::isUserCorrect(const char* userN, const char* userPass) const {
	 for (int i = 0; i < usersCount; i++)
	 {
		 if (strcmp(users[i].getUsername(),userN) == 0 && strcmp(users[i].getPassword(), userPass) == 0)
		 {
			 return true;
		 }

	 }

	 return false;
 }