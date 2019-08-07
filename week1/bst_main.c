#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

NODE root=NULL;

int main()
{
	int ch;
	int val;
	printf("\nOPERATIONS ---");
    printf("\n1 - Insert an element into tree\n");
    printf("2 - Inorder Traversal\n");
    printf("3 - Preorder Traversal\n");
    printf("4 - Postorder Traversal\n");
    printf("5 - Exit\n");
    while(1)

    {

        printf("\nEnter your choice : ");

        scanf("%d", &ch);

        switch (ch)

        {

        case 1:   
        	printf("Enter value to be inserted \n") ;
        	scanf("%d",&val);
        	printf("aaaa \n");
       		root=insert(root,val);
            break;

        case 2:  

        	printf(" Inorder traversal is \n");  

            inorder(root);

            break;

        case 3:

        	printf(" Preorder traversal is \n");    

            preorder(root);

            break;

        case 4:    

        	printf(" Postorder traversal is \n");    

            postorder(root);

            break;

        case 5:    

            exit(0);

        default :     

            printf("Wrong choice, Please enter correct choice  ");

            break;    

        }

    }
return 0;
}