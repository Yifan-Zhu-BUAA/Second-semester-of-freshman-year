#include <stdio.h>
#include <string.h>
#include <ctype.h>

void replace(char be[],char af[],char in[],char out[]);

int main()
{
    FILE *fp=NULL;
    char be[1000],af[1000];
    char in[10],out[10];
    fp=fopen("filein.txt","r");
    if (NULL==fp)
    {
        perror("perror");
        return 1;
    }
    gets(in);gets(out);
    fseek(fp, 0, SEEK_END);
    int length = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    fread(be,sizeof(char),length,fp);
    be[length+1]='\0';
    fclose(fp);
    replace(be,af,in,out);
    fp=fopen("fileout.txt","w");
    if (NULL==fp)
    {
        perror("perror");
        return 1;
    }
    fprintf(fp,"%s",af);
    fclose(fp);
}

void replace(char be[],char af[],char in[],char out[])
{
    int i=0,j=0,in_n=strlen(in),out_n=strlen(out);//i是be下标，j是af下标
    while(be[i]!='\0')
    {
        if (tolower(be[i])!=tolower(in[0]))
        {
            af[j++]=be[i++];
        }
        else
        {
            int check=1;
            for (int k=0;k<in_n;k++)
            {
                if ((be[i+k])=='\0' || tolower(be[i+k])!=tolower(in[k])){check=0;break;}
            }
            if (check==1)
            {
                for (int k=0;k<out_n;k++) af[j++]=out[k];
                i+=in_n;
            }
            else af[j++]=be[i++];
        }
    }
    af[j]='\0';
}