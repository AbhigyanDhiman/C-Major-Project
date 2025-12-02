#ifndef LIBRARY_H
#define LIBRARY_H

#define MAX 100

struct Book {
    int id;
    char title[50];
    char author[50];
    int issued;
};

struct Member {
    int id;
    char name[50];
};

extern struct Book books[MAX];
extern struct Member members[MAX];
extern int bcount, mcount;

void addBook();
void addMember();
void searchBook();
void issueBook();
void returnBook();
void displayBooks();
void displayMembers();

#endif

