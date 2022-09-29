#include <stdio.h>
#include <stdlib.h>

struct node
{
    float coeff;
    int expo;
    struct node *next;
};

// Display Linked list
void print(struct node * head)
{
    if (head == NULL)
    {
        printf("No polynomial");
    }
    
    else
    {
    struct node * temp = head;   
    while (temp != NULL)
    {
        printf("  %.1f X^ %d  ", temp->coeff,temp->expo);
        temp = temp->next;
        
            if (temp != NULL)
                printf(" + ");
            else
                printf("  \n");
    }
    }
}


// We get sorted arrangment irrespective of the data entering format
struct node *insert(struct node *head, float coeff, int ex)
{
    struct node *temp;
    struct node *nn = malloc(sizeof(struct node));
    nn->coeff = coeff;
    nn->expo = ex;
    nn->next = NULL;

    // if there is no node in the list OR given exponent is greater than the first exponent
    if (head == NULL || ex > head->expo)
    {
        nn->next = head;
        head = nn;
    }
    else
    {
        temp = head;

        // Until the list ends OR 1 node before the node smaller than given node
        // i.e., temp points to a last node that is great than given node
        while (temp->next != NULL && temp->next->expo >= ex)
        {
            temp = temp->next;
        }
        nn->next = temp->next;
        temp->next = nn;
    }
    return head;
}

// Function to create new node
struct node *create(struct node *head)
{
    int n, i;
    float coeff;
    int expo;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the coefficient of the term %d :    ", i + 1);
        scanf("%f", &coeff);

        printf("Enter the exponent of the term %d  :    ", i + 1);
        scanf("%d", &expo);
        head = insert(head, coeff, expo);
    }
    print(head);
    printf("  \n");
    return head;
}

// Function Adding two polynomial numbers
void polyadd(struct node* head1,struct node *head2)
{

    struct node * ptr1 = head1;
    struct node * ptr2 = head2;
    struct node * head3 = NULL;
    
    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->expo == ptr2->expo)
        {
            head3 = insert(head3,ptr1->coeff+ptr2->coeff, ptr1->expo);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
            
        }

        else if (ptr1->expo < ptr2->expo)
        {
            head3 = insert(head3,ptr2->coeff, ptr2->expo);
            ptr2 = ptr2->next;
        }
        else if (ptr1->expo > ptr2->expo)
        {
            head3 = insert(head3,ptr1->coeff, ptr1->expo);
            ptr1 = ptr1->next;
        }
    }
    while (ptr1!= NULL)
    {
        head3 = insert(head3,ptr1->coeff, ptr1->expo);
        ptr1 = ptr1->next;
    }

    while (ptr2!= NULL)
    {
        head3 = insert(head3,ptr2->coeff, ptr2->expo);
        ptr2 = ptr2->next;
    }
print(head3);
}



// Driver code
int main()
{
    struct node *head1 = NULL, *head2 = NULL, *poly = NULL;

    printf("For the first polynomial\n");
    head1 = create(head1);
    
    printf("For the second polynomial\n");
    head2 = create(head2);

    polyadd(head1, head2);

    return 0;
}
