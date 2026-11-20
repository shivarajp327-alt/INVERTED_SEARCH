#include "index.h"

int main(int argc,char *argv[])
{
    file_t *files = NULL;
    mainnode_t *arr[27] = {0};
    int choice;
    char word[size];
    short create_flag = 0,update_flag = 0;


    validate_arguments(argv,&files);

    printf("\n1. Create Database\n2. Display Database\n3. Search Database\n4. Update Database\n5. Save Database\n6. Exit\n");
    
    while(1)
    {
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                if(create_flag == 0)
                {
                    Create_Database(files,arr);
                    printf("[ SUCCESS ] Database created\n");
                    create_flag = 1;
                }
                else
                {
                    printf("[ FAILURE ] Database already created\n");
                }
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
                if(update_flag == 0)
                {
                    if(create_flag == 1)
                    {
                        printf("[ FAILURE ] Database update is not allowed after database creation.\n");
                    }
                    else
                    {
                        Update_Database(files,arr);
                        printf("[ SUCCESS ] Database updated\n");
                        update_flag = 1;
                    }
                }
                else
                {
                    printf("[ FAILURE ] Database already updated\n");
                }
            break;
            case 5:
                Save_Database(arr);
                printf("[ SUCCESS ] Database saved\n");
            break;
            case 6:
                return SUCCESS;
            break;
            default:
                printf("[ ERROR ] Invalid choice! Re-try:\n");
        }
    }
    return SUCCESS;
}