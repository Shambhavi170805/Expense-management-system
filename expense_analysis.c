#include <stdio.h>

extern Expense* expenses;
extern int expense_count;

void showReports() {
    float total = 0;
    printf("\nAll Expenses:\n");
    for (int i = 0; i <expense_count; i++) {
        printf("%d. %s - %.2f - %s\n", i+1, expenses[i].category, expenses[i].amount, expenses[i].date);
        total += expenses[i].amount;
    }
    printf("Total Spent: %.2f\n", total);
}