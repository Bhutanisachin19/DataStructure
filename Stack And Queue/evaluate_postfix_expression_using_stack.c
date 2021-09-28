// First we have to convert is to postfix for that i am using previous code i.e infix_to_postfix using stack


//converting infix to postfix using stack and then evaluating it using stack

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAX 500

struct stack
{
    char value;
    struct stack * next;
};

struct stack *top;

char expression[MAX], postfix[MAX];
int postfix_index =0;

void push_char(char c)
{
    printf("Pushing %c in stack \n",c);
    struct stack *temp;
    temp = (struct stack *)malloc(sizeof(struct stack));
    temp->value = c;
    temp->next = NULL;

    if(top == NULL)
    {
        top = temp;
    }
    else
    {
        temp->next = top;
        top=temp;
    }
}

char pop()
{
    struct stack *temp;
    char c;

    if(top->next==NULL)
    {
        //only one element
        temp = top;
        c = temp->value;
        printf("Poping %c from stack \n",c);
        free(temp);
        top = NULL;
        return c;
    }
    else
    {
        temp = top;
        c = temp->value;
        printf("Poping %c from stack \n",c);
        top = top->next;
        free(temp);
        return c;
    }
}


void display_stack()
{
    if(top==NULL)
        printf("EMPTY STACK \n");
    else
    {
        struct stack *temp;
        temp = top;
        while(temp!=NULL)
        {
            printf("%c ",temp->value);
            temp=temp->next;
        }
    }
}


void add_in_postfix(char c)
{
    // 1st time index will be 0
    postfix[postfix_index] = c;
    postfix_index++;
}

void display_postfix()
{
    int i;
    for(i=0;i<postfix_index;i++)
    {
        printf("%c ",postfix[i]);
    }
}

int check_priority(char c)
{
    switch(c)
    {
    case '^':
        return 3;
    case '*':
    case '/':
    case '%':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        printf("Some Other Operator \n");
    }
}

void operator_case(char c)
{
    //most confusing part
    while(top!=NULL && check_priority(top->value)>=check_priority(c))
    {
        char v = pop();
        add_in_postfix(v);
    }

    push_char(c);

    /*
    if(check_priority(c) > check_priority(top->value))
    {
        push_char(c);
    }
    else
    {
        char v = pop();
        add_in_postfix(v);
    }*/

}


//evaluating the expression

void evaluate()
{
    //using the postfix array (global)
    int final_result;
    int top = -1;

    int stackk[MAX];

    int leng = strlen(postfix);
    int i;



    for(i=0;i<leng;i++)
    {
        //if not an operator push in stack
        if(postfix[i] >='0' && postfix[i]<='9')
        {
            //push to stack
            if(top==-1)
            {
                top = 0;
            }
            else
            {
                top++;
            }
            stackk[top] = postfix[i]-'0'; //converting the asci values to int asci
        }
        else
        {
            //pop top 2 elements from stack
            int one = stackk[top];
            printf("One %d \n",one);
            top = top-1;
            int two = stackk[top];
            printf("Two %d \n",two);

            char c;
            c = postfix[i];
            switch(c)
            {
            case '+':
                stackk[top] = one + two;
                break;

            case '-':
                stackk[top] = two -one;
                break;

            case '*':
                stackk[top] = one * two;
                break;

            case '/':
                stackk[top] = two/one;
                break;

            case '%':
                stackk[top] = two%one;
                break;

            case '^':
                stackk[top] = pow(two,one);
                break;
            }
        }

    }

    final_result = stackk[top];
    printf("Final result is %d \n",final_result);

}

void main()
{
    int i;
    top=NULL;

    printf("Enter a valid expression \n");
    gets(expression);

    printf("You have entered \n");
    puts(expression);


    //scanning the expression
    int l = strlen(expression);

    for(i=0;i<l;i++)
    {
        char c = expression[i];
        printf("Scanning %c \n",c);
        char pop_element;

        switch(c)
        {
            case '+':
            case '*':
            case '/':
            case '-':
            case '^':
            case '%':
                if(top!=NULL)
                {
                    operator_case(c);
                }
                else
                {
                    push_char(c);
                }
                break;
            case '(':
                push_char(c);
                break;
            case ')':
                //pop and add elements from stack to postfix till '('
                    do
                    {
                        pop_element = pop();
                        if(pop_element=='(')
                            continue;
                        else
                            add_in_postfix(pop_element);
                    }while(pop_element!='(');
                    break;
            default:
                add_in_postfix(c);
                break;
        }
    }

    while(top!=NULL)
    {
        char c = pop();
        add_in_postfix(c);
    }

    printf("Stack is \n");
    display_stack();
    printf("\n");

    printf("Postfix expression is \n");
    display_postfix();
    printf("\n");


    printf("****************\n");
    evaluate();

}



















