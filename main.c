#include "index.h"

int main(int argc,char *argv[])
{
    file_t *files = NULL;
    mainnode_t *arr[27] = {0};
    int choice;

    validate_arguments(argv,&files);

    printf("1. Create Database\n2. Display Database\n3. Search Database\n4. Update Database\n5. Save Database\n6. Exit\n");
    
    while(1)
    {
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                Create_database();
            break;
            case 2:
                Display_Database();
            break;
            case 3:
                Search_Database();
            break;
            case 4:
                Update_Database();
            break;
            case 5:
                Save_Database();
            break;
            case 6:
                return SUCCESS;
            break;
            default:
                printf("Invalid choice! Re-try:\n");
        }

    }
}