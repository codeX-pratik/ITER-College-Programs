#include <stdio.h>

int main()
{
    int piels_inventory, coors_inventory, bud_inventory, iron_city_inventory;
    int brand_id, amount;

    printf("Enter the initial inventory for each brand:\n");
    printf("Piels (Brand ID 1): ");
    scanf("%d", &piels_inventory);
    printf("Coors (Brand ID 2): ");
    scanf("%d", &coors_inventory);
    printf("Bud (Brand ID 3): ");
    scanf("%d", &bud_inventory);
    printf("Iron City (Brand ID 4): ");
    scanf("%d", &iron_city_inventory);

    printf("\nEnter transactions (Brand ID followed by amount, e.g., 1 10 or 2 -5).\n");
    printf("Enter 0 0 to end transactions.\n");
    while (1)
    {
        printf("Transaction: ");
        scanf("%d %d", &brand_id, &amount);

        if (brand_id == 0 && amount == 0)
        {
            break;
        }

        if (brand_id < 1 || brand_id > 4)
        {
            printf("Invalid brand ID. Please enter a brand ID between 1 and 4.\n");
            continue;
        }

        switch (brand_id)
        {
        case 1:
            piels_inventory += amount;
            break;
        case 2:
            coors_inventory += amount;
            break;
        case 3:
            bud_inventory += amount;
            break;
        case 4:
            iron_city_inventory += amount;
            break;
        }

        if ((brand_id == 1 && piels_inventory < 0) ||
            (brand_id == 2 && coors_inventory < 0) ||
            (brand_id == 3 && bud_inventory < 0) ||
            (brand_id == 4 && iron_city_inventory < 0))
        {
            printf("Warning: Inventory for brand ID %d is negative!\n", brand_id);
        }
    }

    printf("\nFinal inventory:\n");
    printf("Piels (Brand ID 1): %d cases\n", piels_inventory);
    printf("Coors (Brand ID 2): %d cases\n", coors_inventory);
    printf("Bud (Brand ID 3): %d cases\n", bud_inventory);
    printf("Iron City (Brand ID 4): %d cases\n", iron_city_inventory);

    return 0;
}