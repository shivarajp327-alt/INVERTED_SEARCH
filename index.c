#include "index.h"

int insert_file(file_t **files, char *fname)
{
    file_t *newnode = malloc(sizeof(file_t));
    
    if(newnode == NULL)
        return FAILURE;
    strcpy(newnode->fname,fname);
    newnode->link = NULL;

    if(*files == NULL)
    {
        *files = newnode;
        return SUCCESS;
    }

    file_t *temp = *files;

    while(temp->link != NULL)
    {
        temp = temp->link;
    }
    temp->link = newnode;
    return SUCCESS;
}


int isduplicate_file(char *fname, file_t *files)
{
    while(files!=NULL)
    {
        if(strcmp(files->fname,fname) == 0)
            return SUCCESS;

        files = files->link;
    }
    return FAILURE;
}


void display_file(file_t *head)
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("head -> ");
    while(head!=NULL)
    {
        printf("%s -> ",head->fname);
        head = head->link;
    }
    printf("NULL\n");
}



int validate_arguments(char *argv[],file_t **files)
{
    for(int i=1;argv[i]!=0;i++)
    {
        char *dot=strrchr(argv[i],'.');
        if(strcmp(dot,".txt")!=0)
        {
            printf("ERROR: %s file should be \".txt\" type\n",argv[i]);
            continue;
        }

        FILE *fptr = fopen(argv[i],"r");

        if(fptr == NULL)
        {
            fclose(fptr);
            printf("ERROR: Unable to open %s file\n",argv[i]);
            continue;
        }
        if(fgetc(fptr)==EOF)
        {
            printf("ERROR: %s is an empty file\n",argv[i]);
            continue;
        }
        if(isduplicate_file(argv[i], *files)==SUCCESS)
        {
            printf("ERROR: File %s is already Exists\n",argv[i]);
            continue;
        }

        insert_file(files,argv[i]);
        fclose(fptr);
    }
    display_file(*files);
}



int Create_database()
{

}



int Display_Database()
{

}



int Search_Database()
{

}



int Update_Database()
{

}



int Save_Database()
{

}

