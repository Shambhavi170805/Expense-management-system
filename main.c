#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "auth.c"
#include "expense_data.c"
#include "expense_operations.c"
#include "expense_analysis.c"
#include "file_operations.c"

int main() {
    if (!authenticateUser()) {
        printf("Authentication failed. Exiting.\n");
        return 1;
    }

    int choice;
    char category[50], date[20];
    float amount;

    loadExpenses();

    do {
        printf("\nExpense Management System\n");
        printf("1. Add Expense\n2. Update Expense\n3. Delete Expense\n4. View Reports\n5. Save & Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Enter category: ");
                fgets(category, sizeof(category), stdin);
                category[strcspn(category, "\n")] = 0;
                printf("Enter amount: ");
                scanf("%f", &amount);
                getchar();
                printf("Enter date (DD-MM-YYYY): ");
                fgets(date, sizeof(date), stdin);
                date[strcspn(date, "\n")] = 0;
                createExpense(category, amount, date);
                break;
            case 2:
                updateExpense();
                break;
            case 3:
                deleteExpense();
                break;
            case 4:
                showReports();
                break;
            case 5:
                saveExpenses();
                printf("Data saved. Exiting.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}