#include<stdio.h>
#include<stdlib.h>
struct queue
{
	int data;
	struct queue * next;
};
struct queue * front=NULL;
struct queue * create_node(int d)
{
	struct queue *newnode=NULL;
	newnode=(struct queue *)malloc(sizeof(struct queue));
	newnode->data=d;
	newnode->next=NULL;
	return newnode;
}
void enqueue(int data)
{
	struct queue *newnode=NULL;
	if(front==NULL)
	{
		front=create_node(data);
	}
	else
	{
		newnode=create_node(data);
		struct queue *temp=front ,*temp1=front;
		while(data>temp->data)
		{
			temp1=temp;
			temp=temp->next;
			if(temp==NULL)
			break;
			
		}
		if(temp==front)
		{
			newnode->next=temp1;
			front=newnode;
		}
		else
		{
			if(temp==NULL)
			{
				temp1->next=newnode;
			}
			else
			{
				temp1->next=newnode;
				newnode->next=temp;
			}
		}
	}
}
int dequeue()
{int d;
d=front->data;
front=front->next;
return d;
}
void display()
{
	struct queue *temp=front;
	while(temp!=NULL)
	{
		printf("%d",temp->data);
		temp=temp->next;
	}
}
int main()
{
	int n;
	printf("enter size:");
	scanf("%d",&n);
	int i,data;
	printf("enter elements:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&data);
		enqueue(data);
	}
	//display
	int a,b,sum=0,prev=0;
	int arr[n],k=0;
	while(front->next!=NULL)
	{
		a=dequeue();
		b=dequeue();
		enqueue(a+b);
		arr[k++]=a+b;
		
	}
	int ans=0;
	for(i=0;i<k;i++)
	{
		ans=ans+arr[i];
	}
	printf("%d",ans);
	
}
