/* CS261- Assignment 1 - Q.1*/
/* Name: Aldiansyah
 * Date:
 * Solution description:
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct student{
    int id;
    int score;
};

struct student* allocate() {
    /* Allocate memory for ten students */
    int n=10;
    struct student* stud=malloc(n *sizeof(struct student));
    /* return the pointer */
    return stud;
}


void generate(struct student* students) {
    /*
     * Generate random ID and scores for 10 students, ID being between
     * 0 and 9, scores equal to (id * 10) % 50.
     */
    int i, n=10;
    int x;
    printf("ID\t Score\n");
    printf("---\t------\n");
    
    for (i=0;i<n;i++){
        students[i].id = i;
        x=(10*i)%50;
        students[i].score=x;
   					
   					
        
        
    }
}

void output(struct student* students) {
    /*
     * Output information about the ten students in the format:
     *
     *   ID0 Score0
     *   ID1 score1
     *   ID2 score2
     *   ...
     *   ID9 score9
     */
    for (int i=0;i<10;i++){
        
   					
        printf("ID%d\t %d\n",students[i].id,students[i].score);
    }
    
}

int min(struct student* students) {
    /* return the minimum score */
    int minimum;
    int i;
    minimum=students[0].score;
    for (i=1;i<10;i++)
        if(students[i].score<minimum)
            minimum = students[i].score;
    
    return minimum;
}

float avg(struct student* students) {
    /* return the average score */
    float Total=0;
    for (int i=0;i<10;i++)
        Total += students[i].score;
    return Total/10;
}


void sort(struct student* students){
    /* return the average score */
    int i,j, sort;
    for (i=0;i<10;i++)
        for (j=i+1;j<10;j++)
            if (students[i].score<students[j].score) {
                sort=students[j].score;
                students[j].score=students[i].score;
                students[i].score=sort;
                
            }
}

void deallocate(struct student* stud) {
    /* Deallocate memory from stud */
    if (stud!=0){
        free(stud);
    }
}

int main(){
    struct student* stud = allocate();
    generate(stud);
    output(stud);
    sort(stud);
    for (int i=0; i<10; i++) {
        printf("%d %d\n", stud[i].id, stud[i].score);
    }
    printf("Avg: %f \n", avg(stud));
    printf("Min: %d \n", min(stud));
    return 0;
}
