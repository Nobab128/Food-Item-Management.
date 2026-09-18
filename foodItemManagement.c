

#include <stdio.h>
#include <string.h>

#define MAX 100


char names[MAX][50];
float prices[MAX];
int quantities[MAX];
int totalItems = 0;   
void addItem()
{
    if (totalItems >= MAX)
    {
        printf("\nList is full. Cannot add more items.\n");
        return;
    }

    printf("\nEnter item name: ");
    scanf(" %[^\n]", names[totalItems]);

    printf("Enter item price: ");
    scanf("%f", &prices[totalItems]);

    printf("Enter item quantity: ");
    scanf("%d", &quantities[totalItems]);

    totalItems++;

    printf("\nItem added successfully!\n");
}


void viewItems()
{
    if (totalItems == 0)
    {
        printf("\nNo items in the list.\n");
        return;
    }

    printf("\nNo.\tName\t\tPrice\tQuantity\n");
    printf("-------------------------------------------\n");

    int i;
    for (i = 0; i < totalItems; i++)
    {
        printf("%d\t%-15s\t%.2f\t%d\n", i + 1, names[i], prices[i], quantities[i]);
    }
}

void editItem()
{
    int index;

    viewItems();

    if (totalItems == 0)
        return;

    printf("\nEnter item number to edit: ");
    scanf("%d", &index);
    index = index - 1; 

    if (index < 0 || index >= totalItems)
    {
        printf("\nInvalid item number.\n");
        return;
    }

    printf("Enter new name: ");
    scanf(" %[^\n]", names[index]);

    printf("Enter new price: ");
    scanf("%f", &prices[index]);

    printf("Enter new quantity: ");
    scanf("%d", &quantities[index]);

    printf("\nItem updated successfully!\n");
}


void deleteItem()
{
    int index, i;

    viewItems();

    if (totalItems == 0)
        return;

    printf("\nEnter item number to delete: ");
    scanf("%d", &index);
    index = index - 1;

    if (index < 0 || index >= totalItems)
    {
        printf("\nInvalid item number.\n");
        return;
    }


    for (i = index; i < totalItems - 1; i++)
    {
        strcpy(names[i], names[i + 1]);
        prices[i] = prices[i + 1];
        quantities[i] = quantities[i + 1];
    }

    totalItems--;

    printf("\nItem deleted successfully!\n");
}


void calculateTotal()
{
    float total = 0;
    int i;

    for (i = 0; i < totalItems; i++)
    {
        total = total + (prices[i] * quantities[i]);
    }

    printf("\nTotal cost of all items: %.2f\n", total);
}

void saveToFile()
{
    char filename[50];
    int i;

    printf("\nEnter filename to save (example: list.txt): ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "w");

    if (fp == NULL)
    {
        printf("\nError opening file.\n");
        return;
    }

    fprintf(fp, "%d\n", totalItems);

    for (i = 0; i < totalItems; i++)
    {
        fprintf(fp, "%s\n%.2f\n%d\n", names[i], prices[i], quantities[i]);
    }

    fclose(fp);

    printf("\nFile saved successfully!\n");
}


void loadFromFile()
{
    char filename[50];
    int i;

    printf("\nEnter filename to load (example: list.txt): ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("\nFile not found.\n");
        return;
    }

    fscanf(fp, "%d", &totalItems);

    for (i = 0; i < totalItems; i++)
    {
        fscanf(fp, " %[^\n]", names[i]);
        fscanf(fp, "%f", &prices[i]);
        fscanf(fp, "%d", &quantities[i]);
    }

    fclose(fp);

    printf("\nFile loaded successfully!\n");
}


int main()
{
    int choice;

    while (1)
    {
        printf("\n===== FOOD ITEM MANAGEMENT SYSTEM =====\n");
        printf("1. Add a food item\n");
        printf("2. Edit a food item\n");
        printf("3. Delete a food item\n");
        printf("4. View all food items\n");
        printf("5. Calculate total cost\n");
        printf("6. Save food item list\n");
        printf("7. Load food item list\n");
        printf("8. Exit\n");
        printf("========================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addItem();
                break;
            case 2:
                editItem();
                break;
            case 3:
                deleteItem();
                break;
            case 4:
                viewItems();
                break;
            case 5:
                calculateTotal();
                break;
            case 6:
                saveToFile();
                break;
            case 7:
                loadFromFile();
                break;
            case 8:
                printf("\nExiting program. Thank you!\n");
                return 0;
            default:
                printf("\nInvalid choice. Try again.\n");
        }
    }

    return 0;
}