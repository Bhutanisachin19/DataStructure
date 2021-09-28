//creating a sorted a linked list

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};

void display(struct node *p)
{
    struct node *temp;
    printf("\n");
	if(p==NULL)
	{
		printf("List is empty\n");
		return;
	}
	temp=p;
	while(temp!=NULL)
	{
		printf("%d ", temp->data);
		temp=temp->next;
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

void hello()
{
    printf("hello \n");
}

main()
{
    char ch;
    int num,i;
    struct node *list_start=NULL;

    /*
    //else and if both are being executed
    while(1)
    {
        printf("Do you want to insert a node \n");
        printf("Press Y for yes and N for no \n");
        scanf("%c",&ch);

        if(ch == 'Y' || ch== 'y')
        {
            list_start = create_sorted_list(list_start);
        }
        else
        {
            hello();
            //break;
        }

    }
    */

    printf("Enter the number of node \n");
    scanf("%d",&num);

    for(i=0;i<num;i++)
    {
        list_start = create_sorted_list(list_start);
    }

    display(list_start);
}


