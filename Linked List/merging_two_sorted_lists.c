
/*
    merging two sorted lists
    1 creating new merged list
    2 rearranging links
*/


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
    printf("Creating list callled \n");
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



struct node *Merge_in_new(struct node *p1 , struct node *p2)
{

    //creating new merged sorted linked list
    if(p1 == NULL)
        return p2;

    if(p2 == NULL)
        return p1;

    struct node *Merged=NULL, *p3 ,*temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->next = NULL;
    Merged = temp;


    if(p1->data <= p2->data)
    {
        temp->data = p1->data;
        p1 = p1->next;
    }
    else
    {
        temp->data = p2->data;
        p2 = p2->next;
    }


    p3 = Merged; //for merged list

    while(p1!=NULL && p2!=NULL)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        if(p1->data <= p2->data)
        {
                //temp = (struct node *)malloc(sizeof(struct node));
                temp->data = p1->data;
                temp->next = NULL;
                p3->next = temp;
                p3 = temp;
                p1=p1->next;
        }
        else
        {
                //temp = (struct node *)malloc(sizeof(struct node));
                temp->data = p2->data;
                temp->next = NULL;
                p3->next = temp;
                p3 = p3->next;
                p2=p2->next;

        }

    }

        while(p1!=NULL)
        {
                temp = (struct node *)malloc(sizeof(struct node));
                temp->data = p1->data;
                temp->next = NULL;
                p3->next = temp;
                p3 = temp;
                p1=p1->next;
        }


        while(p2!=NULL)
        {
                temp = (struct node *)malloc(sizeof(struct node));
                temp->data = p2->data;
                temp->next = NULL;
                p3->next = temp;
                p3 = temp;
                p2=p2->next;
        }
    return Merged;
}



struct node  *merge_by_rearranging(struct node *p1,struct node *p2)
{
    struct node *merg ,*ptrM , *ptr1 , *ptr2;

    ptr1 = p1;
    ptr2 = p2;

    if(p1->data <= p2->data)
    {
        merg = ptrM = p1;
        ptr1 = ptr1->next;
    }
    else
    {
        merg = ptrM = p2;
        ptr2 = ptr2->next;
    }

    while(ptr1!=NULL && ptr2!=NULL)
    {
        if(ptr1->data <= ptr2->data)
        {
            ptrM->next = ptr1;
            ptrM = ptrM->next;
            ptr1 = ptr1->next;
        }
        else
        {
            ptrM->next = ptr2;
            ptrM = ptrM->next;
            ptr2 = ptr2->next;
        }
    }

    if(ptr1==NULL)
        ptrM->next = ptr2;
    else
        ptrM->next =ptr1;


    return merg;
}


main()
{
    int num,i;
    struct node *list1=NULL,*list2 = NULL,*result, *result2;


    printf("Enter the number of node for 1st list \n");
    scanf("%d",&num);

    for(i=0;i<num;i++)
    {
        list1= create_sorted_list(list1);
    }



    printf("Enter the number of node for 2nd list \n");
    scanf("%d",&num);

    for(i=0;i<num;i++)
    {
        list2= create_sorted_list(list2);
    }

    printf("1st list is \n");
    display(list1);


    printf("2nd list is \n");
    display(list2);


    result = Merge_in_new(list1 , list2);
    printf("Sorted Merged list by creating a new list is \n");
    display(result);

    result2 = merge_by_rearranging(list1,list2);
    printf("Sorted Merged list by rearranging the lists is \n");
    display(result2);


}


