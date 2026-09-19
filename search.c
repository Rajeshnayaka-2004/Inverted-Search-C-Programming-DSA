#include "inverted.h"

void search_database(hash_t HT[])
{
    char word[20];
    printf("Enter the word you need search : ");
    scanf("%s",word);

    int index = get_index(word);

        M_node *Mtemp = HT[index].main_link;
    
        while(Mtemp)
        {
            if(strcmp(Mtemp->word , word) == 0)
            {
                printf("\033[1;33m");
                printf("word %s is present in %d file\n",word , Mtemp->file_count);
                S_node *Stemp = Mtemp->sub_link;

                while(Stemp)
                { 
                    printf("In file %s %d time\n",Stemp->filename , Stemp->word_count);
                        
                    Stemp = Stemp->sub_link;
                }
                printf("\n\033[0m");
                return;
            }
           
           Mtemp = Mtemp->main_link;
        }

    printf("\033[1;31m%s is not present in any file\n\n\033[0m",word);
}
