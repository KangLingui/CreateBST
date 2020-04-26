#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	
	int nvalue;
	struct node *pleft;
	struct node *pright;
}mytree;

void zhongxubianli(mytree *ptree)
{
		if(ptree ==NULL)return -1;

        zhongxubianli(ptree->pleft);
	    printf("%d  ",ptree->nvalue);
    	zhongxubianli(ptree->pright);
}

void  addnode(mytree ** ptree,int num)
{
	
	mytree *ptemp  = (mytree*)malloc(sizeof(mytree));
	ptemp->nvalue = num;
	ptemp->pleft = NULL;
	ptemp->pright =NULL;

	if(*ptree ==NULL)//如果传进来的树为空
	{
		*ptree =ptemp;
		return;
	}

	//非空树
	mytree *pnode  = *ptree;//定义一个临时树，遍历树--添加

	while(pnode)
	{
			if(pnode->nvalue>num)//树根值>新来的
			{
				//左侧
				if(pnode->pleft==NULL)//如果左为空
				{
					pnode->pleft = ptemp;		
					return;
				}
				pnode = pnode->pleft;//继续向左走
			}
			else if(pnode->nvalue< num)
			{
				//右侧
				if(pnode->pright ==NULL)
				{
					pnode->pright =ptemp;	
					return;
				}
				pnode =pnode->pright;
			}	
			else//相等
			{
				printf("该值重复\n");
				free(ptemp);
				ptemp=  NULL;	
			return;
			}		
	}

}


mytree * createbst(int arr[],int nlenght)
{
		
	if(arr==NULL ||  nlenght<=0)
	{
		return -1;	
	}
	mytree *ptree = NULL;
	//循环的将数组所有元素放入树中
	int i;
	for(i = 0;i<=nlenght-1;i++)
	{	
		addnode(&ptree,arr[i]);//调用添加节点函数	
	}
	return ptree;
}

int  main()
{
	int arr[] = {10,36,55,2,8,57,44,12};
	mytree *ptree = createbst(arr,sizeof(arr)/sizeof(arr[0]));
	
	zhongxubianli(ptree);
	printf("\n");
	
	
return 0;
}
