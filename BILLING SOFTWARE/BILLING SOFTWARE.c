#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct items{
    char item[20];
    float price;
    int qty;
};
struct orders{
    char customer[50];
    char date[50];
    int numOfItems;
    struct items itm[50];
};
//functions to generate bills
void generateBillHeader(char name[50],char date[30]){
    printf("\n\n");
    printf("\t    ASM. Restaurant");
    printf("\n\t    ---------------");
    printf("\nDate:%s",date);
    printf("\nInvoice To: %s",name);
    printf("\n");
    printf("-----------------------------------------\n");
    printf("Items\t\t");
    printf("Qty\t\t");
    printf("Total\t\t");
    printf("\n-----------------------------------------");
    printf("\n\n");
}

void generateBillBody(char item[30],int qty,float price)
{
    printf("%s\t\t",item);
    printf("%d\t\t",qty);
    printf("%.2f\t\t",qty*price);
    printf("\n");
}

void generateBillFooter(float total)
{
    printf("\n");
    float dis=0.1*total;
    float netTotal=total-dis;
    float cgst=0.09*netTotal,grandTotal=netTotal + 2*cgst;
    printf("-----------------------------------------\n");
    printf("Sub Total\t\t\t%.2f",total);
    printf("\nDiscount @10%s\t\t\t%.2f","%",dis);
    printf("\n\t\t\t\t----------");
    printf("\nNet Total\t\t\t%.2f",netTotal);
    printf("\nCGST @9%s\t\t\t%.2f","%",cgst);
    printf("\nSGST @9%s\t\t\t%.2f","%",cgst);
    printf("\n-----------------------------------------");
    printf("\ngrand Total\t\t\t%.2f",grandTotal);
    printf("\n-----------------------------------------\n");
}

int main()
{
    float total;
    struct orders ord;
    struct orders order;
    int opt,n;
    char saveBile ='y';
    FILE* fp;
    printf("\t==========ASM. RESTAURANT===============");
    printf("\n\n1.Generate Invoice");
    printf("\n2.Show all Invoices");
    printf("\n3.Search Invoice");
    printf("\n4.Exit");

    printf("\n\nPlease select your prefered operation:\t");
    scanf("%d",&opt);
    fgetc(stdin);

    switch(opt)
    {
        case 1:
            //system("clear");
            printf("\nPleasr Enter The Name of The Customer: ");
            fgets(ord.customer,50,stdin);
            ord.customer[strlen(ord.customer)-1]=0;
            strcpy(ord.date,__DATE__);
            printf("\nPlease Enter the Number of Items: ");
            scanf("%d",&n);
            ord.numOfItems=n;

            for(int i=0;i<n;i++)
            {
                fgetc(stdin);
                printf("\n\n");
                printf("Please Enter The Item %d Name: ",i+1);
                fgets(ord.itm[i].item,20,stdin);
                ord.itm[i].item[strlen(ord.itm[i].item)-1]=0;
                printf("Please Enter The Quantity: ");
                scanf("%d",&ord.itm[i].qty);
                printf("Please Enter The Unit Price: ");
                scanf("%f",&ord.itm[i].price);
                total += ord.itm[i].qty * ord.itm[i].price;
            }
            generateBillHeader(ord.customer,ord.date);
            for(int i=0;i<ord.numOfItems;i++)
            {
                generateBillBody(ord.itm[i].item,ord.itm[i].qty,ord.itm[i].price);

            }
            generateBillFooter(total);

            printf("\nDO you want to save the invoice[y/n]: ");
            scanf("%s",&saveBile);

            if(saveBile=='y')
            {
                fp=fopen("RestaurantBill.dat","a+");
                fwrite(&ord,sizeof(struct orders),1,fp);
                if(fwrite!=0)
                    printf("\nSuccessfully saved");
                else
                    printf("\nError saving");
                fclose(fp);
            }
            break;


        case 2:

            fp=fopen("RestaurantBill.dat","r");
            printf("\n ******Your Previous Invouces*****\n");
            while(fread(&order,sizeof(struct orders),1,fp)){
                    float tot=0;
                generateBillHeader(order.customer,order.date);
                for(int i=0;i<order.numOfItems;i++)
                {
                    generateBillBody(order.itm[i].item,order.itm[i].qty,order.itm[i].price);
                    tot += order.itm[i].qty * order.itm[i].price;
                }
                generateBillFooter(tot);
            }
            fclose(fp);
            break;

    }
    printf("\n\n");

    return 0;
}
