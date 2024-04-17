#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct link
{
    char *word;
    int count;
    struct link *next;
}Link;

Link *insert_link(Link* head,char word[]);
void print_wordlink(Link *head);
Link *creat_word(char word[]);

int main(void)
{
    FILE *fp=NULL;
    char word[21],c;
    int i=0;
    Link *head=NULL;
    fp=fopen("article.txt","r");
    while (1)
    {
        while((c=fgetc(fp)) && isalpha(c))
        {
            if(isalpha(c))
            word[i++]=tolower(c);
        }
        if (i>0)
        {
            word[i]='\0';
            head=insert_link(head,word);
        }
        i=0;
        if (c==EOF) break;
    }
    print_wordlink(head);
}

Link *insert_link(Link* head,char word[])
{
    if (head==NULL)
    {
        head=creat_word(word);
        return head;
    }
    Link* front=NULL,*next=NULL,*temp=NULL;
    int n=strcmp(word,head->word);
    if (n<0)
    {
        temp=creat_word(word);
        temp->next=head;
        return temp;
    }
    else if(n==0)
    {
        head->count++;
        return head;
    }
    front=head;
    next=front->next;
    while(next!=NULL)
    {
        n=strcmp(word,next->word);
        if (n<0)
        {
            temp=creat_word(word);
            temp->next=next;
            front->next=temp;
            return head;
        }
        else if(n==0)
        {
            next->count++;
            return head;
        }
        next=next->next;
        front=front->next;
    }
    temp=creat_word(word);
    front->next=temp;
    return head;
}

Link *creat_word(char word[])
{
    int i=0;
    char *pword;
    while(word[i++]!='\0');
    //i-=1;
    pword=(char *)malloc(sizeof(char)*i);
    i=0;
    while(word[i]!='\0')
    {
        pword[i]=word[i];
        i++;
    }
    pword[i]='\0';

    Link* word_link=NULL;
    word_link=(Link *)malloc(sizeof(Link));
    if (NULL==word_link)
    {
        printf("worng");
        return NULL;
    }
    word_link->word=pword;
    word_link->count=1;
    word_link->next=NULL;
    return word_link;
}

void print_wordlink(Link *head)
{
    while(head!=NULL)
    {
        printf("%s %d\n",head->word,head->count);
        head=head->next;
    }
}