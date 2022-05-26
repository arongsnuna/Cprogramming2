#include <ncurses.h>
#include "tel.h"

int choice, highlight = 0;
int yMax, xMax;
char *choices[6] = {"SEARCH", "ADD", "DELETE", "UPDATE", "LIST"};
void makeNewWin();
int openFile(MEMBER *list, int *count);
int tel_updt(MEMBER *list, int *count);

int main(void)
{
	MEMBER list[MAX]; //structure to store the contens of phonebook

	int count = 0; //declare integer type variable for counting member
	openFile(list, &count); //open data.txt and store to the list 

	initscr();
        cbreak();
        noecho();
	curs_set(0); //invisivle cursor
        getmaxyx(stdscr, yMax, xMax); //get column and row of screen

        WINDOW *main = newwin(10, xMax-8, yMax-10, 4); //make the window
        box(main, 0, 0);
        refresh();
        wrefresh(main);
       	keypad(main, true);
        mvwprintw(main, 1, 2, "%s", "<COMPUTER SCIENCE PHONEBOOK>");
	mvwprintw(main, 2, 2, "%s", "select the function you want with enter key!");
	//show the choice to make user choose
	while(1){
	 	for (int i = 0; i < 5; i++){
			if (i==highlight)
                               	wattron(main, A_REVERSE);
			mvwprintw(main, i+4, 2, "%d. %s",i+1,choices[i]);
			wattroff(main, A_REVERSE);
			}
		choice = wgetch(main);
		switch (choice){
                        case KEY_UP:
       	                        highlight--;
               	                if (highlight == -1)
                       	                highlight = 0;
                               	break;
                        case KEY_DOWN:
       	                        highlight++;
               	                if (highlight == 5)
                       	                highlight = 4;
                               	break;
                        default:
       	                        break;
		}
		if (choice == 10)
                       	break;
       	}
       	printw("\n   Your choice is %s.", choices[highlight]);
        getch();
       	endwin();

	char c[20];
	strcpy(c, choices[highlight]);
	if (strcmp(c, "SEARCH") == 0){ //select search
                makeNewWin(); //make new window to do search function
                tel_srch(list, &count);
                tel_list(list, &count);
		getch();
                endwin();
	}
	else if (strcmp(c, "ADD") == 0){ //select add
		makeNewWin(); //make new window to do add function
		tel_add(list, &count);
                tel_list(list, &count);
                getch();
                endwin();
	}
	else if (strcmp(c, "DELETE") == 0){ //select delete
		makeNewWin();//make new window to do delete funtion
		tel_list(list, &count);
		tel_delt(list, &count);
		getch();
		endwin();
	}
	else if(strcmp(c, "UPDATE")==0){ //select update
		makeNewWin(); //make new window to do update function
                tel_list(list, &count);
                tel_updt(list, &count);
                getch();
                endwin();
	}
	else if(strcmp(c, "LIST")==0){ //select list
                makeNewWin();//make new window to do list function
                tel_list(list, &count);
                getch();
                endwin();
        }
	else
		printw("Error!");

	return 0;
}
int openFile(MEMBER *list, int *count)
{
        FILE *fp = fopen("data.txt", "rt");//open the data.txt file with rt option
        while (!feof(fp)){//until end of the file
                fscanf(fp, "%[^:]:%[^:]:%s\n", list[*count].name, list[*count].phone, list[*count].memo);//make the list
	}
}
void makeNewWin()
{
	initscr();
        cbreak();
        echo();
	//make new window to show choice 
	WINDOW *new = newwin(10, xMax-8, yMax-25, 5);
	refresh();
	wrefresh(new);
}
void tel_list(MEMBER *list, int *count)
{
        int i = 0;//declare integer type variable and initailize
        if (*count == 0) //empty member list
                printw("\n   Empty!\n");
        else if (*count == 1) //one member
                printw("\n   %d %s %s %s\n", i+1, list[i].name, list[i].phone, list[i].memo);
        else if (*count >= 2) { //more than two members
                qsort(list, *count, sizeof(MEMBER), strcmp);//sort alphabetically
                for(i = 0; i < *count; i++) //print memebers
                        printw("\n   %d %s %s %s\n", i+1, list[i].name, list[i].phone, list[i].memo);
        }
}
int tel_srch(MEMBER *list, int *count)
{
        char k;
        printw("\n   Input what you want to search: ");
        scanw("%s", &k); //get searching contents from user
        int num = 0;//declare integer type variable (number of searched member)
        //if there is k in list, ++num and print the information of list
        for(int i = 0; i < *count; i++) {
                if (strstr(list[i].name, k) != NULL || strstr(list[i].phone, k) != NULL || strstr(list[i].memo, k) != NULL )
                        printf("%d %s %s %s", ++num, list[i].name, list[i].phone, list[i].memo);
        }
}
void tel_add(MEMBER *list, int *count)
{
        printw("\n   Add? [Y/N]: ");
        char ch;
	scanw("%s", &ch); //get answer from user
        if (ch == 'Y'){ //copy name, phone, memo on the list
		if (*count < MAX){
			*count++;
			printw("\n   Input Name, Phone, Memo:");
			scanw("%s %s %s", list[*count].name, list[*count].phone, list[*count].memo);
			//change the data.txt
                	FILE *fp = fopen("data.txt", "w");//open data.txt with option w
                	for(int i = 0; i < *count+1; i++) {
                        	char *input = (char *)malloc(sizeof(char) * MAX);//put name, phone, memo together in one line
	                        strcpy(input, list[i].name);
        	                strcat(input, ":");
                	        strcat(input, list[i].phone);
                        	strcat(input, ":");
	                        strcat(input, list[i].memo);
        	                if(i == *count)
                	                strcat(input, "\n");
                        	fputs(input, fp);//put to the data.txt file
                	}
                	fclose(fp);//close the data.txt file

			printw("\n   Data Added!\n");
		}
		else
			printw("\n   Sorry. Data is fulled.");

		}
}

void tel_delt(MEMBER *list, int *count)
{
	char k;
	printw("\n   Which word do you want to delete? ");
	scanf("%s", &k);

        int smem[*count]; //declare integer type array (using for search memeber)
        int num = 0; //declare integer type variable (number of searched member)

        for(int i = 0; i < *count; i++) {
                if(strstr(list[i].name, k) != NULL || strstr(list[i].phone, k) != NULL || strstr(list[i].memo, k) != NULL){ //search k in the list
                        printw("\n   %d %s %s %s", ++num, list[i].name, list[i].phone, list[i].memo); //if present, print
                        smem[num] = i; //save it to smem
                }
        }
        if (num == 0) //no match found
                printw("\n   no match found\n");
        else {
                //select member tha is searched using count
                printw("\n   which one? ");
                int num1;
                scanw("%d", &num1);

                //move the index one by one and delete
                for(int num2 = smem[num1]; num2 < *count; num2++)
                        list[num2] = list[num2+1];
		//change the data.txt
                FILE *fp = fopen("data.txt", "w");//open data.txt with option w
                for(int i = 0; i < *count-1; i++) {
                        char *input = (char *)malloc(sizeof(char) * MAX);
                        //put name, phone, mmemo together in one line
                        strcpy(input, list[i].name);
                        strcat(input, ":");
                        strcat(input, list[i].phone);
                        strcat(input, ":");
                        strcat(input, list[i].memo);
                        fputs(input, fp); //put the line to the data.txt file
                }
                fclose(fp);//close the data.txt file
        }
}

int tel_updt(MEMBER *list, int *count){
	int i, answer; //declare integer type variable
	char new_name[30];
	char new_phone[20];
	char new_memo[40]; 
	//character array to store updating data temporary

	if (*count >0){
		printw("\n   Input the number to update: ");
		scanw("%d", answer);
		printw("\n   Input new name, phone, memo in sequence: ");
		scanw("%s %s %s", new_name, new_phone, new_memo);

		for(i=0; i<MAX; i++){
			if (answer-1 == i){
				strcpy(list[i].name, new_name);
				strcpy(list[i].phone, new_phone);
				strcpy(list[i].memo, new_memo);
				//update the contents of list
				
				printw("%s %s %s", list[i].name, list[i].phone, list[i].memo);
				printw("\n   Data Updated");
				return 0;
			}
		}
		printw("\n   no match found.");
		return 0; 
	}
	else{
		printw("\n   There isn't any data here.");
		return 0;
	}
}
