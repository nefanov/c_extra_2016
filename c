#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int *forch(char *a,char *b,int *j,int i)
{
    int t=0,g,z,q;
    z=i;
    g=i;
    q=*j;
    for (i=q;i<z;i++)
        b[i]=a[i];
    b[i++]='/';
    b[i]='*';
    while (a[z]!='}')
    {
        if (a[z]=='{')
            t++;
        b[++i]=a[z++];
    }
    if (t==1)
    {
        z++;
        b[++i]='}';
        b[++i]='*';
        b[++i]='/';
        *j=i-3;
        for ( ;z<strlen(a);z++)
            b[++i]=a[z];
        i=g;
    }
    else
    {
        while(t!=0)
        {
            if (a[z]=='}')
                t--;
            b[++i]=a[z++];
        }
        b[++i]='*';
        b[++i]='/';
        *j=i-3;
        for ( ;z<strlen(a);z++)
            b[++i]=a[z];
        i=g;
    }
    return j;
}
int checker1(char *t)
{
    int k=0;
    if (fopen(t,"r+")==NULL)
    {
        printf("Your file hasn't found :("
               ",but it's been created a new one on printed adress(if it is avaliable)."
               "Please,follow it and then place your code there");
        FILE *p;
        p=fopen(t,"w+");
        fclose(p);
    }
    else
        k=1;
    return k;
}
/*int checker2(int r)
{

    if (r==0)
        printf("To use this function properly you need to have at least a one for-cycle in your
 file and you don't.Please,rewrite it.");
    return r;
}*/



int comment()
{
    FILE *filename;
    char a[100000],b[100000],c,o;
    int z=0,i=0,k,p=1,q=0;
    int *j,*e;
    j=&q;
    char buf[100];
    printf("Enter the whole way to file with code :\n");

    while ((c=getchar()) !='\n')
        buf[i++]=c;
    filename=fopen(buf,"r+");
    i=0;
    while ((o=fgetc(filename)) != EOF)
        a[i++]=o;

    k=checker1(buf);
    if (k!=0)
    {
        filename=fopen(buf,"w+");
        for (i=0;i<strlen(a);i+=p)
        {
            z=i;
            p=1;
            if (a[i]=='f' && a[i+1]=='o' && a[i+2]=='r' && a[i+3]==' '  && a[i+4]=='(' )
            {
                e=forch(a,b,j,i);
                p=*e-z+1;
            }
        }
    }
    /*if  ((w=checker2(l))==0)
           fprintf(filename,"%s",b);*/
    //else
    //{
    fprintf(filename,"%s",b);
    fclose(filename);
    printf("Enjoy your fixed file ;)");
    // }

return 0;
}
int main()
{
    comment();
    return 0;
}


