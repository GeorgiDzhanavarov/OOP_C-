#include "upload.h"

void uploadData(Kindle& kindle) {
	std::ifstream inUser("users.txt", std::ios::in);

	if (inUser.is_open())
	{
		int users;
		char userN[100], userPass[100];
		size_t readC, writtenC;
		BookID* read, * written;

		inUser >> users;
		for (int i = 0; i < users; i++) {

			inUser >> userN;
			inUser >> userPass;
			inUser >> readC >> writtenC;
			read = new BookID[readC];
			written = new BookID[writtenC];
			for (int i = 0; i < readC; i++)
			{
				inUser >> read[i].id;
			}
			for (int i = 0; i < writtenC; i++)
			{
				inUser >> written[i].id;
			}

			User temp(userN, userPass, readC, writtenC, read, written);
			kindle.addUser(temp);
			delete[] read;
			delete[] written;

		}
	}

	inUser.close();

	std::ifstream inBook("books.txt", std::ios::in);

	if (inBook.is_open())
	{
		int books;
		char bookN[100], authorN[100], tmp[2000];
		size_t ratingC, commentC, pageC;
		BookID id;
		Rating* rating;
		Page* page;
		Comment* comment;
		inBook >> books;
		inBook.ignore(255, '\n');
		for (int i = 0; i < books; i++)
		{
			inBook.getline(bookN, 255);
			inBook >> authorN;
			inBook >> ratingC >> commentC >> pageC;
			inBook >> id.id;

			rating = new Rating[ratingC];
			for (int j = 0; j < ratingC; j++) {
				inBook >> rating[j].rating;
				inBook >> tmp;
				rating[j].author = new char[strlen(tmp) + 1];
				strcpy(rating[j].author, tmp);
			}

			page = new Page[pageC];
			for (int j = 0; j < pageC; j++) {
				inBook >> page[j].number;
				inBook.ignore(255, '\n');
				inBook.getline(tmp, 2000);
				page[j].text = new char[strlen(tmp) + 1];
				strcpy(page[j].text, tmp);
			}

			comment = new Comment[commentC];
			for (int j = 0; j < commentC; j++) {
				inBook >> tmp;
				comment[j].author = new char[strlen(tmp) + 1];
				strcpy(comment[j].author, tmp);
				inBook.ignore(255, '\n');
				inBook.getline(tmp, 2000);
				comment[j].comment = new char[strlen(tmp) + 1];
				strcpy(comment[j].comment, tmp);
			}

			Book result(bookN, authorN, ratingC, pageC, commentC, id, rating, page, comment);
			kindle.addBook(result);
			delete[] rating;
			delete[] page;
			delete[] comment;
		}
	}

	inBook.close();

}

bool strContain(const char* strOne, const char* strTwo)
{
	int strTwoLength = strlen(strTwo);

	bool flag = 1;

	for (int i = 0; i < strTwoLength; i++)
	{
		if (strOne[i] != strTwo[i])
			flag = 0;
	}

	return flag;
}