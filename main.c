#include <stdio.h>
#include <stdlib.h>
const int max = 100;
struct student{
    char ID[8];
    char name[40];
    char dob[10];
    char gender[10];
    char faculty[50];
    int age;
    double gpa;
    char aca_rating[8];
};
void addStudent(struct student studentList[], int *size);
void showStudent(struct student studentList[], int size);
void sortStudentByGPA(struct student studentList[],int size);
void sortStudentByName(struct student studentList[], int size);
int findIndexByID(struct student studentList[], int size, char key[]);
void findStudentByID(struct student studentList[], int size, char key[]);
void removeStudent(struct student studentList[], int *size, char key[]);

int main()
{
    struct student studentList[max];
    int size = 0;
    int choice;
    char buffer;
    char key[max];
    do{
        showMenu();
        do{
            printf("\nEnter your choice: ");
            scanf("%d",&choice);
            scanf("%c",&buffer);
            if(buffer != 10) printf("nInvalid");
        }while(buffer != 10);
        switch(choice){
            case 1:{
                addStudent(studentList,&size);
                break;
            }
            case 2:{
                showStudent(studentList,size);
                break;
            }
            case 3:{
                sortStudentByName(studentList,size);
                break;
            }
            case 4:{
                sortStudentByGPA(studentList,size);
                break;
            }
            case 5:{
                printf("\nEnter ID: ");
                gets(key);
                findStudentByID(studentList,size,key);
                break;
            }
            case 6:{
                printf("\nEnter ID: ");
                gets(key);
                removeStudent(studentList,&size,key);
                break;
            }
            case 7:{
                printf("\nExit program");
                break;
            }
            default:{
                printf("\nInvalid");
                break;
            }
        }
    }while(choice != 7);
    return 0;
}
void showMenu(){
    printf("\n1.Add Student infomation: ");
    printf("\n2.Show student list: ");
    printf("\n3.Sorting student by Name: ");
    printf("\n4.Sorting student by ID: ");
    printf("\n5.Find student ID: ");
    printf("\n6.Remove student: ");
    printf("\nExit");
}
void addStudent(struct student studentList[], int *size){
    printf("\n===ADD STUDENT TO LIST===");
    printf("\n---------------------------------");

    while(1==1){
        int isFound = 0;
        printf("\nEnter Student ID: ");
        gets(studentList[*size].ID);

        for(int i = 0; i <= *size - 1;i++){
            if(strcmp(studentList[i].ID,studentList[*size].ID) == 0){
                isFound = 1;
            }
        }
        if(isFound == 1){
            printf("ID is duplicated!");
        }else break;
    }
    printf("\nEnter Student Name: ");
    gets(studentList[*size].name);

    printf("\nEnter Student Birthday with format [dd/mm/yyyy]: ");
    gets(studentList[*size].dob);

    printf("\nEnter Student Gender: ");
    gets(studentList[*size].gender);

    printf("\nEnter Student Faculty: ");
    gets(studentList[*size].faculty);

    printf("\nEnter Student Age: ");
    scanf("%d",&studentList[*size].age);


    do{
        printf("\nEnter Student gpa: ");
        scanf("%lf",&studentList[*size].gpa);
        if(studentList[*size].gpa < 0 || studentList[*size].gpa > 10){
            printf("\nInvalid");
        }
    }while(studentList[*size].gpa < 0 || studentList[*size].gpa > 10);



    if(studentList[*size].gpa >= 5 && studentList[*size].gpa < 6.5){
        strcpy(studentList[*size].aca_rating,"TB");
    }else if(studentList[*size].gpa >= 6.5 && studentList[*size].gpa < 7.5){
        strcpy(studentList[*size].aca_rating,"Kha");
    }else if(studentList[*size].gpa >= 7.5 && studentList[*size].gpa < 8.5){
        strcpy(studentList[*size].aca_rating,"Gioi");
    }else if(studentList[*size].gpa >= 8.5 && studentList[*size].gpa <=10){
        strcpy(studentList[*size].aca_rating,"Xuat sac");
    }

    (*size)++;
}

void showStudent(struct student studentList[], int size){
    printf("\n%-15s%-30s%-20s%-10s%-10s%10s%10s%20s","ID","Name","Birthday",
           "Gender","Faculty","Age","Gpa","Rating");
    printf("\n----------------------------------------------------------------------------------------------------------------------------------");
    for(int i = 0; i <= size - 1;i++){
        printf("\n%-15s%-30s%-20s%-10s%-10s%10d%10.1lf%20s",studentList[i].ID,
               studentList[i].name,studentList[i].dob,studentList[i].gender,
               studentList[i].faculty,studentList[i].age,studentList[i].gpa,
               studentList[i].aca_rating);
    }
}

void sortStudentByGPA(struct student studentList[],int size){
    for(int i = 0; i <= size - 2;i++){
        for(int j = 1; j <= size - 1;j++){
            if(studentList[i].gpa <= studentList[j].gpa){
            char tmp[max];

            strcpy(tmp,studentList[i].ID);
            strcpy(studentList[i].ID,studentList[j].ID);
            strcpy(studentList[j].ID,tmp);

            strcpy(tmp,studentList[i].name);
            strcpy(studentList[i].name,studentList[j].name);
            strcpy(studentList[j].name,tmp);

            strcpy(tmp,studentList[i].dob);
            strcpy(studentList[i].dob,studentList[j].dob);
            strcpy(studentList[j].dob,tmp);

            strcpy(tmp,studentList[i].gender);
            strcpy(studentList[i].gender,studentList[j].gender);
            strcpy(studentList[j].gender,tmp);

            strcpy(tmp,studentList[i].faculty);
            strcpy(studentList[i].faculty,studentList[j].faculty);
            strcpy(studentList[j].faculty,tmp);

            int temp = studentList[i].age;
            studentList[i].age = studentList[j].age;
            studentList[j].age = temp;

            double dTmp = studentList[i].gpa;
            studentList[i].gpa = studentList[j].gpa;
            studentList[j].gpa = dTmp;

            strcpy(tmp,studentList[i].aca_rating);
            strcpy(studentList[i].aca_rating,studentList[j].aca_rating);
            strcpy(studentList[j].aca_rating,tmp);
            }
        }
    }
    printf("\nsorting successfully");
}

void sortStudentByName(struct student studentList[], int size){
    for(int i = 0; i <= size - 2;i++){
        for(int j = 1; j <= size - 1;j++){
            if(strcmp(studentList[i].name,studentList[j].name)==1){
            char tmp[max];

            strcpy(tmp,studentList[i].ID);
            strcpy(studentList[i].ID,studentList[j].ID);
            strcpy(studentList[j].ID,tmp);

            strcpy(tmp,studentList[i].name);
            strcpy(studentList[i].name,studentList[j].name);
            strcpy(studentList[j].name,tmp);

            strcpy(tmp,studentList[i].dob);
            strcpy(studentList[i].dob,studentList[j].dob);
            strcpy(studentList[j].dob,tmp);

            strcpy(tmp,studentList[i].gender);
            strcpy(studentList[i].gender,studentList[j].gender);
            strcpy(studentList[j].gender,tmp);

            strcpy(tmp,studentList[i].faculty);
            strcpy(studentList[i].faculty,studentList[j].faculty);
            strcpy(studentList[j].faculty,tmp);

            int temp = studentList[i].age;
            studentList[i].age = studentList[j].age;
            studentList[j].age = temp;

            double dTmp = studentList[i].gpa;
            studentList[i].gpa = studentList[j].gpa;
            studentList[j].gpa = dTmp;

            strcpy(tmp,studentList[i].aca_rating);
            strcpy(studentList[i].aca_rating,studentList[j].aca_rating);
            strcpy(studentList[j].aca_rating,tmp);
            }
        }
    }
    printf("\nsorting successfully");
}

int findIndexByID(struct student studentList[], int size, char key[]){
    for(int i = 0; i <= size - 1;i++){
        if(strcmp(studentList[i].ID,key) == 0){
            return i;
        }
    }
    return -1;
}

void findStudentByID(struct student studentList[], int size, char key[]){
    int pos = findIndexByID(studentList,size,key);
    if(pos == -1){
        printf("\nInvalid");
    }else{
        printf("\n%-15s%-30s%-20s%-10s%-10s%10d%10.1lf%20s",studentList[pos].ID,
           studentList[pos].name,studentList[pos].dob,studentList[pos].gender,
           studentList[pos].faculty,studentList[pos].age,studentList[pos].gpa,
           studentList[pos].aca_rating);
    }
}

void removeStudent(struct student studentList[], int *size, char key[]){
    int pos = findIndexByID(studentList,*size,key);
    if(pos == -1){
        printf("\nID is not found ");
    }else{
        printf("\nRemove student");
        printf("\n%-15s%-30s%-20s%-10s%-10s%10d%10.1lf%20s",studentList[pos].ID,
               studentList[pos].name,studentList[pos].dob,studentList[pos].gender,
               studentList[pos].faculty,studentList[pos].age,studentList[pos].gpa,
               studentList[pos].aca_rating);
    }
    for(int i = pos; i <= *size - 1;i++){
        strcpy(studentList[i].ID,studentList[i+1].ID);
        strcpy(studentList[i].name,studentList[i+1].name);
        strcpy(studentList[i].dob,studentList[i+1].dob);
        strcpy(studentList[i].gender,studentList[i+1].gender);
        strcpy(studentList[i].faculty,studentList[i+1].faculty);
        studentList[i].age = studentList[i+1].age;
        studentList[i].gpa = studentList[i+1].gpa;
        strcpy(studentList[i].aca_rating,studentList[i+1].aca_rating);
    }
    (*size)--;
    printf("\nRemove successfully");
}











