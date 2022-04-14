#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int ID;
    char name[50];
    float score;
    struct Node* next;

};
//////////////////////////////////////////////////////////////////////////
void printlist(struct Node *start){
    int swapped;
    struct Node *ptr1;
    struct Node *lptr = NULL;
    if (start == NULL){
            printf("    game has no players to print  ");
           return;}
    do{
        swapped = 0;
        ptr1 = start;

        while (ptr1->next != lptr){
            if (ptr1->score > ptr1->next->score){

               float temp = ptr1->score;
               ptr1->score = ptr1->next->score;
               ptr1->next->score = temp;

               int tempid = ptr1->ID;
               ptr1->ID = ptr1->next->ID;
               ptr1->next->ID = temp;

               char tempn[50];
               strcpy(tempn ,ptr1->name );
               strcpy(ptr1->name , ptr1->next->name );
               strcpy(ptr1->next->name ,tempn );
               swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);

        while (start != NULL ){
        printf("\n \n     %d ",start->ID);
        printf("\n     %f ", start->score);
        printf("\n     %s" , start->name);
        start = start->next;
    }
}
///////////////////////////////////////////////////////////////////////////
void addplayer(struct Node** head_ref ,struct Node *head ){
    printf("    id");
    int new_ID;
    float new_score;
    char name [50];
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    scanf("%d", &new_ID);
    struct Node* current = head; // Initialize current
    while (current != NULL)
    {
        if (current->ID == new_ID){
            printf("\n    this id already exist please change it  ");
             return ;
        }
        current = current->next;
    }
    printf("    score");

    scanf("  %f", &new_score);

    printf("    name");
    scanf("  %s" ,&name );

    new_node->ID = new_ID;
    new_node->score = new_score;
    strcpy(new_node->name,name);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
///////////////////////////////////////////////////////////////////////////////////////////
void calc(struct Node *node){
    float sum=0 , avg=0;
    int c=0;
    if(node==NULL){

        printf("\n    no players assigned to this game yet  ");
        return;
    }
    while (node != NULL)
  {
     sum+=node->score;
     c++;
     node = node->next;
  }
  avg=sum/c;
  printf("    avg");
  printf("  %f",avg);
}
///////////////////////////////////////////////////////////////////////////////////////
void max(struct Node *node){
    float max=-1000;
    char name[50];
    if(node==NULL){

        printf("\n    no players assigned to this game yet  ");
        return;
    }
    while (node != NULL){

      if(node->score>max){
        max=node->score;
        strcpy(name,node->name);

      }
     node = node->next;
  }
  printf("\n    max");
  printf("\n   %s",name);
}
/////////////////////////////////////////////////////////////////////////////////////////
void deleteplayer(struct Node **head_ref){
    struct Node* temp = *head_ref, *prev;
    int b ;
    int key ;
    if(temp==NULL){
        printf("\n    game has no players to delete  ");
        return;

    }
    printf("\n    delete player of ID  ");
    scanf("%d",&key);
    while(temp!=NULL){
            if (temp->ID == key){
            b= 1; break;}
        temp = temp->next;
    b= 0 ;

    }
    if(b==0){
        printf("\n    player not found  ");
        return;
    }
    else if(b==1){

    if (temp != NULL && temp->ID == key)    {
        *head_ref = temp->next;
        free(temp);
        printf("\n    player deleted successfully  ");
        return;
    }
    while (temp != NULL && temp->ID != key){
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;
    prev->next = temp->next;

    free(temp);}
}
/////////////////////////////////////////////////////////////////////////////////////////////
void update(struct Node *node){
    int x;
    float y;
    if(node==NULL){
        printf("\n    game has no players to update their score  ");
        return;

    }
    printf ("\n    please enter the player's id you want to modify his score  ");
    scanf("%d",&x);
    while (node != NULL && node->ID != x){
        node = node->next;
    }
    if(node->ID==x){

         printf ("    please enter the the new score  ");
         scanf("%f", &y);
        node->score=y;
        printf("score updated successfully ");
        return;
    }
    printf("    player not found");
}
/////////////////////////////////////////////////////////////////////////////////////////////
int main (){
    struct Node* head = NULL;
    int n = 0;
    system("COLOR 0A");
    printf("\n           A NEW GAME HAS STARTED");
    while (n==0){
    printf("\n\n        please enter your choice");
    printf("\n        press 1 to add a new player ");
    printf("\n        press 2 to update players score given his id");
    printf("\n        press 3 to print the name of the top player with max score");
    printf("\n        press 4 to remove a player by id");
    printf("\n        press 5 to print all the players data sorted by the score ");
    printf("\n        press 6 to calculate avg score\n\n        ");
    scanf("\n %d", &n);
    switch(n) {
        case 1://add a new player
             addplayer(&head , head);break;

        case 2://update players score given his id
             update(head);break;

        case 3://print the name of the top player with max score
             max(head);break;

        case 4://remove a player by id
             deleteplayer(&head);break;

        case 5 :// print all the players data sorted by the score
             printlist(head);break;

        case 6 ://calculate avg score
             calc(head);break ;
    }
    printf("\n   press  any key to quit ");
    printf("\n   press 0 continue");
    scanf("\n  %d", &n);
    system("CLS");
}
}
////////////////////////////////////////////////////////////////////////////////////////
