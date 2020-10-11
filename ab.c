/*
Date of Assignment: 14/09/2020
Date of Submission: 12/10/2020
Problem 6: Case Study of Array using Stack: Write an ADT program for Stack using an
array. Use a method every case to be checked. In general define the following methods.
1. isEmpty()
2. isFull()
3. create() // This method may be omitted/avoided in array based ADT
implementation of Stack.
4. push()
5. pop()
6. peek()/peep()
7. update()
*/
#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>

#define size 10

int stack[size];
int top=-1;

int isEmpty()
{
    if(top==-1)
    {
        return 1;
    }
    return 0;
}

int isFull()
{
    if(top == size-1)
    {
        return 1;
    }
    return 0;
}

void push(int data)
{
    if(isFull())
    {
        printf("Overflow!\n");
        return;
    }
    top += 1;
    stack[top]=data;
}

int pop()
{
    if(isEmpty())
    {
        printf("Underflow!\n");
        return -1;
    }
    int del_element = stack[top];
    top -= 1;
    return del_element;
}

int peek(int index)
{
    if(isEmpty())
    {
        printf("Underflow!\n");
        return -1;
    }
    int stack2[size],top2=-1,element=-1;
    for(int i=0;i<index;i++)
    {
        if(i == index-1)
        {
            element = stack[top];
        }
        else
        {
            top2 += 1;
            stack2[top2] = pop();
        }
    }

    for(int i=0; i<=top2 ; i++)
    {
        push(stack2[top2]);
        top2 -= 1;
    }
    return element;
}

int main()
{
    int option=0;
    while(1)
    {
        system("cls");
        printf("=====================================\n");
        printf("               MAIN MENU\n");
        printf("=====================================\n");
        printf("[1]Check Stack Empty\n");
        printf("[2]Check Stack Full\n");
        printf("[3]Push\n");
        printf("[4]Pop\n");
        printf("[5]Peek\n");
        printf("[6]Update\n");
        scanf("%d",&option);
        switch(option)
        {
        case 1:
        {
            if(isEmpty())
            {
                printf("Underflow!\n");
            }
            else
            {
                printf("Not underflow!\n");
            }
        }
        break;
        case 2:
        {
            if(isFull())
            {
                printf("Overflow!\n");
            }
            else
            {
                printf("Not overflow!\n");
            }
        }
        break;
        case 3:
        {
            int element;
            printf("Enter the element to push\n");
            scanf("%d",&element);
            push(element);
        }
        break;
        case 4:
        {
            int del_ele = pop();
            if(!(del_ele==-1))
            {
                printf("The element deleted is:%d\n",del_ele);
            }
        }
        break;
        case 5:
        {
            int position=-1;
            printf("Enter the position to peek\n");
            scanf("%d",&position);
            if(position<0 || position-1>top)
            {
                printf("Out of Range!\n");
            }
            else
            {
                printf("Element at %d is: %d\n",position,peek(position));
            }
        }
        break;
        case 6:
            break;
        default:
            printf("Invalid choice!\n");
        }
        system("pause");
    }
    return 0;
}
