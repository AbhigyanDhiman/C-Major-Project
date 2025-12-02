#include <stdio.h>
#include "library.h"

int main() {
    int c;

    while (1) {
        printf("\n1.Add Book\n2.Add Member\n3.Search Book\n4.Issue Book\n5.Return Book\n6.Display Books\n7.Display Members\n8.Exit\nChoice: ");
        scanf("%d", &c);

        if (c == 1) addBook();
        else if (c == 2) addMember();
        else if (c == 3) searchBook();
        else if (c == 4) issueBook();
        else if (c == 5) returnBook();
        else if (c == 6) displayBooks();
        else if (c == 7) displayMembers();
        else if (c == 8) break;
        else printf("Invalid.\n");
    }

    return 0;
}

