#include <stdio.h>
#include <stdlib.h>

typedef unsigned int uint32;
typedef unsigned short uint16;
typedef unsigned char uint8;

struct node {
    uint32 nodedate;
    struct node *nodelink;
};

void Insert_Node_At_Beginning(struct node **List);
void Insert_Node_At_End(struct node **List);
void Insert_Node_After(struct node *List);
void Delete_Node_At_Beginning(struct node **List);
void Delete_Node(struct node *List);
void Display_All_Nodes(struct node *List);
uint32 Get_Length(struct node *List);

struct node *ListHead = NULL;

uint8 choice = 0;
uint32 lengh = 0;

int main()
{

    printf("welcome to single list \n");
    while (1){
        printf("\n");
        printf("===============================\n");
        printf(" 1) Insert Node At Beginning \n");
        printf(" 2) Insert Node At End \n");
        printf(" 3) Insert Node After \n");
        printf(" 4) Delete Node At Beginning \n");
        printf(" 5) Delete Node \n");
        printf(" 6) Display All Nodes \n");
        printf(" 7) Get Length \n");
        printf(" 8) exit from application \n");
        printf("===============================\n");

        printf("enter choice ");
        scanf("%i",&choice);

        switch(choice){
           case 1:
               Insert_Node_At_Beginning(&ListHead);
           break;
           case 2:
               Insert_Node_At_End(&ListHead);
           break;
           case 3:
               Insert_Node_After(ListHead);
           break;
           case 4:
               Delete_Node_At_Beginning(&ListHead);
           break;
           case 5:
               Delete_Node(ListHead);
           break;
           case 6:
               Display_All_Nodes(ListHead);
           break;
           case 7:
               lengh = Get_Length(ListHead);
               printf("number of elements = %i",lengh);
           break;
           case 8:
               printf("exit from application \n");
               exit(1);
           break;
           default:
               printf("ERROR !! out of range \n");
           break;

        }
    }





    return 0;
}

void Insert_Node_At_Beginning(struct node **List){
    struct node *tempnode = NULL;

    tempnode = (struct node *)malloc(sizeof(struct node));
    if(NULL != tempnode){
        printf("enter value =  ");
        scanf("%i",&tempnode->nodedate);
        if(NULL == *List){
            tempnode->nodelink = NULL;
            *List = tempnode;
        }
        else{
            tempnode->nodelink = *List;
            *List = tempnode;
        }
    }


}


void Insert_Node_At_End(struct node **List){
    struct node *tempnode = NULL;
    struct node *lastnode = NULL;

    tempnode = (struct node *)malloc(sizeof(struct node));
    if(NULL != tempnode){
        printf("enter value =  ");
        scanf("%i",&tempnode->nodedate);
        tempnode->nodelink = NULL;

        if(NULL == *List){
            *List = tempnode;
        }
        else{
            lastnode = *List;
            while(lastnode->nodelink != NULL){
                lastnode = lastnode->nodelink;
            }
        lastnode->nodelink = tempnode;
        }
    }
    else{}

}


void Insert_Node_After(struct node *List){
    struct node *tempnode = NULL;
    struct node *nodelistcounter = NULL;
    uint32 nodelengh = 0;
    uint32 nodcounter = 1;
    uint32 nodeposition = 0;

    printf("enter node position (first node position = 1 ) = ");
    scanf("%i",&nodeposition);

    nodelengh = Get_Length(List);
    if(nodeposition > nodelengh){
        printf("error !!\n");
    }
    else{
        nodelistcounter = List;
        while(nodcounter < nodeposition){
            nodcounter++;
            nodelistcounter = nodelistcounter->nodelink;
        }
        tempnode = (struct node *)malloc(sizeof(struct node));
        if(NULL != tempnode){
            printf("enter node date ");
            scanf("%i",&tempnode->nodedate);
            tempnode->nodelink = nodelistcounter->nodelink;
            nodelistcounter->nodelink = tempnode;
        }
        else{}
    }

}


void Delete_Node_At_Beginning(struct node **List){
    struct node *tempnode = *List;
    uint32 lengthnode = 0;

    lengthnode = Get_Length(*List);
    if(lengthnode == 0){
        printf("error !! , can't delete any node \n");
    }
    else{
        *List = tempnode->nodelink;
        tempnode->nodelink = NULL;
        free(tempnode);
    }

}


void Delete_Node(struct node *List){
    struct node *nextnode = List;
    struct node *nodecounter = List;
    uint32 lengthnode = 0;
    uint32 nodeposition = 0;
    uint32 counternode = 1;

    printf("Enter Node Position (First node is position = 1): ");
    scanf("%i", &nodeposition);
    lengthnode = Get_Length(List);
    if((nodeposition > lengthnode) || (lengthnode == 1)){
        printf("error !! , please use Delete_Node_At_Beginning\n");
    }
    else{
        while(counternode < (nodeposition-1)){
            counternode++;
            nodecounter = nodecounter->nodelink;
        }
        nextnode = nodecounter->nodelink;
        nodecounter->nodelink = nextnode->nodelink;
        free(nextnode);
    }

}


void Display_All_Nodes(struct node *List){
    struct node *tempnode = List;

    printf("value : ");
    if(NULL == tempnode){
        printf("list is empty !!\n");
    }
    else{
        while(tempnode != NULL){
            printf(" == %i",tempnode->nodedate);
            tempnode = tempnode->nodelink;
        }
        if(NULL == tempnode){
            printf("NULL\n");
        }
    }

}


uint32 Get_Length(struct node *List){
    struct node *tempnode = List;
    uint32 nodecounter = 0;

    while(tempnode != NULL){
        nodecounter++;
        tempnode = tempnode->nodelink;
    }

  return nodecounter;
}
