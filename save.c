#include "inverted.h"

void save_database(hash_t HT[])
{
    char file_name[20];

    printf("Enter the file name : ");
    scanf("%s",file_name);

    if(strstr(file_name , ".txt") == NULL)
    {
        printf("\033[1;31mINVALID FILE NAME !!!\033[0m\n\n");
        return;
    }

    FILE *fp = fopen(file_name,"w");
    fprintf(fp ,"INDEX;WORD;FILECOUNT;FILENAME;WORDCOUNT\n");

    for(int i = 0 ; i < 27 ; i++)
    {
        if(HT[i].main_link == NULL)
          continue;

        char word[20], file_name[50] , word_count[20];
        int file_count;

        M_node *Mtemp = HT[i].main_link;

        while(Mtemp)
        {
           S_node *Stemp = Mtemp->sub_link;

           file_count = Mtemp->file_count;
           strcpy(word , Mtemp->word);

           file_name[0] = '\0';
           word_count[0] = '\0';

           while(Stemp)
           {  
                char temp_file[100] , temp_word_count[20];

                if(Stemp->sub_link != NULL)
                {
                    sprintf(temp_file , "%s,",Stemp->filename);
                    sprintf(temp_word_count, "%d," ,Stemp->word_count);
                    
                }
                else
                {
                    strcpy(temp_file , Stemp->filename);
                    sprintf(temp_word_count ,"%d", Stemp->word_count);
                    //printf("%s\n",temp_word_count);
                }

                strcat(file_name , temp_file);
                strcat(word_count , temp_word_count);
                //printf("%s",word_count);
                Stemp = Stemp->sub_link;
           }

           fprintf(fp , "%d;%s;%d;%s;%s\n", i , word , file_count , file_name , word_count);
           
           Mtemp = Mtemp->main_link;
        }
    }

    fclose(fp);

    printf("\033[1;32mDatabase saved successfully\n\033[0m");
}   
