#ifndef INDEX_H
#define INDEX_H

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#define SUCCESS 0
#define FAILURE -1

typedef struct f_node
{
    char fname[25];
    struct f_node *link;
}file_t;

typedef struct snode
{
    char file_name[25];
    int word_count;
    struct s_node *link;
}subnode_t;

typedef struct m_node
{
    char word[25];
    int file_count;
    subnode_t *sub_link;
    struct m_node *link;
}mainnode_t;

int validate_arguments(char *argv[],file_t **);
int insert_file(file_t **, char *);
int isduplicate_file(char *,file_t *);
int Create_database();
int Display_Database();
int Search_Database();
int Update_Database();
int Save_Database();

#endif