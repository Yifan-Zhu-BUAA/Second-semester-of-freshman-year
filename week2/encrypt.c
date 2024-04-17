#include <stdio.h>
#include <string.h>

void get_keys(char fea[],char keys[27]);//先打出密码表
void replace(char be[],char af[],char keys[27]);

int main()
{
    FILE *fp=NULL;
    char fea[51],keys[27],be[500],af[500];
    int keys_n[26];
    gets(fea);
    get_keys(fea,keys);
    fp=fopen("encrypt.txt","r");
    if (NULL==fp)
    {
        perror("perror");
        return 1;
    }
    fseek(fp, 0, SEEK_END);
    int length = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    fread(be,sizeof(char),length,fp);
    be[length+1]='\0';
    fclose(fp);
    replace(be,af,keys);
    fp=fopen("output.txt","w");
    if (NULL==fp)
    {
        perror("perror");
        return 1;
    }
    fprintf(fp,"%s",af);
    fclose(fp);
}

void get_keys(char fea[],char keys[27])
{
    int num[26]={0},i=0,j=0;//i是fea下标，j是keys下标
    char c;
    while ((c=fea[i])!='\0')
    {
        if (num[c-'a']==0)
        {
            num[c-'a']=1;
            keys[j++]=fea[i++];
        }
        else i++;
    }
    for (i=25;i>=0;i--)
    {
        if (num[i]==0) keys[j++]='a'+i;
    }
    keys[j]='\0';
}



void replace(char be[],char af[],char keys[27])
{
    int i=0;
    char c;
    while((c=be[i])!='\0')
    {
        if (c<='z' && c>='a')
        {
            af[i++]=keys[c-'a'];
        }
        else
        {
            af[i]=be[i];
            i++;
        }
    }
    af[i]='\0';
}