#include "AAtree.h"
#include <stdio.h>
#include <sys/time.h>

double wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

void printMenu()
{
    printf("1. Добавить элемент\n");
    printf("2. Удалить элемент\n");
    printf("3. Элемент по ключу\n");
    printf("4. Минимальный элемент\n");
    printf("5. Максимальный элемент\n");
    printf("6. Выход\n");
}

int main()
{
    struct aatree* root = NULL;
    double time_start;
    double time_end;

    time_start = wtime();
    for (int i = 0; i < 50000; i++)
    {
        root = aatree_insert(root, i);
    }
    time_end = wtime() - time_start;
    printf("insert = %lf\n", time_end);

    time_start = wtime();
    for (int i = 0; i < 50000; i++)
    {
        struct aatree* node = aatree_lookup(root, i); //Без вывода
    }
    time_end = wtime() - time_start;
    printf("lookup = %lf\n", time_end);

    time_start = wtime();
    for (int i = 0; i < 50000; i++)
    {
        root = aatree_delete(root, i);
    }
    time_end = wtime() - time_start;
    printf("delete = %lf\n", time_end);

    /*int item = -1;
    int key;
    while (item != 7)
    {
        struct aatree* node = NULL;
        printMenu();
        scanf("%d", &item);
        switch (item)
        {
        case 1:
            printf("Введите ключ:\n");
            scanf("%d", &key);
            root = aatree_insert(root, key);
            break;
        case 2:
            printf("Введите ключ:\n");
            scanf("%d", &key);
            root = aatree_delete(root, key);
            break;
        case 3:
            printf("Введите ключ:\n");
            scanf("%d", &key);
            node = aatree_lookup(root, key);
            if (node == NULL)
            {
                printf("Элемент не найден\n");
            }
            else
            {
                printf("Элемент найден\n");
            }
            break;
        case 4:
            node = aatree_min(root);
            if (node == NULL)
            {
                printf("Дерево пустое\n");
            }
            else
            {
                printf("Минимальный элемент: %d\n", node->key);
            }
            break;
        case 5:
            node = aatree_max(root);
            if (node == NULL)
            {
                printf("Дерево пустое\n");
            }
            else
            {
                printf("Максимальный элемент: %d\n", node->key);
            }
            break;
        case 6:
            aatree_free(root);
            return 0;
        }
    }*/
}