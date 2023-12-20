

#include <stdio.h>

struct Employee
{
    char name[30];
    char designation[30];
    int id;
    int age;
    int salary;
    
};

struct Employee e;
FILE *ptr;

//add record function
void add_record()
{
    char option='y';
    do
    {

        printf("\nEnter Employee Id: ");
        scanf("%d", &e.id);

        printf("Enter Name : ");
        fflush(stdin);
        fgets(e.name, 30, stdin);

        printf("Enter Designation : ");
        fgets(e.designation, 30, stdin);

        printf("Enter Age : ");
        scanf("%d", &e.age);

        printf("Enter Salary : ");
        scanf("%d", &e.salary);
        
        ptr=fopen("Employee.txt", "a");
        if (ptr==NULL)
        {
        printf("------------------");
        printf("\n| file not exist |");
        printf("\n------------------");
        }

        else
        {
            fwrite(&e,sizeof(e),1,ptr);
            printf("----------------------------");
            printf("\n| Record Saved Sucessfully |");
            printf("\n----------------------------");
            fclose(ptr) ;
        }

        printf("\nDo you want to add more record (Y/N) : ");
        scanf("%s",&option);
    }
    while (option=='y');     

    fclose(ptr) ;
}

//Display record function
void display_record()
{
    ptr=fopen("Employee.txt", "r");
    if (ptr==NULL)
    {
        printf("------------------");
        printf("\n| file not exist |");
        printf("\n------------------");
    }
    else
    {
        printf("\nEmp Id\t\tName\t\tAge\t\tSalary\t\tDesignation\n");
        printf("============================================================================\n");
        while(fread(&e,sizeof(e),1,ptr)==1)
        {
            //fflush(stdin);
            printf("%d\t\t%s\t\t%d\t\t%d\t\t%s\n", e.id, e.name, e.age, e.salary, e.designation);
        }
    }
    fclose(ptr);
}

void update_record()
{
    FILE *ptr1;

    int empId,flag=0;
    char choice='y';

    ptr=fopen("Employee.txt", "r");
    ptr1=fopen("temp.txt","w");
    if (ptr==NULL)
    {
        printf("------------------");
        printf("\n| file not exist |");
        printf("\n------------------");
    }
    else
    {
        printf("\nEnter employee Id to update record :");
        scanf("%d",&empId);

        while(fread(&e,sizeof(e),1,ptr)==1)
        {
            if (e.id==empId)
            {
                flag=1;
                fflush(stdin);
                printf("\nEnter New Employee Id: ");
                scanf("%d", &e.id);

                printf("Enter New Name : ");
                fflush(stdin);
                fgets(e.name, 30, stdin);

                printf("Enter New Designation : ");
                fgets(e.designation, 30, stdin);

                printf("Enter New Age : ");
                scanf("%d", &e.age);

                printf("Enter New Salary : ");
                scanf("%d", &e.salary);

            }
            fwrite(&e,sizeof(e),1,ptr1);
        }
        fclose(ptr);
        fclose(ptr1);
        if (flag==1)
        {
            ptr1=fopen("temp.txt","r");
            ptr=fopen("Employee.txt","w");

            while(fread(&e,sizeof(e),1,ptr1))
            {
                fwrite(&e,sizeof(e),1,ptr);
            }
            fclose(ptr);
            fclose(ptr1);

            printf("------------------");
            printf("\n| Record Updated |");
            printf("\n------------------");
        }
        else
        {
            printf("--------------------");
            printf("\n| Record Not Found |");
            printf("\n--------------------");
        }
        
    
        printf("\nDo you want to Update another record (Y/N) :");
        scanf("%s",&choice);
        while (choice=='y');
    }

    fclose(ptr);
}

void search_record()
{
int emp_id,flag=0;

    ptr=fopen("Employee.txt", "r");
    if (ptr==NULL)
    {
        printf("------------------");
        printf("\n| file not exist |");
        printf("\n------------------");
    }
    else
    {
        printf("\nEnter Employee Id to search record of Employee :");
        scanf("%d",&emp_id);

        while(fread(&e,sizeof(e),1,ptr)==1)
        {
            if (emp_id==e.id)
            {
                flag=1;
                printf("\nEmp Id\t\tName\t\tAge\t\tSalary\t\tDesignation\n");
                printf("============================================================================\n");
                printf("%d\t\t%s\t\t%d\t\t%d\t\t%s\n", e.id, e.name, e.age, e.salary, e.designation);
            }   
        }
        if (flag==1)
        {
            printf("-----------------");
            printf("\n| Record found |");
            printf("\n----------------");
        }
        else
        {
            printf("---------------------");
            printf("\n| Record not found |");
            printf("\n--------------------");
        }
    }
    
    fclose(ptr);
}

void delete_record()
{
        FILE *ptr1;

    int empId,flag=0;
    char choice='y';

    ptr=fopen("Employee.txt", "r");
    ptr1=fopen("temp.txt","w");
    if (ptr==NULL)
    {
        printf("------------------");
        printf("\n| file not exist |");
        printf("\n------------------");
    }
    else
    {
        printf("\nEnter employee Id to Delete record :");
        scanf("%d",&empId);

        
        while(fread(&e,sizeof(e),1,ptr)==1)
        {
            if (e.id==empId)
            {
                flag=1;
            }
            else
            {
                fwrite(&e,sizeof(e),1,ptr1);
            }
            
        }
        fclose(ptr);
        fclose(ptr1);
        if (flag==1)
        {
            ptr1=fopen("temp.txt","r");
            ptr=fopen("Employee.txt","w");

            while(fread(&e,sizeof(e),1,ptr1))
            {
                fwrite(&e,sizeof(e),1,ptr);
            }
            fclose(ptr);
            fclose(ptr1);

            printf("------------------");
            printf("\n| Record Deleted |");
            printf("\n------------------");
        }
        else
        {
            printf("--------------------");
            printf("\n| Record Not Found |");
            printf("\n--------------------");
        }
        
    
    printf("\nDo you want to Update another record (Y/N) :");
    scanf("%s",&choice);
    while (choice=='y');
    }

    fclose(ptr); 
}

//main code
int main()
{
    int choice;
    
    while(1)
    {
    
        printf("\n============================================");
        printf("\n>> WELCOME TO EMPLOYEE MANAGEMENT SYSTEM <<");
        printf("\n============================================");

        printf("\n1. ADD RECORD");
        printf("\n2. DISPLAY RECORD");
        printf("\n3. UPDATE RECORD");
        printf("\n4. SEARCH RECORD");
        printf("\n5. DELETE RECORD");
        printf("\n6. EXIT");
        printf("\nENTER YOUR CHOICE...");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            add_record();
            break;

        case 2:
            display_record();
            break;
        
        case 3:
            update_record();
            break;

        case 4:
            search_record();
            break;

        case 5:
            delete_record();
            break;

        case 6:
            printf("\nYour program is exit...");
            return 0;

        default:
            printf("\nINVALID CHOICE...\n");
        }
    }
    
    return 0;
}