#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _CRT_SECURE_NO_WARNINGS
#define MAX_IG_LENGTH 30
#define MAX_CONTACTS 10

typedef struct {
    char name[MAX_CONTACTS][MAX_IG_LENGTH + 1];
    char id[MAX_CONTACTS][MAX_IG_LENGTH + 1];
    size_t size;
} WhitePages;

void saveNameIG(WhitePages* whitePages);
void findID(const WhitePages* whitePages);
void findName(const WhitePages* whitePages);
void removeContact(WhitePages* whitePages);

int main(void) {
    WhitePages whitePages = { {""}, {""}, 0 };
    int nums;
    int i;

    do {
    printf("Select code.\n");
    printf("1: Save ID and name.\n");
    printf("2: Find ID.\n");
    printf("3: Find name.\n");
    printf("4: Remove contact\n");
    scanf("%d", &nums);


        switch (nums) {
        case 1:
            saveNameIG(&whitePages);
            break;
        case 2:
            findID(&whitePages);
            break;
        case 3:
            findName(&whitePages);
            break;
        case 4:
            removeContact(&whitePages);
            break;
        default:
            printf("Error: Invalid code!\n");
            break;
        }
    } while (i = !0);
    return 0;
}

void saveNameIG(WhitePages* whitePages) {
    if (whitePages->size < MAX_CONTACTS) {
        printf("Insert ID and name.\n");
        printf("ID: ");
        scanf("%s", whitePages->id[whitePages->size]);

        printf("Name: ");
        scanf("%s", whitePages->name[whitePages->size]);

        whitePages->size++;
        printf("Contact saved successfully!\n");
    }
    else {
        printf("Error: Contact list is full.\n");
    }
}

void findID(const WhitePages* whitePages) {
    char searchName[MAX_IG_LENGTH + 1];
    printf("Enter the name to find: ");
    scanf("%s", searchName);

    for (size_t i = 0; i < whitePages->size; ++i) {
        if (strcmp(whitePages->name[i], searchName) == 0) {
            printf("ID found for %s: %s\n", searchName, whitePages->id[i]);
            return;
        }
    }

    printf("Contact not found for the given name.\n");
}

void findName(const WhitePages* whitePages) {
    char searchID[MAX_IG_LENGTH + 1];
    printf("Enter the ID to find: ");
    scanf("%s", searchID);

    for (size_t i = 0; i < whitePages->size; ++i) {
        if (strcmp(whitePages->id[i], searchID) == 0) {
            printf("Name found for ID %s: %s\n", searchID, whitePages->name[i]);
            return;
        }
    }

    printf("Contact not found for the given ID.\n");
}

void removeContact(WhitePages* whitePages) {
    printf("Choose contact to remove:\n");

    for (size_t j = 0; j < whitePages->size; ++j) {
        printf("%zu - Name: %s\tID: %s\n", j + 1, whitePages->name[j], whitePages->id[j]);
    }

    size_t choice;
    printf("Enter the number of the contact to remove: ");
    scanf("%zu", &choice);

    if (choice > 0 && choice <= whitePages->size) {
        // Use fflush to clear the input buffer
        fflush(stdin);

        // Use gets to read the newline character left in the buffer
        gets_s(whitePages->name[choice - 1]);
        gets_s(whitePages->id[choice - 1]);

        // Shift elements to remove the chosen contact
        for (size_t i = choice - 1; i < whitePages->size - 1; ++i) {
            strcpy(whitePages->name[i], whitePages->name[i + 1]);
            strcpy(whitePages->id[i], whitePages->id[i + 1]);
        }

        whitePages->size--;
        printf("Contact removed successfully.\n");
    }
    else {
        printf("Error: Invalid contact number.\n");
    }
}