/*
Algoritma Huffman
Nama    : Rizky Noor Ichwan
NRP     : 5109100090
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct link
{
            int fre;
            char alpha[30];
            struct link *left;
            struct link *right;
};
typedef struct link node;

void sort(node *[], int);
void sright(node *[], int);
void assign(node*, int [], int);
void deltree(node *);
node* create(char[], int);

main()
{
      node *ptr,
           *head;
      int f[30], fr, u, i, n, total = 0;
      char alpha2[30];
      node *a[30];
            
      printf("Banyak huruf : ");
      scanf("%d", &n);
      for(i = 0; i < n; i++)
      {
            printf("input huruf dan frekuensi :\n");
            scanf("%s %d", alpha2, &fr);
            a[i] = create(alpha2, fr);
      }
      
      for( ;n > 1; n--)
      {
              sort(a, n);
              u = a[0] -> fre + a[1] -> fre;
              
              strcpy(alpha2, a[0] -> alpha);
              strcat(alpha2, a[1] -> alpha);
              ptr = create(alpha2, u);
              ptr -> right = a[1];
              ptr -> left = a[0];
              a[0] = ptr;
              sright(a, n);
      }
      
      assign(a[0], f, 0);
      
      deltree(a[0]);
}

node* create(char a[], int x)
{
      node* ptr;
      ptr = (node *) malloc(sizeof(node));
      ptr -> fre = x;
      strcpy(ptr -> alpha, a);
      ptr -> right = ptr -> left = NULL;
      
      return(ptr);
}

void sort(node* a[], int n)
{
     int i, j;
     node* temp;
     
     for(i = 0; i < n - 1; i++)
           for(j = i; j < n; j++)
                 if(a[i] -> fre > a[j] -> fre)
                 {
                         temp = a[i];
                         a[i] = a[j];
                         a[j] = temp;
                 }
}

void sright(node* a[], int n)
{
     int i;
     for(i = 1; i < n - 1; i++)
           a[i] = a[i + 1];
}

void assign(node* tree, int c[], int n)
{
     int i;
     
     if((tree -> left == NULL) && (tree -> right == NULL))
     {
              printf("%s kode : ", tree -> alpha);
              for(i = 0; i < n; i++)
                    printf("%d", c[i]);
              printf("\n");
     }
     else
     {
         c[n] = 1;
         n++;
         assign(tree -> left, c, n);
         c[n - 1] = 0;
         assign(tree -> right, c, n);
     }
}

void deltree(node * root)
{
     if(root != NULL)
     {
             deltree(root -> left);
             deltree(root -> right);
             free(root);
     }
}
