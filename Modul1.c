//2702309315 - AGATHA LOUISA WIJAYANI

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXDATA 4

struct Medicine {
    char code[7];
    char nama[30];
    char penyakit[20];
    int stock;
    int harga;
};

// Function prototypes
void addStock(struct Medicine obat[]);
void sellMedicine(struct Medicine obat[]);

int main() {
    struct Medicine obat[MAXDATA];

    // data medicine
    strcpy(obat[0].code, "DIZ001");
    strcpy(obat[0].nama, "Paramex");
    strcpy(obat[0].penyakit, "Dizziness");
    obat[0].stock = 120;
    obat[0].harga = 14000;

    strcpy(obat[1].code, "FLU001");
    strcpy(obat[1].nama, "Panadol");
    strcpy(obat[1].penyakit, "Flu & Fever");
    obat[1].stock = 57;
    obat[1].harga = 8000;

    strcpy(obat[2].code, "DIA001");
    strcpy(obat[2].nama, "Diatabs");
    strcpy(obat[2].penyakit, "Diarrhea");
    obat[2].stock = 10;
    obat[2].harga = 6500;

    strcpy(obat[3].code, "DIA002");
    strcpy(obat[3].nama, "Diapet");
    strcpy(obat[3].penyakit, "Diarrhea");
    obat[3].stock = 18;
    obat[3].harga = 6000;


    int choice;

    do {
        // tampilan menu
        printf("\n                                  +------------------------+\n");
        printf("\n                                  |     SUNIB Hospital     |\n");
        printf("\n                                  +------------------------+\n");
        printf("+------------------------------------------------------------------------------------------------+\n");
        printf("| No. | Medicine Code   | Medicine Name           | Disease           | Stock  | Price           |\n");
        printf("+------------------------------------------------------------------------------------------------+\n");
        for (int i = 0; i < MAXDATA; i++) {
            printf("| 0%d. | %-15s | %-23s | %-17s | %-6d |  Rp. %d.%03d,-\t |\n",
                   i + 1, obat[i].code, obat[i].nama, obat[i].penyakit, obat[i].stock, obat[i].harga / 1000, obat[i].harga % 1000);
        }
        printf("+------------------------------------------------------------------------------------------------+\n");

        // tampilan menu
        printf("\nMenu :\n");
        printf("[1.] Add Stock\n");
        printf("[2.] Sell\n");
        printf("[3.] Exit\n\n");
        printf("Input Choice [1-3]: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStock(obat);
                break;
            case 2:
                sellMedicine(obat);
                break;
            case 3:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please choose again.\n");
        }
    } while (choice != 3);

    return 0;
}

void addStock(struct Medicine obat[]) {
    char inputCode[7];
    int quantity;

    // meminta user untuk memasukkan kode medicine
    printf("Enter Medicine Code: ");
    scanf("%s", inputCode);

    // Validate medicine code
    int found = 0;
    int index = -1;
    for (int i = 0; i < MAXDATA; i++) {
        if (strcmp(obat[i].code, inputCode) == 0) {
            found = 1;
            index = i;
            break;
        }
    }

    if (!found) {
        printf("Medicine Code Doesn't Exist!\n");
        return;
    }

    // meminta user untuk memasukkan quantity
    printf("Enter the quantity (1-100): ");
    scanf("%d", &quantity);

    // Validate quantity
    if (quantity < 1 || quantity > 100) {
        printf("Invalid quantity. Please enter a quantity between 1 and 100.\n");
        return;
    }

    // Add stock
    obat[index].stock += quantity;

    printf("Stock added successfully. Press Enter to continue...\n");
    getchar();  
    getchar();  
}

void sellMedicine(struct Medicine obat[]) {
    char inputCode[7];
    int quantity;

    // meminta user untuk memasukkan kode medicine
    printf("Enter Medicine Code you want to sell: ");
    scanf("%s", inputCode);

    // Validate medicine code
    int found = 0;
    int index = -1;
    for (int i = 0; i < MAXDATA; i++) {
        if (strcmp(obat[i].code, inputCode) == 0) {
            found = 1;
            index = i;
            break;
        }
    }

    if (!found) {
        printf("Medicine Code Doesn't Exist!\n");
        return;
    }

    // meminta user untuk memasukkan quantity
    printf("Enter the quantity (1-%d): ", obat[index].stock);
    scanf("%d", &quantity);

    // Validate quantity
    if (quantity < 1 || quantity > obat[index].stock) {
        printf("Invalid quantity. Please enter a quantity between 1 and %d.\n", obat[index].stock);
        return;
    }

    // Calculate total price
    int totalPrice = quantity * obat[index].harga;

    // Update stock
    obat[index].stock -= quantity;
    printf("+----Total Price----+\n");
    printf("Total price: Rp. %d.%03d,-\n", totalPrice / 1000, totalPrice % 1000);
    printf("+-------------------+\n");

}
