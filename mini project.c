#include <stdio.h>
#include <string.h>

#define MAX 100

struct Contact {
    char name[50];
    char phone[20];
};

int main() {
    struct Contact c[MAX];
    int count = 0, choice, i, found;
    char searchName[50];
    FILE *fp;

    // 🔹 Load contacts from file at start
    fp = fopen("contactsaver.txt", "r");
    if (fp != NULL) {
        while (fscanf(fp, "%49s %19s", c[count].name, c[count].phone) != EOF) {
            count++;
        }
        fclose(fp);
    }

    while (1) {
        printf("\n====== Contact Manager ======\n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Edit Contact\n");
        printf("5. Delete Contact\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        /* ---------- ADD CONTACT ---------- */
        if (choice == 1) {
            printf("Enter name: ");
            scanf("%49s", c[count].name);
            printf("Enter phone: ");
            scanf("%19s", c[count].phone);
            count++;

            // ✅ Save immediately
            fp = fopen("contactsaver.txt", "w");
            for (i = 0; i < count; i++) {
                fprintf(fp, "%s %s\n", c[i].name, c[i].phone);
            }
            fclose(fp);

            printf("Contact added and saved!\n");
        }

        /* ---------- VIEW CONTACTS ---------- */
        else if (choice == 2) {
            if (count == 0) {
                printf("No contacts found.\n");
            } else {
                for (i = 0; i < count; i++) {
                    printf("%d. %s - %s\n", i + 1,
                           c[i].name, c[i].phone);
                }
            }
        }

        /* ---------- SEARCH CONTACT ---------- */
        else if (choice == 3) {
            printf("Enter name to search: ");
            scanf("%49s", searchName);
            found = 0;

            for (i = 0; i < count; i++) {
                if (strcmp(c[i].name, searchName) == 0) {
                    printf("Found: %s - %s\n",
                           c[i].name, c[i].phone);
                    found = 1;
                    break;
                }
            }

            if (!found) {
                printf("Contact not found.\n");
            }
        }

        /* ---------- EDIT CONTACT ---------- */
        else if (choice == 4) {
            printf("Enter name to edit: ");
            scanf("%49s", searchName);
            found = 0;

            for (i = 0; i < count; i++) {
                if (strcmp(c[i].name, searchName) == 0) {
                    printf("Enter new phone number: ");
                    scanf("%19s", c[i].phone);
                    found = 1;

                    // ✅ Save immediately
                    fp = fopen("contactsaver.txt", "w");
                    for (int j = 0; j < count; j++) {
                        fprintf(fp, "%s %s\n",
                                c[j].name, c[j].phone);
                    }
                    fclose(fp);

                    printf("Contact updated and saved!\n");
                    break;
                }
            }

            if (!found) {
                printf("Contact not found.\n");
            }
        }

        /* ---------- DELETE CONTACT ---------- */
        else if (choice == 5) {
            printf("Enter name to delete: ");
            scanf("%49s", searchName);
            found = 0;

            for (i = 0; i < count; i++) {
                if (strcmp(c[i].name, searchName) == 0) {
                    for (int j = i; j < count - 1; j++) {
                        c[j] = c[j + 1];
                    }
                    count--;
                    found = 1;

                    // ✅ Save immediately
                    fp = fopen("contactsaver.txt", "w");
                    for (int j = 0; j < count; j++) {
                        fprintf(fp, "%s %s\n",
                                c[j].name, c[j].phone);
                    }
                    fclose(fp);

                    printf("Contact deleted and saved!\n");
                    break;
                }
            }

            if (!found) {
                printf("Contact not found.\n");
            }
        }

        /* ---------- EXIT ---------- */
        else if (choice == 6) {
            printf("Exiting program...\n");
            break;
        }

        else {
            printf("Invalid choice!\n");
        }
    }

    return 0;
}


