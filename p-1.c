#include <stdio.h>

int arr[100];
int n = 0;

// Create Array
void create()
{
    int i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

   
}

// Display Array
void display()
{
    int i;

    if(n == 0)
    {
        printf("Array is empty!\n");
        return;
    }

    printf("Array Elements: ");
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Insert Element at End
void insert()
{
    int value;

    if(n == 100)
    {
        printf("Array is Full!\n");
        return;
    }
else{
    printf("Enter value to insert: ");
    scanf("%d", &value);

    arr[n] = value;
    n++;

    printf("Element inserted successfully.\n");
}
}
// Delete Last Element
void deleteElement()
{
    if(n == 0)
    {
        printf("Array is Empty!\n");
        return;
    }

    n--;

    printf("Last element deleted successfully.\n");
}

// Search Element
void search()
{
    int key, i, found = 0;

    if(n == 0)
    {
        printf("Array is Empty!\n");
        return;
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    for(i = 0; i < n; i++)
    {
        if(arr[i] == key)
        {
            printf("Element found at position %d\n", i + 1);
            found = 1;
            break;
        }
    }

    if(found == 0)
    {
        printf("Element not found.\n");
    }
}

int main()
{
    int choice;

    while(1)
    {
        printf("\n===== ARRAY MENU =====\n");
        printf("1. Create Array\n");
        printf("2. Display Array\n");
        printf("3. Insert Element\n");
        printf("4. Delete Last Element\n");
        printf("5. Search Element\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                create();
                break;

            case 2:
                display();
                break;

            case 3:
                insert();
                break;

            case 4:
                deleteElement();
                break;

            case 5:
                search();
                break;

            case 6:
                printf("Exit\n");
                return 0;

            default:
                printf("Invalid Choice!\n");
        }
    }
}