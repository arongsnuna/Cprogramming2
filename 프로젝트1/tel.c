#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NUM 100
typedef struct MEMBER{
	char name[30];
	char phone[20];
	char memo[40];
}MEMBER;

void tel_info();
int tel_srch(MEMBER *list, char *k, int size);
void tel_add(MEMBER *list, char *name, char *phone, char *memo, int size);
void tel_delt(MEMBER *list, char *k, int size);
void tel_list(MEMBER *list, int size);

int main(int argc, char *argv[])
{
        MEMBER *list = (MEMBER *)malloc(sizeof(MEMBER) * 100);
        int count = 0; //declare integer type variable (number of member)

        FILE *fp = fopen("data.txt", "r");//open data.txt with option r
        while(!feof(fp)) { //until end of file
                char *line = (char *)malloc(sizeof(char) * MAX_NUM);
                fgets(line, MAX_NUM, fp);//read by string and save it to line
                if (strcmp(line, "\0") == 0) //blank line
                        continue;
		//cut based on : and save on member(name, phone, memo)
                strcpy(list[count].name, strtok(line, ":"));
                strcpy(list[count].phone, strtok(NULL, ":"));
                strcpy(list[count].memo, strtok(NULL, ":"));
                count++;
        }
        fclose(fp);//close data.txt
        //basic
        if (argc == 1) {
                tel_info();
                return 0;
        }
        //option
        else if (argc > 1) {
                if (strcmp(argv[1], "-a") == 0) //add(-a)
                        tel_add(list, argv[2], argv[3], argv[4], count);
                else if (strcmp(argv[1], "-d") == 0) //delete(-d)
                        tel_delt(list, argv[2], count);
                else if (strcmp(argv[1], "-l") == 0) //list(-l)
                        tel_list(list, count);
                else if (argc == 2) { //search
                        int c = tel_srch(list, argv[1], count);
                        if (c == 0)
                                printf("no match found.\n");
                        else
                                printf("match found.\n");
                }
        }
        return 0;
}

//information of tel
void tel_info() 
{
	printf("tel is for showing phonebook.\n<<<<<tips>>>>>\n");
	printf("'Search mode': input that what you want to find and press the enter key.\n");
	printf("'Add mode': input name:phone_number:memo with option -a.\n");
	printf("'Delete mode': input the number of information that you search with option -d.\n");
	printf("'List mode': input option -l.\n");
}

//add
void tel_add(MEMBER *list, char *name, char *phone, char *memo, int size) 
{	
	printf("%s %s %s\nadd? [Y/N]: ", name, phone, memo);
	char ch = getchar();
	if (ch == 'Y'){ //copy name, phone, memo on the list
		strcpy(list[size].name, name);
		strcpy(list[size].phone, phone);
		strcpy(list[size].memo, memo);

		FILE *fp = fopen("data.txt", "w");//open data.txt with option w
		for(int i = 0; i < size+1; i++) {
			char *input = (char *)malloc(sizeof(char) * MAX_NUM);
			//put name, phone, memo together in one line
			strcpy(input, list[i].name);
			strcat(input, ":");
			strcat(input, list[i].phone);
			strcat(input, ":");
			strcat(input, list[i].memo);
			if(i == size) 
				strcat(input, "\n");
			fputs(input, fp);//put to the data.txt file
		}
		fclose(fp);//close the data.txt file
	}
}

//delete
void tel_delt(MEMBER *list, char *k, int size) 
{
	int smem[size]; //declare integer type array (using for search memeber)
	int count = 0; //declare integer type variable (number of searched member)

	for(int i = 0; i < size; i++) {
		if(strstr(list[i].name, k) != NULL || strstr(list[i].phone, k) != NULL || strstr(list[i].memo, k) != NULL){ //search k in the list
			printf("%d %s %s %s", ++count, list[i].name, list[i].phone, list[i].memo); //if present, print
			smem[count] = i; //save it to smem
		}
	}
	if (count == 0) //no match found
		printf("no match found\n");
	else {
		//select member tha is searched using count
		printf("which one? ");
		int num;
		scanf("%d", &num);

		//move the index one by one and delete
		for(int num2 = smem[num]; num2 < size; num2++)
			list[num2] = list[num2+1];
	
		FILE *fp = fopen("data.txt", "w");//open data.txt with option w
		for(int i = 0; i < size-1; i++) {
			char *input = (char *)malloc(sizeof(char) * MAX_NUM);
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

//list
void tel_list(MEMBER *list, int size) 
{
	int i = 0;//declare integer type variable and initailize
	if (size == 0) //empty member list
		printf("empty\n");
	else if (size == 1) //one member
		printf("%d %s %s %s", i+1, list[i].name, list[i].phone, list[i].memo);
	else if (size >= 2) { //more than two members
		qsort(list, size, sizeof(MEMBER), strcmp);//sort alphabetically
		for(i = 0; i < size; i++) //print memebers
			printf("%d %s %s %s", i+1, list[i].name, list[i].phone, list[i].memo);
	}
}
//search
int tel_srch(MEMBER *list, char *k, int size)
{
        int count = 0;//declare integer type variable (number of searched member)
        //if there is k in list, ++count and print the information of list
        for(int i = 0; i < size; i++) {
                if (strstr(list[i].name, k) != NULL || strstr(list[i].phone, k) != NULL || strstr(list[i].memo, k) != NULL )
                        printf("%d %s %s %s", ++count, list[i].name, list[i].phone, list[i].memo);
        }
        return count;
}

