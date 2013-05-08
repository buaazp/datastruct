/*
 * 二叉查找树的建立、插入、删除和查找算法
 * 下面是运行示例：
 * zippo@localhost datastruct$ ./ttbt
 * 开始创建二叉树:
 * 请输入BiTree结点数n: 3
 * 输入T[0]的key值: 1
 * 输入T[1]的key值: 2
 * 输入T[2]的key值: 3
 * 二叉树创建成功.
 * 输入要删除的key值: 1
 * 删除成功!
 * 输入要查找的key值: 1
 * 查找失败!!!!
 * 输入要查找的key值: 2
 * 查找成功!
 * 输入要查找的key值: 3
 * 查找成功!
 */



#include <stdio.h>
#include "bitree.h"


int main()
{
    int ret;
    keytype key;
    bitree T = NULL;
    bitree p;
    printf("开始创建二叉树:\n");
    ret = createBitree(&T);
    if(ret > 0)
    {
        printf("二叉树创建成功.\n");
        printf("输入要删除的key值: ");
        scanf("%d", &key);
        ret = delBitree(&T, key);
        if(ret > 0)
        {
            printf("删除成功!\n");
        }
        else
        {
            printf("删除失败!!!!\n");
        }
        while(1)
        {
            printf("输入要查找的key值: ");
            scanf("%d", &key);
            ret = searchBitree(T, key, NULL, &p);
            if(ret > 0)
            {
                printf("查找成功!\n");
            }
            else
            {
                printf("查找失败!!!!\n");
            }
        }
    }
    else
    {
        printf("二叉树创建失败!\n");
    }
    return 0;
}
