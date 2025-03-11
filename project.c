#include <stdio.h>

char bookTitle[50];
char bookAuthor[50];
int isBorrowed = 0;

void addBook() {
    printf("\nEnter book title: ");
    scanf(" %[^\n]", bookTitle);
    
    printf("Enter author name: ");
    scanf(" %[^\n]", bookAuthor);
    
    isBorrowed = 0;
    printf("\nBook added successfully!\n");
}

void borrowBook() {
    if (isBorrowed) {
        printf("\nThis book is already borrowed.\n");
    } else {
        isBorrowed = 1;
        printf("\nYou borrowed '%s' by %s.\n", bookTitle, bookAuthor);
    }
}

void returnBook() {
    if (!isBorrowed) {
        printf("\nNo book is currently borrowed.\n");
    } else {
        isBorrowed = 0;
        printf("\nBook returned successfully!\n");
    }
}

void checkStatus() {
    printf("\nBook: %s\nAuthor: %s\n", bookTitle, bookAuthor);
    if (isBorrowed) {
        printf("Status: Borrowed\n");
    } else {
        printf("Status: Available\n");
    }
}

int main() {
    int choice;
    
    while (1) {
        printf("\nLibrary Management System\n");
        printf("1. Add a Book\n2. Borrow a Book\n3. Return a Book\n4. Check Book Status\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            addBook();
        } else if (choice == 2) {
            borrowBook();
        } else if (choice == 3) {
            returnBook();
        } else if (choice == 4) {
            checkStatus();
        } else if (choice == 5) {
            printf("\nExiting...\n");
            break;
        } else {
            printf("\nInvalid choice. Try again.\n");
        }
    }
    
    return 0;
}

