#include <stdlib.h>
#include <string.h>

typedef struct {
    char category[50];
    float amount;
    char date[20];
} Expense;

Expense* expenses = NULL;
int expense_count = 0;

void createExpense(char* category, float amount, char* date) {
    expenses = realloc(expenses, sizeof(Expense) * (expense_count + 1));
    strcpy(expenses[expense_count].category, category);
    expenses[expense_count].amount = amount;
    strcpy(expenses[expense_count].date, date);
    expense_count++;
}