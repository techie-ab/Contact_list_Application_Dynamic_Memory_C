#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[50];
    char phone[15];
} Contact;

void addContact(Contact **list, int *size, int *capacity);
void deleteContact(Contact *list, int *size);
void searchContact(Contact *list, int size);
void displayContacts(Contact *list, int size);

int main()
{
    Contact *contactList = NULL;
    int size = 0;
    int capacity = 0;
    int choice;
    do
    {
        printf("\nContact List Application\n");
        printf("1. Add Contact\n");
        printf("2. Delete Contact\n");
        printf("3. Search Contact\n");
        printf("4. Display All Contacts\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addContact(&contactList, &size, &capacity);
            break;
        case 2:
            deleteContact(contactList, &size);
            break;
        case 3:
            searchContact(contactList, size);
            break;
        case 4:
            displayContacts(contactList, size);
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);

    free(contactList);
    return 0;
}

void addContact(Contact **list, int *size, int *capacity)
{
    if (*size == *capacity)
    {
        *capacity = (*capacity == 0) ? 2 : (*capacity * 2);
        *list = realloc(*list, *capacity * sizeof(Contact));
        if (*list == NULL)
        {
            printf("Memory allocation failed!\n");
            exit(1);
        }
    }
    printf("Enter name: ");
    scanf("%s", (*list)[*size].name);
    printf("Enter phone: ");
    scanf("%s", (*list)[*size].phone);
    (*size)++;
    printf("Contact added successfully!\n");
}

void deleteContact(Contact *list, int *size)
{
    if (*size == 0)
    {
        printf("Contact list is empty!\n");
        return;
    }
    char name[50];
    printf("Enter the name of the contact to delete: ");
    scanf("%s", name);
    for (int i = 0; i < *size; i++)
    {
        if (strcmp(list[i].name, name) == 0)
        {
            for (int j = i; j < *size - 1; j++)
            {
                list[j] = list[j + 1];
            }
            (*size)--;
            printf("Contact deleted successfully!\n");
            return;
        }
    }
    printf("Contact not found!\n");
}


void searchContact(Contact *list, int size)
{
    if (size == 0)
    {
        printf("Contact list is empty!\n");
        return;
    }

    char name[50];
    printf("Enter the name of the contact to search: ");
    scanf("%s", name);

    for (int i = 0; i < size; i++)
    {
        if (strcmp(list[i].name, name) == 0)
        {
            printf("Contact found:\n");
            printf("Name: %s, Phone: %s\n", list[i].name, list[i].phone);
            return;
        }
    }
    printf("Contact not found!\n");
}

void displayContacts(Contact *list, int size)
{
    if (size == 0)
    {
        printf("Contact list is empty!\n");
        return;
    }

    printf("All Contacts:\n");
    for (int i = 0; i < size; i++)
    {
        printf("Name: %s, Phone: %s\n", list[i].name, list[i].phone);
    }
}
