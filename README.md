# Binary-tree-of-data-structure
## Data structure | Binary tree
Language: C </br>
> The repository includes:
* 1 source file
* 1 input_txt (for testing the source code)
* 1 demmand for the code (in Chinese; complete requirement for the tasks)

TASK concerning **binary tree** :</br>
*  Write an `algorithm`: Input numbers to create a binary tree, and then figure out all the paths with a typical sum.(the number can be designated at the discreation of you!)



### Preview:

```c
#include<stdio.h>
#include<stdlib.h>  //exit(0)
#include<malloc.h>  //malloc
typedef struct Node  
{
	int data;
	struct Node * lchild;
	struct Node * rchild;
}BiTNode, *BiTree;
int sum=0;
int con_sum;
int tag=0;
int time=0;
int a[20]={0};
int CountLine (FILE *fp);
void post_error(FILE *fp2);
void post_null(FILE *fp2);
void SearchTree (BiTree T, int x, FILE* fp);
void CreateTree(BiTree T, int x, FILE* fp);
void PreTree(BiTree T, FILE * fp2);

```

### Say thanks to ...
This project is my assignment for the course Data Structure when I was a first-year student at :blue_book: [the Department of Electrical Engineering at South China University of Technology](http://www.scut.edu.cn/ee/). </br>
I really appreciate the guidance and help from my teacher Dr. Qin, along with my classmates.:bowtie:

`Please feel free to give suggestions and comments!`
