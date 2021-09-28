//bst using itertive method (insertion , deletion)


//Inorder Algo

/*
        1) Create an empty stack S.
        2) Initialize current node as root
        3) Push the current node to S and set current = current->left until current is NULL
        4) If current is NULL and stack is not empty then
             a) Pop the top item from stack.
             b) Print the popped item, set current = popped_item->right
             c) Go to step 3.
        5) If current is NULL and stack is empty then we are done.

*/


#include<stdio.h>
#include<stdlib.h>
#define MAX 200

struct bst_node
{
    struct bst_node *lchild; //left child
    int data;
    struct bst_node *rchild; //right child
};


struct bst_node *root_ptr;


//stack from iterative traversal , here i'm using stack on array
struct bst_node *stack1[MAX];
int top;



//array of pointers for queue for calculating height nad level order traversal
struct bst_node *queue_of_nodes[MAX];
int front , rear ;


void insert_in_queue(struct bst_node *p)
{
    //printf("Inserted element %d \n ", p->data);

    if(rear==-1)
    {
        //1st node
        front = rear = 0;
    }
    else
        rear++;

    //inserting at rear
    queue_of_nodes[rear] = p;
}



struct bst_node *remove_from_queue()
{
    if(front==-1)
    {
        //empty queue
        return NULL;
    }
    else
    {
        struct bst_node *temp = queue_of_nodes[front];


        //printf("Poped element %d \n ", temp->data);

        if(front == rear)
        {
            front = rear = -1;
            return temp;
        }
        else
        {
            front++;
            return temp;
        }
    }
}


int size_of_queue()
{
    int i,size_q=0;

    if(rear==-1)
        size_q = 0;
    else
    {
        for(i=front;i<=rear;i++)
            size_q++;
    }

    //printf("Size of queue %d \n", size_q);

    return size_q;
}


//calculating height iterative (using queue) , GFG
int tree_height(struct bst_node *p)
{
    if(p==NULL)
        return 0;

    insert_in_queue(p);
    int height = 0;

    while(1)
    {
        int nodeCount = size_of_queue();

        //printf("Node count is %d \n ", nodeCount);

        if(nodeCount == 0)
            return height;

        height++;
        //printf("Height is %d \n",height);

        while(nodeCount > 0)
        {
            struct bst_node *node = queue_of_nodes[front];

            struct bst_node *poped = remove_from_queue();

            if(node->lchild!=NULL)
                insert_in_queue(node->lchild);
            if(node->rchild!=NULL)
                insert_in_queue(node->rchild);

            nodeCount--;
        }
    }
}



void level_order_traversal(struct node *p)
{
    if(p==NULL)
        return;

    insert_in_queue(p);


    while(size_of_queue())
    {
        struct bst_node *popped_node = remove_from_queue();

        printf("%d  ",popped_node->data);

        if(popped_node->lchild!=NULL)
            insert_in_queue(popped_node->lchild);

        if(popped_node->rchild!=NULL)
            insert_in_queue(popped_node->rchild);

    }
}


void insert_in_bst()
{
    struct bst_node *temp;

    int key;

    printf("Enter the data of the node you want to insert in the BST \n");
    scanf("%d",&key);

    temp = (struct bst_node *)malloc(sizeof(struct bst_node));

    temp->data = key;
    temp->lchild = NULL;
    temp->rchild = NULL;



    // If the root is NULL i.e the tree is empty
    // The new node is the root node
    if (root_ptr == NULL)
        root_ptr = temp;
    else
    {
        struct bst_node *x = root_ptr;
        struct bst_node *y;

        while (x != NULL)
        {
            y = x;
            if (key <= x->data)
                x = x->lchild;
            else
                x = x->rchild;
        }

        // If the new key is less then the leaf node key
        // Assign the new node to be its left child
        if (key < y->data)
            y->lchild = temp;
        else
            y->rchild = temp;

    }

}


void inorder_recursive(struct bst_node *p)
{
    //ascending
    if(p == NULL)
        return;

    inorder_recursive(p->lchild);
    printf("%d ",p->data);
    inorder_recursive(p->rchild);
}



void push_in_stack1(struct bst_node *p)
{
    if(top==-1)
        top=0;
    else
        top++;

    stack1[top] = p;
}


struct bst_node *pop_from_stack1()
{
    struct bst_node *poped;

    poped = stack1[top];
    top--;

    return poped;
}


int stack1_is_Empty()
{
    if(top==-1)
        return 1;//true
    else
        return 0;//false
}


void inorder_iterative(struct bst_node *p)
{
    //gfg
    //using stack1 from implementation

    int done = 0;
    struct bst_node *current , *popped_item;

    current = p;

    while(!done)
    {
        if(current!=NULL)
        {
            push_in_stack1(current);
            current = current->lchild;
        }
        else
        {
            if(!stack1_is_Empty())
            {
                popped_item = pop_from_stack1();
                printf("%d ",popped_item->data);
                current = popped_item->rchild;
            }
            else
                done = 1;
        }
    }
}

void preorder_recursive(struct bst_node *p)
{
    //ascending
    if(p == NULL)
        return;

    printf("%d ",p->data);
    preorder_recursive(p->lchild);
    preorder_recursive(p->rchild);
}


void postorder_recursive(struct bst_node *p)
{
    //ascending
    if(p == NULL)
        return;

    postorder_recursive(p->lchild);
    postorder_recursive(p->rchild);
    printf("%d ",p->data);
}


// iterative method
int search_in_tree(struct bst_node * p , int x)
{
    int flag = 0;
    while(p!=NULL)
    {
        if(x < p->data)
            p = p->lchild;
        else if(x > p->data)
            p = p->rchild;
        else if(x == p->data)
        {
            flag = 1;
            break;
        }
    }

    /*
    if(flag==1)
        printf("Element Found \n");
    else
        printf("Element Not Found \n");
    */

    return flag;

}


void MIN_in_tree()
{
    //last node in the leftmost part is the smallest

    if(root_ptr==NULL)
        printf("Tree is empty \n");
    else
    {
        struct bst_node *p = root_ptr;
        while(p->lchild!=NULL)
            p = p->lchild;

        printf("Smallest node is %d \n", p->data);
    }
}



void MAX_in_tree()
{
    //last node in the rightmost part is the largest

    if(root_ptr==NULL)
        printf("Tree is empty \n");
    else
    {
        struct bst_node *p = root_ptr;
        while(p->rchild!=NULL)
            p = p->rchild;

        printf("Largest node is %d \n", p->data);
    }
}



//displaying tree
void show(struct bst_node *p, int space)
{
    int i;
    if(p){
        show(p->rchild,space+=6);
        printf("\n");
        for(i=0;i<space;i++)
            printf(" ");
        printf("%d ",p->data);
        printf("\n");
        show(p->lchild,space);
     }
}




void delete_a_node()
{
    int del_key;
    printf("Enter the value of the node to be deleted \n");
    scanf("%d",&del_key);

    //searching node and its parent
    struct bst_node *p , *parent , *successor , *parent_successor , *child;

    p = root_ptr;
    parent = NULL;

    //searching the node
    while(p!=NULL)
    {
        if(p->data == del_key)
            break;

        parent = p;
        if(del_key < p->data)
            p = p->lchild;
        else
            p = p->rchild;
    }

    if(p==NULL)
    {
        printf("Element not found \n");
        return;
    }

    //Case C : 2 childrens
    // find inorder  successor or inorder predecissor of the node , here we are finding inorder successor
    if(p->lchild !=NULL && p->rchild!=NULL)
    {
        parent_successor = p;
        successor = p->rchild;

        //inorder successor is the smallest element in the right subtree
        while(successor->lchild!=NULL)
        {
            parent_successor = successor;
            successor = successor->lchild;
        }
        p->data = successor->data; //swapping values
        p = successor;
        parent = parent_successor; //now we check if the node to be deleted has any child (can have only right child) or not i.e case A and B
    }


    //case B and case A : 1 or no child
    if(p->lchild!=NULL) // this will happen when the node has one child only i.e case B
        child = p->lchild;
    else //node has right child or no child
        child = p->rchild;

    //node to be deleted is the root node
    if(parent==NULL)
        root_ptr = child;
    else if(p == parent->lchild) //node to be deleted is the left child of its parent
        parent->lchild = child;
    else
        parent->rchild = child;

    free(p);
}

main()
{
    root_ptr = NULL;
    front = -1;
    rear = -1;
    top = -1;

    int choice,x,s,srch;
    do
    {
        printf("Press 0 to exit \n");
        printf("Press 1  to insert elements  in the tree \nPress 2 to display the tree \nPress 3 to search an element \n");
        printf("Press 4 to get Inorder traversal recursively \n");
        printf("Press 5 to get Preorder traversal recursively \n");
        printf("Press 6 to get Postorder traversal recursively \n");
        printf("Press 7 to get smallest number in the tree \n");
        printf("Press 8 to get the largest number in the tree \n");
        printf("Press 9 to get the height  of the tree \n");
        printf("Press 10 to get the level order traversal  of the tree \n");
        printf("Press 11 to delete a node from the tree \n");
        printf("Press 12 to get the Inorder Traversal iteratively \n");



        printf("Enter a choice \n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 0:
                printf("Exit \n");
                break;
            case 1:
                insert_in_bst();
                break;
            case 2:
                show(root_ptr,0);
                break;
            case 3:
                    printf("Enter a number to be searched \n");
                    scanf("%d",&x);
                    srch = search_in_tree(root_ptr,x);

                    if(srch==1)
                        printf("Element Found \n");
                    else
                        printf("Element Not Found \n");

                    break;
            case 4:
                inorder_recursive(root_ptr);
                break;
            case 5:
                preorder_recursive(root_ptr);
                break;
            case 6:
                postorder_recursive(root_ptr);
                break;
            case 7:
                MIN_in_tree();
                break;
            case 8:
                MAX_in_tree();
                break;
            case 9:
                s = tree_height(root_ptr);
                printf("Height of the tree is %d \n",s);
                break;
            case 10:
                level_order_traversal(root_ptr);
                break;
            case 11 :
                delete_a_node();
                break;
            case 12 :
                inorder_iterative(root_ptr);
                break;
            default:
                printf("Please enter correct choice \n");
                break;
        }
    }while(choice != 0);
}






