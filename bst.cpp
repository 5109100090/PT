#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

FILE *fp;
FILE *fr;

struct tnode
{
   char *data;
   struct tnode *lchild, *rchild;
};

/* a function to binary tree in inorder */
void inorder(struct tnode *p)
{
      if(p != NULL)
      {
           inorder(p->lchild);
           fprintf(fp,"%s\n",(*p).data);
           inorder(p->rchild);
      }
}

struct tnode *insert(struct tnode *p,char val[])
{
   struct tnode *temp1,*temp2;
   if(p == NULL)
   {
      p = (struct tnode *) malloc(sizeof(struct tnode)); /* insert the new node as root node*/
      if(p == NULL)
      {
		printf("Cannot allocate\n");
		exit(0);
      }
      (*p).data = (char*)malloc(sizeof(char)*strlen(val));
      if ((*p).data == NULL){
		printf("Cannot allocate data\n");
		exit(0);
      }
      strcpy(p->data,val);

      p->lchild=p->rchild=NULL;
   }
  else // insert node
  {
	  temp1 = p;
	  /* traverse the tree to get a pointer to that node whose child will be the newly created node*/
	  while(temp1 != NULL)
	  {
		 temp2 = temp1;
		 //printf("data %s vs %s\n", temp1->data, val);
		 if( strcmp(temp1 ->data, val) > 0){
			  temp1 = temp1->lchild;
		}
		else{
			  temp1 = temp1->rchild;
		}
	  }

	  if( strcmp(temp2->data , val)> 0)
	  {
		//printf("insert left\n ");
		/*inserts the newly created node as left child*/
		temp2->lchild = (struct tnode*)malloc(sizeof(struct tnode));
		temp2 = temp2->lchild;
		if(temp2 == NULL)
		{
			printf("Cannot allocate\n");
			exit(0);
		}
	    (*temp2).data = (char*)malloc(sizeof(char)*strlen(val));
		strcpy(temp2->data,val);
		temp2->lchild=temp2->rchild = NULL;
	  }
	  else
	  {
		//printf("insert right\n ");
		/*inserts the newly created node as left child*/
		temp2->rchild = (struct tnode*)malloc(sizeof(struct tnode));
		temp2 = temp2->rchild;
		if(temp2 == NULL)
		{
		  printf("Cannot allocate\n");
		  exit(0);
		}
	    (*temp2).data = (char*)malloc(sizeof(char)*strlen(val));
		strcpy(temp2->data,val);
		temp2->lchild=temp2->rchild = NULL;
	   }

	}
	return(p);
}

main(int argc, char* argv[])
{
   struct tnode *root = NULL;
   int n;
   char x[20];
   if (argc >= 3){
		printf("input : %s\n", argv[1]);
		printf("output : %s\n", argv[2]);
	   fp = fopen(argv[2],"a");
	   fr = fopen(argv[1],"r");
	   while (!feof(fr)){
		fscanf(fr,"%s\n",&x);
		if (x[0] != '\n')	// kita ga mau line kosong masuk
			root = insert(root,x);
	   }
		// tulis hasil secara inorder
		inorder(root);
		fclose(fp);
		fclose(fr);
    }else{
		printf("command: bstq  namafileinput namafileoutput");
    }
    
    getch();
 }
