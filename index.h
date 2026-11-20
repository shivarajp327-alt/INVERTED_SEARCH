#ifndef INDEX_H
#define INDEX_H

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#define size 25
#define SUCCESS 0
#define FAILURE -1

typedef struct f_node
{
    char fname[size];
    struct f_node *link;
}file_t;

typedef struct s_node
{
    char file_name[size];
    int word_count;
    struct s_node *link;
}subnode_t;

typedef struct m_node
{
    char word[size];
    int file_count;
    subnode_t *sub_link;
    struct m_node *link;
}mainnode_t;



int validate_arguments(char *argv[],file_t **);
int validate_update_file(char *fname);
int insert_file(file_t **, char *);
subnode_t *update_subnode(mainnode_t *arr[],int,char *,int);
mainnode_t *update_mainnode(mainnode_t *arr[],int,char *,int);
int insert_word(char *,char *,mainnode_t *arr[]);
int isduplicate_file(char *,file_t *);
int Create_Database(file_t *, mainnode_t *arr[]);
int Display_Database (mainnode_t *arr[]);
int Search_Database(char *, mainnode_t *arr[]);
int Update_Database(file_t *, mainnode_t *arr[]);
int Save_Database(mainnode_t *arr[]);



#endif