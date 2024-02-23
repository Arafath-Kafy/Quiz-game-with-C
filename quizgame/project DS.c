#include<stdio.h>

int menu_input, S_n;
char name[20], id[10], ans[1000];
int reg_cmplt, right=0;

void title_bar()
{
    printf("\t\t ||==================================||\n");
    printf("\t      |||||==      ===================     ==||||||\n");
    printf("\t ||||||||||==           Quiz Game          ==|||||||||||\n");
    printf("\t      |||||==      ===================     ==||||||\n");
    printf("\t\t ||==================================||\n\n\n");

}
void input_info()
{
    system ("color 7C");
    printf("\t\t*****************************************\n");
    printf("\t\t**   Enter Your Information Please!    **\n");
    printf("\t\t*****************************************\n\n\n");

    getchar();
    printf("\t\t\tName: ");
    gets(name);
    printf("\t\t\tId: ");
    gets(id);

    printf("\n\n\t\t\tPress 0 to Confirm.....");
    scanf("%d",&reg_cmplt);
    FILE *file;
    file =fopen("results.txt","a");
    fprintf(file, "Name= %s\t\tId= %s\t\t",name,id);
    fclose(file);

}
void save_info()
{
    FILE *file;
    file =fopen("results.txt","a");
    fprintf(file, "Subject=%d\t\tScore=%d\n\n",S_n,right);
    fclose(file);
}
void menu()
{
    system ("color 7C");
    printf("\n");
    printf("\t\t\t************************\n");
    printf("\t\t\t**        MENU        **\n");
    printf("\t\t\t************************\n\n\n");
    printf("\t\t\t1. Start \n");
    printf("\t\t\t2. Previous Results \n");
    printf("\t\t\t3. Exit \n");

    printf("\n\n\t\t\tEnter Chosen Option :  ");
    scanf("%d",&menu_input);
    printf("\n\n");

    return menu_input;
}

void subject_choice()
{
    printf("\n\n\t\t\t**************************\n");
    printf("\t\t\tChoose Your quiz subject-\n\n");
    printf("\t\t\t  1. Data structure\n");
    printf("\t\t\t  2. Discrete Mathematics\n");
    printf("\t\t\t  3. Software project\n");
    printf("\t\t\t  4. Electrical circuit\n");

    printf("\n\n\t\t\t Enter Your Subject Number: ");
    scanf("%d",&S_n);
    quiz_start();
}

void quiz_start()
{
    if(S_n==1)
    {
        system("cls");
        system ("color 0A");
        char ans;

        printf("\n\t\t\t^^^^^^^^^^^^^^^^^^^\n");
        printf("\t\t\t^^^^^^^^^^^^^^^^^^^\n");
        printf("\t\t\t   Data Structure   ");
        printf("\n\t\t\t^^^^^^^^^^^^^^^^^^^\n\n\n");

        char question[][100]= {"1. What is it called when stack is full?",
                               "2. Which rule stack follows?",
                               "3. In stack insertion and deletion can be performed- ",
                               "4. Which rule queue follows?"
                              };

        char option[][100]= {"a) Complete", "b) Full", "c) Overflow", "d) Underflow",
                             "a) LIFO ", "b) FIFO", "c) FILO", "d) LILO ",
                             "a) on the top of the list", "b) both top and below of the list", "c) anywhere of the list", "d) cannot be performed",
                             "a) LIFO ", "b) FIFO", "c) FILO", "d) LILO "
                            };

        char answers[]= {'c','a','a','b'};

        int number_of_question= sizeof(question)/sizeof(question[0]);

        for(int i=0; i<number_of_question; i++)
        {
            printf("\t\t\t%s\n",question[i]);

            for(int j= (i*4); j<(i*4)+4; j++)
            {
                printf("\t\t\t  %s\n",option[j]);
            }
            printf("\n\t\t\tEnter your answer: ");
            getchar();
            scanf("%c",&ans);

            if(ans == answers[i])
            {
                printf("\n\t\t\t Correct\n\n");
                right++;
            }
            else
            {
                printf("\n\t\t\t Incorrect\n\n");
            }
        }
        printf("\t\t\tYou answered %d correctly",right);
        save_info();
    }
    if(S_n==2)
    {
        system("cls");
        system ("color 0A");
        char ans;

        printf("\n\t\t\t^^^^^^^^^^^^^^^^^^^\n");
        printf("\t\t\t^^^^^^^^^^^^^^^^^^^\n");
        printf("\t\t\t   Discrete Mathematics   ");
        printf("\n\t\t\t^^^^^^^^^^^^^^^^^^^\n\n\n");

        char question[][100]= {"1. P=T & Q= F then P^Q=? ",
                               "2. A compound proposition that is always true is called-",
                               "3. What is the full meaning of MST? "
                              };

        char option[][100]= {"a) T ", "b) F", "c) Both", "d) None",
                             "a) Tautology", "b) Contradiction", "c) Cotingency", "d) None",
                             "a) Minimum Spare Tree", "b) Maximum spinning tree", "c) Minimum spanning tree", "d) Most Shortest Tree"
                            };

        char answers[]= {'b','a','c'};

        int number_of_question= sizeof(question)/sizeof(question[0]);

        for(int i=0; i<number_of_question; i++)
        {
            printf("\t\t\t%s\n",question[i]);

            for(int j= (i*4); j<(i*4)+4; j++)
            {
                printf("\t\t\t  %s\n",option[j]);
            }
            printf("\n\t\t\tEnter your answer: ");
            getchar();
            scanf("%c",&ans);

            if(ans == answers[i])
            {
                printf("\n\t\t\t Correct\n\n");
                right++;
            }
            else
            {
                printf("\n\t\t\t Incorrect\n\n");
            }
        }
        printf("\t\t\tYou answered %d correctly",right);
        save_info();
    }

}


/*void previous_result()
{
    FILE *file;
    file =fopen("results.txt","a");
    //fprintf(file,"NAME ======= ID ====== Subject ======= Score\n %s\t%s\t%d\t%d\n",name[20],id[10],S_n,right);
    fputs(name[20],file);
    fputs(id[10],file);
    fclose(file);

}
*/
int main()
{
        title_bar();
        menu();
        if (menu_input==1)
        {
            system("cls");
            title_bar();
            input_info();
            if (reg_cmplt==0)
                {
                    system("cls");
                    title_bar();
                    subject_choice();
                }
        }

        else if (menu_input==2)
        {


        }

        else if (menu_input==3)
        {
            exit(0);
        }



}
