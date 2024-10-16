#include <stdio.h>
#include <string.h>

// Function prototypes
void inputCustomerDetails(char *name, char *id, char *telephone, char *type, int *units);
float calculateAmount(const char *type, int units);
void displayBill(const char *name, const char *id, const char *telephone, const char *type, int units, float amount);

int main() {
    char customerName[50];
    char customerId[14];
    char telephone[11];
    char customerType[11];
    int units;
    float amount;

    // Input customer details
    inputCustomerDetails(customerName, customerId, telephone, customerType, &units);

    // Calculate amount based on customer type and units consumed
    amount = calculateAmount(customerType, units);

    // Output the bill details
    displayBill(customerName, customerId, telephone, customerType, units, amount);

    return 0;
}

void inputCustomerDetails(char *name, char *id, char *telephone, char *type, int *units) {

    while (1) {
        printf("Enter phone number (10 digits): ");
        scanf("%s", telephone);
        if (strlen(telephone) == 10 && strspn(telephone, "0123456789") == 10) {
            break; // Valid input
        } else {
            printf("Invalid phone number. Please enter exactly 10 digits.\n");
        }
    }

    while (1) {
        printf("Enter customer type (residential/industrial): ");
        scanf("%s", type);
        if (strcmp(type, "residential") == 0 || strcmp(type, "industrial") == 0) {
            break; // Valid input
        } else {
            printf("Invalid customer type. Please enter 'residential' or 'industrial'.\n");
        }
    }

    while (1) {
        printf("Enter units of water consumed (in cubic meters): ");
        scanf("%d", units);
        if (*units >= 0) {
            break; // Valid input
        } else {
            printf("Invalid number of units. Please enter a non-negative integer.\n");
        }
    }

    printf("Enter customer name: ");
    scanf("%s", name);

    while (1) {
        printf("Enter customer ID (13 digits): ");
        scanf("%s", id);
        if (strlen(id) == 13 && strspn(id, "0123456789012") == 13) {
            break; // Valid input
        } else {
            printf("Invalid customer ID. Please enter exactly 13 digits.\n");
        }
    }
}

float calculateAmount(const char *type, int units) {
    float amount = 0.0;

    if (strcmp(type, "residential") == 0) {
        if (units <= 100) {
            amount = units * 2.0; // Example residential rate: $2 per cubic meter for up to 100 units
        } else if (units <= 300) {
            amount = 100 * 2.0 + (units - 100) * 3.0; // $3 per cubic meter for units beyond 100
        } else {
            amount = 100 * 2.0 + 200 * 3.0 + (units - 300) * 5.0; // $5 per cubic meter beyond 300
        }
    } else if (strcmp(type, "industrial") == 0) {
        if (units <= 100) {
            amount = units * 3.5; // Example industrial rate: $3.5 per cubic meter for up to 100 units
        } else if (units <= 300) {
            amount = 100 * 3.5 + (units - 100) * 5.0; // $5 per cubic meter for units beyond 100
        } else {
            amount = 100 * 3.5 + 200 * 5.0 + (units - 300) * 7.0; // $7 per cubic meter beyond 300
        }
    }

    return amount;
}

void displayBill(const char *name, const char *id, const char *telephone, const char *type, int units, float amount) {
    printf("\nWater Bill\n");
    printf("----------------\n");
    printf("Customer Name: %s\n", name);
    printf("Customer ID: %s\n", id);
    printf("Phone Number: %s\n", telephone);
    printf("Customer Type: %s\n", type);
    printf("Units of Water Consumed (cubic meters): %d\n", units);
    printf("----------------\n");
    printf("Amount to be Paid: %.2f\n", amount);
    printf("Make payment at this Gpay ID: paymentpunecorporation@axisbank \n");
	printf("Your payment slip will be sent on your E-mail");
}
