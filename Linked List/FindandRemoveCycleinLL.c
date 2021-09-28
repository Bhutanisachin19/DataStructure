/*
Finding and removing a cycle in linked list
using hare and tortoise algo
*/


#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};

void display(struct node *p,int s)
{
    int count = 1;

    printf("Displaying the list using disp function \n");
    struct node *temp;
	if(p==NULL)
	{
		printf("List is empty\n");
		return;
	}
	temp=p;
	while(temp!=NULL)
	{
		if(count > s)
        {
            printf("List contains cycle \n");
            break;
        }

		printf("%d ", temp->data);
		temp=temp->next;
		count++;
	}
	printf("\n");
}


struct node *create_sorted_list(struct node *p)
{
    printf("Creating list called \n");
    struct node *temp,*start;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Please enter the value of the node \n");
    scanf("%d",&temp->data);

    temp->next = NULL;


    //if 1st node
    if(p == NULL)
    {
        p = temp;
        return p;
    }
    else if(p->data > temp->data)
    {
        //insert at beginning
        temp->next = p;
        p = temp;
        return p;
    }
    else
    {
        start = p;
        while(start->next != NULL && start->next->data <= temp->data)
            start = start->next;

        temp->next = start->next;
        start->next = temp;
        return p;
    }
}


void create_cycle(struct node *List1,int s)
{
    // s is the size of list used to display the new list below

    //taking a position from user which the last node will point to , to create a cycle
    int num,i,new_size;
    printf("Enter the position where you want the last node to point to \n");
    scanf("%d",&num);

    if(num>s || num <0)
    {
        printf("Position does not exist \n");
        return;
    }

    struct node *p,*p1,*temp;
    p = List1;

    //goto the last node to make its next = the inserted pos
    i = 1;
    while(p->next!=NULL)
    {
        if(i == num)
            p1 = p;

        i++;
        p=p->next;
    }


    //last node pointing to the given pos to create cycle
    p->next = p1;

    new_size = s + (s-num);
    temp= List1;
    printf("Displaying the new list with cycle \n");
    while(new_size >= 0)
    {
		printf("%d ", temp->data);
		temp=temp->next;
		new_size--;
    }
    printf("\n");
}


struct node  *find_cycle(struct node *List1)
{
    /*
    find cycle without using size of linked list
    here we are using the hare and tortoise algo
    */
    struct node *slowP , *fastP;

    if(List1->next ==NULL)
        return NULL;

    slowP = fastP = List1;

    //cases for odd and even no of elements in liked list
    while(fastP!=NULL && fastP->next!=NULL)
    {
        slowP=slowP->next; // 1 node at a time
        fastP=fastP->next->next; // 2 nodes at a time

        //if they meet it means there's a cycle
        if(slowP==fastP)
            return slowP; //will be used in remove cycle
    }
    return NULL;//no cycle

}

void remove_cycle(struct node *List1, struct node *cyc)
{
    //cyc pointer where slow and fast pointer met in above function

    struct node *p,*q;
    int i, lenCycle ,lenRemList ,lengthList;

    printf("Node at which cycle was detected %d \n",cyc->data);

    p=q=cyc;
    lenCycle = 0;

    do{
        lenCycle++;
        q=q->next;
    }while(p!=q);

    printf("length of cycle is %d \n",lenCycle);

    lenRemList=0;
    p=List1;
    while(p!=q)
    {
        lenRemList++;
        p=p->next;
        q=q->next;
    }

    printf("Number of nodes not included in the cycle  are %d \n",lenRemList);

    lengthList = lenCycle + lenRemList;
    printf("Length of remaining list is %d \n",lengthList);

    p=List1;
    for(i=1;i<=lengthList-1;i++)
        p=p->next;

    p->next=NULL;//last node
}


main()
{
    struct node *List1=NULL,*find_cyc;
    int s,i;
    printf("Enter the size of linked list \n");
    scanf("%d",&s);

    for(i=0;i<s;i++)
    {
        List1 = create_sorted_list(List1);
    }
    display(List1,s);
    create_cycle(List1 , s);
    display(List1,s);
    find_cyc = find_cycle(List1);

    if(find_cyc == NULL)
        printf("List does not have a cycle \n");
    else
    {
        printf("Calling remove list function to remove the cycle \n");
        remove_cycle(List1,find_cyc);
    }

    display(List1,s);
}





