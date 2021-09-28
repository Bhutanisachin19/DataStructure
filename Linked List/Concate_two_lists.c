//creating 2 lists and concating them

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node  *createList(struct node *start)
{
    //inserting at the beginning only
    int i,n, val;
    printf("Enter the no of nodes: ");
    scanf("%d",&n);

    if(n<=0)
    printf("This list will be empty 0\n");
    else
    {
        struct node *temp,*p;
        for(i=0;i<n;i++)
        {
            temp = (struct node *)malloc(sizeof(struct node));
            //temp->next = NULL;

            printf("Please enter the value of the node \n");
            scanf("%d",&temp->data);

            if(start==NULL )
            {
                temp->next=start;
                start=temp;
            }
            else
            {
                p=start;
                while(p->next!=NULL)
                    p=p->next;

                temp->next=p->next;
                p->next=temp;
            }
        }
        //return start;
    }
    return start;
}

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

struct node *concate_lists(struct node *p1, struct node *p2)
{
    struct node *con_list;
    if(p1==NULL)
    {
        p1 = p2;
        return p1;
    }
    if(p2==NULL)
        return p1;

    con_list = p1;
    while(con_list->next !=NULL)
        con_list = con_list->next;

    con_list->next = p2;
    return p1;
};


main()
{

    struct node *p1=NULL,*p2=NULL,*p3;
    p1 = createList(p1);
    p2 = createList(p2);


	printf("First list is  : ");
	display(p1);
	printf("Second list is  : ");
	display(p2);
	p3 = concate_lists(p1,p2);
	printf("Final list is ");
	display(p3);

}
