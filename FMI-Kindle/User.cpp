#include"User.h"

User::User() {
	username = nullptr;
	password = nullptr;
	readBooks = nullptr;
	writtenBooks = nullptr;
	readCount = 0;
	writtenCount = 0;
}
User::User(const char* name, const char* pass) {
	username = new char[strlen(name) + 1];
	strcpy(username, name);
	password = new char[strlen(pass) + 1];
	strcpy(password, pass);
	readBooks = nullptr;
	writtenBooks = nullptr;
	readCount = 0;
	writtenCount = 0;
}
User::User(const char* userN, const char* userPass, size_t readC, size_t writtenC,const BookID* read,const BookID* written) {
	username = new char[strlen(userN) + 1];
	strcpy(username, userN);
	password = new char[strlen(userPass) + 1];
	strcpy(password, userPass);

	readCount = readC;
	writtenCount = writtenC;

	readBooks = new BookID[readC];
	for (int i = 0; i < readC; i++) {
		readBooks[i] = read[i];
	}

	writtenBooks = new BookID[writtenC];
	for (int i = 0; i < writtenC; i++) {
		writtenBooks[i] = written[i];
	}
}
User::User(const User& temp) {
	copy(temp);
}
User& User::operator=(const User& temp) {
	if (this != &temp)
	{
		free();
		copy(temp);
	}
	return *this;
}
User::~User() {
	free();
}
void User::free() {
	delete[] username;
	delete[] password;
	delete[] readBooks;
	delete[] writtenBooks;
}
void User::copy(const User& temp) {
	username = new char[strlen(temp.username) + 1];
	strcpy(username, temp.username);
	password = new char[strlen(temp.password) + 1];
	strcpy(password, temp.password);

	readCount = temp.readCount;
	writtenCount = temp.writtenCount;

	readBooks = new BookID[temp.readCount];
	for (int i = 0; i < readCount; i++)
		readBooks[i] = temp.readBooks[i];

	writtenBooks = new BookID[temp.writtenCount];
	for (int i = 0; i < writtenCount; i++)
		writtenBooks[i] = temp.writtenBooks[i];

}

const char* User::getUsername() const {
	return username;
}
const char* User::getPassword() const {
	return password;
}

void User::read(const BookID temp) {
	readCount++;
	BookID* result = new BookID[readCount];

	for (int i = 0; i < readCount - 1; i++)
	{
		result[i] = readBooks[i];
	}

	result[readCount - 1] = temp;
	delete[] readBooks;
	readBooks = result;
}

void User::write(const BookID temp) {
	writtenCount++;
	BookID* result = new BookID[writtenCount];

	for (int i = 0; i < writtenCount - 1; i++)
	{
		result[i] = writtenBooks[i];
	}

	result[writtenCount - 1] = temp;
	delete[] writtenBooks;
	writtenBooks = result;
}

void User::viewPage(const Book& book, size_t page) const{
	std::cout << book.getPage(page) << std::endl;
}

void User::comment(Book& book, const Comment& comment) {

	bool flag = false;

	for (int i = 0; i < readCount; i++)
	{
		if (readBooks[i].id == book.getID().id)
		{
			book.addComment(comment);
			flag = true;
			break;
		}
	}
	
	if (flag == false)
		std::cout << "the book has not been read" << std::endl;
}

void User::readComments(const Book& temp) const {
	temp.showComments();
}

void User::rateBook(Book& book, const Rating& temp) {

	bool flag = false;


	for (int i = 0; i < readCount; i++)
	{
		if (readBooks[i].id == book.getID().id)
		{
			flag = true;
			break;
		}
	}

	for (int i = 0; i < writtenCount; i++)
	{
		if (writtenBooks[i].id == book.getID().id)
		{
			flag = false;
			break;
		}
	}

	if (flag == false)
		std::cout << "Error" << std::endl;
	else
		book.addRating(temp);
}

void User::addPage(Book& book,const char* temp) {
	
	bool flag = false;

	for (int i = 0; i < writtenCount; i++)
	{
		if (writtenBooks[i].id == book.getID().id)
		{
			book.addPage(temp);
			flag = true;
			break;
		}
	}
	
	if(flag == false)
		std::cout << "Error" << std::endl;
}
void User::deletePage(Book& book) {

	bool flag = false;

	for (int i = 0; i < writtenCount; i++)
	{
		if (writtenBooks[i].id == book.getID().id)
		{
			book.deletePage();
			flag = true;
			break;
		}
	}

	if (flag == false)
		std::cout << "Error" << std::endl;
	
}
void User::changePage(Book& book, const Page& temp) {

	bool flag = false;

	for (int i = 0; i < writtenCount; i++)
	{
		if (writtenBooks[i].id == book.getID().id)
		{
			book.editPage(temp);
			flag = true;
			break;
		}
	}

	if (flag == false)
		std::cout << "Error" << std::endl;
	
}
void User::changeTitle(Book& book, const char* temp) {

	bool flag = false;

	for (int i = 0; i < writtenCount; i++)
	{
		if (writtenBooks[i].id == book.getID().id)
		{
			book.editTitle(temp);
			flag = true;
			break;
		}
	}

	if (flag == false)
		std::cout << "Error" << std::endl;
	
}

void User::saveUser(std::ofstream& out) const{
	out << username;
	out << std::endl;
	out << password;
	out << std::endl;
	out << readCount << " " << writtenCount;
	out << std::endl;
	for (int i = 0; i < readCount; i++)
	{
		out << readBooks[i].id << " ";
	}
	for (int i = 0; i < writtenCount; i++)
	{
		out << writtenBooks[i].id << " ";
	}
	out << std::endl;
}