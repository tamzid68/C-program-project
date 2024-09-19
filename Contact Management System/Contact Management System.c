#include<stdio.h>

// Define a structure to hold contact details: name, phone number, and email
struct contact
{
    char name[50], phone[30], email[50];
};

// Function to add a contact
void add_contact()
{
    FILE *file;

    // Open the "contact.txt" file in append mode to add new contacts
    file = fopen("contact.txt", "a");

    // Check if the file was opened successfully
    if (file == NULL)
    {
        printf("File not open");  // If file opening fails, print an error message
    }
    else
    {
        struct contact cnt;  // Declare a variable of type 'contact'

        fflush(stdin);  // Clear the input buffer

        // Take input from the user for contact details
        printf("Enter Name:");
        fgets(cnt.name, sizeof cnt.name, stdin);

        printf("Enter Phone:");
        fgets(cnt.phone, sizeof cnt.phone, stdin);

        printf("Enter Email:");
        fgets(cnt.email, sizeof cnt.email, stdin);

        // Write the contact details to the file
        fprintf(file, "%s%s%s", cnt.name, cnt.phone, cnt.email);

        fclose(file);  // Close the file after writing
        printf("!Added to Contact Management System!\n");  // Confirm that the contact was added
    }
}

// Function to display all contacts from the file
void display_contact()
{
    FILE *file;
    struct contact cnt;  // Declare a variable of type 'contact'

    // Open the "contact.txt" file in read mode
    file = fopen("contact.txt", "r");

    // Check if the file was opened successfully
    if (file == NULL)
    {
        printf("File is not open");  // If file opening fails, print an error message
    }
    else
    {
        // Read the contact details from the file and print them
        while (fscanf(file, " %[^\n] %[^\n] %[^\n]", cnt.name, cnt.phone, cnt.email) != EOF)
        {
            printf("Name: %s \nPhone: %s \nEmail: %s\n", cnt.name, cnt.phone, cnt.email);  // Display each contact
        }

        fclose(file);  // Close the file after reading
    }
}

// Main function to handle the menu and user choices
int main()
{
    int choice;

    // Loop to keep displaying the menu until the user chooses to exit
    do
    {
        printf("!_____________Welcome To Contact Management System_____________!");
        printf("\n1.Add Contact\n2.Display Contact\n3.Exit\nEnter your Choice: ");
        scanf("%d", &choice);

        // Use a switch statement to call the appropriate function based on the user's choice
        switch(choice)
        {
        case 1:
            add_contact();  // Call the function to add a contact
            break;
        case 2:
            display_contact();  // Call the function to display all contacts
            break;
        case 3:
            printf("Exiting....");  // Exit the program
            break;
        default:
            printf("Invalid Choice, Please try again");  // Handle invalid choices
        }

    }
    while (choice != 3);    // Continue the loop until the user chooses to exit

    return 0;
}
