#include "inverted.h"

/* Function definitions */

int validate_files(char *argv[], F_node **head)
{
    if(argv[1] == NULL)
    {
        return FAILURE;
    }
    
    for(int i = 1 ; argv[i] != NULL ; i++)
    {
      FILE *fp = fopen(argv[i] , "r");
        
        if(strstr(argv[i] , ".") == NULL)
        {
          printf("\033[1;31mINFO : %s => this file has without extension\n\n\033[0m",argv[i]);
        }
        else if(strstr(argv[i] , ".txt") == NULL)
        {
          printf("\033[1;31mINFO : %s => this file has not a .txt extension\n\n\033[0m",argv[i]);
        }
        else if(fp == NULL)
        { 
          printf("\033[1;31mINFO : %s => this file has not created\n\n\033[0m",argv[i]); 
        }
        else if(file_staus(fp) == FAILURE)
        {
          printf("\033[1;31mINFO : %s => this is empty\n\n\033[0m",argv[i]);  
        }
        else if(check_duplicates(*head, argv[i]) == FAILURE)
        {
          printf("\033[1;31mINFO : %s => this is repeted, so it will not store into the sll\n\n\033[0m",argv[i]);  
        }
        else
        {
            insert_last(head, argv[i]);
            printf("\033[1;32mINFO : Successful : inserted file name %s into file linked list\n\n\033[0m",argv[i]);
        }

        if(fp != NULL)
         fclose(fp);
    }

    if(*head == NULL)
     return FAILURE;
    else
     return SUCCESS;
}

int file_staus(FILE *fp)
{
    fseek(fp , 0 , SEEK_END);
    //printf("position = %ld",ftell(fp));
    if(ftell(fp) == 0)
     return FAILURE;
    else
     return SUCCESS;
}

int insert_last(F_node **head, char *f_name)
{
    F_node *new = malloc(sizeof(F_node));

    strcpy(new->f_name , f_name);
    new->flink = NULL;

    if(*head == NULL)
    {
      *head = new;
    }
    else
    {
      F_node *temp = *head;

      while(temp->flink)
      {
        temp = temp->flink;
      }
      temp->flink = new;
    }

    return SUCCESS;
}

int check_duplicates(F_node *head, char *f_name)
{
    if(head == NULL)
    {
      return SUCCESS;
    }
    
    while(head)
    {
       if(strcmp(head->f_name , f_name) == 0)
          return FAILURE;

        head = head->flink;
    }

    return SUCCESS;
    
}

int print_filenames(F_node *head)
{
  printf("\033[1;33m");
   if(head == NULL)
   {
      printf("File List is empty\n");
      return FAILURE;
   }  

   printf("Files name -> ");

   while(head)
   {
      printf("%s -> ", head->f_name);

      head = head->flink;
   }
    printf("NULL\n\n");
    printf("\033[0m");
   return SUCCESS;
}

int get_index(char *word)
{
    if(islower(word[0]))
    {
        return word[0] - 'a';
    }
    else if(isupper(word[0]))
    {
        return word[0] - 'A';
    }
    else
    {
        return 26;
     }
}


void delet_filename_present(F_node **head, char *f_name)
{
    F_node *temp = *head;
    F_node *prev = NULL;

    while(temp)
    {
      if(strcmp(temp->f_name, f_name) == 0)
      {
        if(prev == NULL)
        {
          *head = temp->flink;
          free(temp);
        }
        else
        {
          prev->flink = temp->flink;
          free(temp);
        }
        break;
      }
      prev = temp;
      temp = temp->flink;
    }
}

