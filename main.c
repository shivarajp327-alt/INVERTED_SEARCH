#include "index.h"

int main(int argc,char *argv[])
{
    file_t *files = NULL;
    mainnode_t *arr[27] = {0};
    int choice;
    char word[size];

    validate_arguments(argv,&files);

    printf("1. Create Database\n2. Display Database\n3. Search Database\n4. Update Database\n5. Save Database\n6. Exit\n");
    
    while(1)
    {
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                Create_Database(files,arr);
            break;
            case 2:
                Display_Database(arr);
            break;
            case 3:
                printf("Enter word you want to search: ");
                scanf("%s",word);
                Search_Database(word, arr);
            break;
            case 4:
                Update_Database();
            break;
            case 5:
                Save_Database(arr);
            break;
            case 6:
                return SUCCESS;
            break;
            default:
                printf("Invalid choice! Re-try:\n");
        }
    }
}