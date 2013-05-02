/*
 * 树的前序、中序、后序遍历
 * 递归实现，非递归方法后续待补充
 * 以下是运行实例：
 * zippo@MacBook-Pro datastruct$ ./tree
 * 输入节点（-1代表空树）:1
 * 输入[1]的左子树:输入节点（-1代表空树）:-1
 * 输入[1]的右子树:输入节点（-1代表空树）:2
 * 输入[2]的左子树:输入节点（-1代表空树）:3
 * 输入[3]的左子树:输入节点（-1代表空树）:5
 * 输入[5]的左子树:输入节点（-1代表空树）:-1
 * 输入[5]的右子树:输入节点（-1代表空树）:-1
 * [5]创建成功！
 * 输入[3]的右子树:输入节点（-1代表空树）:6
 * 输入[6]的左子树:输入节点（-1代表空树）:-1
 * 输入[6]的右子树:输入节点（-1代表空树）:-1
 * [6]创建成功！
 * [3]创建成功！
 * 输入[2]的右子树:输入节点（-1代表空树）:4
 * 输入[4]的左子树:输入节点（-1代表空树）:-1
 * 输入[4]的右子树:输入节点（-1代表空树）:7
 * 输入[7]的左子树:输入节点（-1代表空树）:-1
 * 输入[7]的右子树:输入节点（-1代表空树）:-1
 * [7]创建成功！
 * [4]创建成功！
 * [2]创建成功！
 * [1]创建成功！
 *
 * 前序遍历：1 2 3 5 6 4 7
 * 中序遍历：1 5 3 6 2 4 7
 * 后序遍历：5 6 3 7 4 2 1
*/

#include <stdio.h>

#define MAX 100
#define datatype int

typedef struct treeNode
{
    datatype data;
    struct treeNode *lchild;
    struct treeNode *rchild;
}btree;

void preOrder(btree *t)
{
    if(t == NULL)
    {
        return;
    }
    printf("%d ", t->data);
    if(t->lchild)
        preOrder(t->lchild);
    if(t->rchild)
        preOrder(t->rchild);
}

void inOrder(btree *t)
{
    if(t == NULL)
        return;
    if(t->lchild)
        inOrder(t->lchild);
    printf("%d ", t->data);
    if(t->rchild)
        inOrder(t->rchild);
}

void postOrder(btree *t)
{
    if(t == NULL)
        return;
    if(t->lchild)
        postOrder(t->lchild);
    if(t->rchild)
        postOrder(t->rchild);
    printf("%d ", t->data);
}


btree * createTree()
{
    int v;
    btree *t;
    printf("输入节点（-1代表空树）:");
    scanf("%d", &v);
    if(v == -1)
    {
        t = NULL;
    }
    else
    {
        t = (btree *)malloc(sizeof(struct treeNode));
        t->data = v;
        printf("输入[%d]的左子树:", v);
        t->lchild = createTree();
        printf("输入[%d]的右子树:", v);
        t->rchild = createTree();
        printf("[%d]创建成功！\n", v);
    }
    return t;
}


int main()
{
    btree *tree = createTree();
    printf("\n前序遍历：");
    preOrder(tree);
    printf("\n中序遍历：");
    inOrder(tree);
    printf("\n后序遍历：");
    postOrder(tree);
    printf("\n");
    return 0;
}
