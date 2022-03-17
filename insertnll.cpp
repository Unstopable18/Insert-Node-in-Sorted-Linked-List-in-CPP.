#include <iostream>
using namespace std;

struct node
{
	int data;
	struct node* next;
};
void build(struct node** head, int data);
void print(struct node* head);
void sortedInsert(struct node** head, struct node* newNode);
struct node* newNode(int data);

int main()
{
    int n,k;
    cout<<"\n*******************************************\n";
	cout<<"Enter Total No. Elements of linked list = ";
	cin>>n;
	int data[100];
    cout<<"\n*******************************************\n";
	cout<<"Enter linked list data Elements in Sorted Manner Only\n";
	for(int i=0;i<n;i++)
	{
	 cin>>data[i];
	}
	
	struct node* head = NULL;
    

	for (int i = n-1; i >= 0; i--)
	build(&head, data[i]);
    cout<<"\n*******************************************\n";
	cout<<"Linked list before insertion by the User: ";	
    print(head);
    cout<<"\n*******************************************\n";
    cout<<"\nEnter Element to insert in Linked List : ";
    cin>>k;
	sortedInsert(&head, newNode(k));
    cout<<"\n*******************************************\n";
	cout<<"\nLinked list after insertion by the User: ";
	print(head);
    cout<<"\n*******************************************\n";
	return 0;
}

void build(struct node** head, int data)
{
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = data;
	newNode->next = *head;
	*head = newNode;
}
void print(struct node* head)
{
	struct node* ptr = head;
	while (ptr)
	{
		cout<<ptr->data <<" ";
		ptr = ptr->next;
	}
}

struct node* newNode(int data)
{
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

void sortedInsert(struct node** head, struct node* newNode)
{
	
	if (*head == NULL || (*head)->data >= newNode->data)
	{
		newNode->next = *head;
		*head = newNode;
		return;
	}

	
	struct node* current = *head;
	while (current->next != NULL && current->next->data < newNode->data)
		current = current->next;

	newNode->next = current->next;
	current->next = newNode;
}