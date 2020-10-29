#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 30
#define Length 31

/***********************************/
/***学生成绩管理系统V2.0************/
/***2020.10.28**********************/
/***设计人：张锐洋*****************/

/*函数功能：存储输入的学号姓名和成绩*/
void readscore (int a[],long b[],char d[][Length],int c)
{
    int i;
    printf("Input student's ID ,name and score,format as(20201111 name 89):\n");
    for (i=0;i<=c-1;i++)
    {
        scanf("%ld %s %d",&b[i],d[i],&a[i]);
        if (a[i]<0 || a[i]>100)
        {
            printf("Invalid score.\nPlease enter again:\n");
            scanf("%ld %s %d",&b[i],d[i],&a[i]);
        }
    }
    printf("Have stored the data successfully,thanks!\n");
}
/*函数功能：计算输入的所有成绩的总和*/
int sum (int a[],int c)
{
    int s,i;
    for (i=0;i<=c-1;i++)
    {
        s+=a[i];
    }
    return s;
}
/*函数功能：两整数值互换*/
void Swapint(int *x,int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
/*函数功能：两长整数值互换*/
void Swaplong(long *x,long *y)
{
    long temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
/*函数功能：两字符串交换*/
/*void Swapstr(char *x,char *y)
{
    char temp;
    do{
        temp=*x;
        *x=*y;
        *y=temp;
        x++;
        y++;
    }while(*x || *y);
    
}*/
void Swapstr(char a[],char b[])
{
	char temp[Length];
	strcpy(temp,b);
	strcpy(b,a);
	strcpy(a,temp);
}
/*使数据按升序排序*/
int ascending(int a,int b)
{
    return a<b;
}

/*使数据按降序排序*/
int descending(int a,int b)
{
	return a>b;
}
/*函数功能：升序或降序排列成绩*/
void datasort(int a[],long b[],int c,int (*compare)(int a,int b),char d[][Length])
{
    int i,j,k;
    for (i = 0 ; i < c-1 ; i++)
    {
        k = i;
        for (j = i+1 ; j<c ; j++)
        {
            if ((*compare)(a[j],a[k]))
                k=j;
        }
        if (k!=i)
        {
            Swapint(&a[k],&a[i]);
            Swaplong(&b[k],&b[i]);
            Swapstr(d[i],d[k]);
        }
    }
}

/*函数功能：升序排列学号*/
void datasortID(int a[],long b[],int c,char d[][Length])
{
    int i,j,k;

    for (i = 0 ; i < c-1 ; i++)
    {
        k = i;
        for (j = i+1 ; j<c ; j++)
        {
            if (b[j]<b[k])
                k=j;
        }
        if (k!=i)
        {
            Swapint(&a[i],&a[k]);
            Swaplong(&b[i],&b[k]);
            Swapstr(d[i],d[k]);
        }
    }
}
/*函数功能：按字典顺序排出成绩表*/
void dicorder(int a[],long b[],int c,char d[][Length])
{
	int i,j,k;
    for (i = 0 ; i < c-1 ; i++)
    {
        k = i;
        for (j = i+1 ; j<c ; j++)
        {
            if (strcmp(d[j],d[k])<0)
                k=j;
        }
        if (k!=i)
        {
            Swapint(&a[i],&a[k]);
            Swaplong(&b[i],&b[k]);
            Swapstr(d[i],d[k]);
        }
    }
}
/*函数功能：查找所输入的学号所对应的数据*/
int BinSearch(long b[],int a[],long x,int c,char d[][Length])
{
    int l=0,h,m;
    h=c-1;
    datasortID(a,b,c,d);
    while (l<=h)
    {
        m=l+(h-l)/2;
        if (x>b[m])
        {
            l=m+1;
        }
        else if (x<b[m])
        {
            h=m-1;
        }
        else
            return m;
    }
    return -1;
}
/*函数功能：查找所输入的姓名所对应的数据*/
int Searchbyname(long b[],int a[],char d[][Length],char f[],int c)
{
    int i;
    datasort(a,b,c,descending,d);
    for (i=0 ; i<c ; i++)
    {
        if (strcmp(f,d[i])==0)
        	return i;
    }
    return -1;
}
/*函数功能：查找成绩对应的排名*/
int searchRank(int b[],long a[],int x,int c,char d[][Length])
{
    int l=0,h,m;
    h=c-1;
    datasort(b,a,c,descending,d);
    while (l<=h)
    {
        m=l+(h-l)/2;
        if (x<b[m])
        {
            l=m+1;
        }
        else if (x>b[m])
        {
            h=m-1;
        }
        else
            return m;
    }
    return -1;
}
/*函数功能：分析成绩分布*/
int analysis(int a[],int c,int b)
{
    int i;
    static int x1,x2,x3,x4,x5;
    x1=x2=x3=x4=x5=0;
    for (i=0 ; i<c ; i++)
    {
        if (a[i]>=90 && a[i]<=100)
            x1++;
        if (a[i]>=80 && a[i]<=89)
            x2++;
        if (a[i]>=70 && a[i]<=79)
            x3++;
        if (a[i]>=60 && a[i]<=69)
            x4++;
        if (a[i]>=0 && a[i]<=59)
            x5++;
    }
    if (b==1)
		return x1;
	if (b==2)
		return x2;
	if (b==3)
		return x3;
	if (b==4)
		return x4;
	if (b==5)
		return x5;
	else
		return -1;
}

int main()
{
    printf("Number:200810319\nName:张锐洋\nsubject No.6 - program No.1\n\n");
    printf("---------------------------------------------------\n");
    int t=0;
while(1)
{
    int c;
    int i,r,v,v1,v2;
    int s;
    long p;
    double avr;
    int op=0;
    int score [N];
    long num [N];
    char name [Length][Length];
    char x[Length];
	int r1,r2,r3,r4,r5;

    printf("\n1. Input record");
    printf("\n2. Calculate total and average score of course");
    printf("\n3. Sort in descending order by score");
    printf("\n4. Sort in ascending order by score");
    printf("\n5. Sort in ascending order by student's ID");
    printf("\n6. Sort in dictionary order by name");
    printf("\n7. Search by student's ID");
    printf("\n8. Search by name");
    printf("\n9. Statistic analysis");
    printf("\n10. List record");
    printf("\n11. Exit");

    printf("\nPlease enter your choice:\n");
    while(scanf("%d",&op)!=1)
	{
		fflush(stdin);
		printf("\ninvalid option.\n");
		printf("---------------------------------------------------\n");
		printf("\nPlease enter your choice again:\n");
	}
    printf("---------------------------------------------------\n");

    switch (op)
    {
        case 1:
            printf("How many students?\n");
            scanf("%d",&c);
            readscore (score,num,name,c);
            printf("---------------------------------------------------\n");
            t=1;
            break;
        case 2:
            if (t==0)
            {
                printf("Please input record first.\n");
                break;
            }
            s=sum (score,c);
            avr=s/(c*1.0);
            printf("The summary of the score is:%d\n",s);
            printf("The average of the score is:%f\n",avr);
            printf("---------------------------------------------------\n");
            break;
        case 3:
            if (t==0)
            {
                printf("Please input record first.\n");
                break;
            }
            datasort(score,num,c,descending,name);
            for (i=0 ; i<c ; i++)
            {
                printf("%d. %ld %s %d\n",i+1,num[i],name[i],score[i]);
            }
            printf("---------------------------------------------------\n");
            break;
        case 4:
            if (t==0)
            {
                printf("Please input record first.\n");
                break;
            }
            datasort(score,num,c,ascending,name);
            for (i=0 ; i<c ; i++)
            {
                printf("%d. %ld %s %d\n",c-i,num[i],name[i],score[i]);
            }
            printf("---------------------------------------------------\n");
            break;
        case 5:
            if (t==0)
            {
                printf("Please input record first.\n");
                break;
            }
            datasortID(score,num,c,name);
            for (i=0 ; i<c ; i++)
            {
                printf("%ld %s %d\n",num[i],name[i],score[i]);
            }
            printf("---------------------------------------------------\n");
            break;
        case 6:
        	if (t==0)
            {
                printf("Please input record first.\n");
                break;
            }
            dicorder(score,num,c,name);
            for (i=0 ; i<c ; i++)
            {
                printf("%ld %s %d\n",num[i],name[i],score[i]);
            }
            printf("---------------------------------------------------\n");
            break;
        case 7:
            if (t==0)
            {
                printf("Please input record first.\n");
                break;
            }
            printf("Please enter the ID:\n");
            scanf("%ld",&p);
            v=BinSearch(num,score,p,c,name);
            while (v==-1)
            {
                printf("Not found.\n");
                printf("Please enter the ID again:\n");
                scanf("%ld",&p);
                v=BinSearch(num,score,p,c,name);
            }
            v1=score[v];
            v2=num[v];
            strcpy(x,name[v]);
            r=searchRank(score,num,v1,c,name);
            printf("%d %s %d",v2,x,v1);
            printf(" ranked %d\n",r+1);
            printf("---------------------------------------------------\n");
            break;
        case 8:
			if (t==0)
            {
                printf("Please input record first.\n");
                break;
            }
            getchar();
            printf("Please enter the name:\n");
            scanf("%s",x);
            v=Searchbyname(num,score,name,x,c);
            while (v==-1)
            {
                printf("Not found.\n");
                getchar();
                printf("Please enter the name again:\n");
                scanf("%s",x);
                v=Searchbyname(num,score,name,x,c);
            }
            v1=score[v];
            v2=num[v];
            r=searchRank(score,num,v1,c,name);
            printf("%d %s %d",v2,x,v1);
            printf(" ranked %d\n",r+1);
            printf("---------------------------------------------------\n");
            break;
        case 9:
            if (t==0)
            {
                printf("Please input record first.\n");
                break;
            }
            for (i=0;i<=5;i++)
            {
                r1=analysis(score,c,1);
                r2=analysis(score,c,2);
                r3=analysis(score,c,3);
                r4=analysis(score,c,4);
                r5=analysis(score,c,5);
            }
            printf("优秀人数:%d , 占%f%%\n",r1,r1*100/(c*1.0));
            printf("良好人数:%d , 占%f%%\n",r2,r2*100/(c*1.0));
            printf("中等人数:%d , 占%f%%\n",r3,r3*100/(c*1.0));
            printf("及格人数:%d , 占%f%%\n",r4,r4*100/(c*1.0));
            printf("不及格人数:%d , 占%f%%\n",r5,r5*100/(c*1.0));
            printf("---------------------------------------------------\n");
            break;
        case 10:
            if (t==0)
            {
                printf("Please input record first.\n");
                break;
            }
            for (i=0 ; i<c ; i++)
            {
                printf("%ld %s %d\n",num[i],name[i],score[i]);
            }
            printf("---------------------------------------------------\n");
            break;
        case 11:
            exit(0);
            printf("---------------------------------------------------\n");
        default:
            printf("invalid option.\n\n");
            printf("---------------------------------------------------\n");
            break;
    }
}
    return 0;
}
