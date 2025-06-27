#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern Expense* expenses;
extern int expense_count;

void updateExpense() {
    int index;
    printf("Enter expense index to update (0 to %d): ", expense_count - 1);
    scanf("%d", &index);
    getchar();
    if (index >= 0 && index < expense_count) {
        char category[50], date[20];
        float amount;
        printf("Enter new category: ");
        fgets(category, sizeof(category), stdin);
        category[strcspn(category, "\n")] = 0;
        printf("Enter new amount: ");
        scanf("%f", &amount);
        getchar();
        printf("Enter new date: ");
        fgets(date, sizeof(date), stdin);
        date[strcspn(date, "\n")] = 0;
        strcpy(expenses[index].category, category);
        expenses[index].amount = amount;
        strcpy(expenses[index].date, date);
    } else {
        printf("Invalid index.\n");
    }
}

void deleteExpense() {
    int index;
    printf("Enter expense index to delete (0 to %d): ", expense_count - 1);
    scanf("%d", &index);
    if (index >= 0 && index < expense_count) {
        for (int i = index; i < expense_count - 1; i++) {
            expenses[i] = expenses[i + 1];
        }
        expense_count--;
        expenses = realloc(expenses, sizeof(Expense) * expense_count);
        printf("Expense deleted.\n");
    } else {
        printf("Invalid index.\n");
    }
}