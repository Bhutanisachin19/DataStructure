// checking the validity of an expression on the basis of parenthisis

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 500

char expression[MAX];

//stack on LL
struct expression_stack
{
    char c;
    struct expression_stack *next;
};

struct expression_stack *top;

int isEmpty()
{
    //returns true if stack empty
    if(top==NULL)
        return 1;
    else
        return 0;
}

void push(char bracket)
{
    //printf("PUSH WORKING \n");
    struct expression_stack *temp;
    temp = (struct expression_stack *)malloc(sizeof(struct expression_stack));
    temp->c = bracket;
    temp->next = NULL;

    //printf("bracket %c \n",bracket);

    if(top==NULL)
    {
        top = temp;
    }
    else
    {
        temp->next =top;
        top = temp;
    }
}

char pop_element()
{
    struct expression_stack *temp;

    //printf("POP caleed \n");
    char bracket;

    temp = top;
    top=top->next;

    bracket = temp->c;
    //printf("POP FUNCTION %c \n",bracket);
    free(temp);

    return bracket;
}


int valid_expression(int len)
{
    top = NULL;
    int i;
    for(i=0;i<len;i++)
    {
        if(expression[i]=='(' || expression[i]=='{' || expression[i]=='[')
            push(expression[i]);
        else if(expression[i]==')' || expression[i]=='}' || expression[i]==']')
        {
            if(isEmpty())
            {
                //if i call empty() in if condition its not working (was not working)
                printf("Invalid Expression Empty Stack \n");
                return 0; //false
            }
            else
            {
                char bracket = pop_element();
                printf("Popped char is %c \n",bracket);

                if( ( expression[i]==')'&& bracket=='(' ) || (bracket=='{' && expression[i]=='}') || (bracket=='['&& expression[i]==']'))
                    continue;
                else
                {
                    //printf("Invalid expression \n");
                    return 0; //false
                }
            }
        }
    }
    //if only one left bracket in the entire expression
    if(top==NULL)
        return 1;//true
    else
        return 0;//false
}

main()
{
    int n,i;
    scanf("%d",&n);
    int res[n];

    for(i=0;i<n;i++)
    {
        printf("Please enter an expression \n");
        //fgets(expression,MAX,stdin);
        //gets(expression);
        scanf("%s",expression);

        printf("You entered \n");
        puts(expression);

        int len = strlen(expression);

        if(valid_expression(len))
            res[i] = 1;
            //printf("Expression Valid \n");
        else
            res[i] = 0;
            //printf("Expression INVALID \n");
    }


    for(int i=0;i<n;i++)
    {
        if(res[i]==1)
            printf("Valid \n");
        else
            printf("Invalid \n");
    }

}


