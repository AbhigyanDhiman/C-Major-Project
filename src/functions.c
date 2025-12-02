#include <stdio.h>
#include <string.h>
#include "library.h"

struct Book books[MAX];
struct Member members[MAX];
int bcount = 0, mcount = 0;

void addBook() {
    printf("Book ID: "); scanf("%d", &books[bcount].id);
    printf("Title: "); scanf(" %[^\n]", books[bcount].title);
    printf("Author: "); scanf(" %[^\n]", books[bcount].author);
    books[bcount].issued = 0;
    bcount++;
    printf("Book added.\n");
}

void addMember() {
    printf("Member ID: "); scanf("%d", &members[mcount].id);
    printf("Name: "); scanf(" %[^\n]", members[mcount].name);
    mcount++;
    printf("Member added.\n");
}

void searchBook() {
    char key[50]; int found = 0;
    printf("Search by Title/Author: ");
    scanf(" %[^\n]", key);

    for (int i = 0; i < bcount; i++) {
        if (strstr(books[i].title, key) || strstr(books[i].author, key)) {
            printf("ID: %d, %s by %s (%s)\n",
            books[i].id, books[i].title, books[i].author,
            books[i].issued ? "Issued" : "Available");
            found = 1;
        }
    }
    if (!found) printf("No match.\n");
}

void issueBook() {
    int id;
    printf("Book ID to issue: "); scanf("%d", &id);

    for (int i = 0; i < bcount; i++) {
        if (books[i].id == id) {
            if (!books[i].issued) {
                books[i].issued = 1;
                printf("Issued.\n");
            } else printf("Already issued.\n");
            return;
        }
    }
    printf("Not found.\n");
}

void returnBook() {
    int id;
    printf("Book ID to return: "); scanf("%d", &id);

    for (int i = 0; i < bcount; i++) {
        if (books[i].id == id) {
            if (books[i].issued) {
                books[i].issued = 0;
                printf("Returned.\n");
            } else printf("Not issued.\n");
            return;
        }
    }
    printf("Not found.\n");
}

void displayBooks() {
    for (int i = 0; i < bcount; i++)
        printf("ID:%d | %s | %s | %s\n",
               books[i].id, books[i].title,
               books[i].author,
               books[i].issued ? "Issued" : "Available");
}

void displayMembers() {
    for (int i = 0; i < mcount; i++)
        printf("ID:%d | %s\n", members[i].id, members[i].name);
}
