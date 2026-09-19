#include "inverted.h"

void display_database(hash_t HT[])
{
    
    printf("\033[1;33m");
    printf("---------------------------------------------------------------------------------------------------------------------------\n");
    printf(" INDEX  |        WORD          |  FILE COUNT  |                    FILE NAME                       |      WORD COUNT      |\n");
    printf("---------------------------------------------------------------------------------------------------------------------------\n");

    for(int i = 0 ; i < 27 ; i++)
    {
        if(HT[i].main_link == NULL)
          continue;

        char word[20], file_name[50] , word_count[20];
        int file_count;

        M_node *Mtemp = HT[i].main_link;

        while(Mtemp)
        {
           int flag = 0;
           S_node *Stemp = Mtemp->sub_link;

           file_count = Mtemp->file_count;
           strcpy(word , Mtemp->word);

           file_name[0] = '\0';
           word_count[0] = '\0';

           while(Stemp)
           {  
                // char temp_file[100] , temp_word_count[20];

                // if(Stemp->sub_link != NULL)
                // {
                //     sprintf(temp_file , "%s,",Stemp->filename);
                //     sprintf(temp_word_count, "%d," ,Stemp->word_count);
                    
                // }
                // else
                // {
                //     strcpy(temp_file , Stemp->filename);
                //     sprintf(temp_word_count ,"%d", Stemp->word_count);
                //     //printf("%s\n",temp_word_count);
                // }

                // strcat(file_name , temp_file);
                // strcat(word_count , temp_word_count);
                // //printf("%s",word_count);
                // Stemp = Stemp->sub_link;

                if(flag == 0)
                {
                    printf("%-7d | %-20s | %-12d | %-50s | %-20d |\n", i , Mtemp->word , Mtemp->file_count , Stemp->filename , Stemp->word_count);
                    flag = 1;
                }
                else
                {
                    printf("%-7s | %-20s | %-12s | %-50s | %-20d |\n", " " , " " , " " , Stemp->filename , Stemp->word_count);
                }

                Stemp = Stemp->sub_link;
           }
           
           printf("---------------------------------------------------------------------------------------------------------------------------\n");
           Mtemp = Mtemp->main_link;
        }
    }
    printf("\033[0m");
}
