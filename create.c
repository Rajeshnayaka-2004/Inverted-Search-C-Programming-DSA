#include "inverted.h"

void create_database(hash_t HT[], F_node *head)
{

    while(head)
    {
        FILE *fp = fopen(head->f_name , "r");
        int index;
        char word[20];

        while((fscanf(fp ,"%s" , word)) == 1)
        {
            //printf("%s\n",word);
            index = get_index(word);

            //printf("%d\n",index);

            if(HT[index].main_link == NULL)
            {
               M_node *Mnew = malloc(sizeof(M_node));
               S_node *Snew = malloc(sizeof(S_node));

               strcpy(Mnew->word , word);
               Mnew->file_count = 1;
               Mnew->main_link = NULL;

               strcpy(Snew->filename , head->f_name);
               Snew->word_count = 1;
               Snew->sub_link = NULL;
               
               Mnew->sub_link = Snew;
               HT[index].main_link = Mnew;
            }
            else
            {
                M_node *Mtemp = HT[index].main_link;
                M_node *Mprev = NULL;

                while(Mtemp)
                {
                    if(strcmp(Mtemp->word, word) == 0)
                    {
                        break;
                    } 
                    
                    Mprev = Mtemp;
                    Mtemp = Mtemp->main_link;
                }

                if(Mtemp == NULL)
                {
                    M_node *Mnew = malloc(sizeof(M_node));
                    S_node *Snew = malloc(sizeof(S_node));

                    strcpy(Mnew->word , word);
                    Mnew->file_count = 1;
                    Mnew->main_link = NULL;

                    strcpy(Snew->filename , head->f_name);
                    Snew->word_count = 1;
                    Snew->sub_link = NULL;

                    Mnew->sub_link = Snew;
                    Mprev->main_link = Mnew;
                }
                else
                {
                    S_node *Stemp = Mtemp->sub_link;
                    S_node *Sprev = NULL;

                    while(Stemp)
                    {
                        if(strcmp(Stemp->filename , head->f_name) == 0)
                        {
                            Stemp->word_count++;
                            break;
                        }

                        Sprev = Stemp;
                        Stemp = Stemp->sub_link;
                    }

                    if(Stemp == NULL)
                    {
                        S_node *Snew = malloc(sizeof(S_node));

                        strcpy(Snew->filename , head->f_name);
                        Snew->word_count = 1;
                        Snew->sub_link = NULL;

                        Sprev->sub_link = Snew;

                        Mtemp->file_count++;
                    }
                }
            } 
        }

        head = head->flink;
    }

    printf("\033[1;32mDatabase created successfully\n\033[0m");
}

