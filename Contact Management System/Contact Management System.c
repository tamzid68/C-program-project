#include<stdio.h>
struct contact
{
    char name[50],phone[30],email[50];
};

void add_contact()
{

    FILE *file;

    file = fopen("contact.txt","a");

    if(file==NULL)
    {
        printf("File not open");
    }
    else
    {
        struct contact cnt;
        fflush(stdin);

        printf("Enter Name:");
        fgets(cnt.name, sizeof cnt.name, stdin);

        printf("Enter Phone:");
        fgets(cnt.phone, sizeof cnt.phone, stdin);

        printf("Enter Email:");
        fgets(cnt.email, sizeof cnt.email, stdin);

        fprintf(file, "%s%s%s",cnt.name,cnt.phone,cnt.email);

        fclose(file);
        printf("!Added to Contact Management System!");
    }
}

void display_contact()
{
    FILE *file;
    struct contact cnt;


    file = fopen("contact.txt","r");
    if(file==NULL)
    {
        printf("File is not open");
    }
    else
    {

        while(fscanf(file," %[^\n] %[^\n] %[^\n]",cnt.name,cnt.phone,cnt.email)!=EOF)
        {
            printf("Name:%s \nPhone:%s \nEmail:%s\n",cnt.name,cnt.phone,cnt.email);
        }

        fclose(file);
    }
}

int main()
{
    int choice;

    do
    {
        printf("!_____________Welcome To Contact Management System_____________!");
        printf("\n1.Add Contact\n2.Display Contact\n3.Exit\nEnter you Choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            add_contact();
            break;
        case 2:
            display_contact();
            break;
        case 3:
            printf("Exiting....");
            break;
        default:
            printf("Invalid Choice,Please try agine");
        }


    }
    while(choice!=3);
    return 0;
}
