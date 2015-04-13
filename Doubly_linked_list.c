
#include <stdio.h>
#include <stdlib.h>
typedef struct _node
{
    struct _node *before;
    int value;
    struct _node *next;
}Node;

typedef struct flat
{
    Node *flat;
}Flat;

void add(Flat * flat,int number, Flat *pend);

int main(int argc,char const *argv[])
{
    /**标记链表头尾**/
    Flat head;
    head.flat = NULL;
    Flat end;
    end.flat = NULL;
    
    int number;
    do
    {
        scanf("%d",&number);
        if (number != -1)
        {
            add(&head,number,&end);
            
        }
    }while (number != -1);
    
    printf("value\taddress\t*next\t\n");
    
    for (;  head.flat ; head.flat=head.flat->next)
    {
        printf("%d\t",head.flat->value);
        printf("%p\t",head.flat);
        printf("↙%p\t",head.flat->next);
        printf("↖%p\n",head.flat->before);
        
    }
    
    printf("value\taddress\t*before\t\n");
    
    for (;  end.flat ; end.flat=end.flat->before)
    {
        printf("%d\t",end.flat->value);
        printf("%p\t",end.flat);
        printf("↙%p\t",end.flat->before);
        printf("↖%p\n",end.flat->next);
        
    }
    
    for (;  end.flat ; end.flat=end.flat->before)
    {
        free(end.flat);
    }
    
}


void add(Flat * phead,int number, Flat *pend)
{
    //创建一块内存，保存Node节点
    Node *p = (Node*)malloc(sizeof(Node));
    p->before = NULL;
    p->value = number;
    p->next = NULL;
    
    //让传进来的end.flat赋新的p值，然后让得到p后的end.flat->before等于前一个p
    Node *pre = pend->flat;
    pend->flat = p;
    pend->flat->before = pre;
    
    //确定head.flat的位置，然后让head.flat->next等于下一个p
    Node *last = phead->flat;
    if (last)
    {
        while (last->next)
        {
            last=last->next;
        }
        last->next = p;
    }
    else
    {
        phead->flat = p;
    }
}

