#include <stdio.h>
#include <stdlib.h>

typedef unsigned int uint32;
typedef unsigned short uint16;
typedef unsigned char uint8;

struct node {
    uint32 nodedate;
    struct node *leftnode;
    struct node *rightnode;
};

struct node *dlinked_1 = NULL;

void Insert_Node_At_Beginning(struct node **list, uint32 Data);
void Insert_Node_At_End(struct node *list, uint32 Data);
void Insert_Node_After(struct node *list, uint32 Data, uint32 position);
void Insert_Node_Before(struct node **list, uint32 Data, uint32 position);
void Delete_Node_At_Beginning(struct node **list);
void Delete_Node_At_End(struct node *list);
void Delete_Node_At_Intermediate(struct node *list, uint32 position);
void Display_All_Nodes_Forward(struct node *list);
void Display_All_Nodes_Reverse(struct node *list);

int main()
{
    Insert_Node_At_Beginning(&dlinked_1, 33);
    Display_All_Nodes_Forward(dlinked_1);
    Insert_Node_At_Beginning(&dlinked_1, 22);
    Display_All_Nodes_Forward(dlinked_1);
    Insert_Node_At_Beginning(&dlinked_1, 11);
    Display_All_Nodes_Forward(dlinked_1);
    printf("----------------------\n");

    Insert_Node_At_End(dlinked_1,44);
    Insert_Node_At_End(dlinked_1,55);
    Display_All_Nodes_Forward(dlinked_1);
    printf("----------------------\n");

    Insert_Node_After(dlinked_1,33,3);
    Display_All_Nodes_Forward(dlinked_1);
    printf("----------------------\n");

    Insert_Node_Before(&dlinked_1,22,2);
    Display_All_Nodes_Forward(dlinked_1);
    printf("----------------------\n");

    Delete_Node_At_Beginning(&dlinked_1);
    Display_All_Nodes_Forward(dlinked_1);
    printf("----------------------\n");


    Delete_Node_At_End(dlinked_1);
    Display_All_Nodes_Forward(dlinked_1);
    printf("----------------------\n");

    Delete_Node_At_Intermediate(dlinked_1,4);
    Display_All_Nodes_Forward(dlinked_1);
    printf("----------------------\n");

    Delete_Node_At_Intermediate(dlinked_1,2);
    Display_All_Nodes_Forward(dlinked_1);
    printf("----------------------\n");

    Display_All_Nodes_Reverse(dlinked_1);
    printf("----------------------\n");

    return 0;
}


void Insert_Node_At_Beginning(struct node **list, uint32 Data){
    struct node *tempnode = NULL;

    tempnode = (struct node *)malloc(sizeof(struct node));
    if(NULL != tempnode){
        tempnode->nodedate = Data;
        if((*list) == NULL){
            tempnode->leftnode = NULL;
            tempnode->rightnode = NULL;
            (*list) = tempnode;
        }
        else{
            tempnode->leftnode = NULL;
            tempnode->rightnode = (*list);
            (*list)->leftnode = tempnode;
            (*list) = tempnode;
        }
    }
    else{
        printf("can't insert any node \n");
    }
}


void Insert_Node_At_End(struct node *list, uint32 Data){
    struct node *tempnode = NULL;
    struct node *listcounter = NULL;

    tempnode = (struct node *)malloc(sizeof(struct node));
    if(tempnode != NULL){
        tempnode->nodedate = Data;
        tempnode->rightnode = NULL;
        listcounter = list;
        while(NULL != listcounter->rightnode){
            listcounter = listcounter->rightnode;
        }
        tempnode->leftnode = listcounter;
        listcounter->rightnode = tempnode;
    }
    else{
        printf("can't insert any node \n");
    }
}


void Insert_Node_After(struct node *list, uint32 Data, uint32 position){
    struct node *listcounterone = list;
    struct node *listcountertwo = NULL;
    struct node *tempnode = NULL;
    uint32 linkedposition = position;


    tempnode = (struct node *)malloc(sizeof(struct node));
    if(NULL != tempnode){
       tempnode->nodedate = Data;

       while(linkedposition != 1){
          listcounterone = listcounterone->rightnode;
          linkedposition--;
       }
       if(NULL == listcounterone->rightnode){
        listcounterone->rightnode = tempnode;
        tempnode->leftnode = listcounterone;
        tempnode->rightnode = NULL;
       }
       else{
        listcountertwo = listcounterone->rightnode;
        tempnode->leftnode = listcounterone;
        tempnode->rightnode = listcountertwo;
        listcounterone->rightnode = tempnode;
        listcountertwo->leftnode = tempnode;
       }
    }
    else {
        printf("can't insert any node \n");
    }
}


void Insert_Node_Before(struct node **list, uint32 Data, uint32 position){
    struct node *tempnode = NULL;
    struct node *listnodetwo = NULL;
    struct node *listnodeone = NULL;
    uint32 listposition = position;

    listnodeone = (*list);
    while(listposition > 2){
        listnodeone = listnodeone->rightnode;
        listposition--;
    }
    tempnode = (struct node *)malloc(sizeof(struct node));
    if(NULL != tempnode){
       tempnode->nodedate = Data;
       if(1 == position){
        tempnode->leftnode = NULL;
        tempnode->rightnode = *list;
        (*list)->leftnode = tempnode;
        *list = tempnode;
       }
       else{
        listnodetwo = listnodeone->rightnode;
        listnodeone->rightnode = tempnode;
        listnodetwo->leftnode = tempnode;
        tempnode->leftnode = listnodeone;
        tempnode->rightnode = listnodetwo;
       }
   }
    else{
        printf("Can't allocate the new node !! \n");
    }
}


void Delete_Node_At_Beginning(struct node **list){
    struct node *tempnode = (*list);

    *list = (*list)->rightnode;
    (*list)->leftnode = NULL;

    free(tempnode);
    tempnode = NULL;
}


void Delete_Node_At_End(struct node *list){
    struct node *listnodeone = NULL;
    struct node *listnodetwo = NULL;

    listnodeone = list;
    while(listnodeone->rightnode != NULL){
        listnodeone = listnodeone->rightnode;
    }
    listnodetwo = listnodeone->leftnode;
    listnodetwo->rightnode = NULL;
    free(listnodeone);
    listnodeone = NULL;
}


void Delete_Node_At_Intermediate(struct node *list, uint32 position){
    struct node *listnodeone = list;
    struct node *listnodetwo = NULL;
    uint32 nodeposition = position;

    if(1 == nodeposition){
        printf("please use Delete_Node_At_Beginning \n");
    }
    else{
        while(nodeposition > 1){
            listnodeone = listnodeone->rightnode;
            nodeposition--;
        }
        listnodetwo = listnodeone->leftnode;
        listnodetwo->rightnode = listnodeone->rightnode;
        listnodeone->rightnode->leftnode = listnodetwo;
        free(listnodeone);
        listnodeone = NULL;
    }
}


void Display_All_Nodes_Forward(struct node *list){
    struct node *tempnode = list;

    printf("date : ");
    printf("%i == ",tempnode->nodedate);

    while(tempnode->rightnode != NULL){
    tempnode = tempnode->rightnode;
    printf("%i == ",tempnode->nodedate);
    }
    if(NULL == tempnode->rightnode){
    printf("NULL\n");
    printf("\n");
        }
}


void Display_All_Nodes_Reverse(struct node *list){
    struct node *tempnode = list;

    printf("date : ");
    while(tempnode->rightnode != NULL){
        tempnode = tempnode->rightnode;
    }
    while(tempnode != NULL){
        printf("%i == ",tempnode->nodedate);
        tempnode = tempnode->leftnode;
    }
    if(tempnode == NULL){
        printf("NULL\n");
    }
}
