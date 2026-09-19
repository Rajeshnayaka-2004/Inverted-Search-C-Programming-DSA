#ifndef INVERTED_H
#define INVERTED_H

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <ctype.h>

#define SUCCESS		1
#define FAILURE		0


typedef struct file
{
    char f_name[20];
    struct file *flink;
}F_node;

typedef struct Sub
{
    int word_count;
    char filename[20];
    struct Sub *sub_link;
}S_node;

typedef struct Main
{
    char word[20];
    int file_count;
    S_node *sub_link;
    struct Main *main_link;
}M_node;

typedef struct hash_table
{
    int index;
    struct Main *main_link;
}hash_t;


void create_database(hash_t HT[], F_node *head);
void display_database(hash_t HT[]);
void search_database(hash_t HT[]);
void save_database(hash_t HT[]);
int update_database(hash_t HT[],F_node **head);

int validate_files(char *argv[], F_node **head);
int insert_last(F_node **head, char *f_name);
int check_duplicates(F_node *head, char *f_name);
int print_filenames(F_node *head);
int get_index(char *word);

int file_staus(FILE *fp);
int getworld(FILE *fp , char *world);
void delet_filename_present(F_node **head, char *f_name);

#endif
