#include "inverted.h"

int main(int argc, char *argv[])
{
    F_node *head = NULL;
    hash_t HT[27];

	for(int i = 0 ; i < 27 ; i++)
    {
        HT[i].index = i;
        HT[i].main_link = NULL;
    }


	int cflag = 0 , uflag = 0;

    // Validate_files
	if(validate_files(argv, &head) == SUCCESS)
	{
		printf("\033[1;32mvalidation SUCCESSFULL\n\n\033[0m");
	}
	else
	{
		printf("\033[1;31mvalidation UNSUCCESSFULL\nyou should run a code by entering a command link\n./a.out <file_name.txt>\n\n\033[0m");
		return FAILURE;
	}

	print_filenames(head);


    int option;
    do
    {
	printf("Select your choice among following operations:\n1. Create Database\n2. Display Database\n3. Save Database\n4. Search\n5. Update Database\n6. Exit\n\nEnter your choice : ");

	scanf("%d", &option);

	switch (option)
	{
	    case 1:
		if(cflag == 0)
		{
			create_database(HT, head);
			cflag = 1;
		}
		else
		{
			printf("\033[1;31mdatabase is allready created !!!!!\n\n\033[0m");
		}
		
		break;

	    case 2:
		display_database(HT);
		break;

	    case 3:
		save_database(HT);
		    break;

	    case 4:
		search_database(HT);
		break;

	    case 5:
		if(cflag == 0 && uflag == 0)
		{
			if(update_database(HT, &head) == SUCCESS)
			{
				uflag = 1;
			}
			else
			{
				printf("\033[1;31mINFO : Enter the valid backup file\n\n\033[0m");
			}
		}
		else
		{
			printf("\033[1;31mdatabase is allready created or updated !!!!\n\n\033[0m");
		}
		print_filenames(head);
		
		break;

	    case 6:
		break;

	    default:
		printf("\033[1;31mINFO : Please enter the valid option\n\n\033[0m");
	}
    }while( option != 6 );

    return 0;
}
