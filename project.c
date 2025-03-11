#include <stdio.h>
#include <string.h>

char username[] = "sachin";
char password[] = "12345";
float balance = 1000.0;

int login() {
    char uname[20], pass[20];
    int attempts = 0;

    while (attempts < 3) {
        printf("\nEnter username: ");
        scanf("%s", uname);
        printf("Enter password: ");
        scanf("%s", pass);

        if (strcmp(username, uname) == 0 && strcmp(password, pass) == 0) {
            return 1;
        }

        attempts++;
        printf("Invalid username or password! Attempts left: %d\n", 3 - attempts);
    }

    printf("Too many failed attempts! Exiting...\n");
    return 0;
}

void deposit() {
    float amount;
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);

    if (amount > 0) {
        balance += amount;
        printf("Deposit successful! New balance: %.2f\n", balance);
    } else {
        printf("Invalid amount!\n");
    }
}

void withdraw() {
    float amount;
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);

    if (amount > 0 && amount <= balance) {
        balance -= amount;
        printf("Withdrawal successful! New balance: %.2f\n", balance);
    } else {
        printf("Invalid amount or insufficient balance!\n");
    }
}

void checkBalance() {
    printf("Your current balance is: %.2f\n", balance);
}

int main() {
    int choice;

    if (!login()) {
        return 0;
    }

    printf("Login successful!\n");

    while (1) {
        printf("\n1. Deposit Money\n2. Withdraw Money\n3. Check Balance\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                deposit();
                break;
            case 2:
                withdraw();
                break;
            case 3:
                checkBalance();
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

