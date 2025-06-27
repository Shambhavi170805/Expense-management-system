#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern Expense* expenses;
extern int expense_count;
void createExpense(char*, float, char*);

void saveExpenses() {
    FILE* f = fopen("expenses.txt", "w");
    for (int i = 0; i < expense_count; i++) {
        fprintf(f, "%s,%f,%s\n", expenses[i].category, expenses[i].amount, expenses[i].date);
    }
    fclose(f);
}

void loadExpenses() {
    FILE* f = fopen("expenses.txt", "r");
    if (!f) return;
    char line[100];
    while (fgets(line, sizeof(line), f)) {
        char category[50], date[20];
        float amount;
        sscanf(line, "%[^,],%f,%[^\n]", category, &amount, date);
        createExpense(category, amount, date);
    }
    fclose(f);
}