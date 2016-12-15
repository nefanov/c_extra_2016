#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node
{
    int data;
    struct Node * left;
    struct Node * right;
}Tree;

typedef struct queue
{
    struct Node **Tree;
    int i;
}queue;

Tree *tree_add(Tree *tree, int key)
{
    Tree *node;
    if (!tree)
    {
        
        node = (Tree *) malloc(sizeof(Tree));
        node->data = key;
        node->left = NULL;
        node->right = NULL;
        return node;
    }
    if (key < tree->data)
    {
        node = tree_add(tree->left, key);
        if (!tree->left)
            tree->left = node;
        return node;
    }
    else
    {
        
        node = tree_add(tree->right, key);
        if (!tree->right)
            tree->right = node;
        return node;
    }
}

int cmp(const void* a, const void* b)
{
    return *((int*)a) - *((int*)b);
}

Tree* add_to_tree(int* arr, int start, int end)
{
    if (end < start)
        return NULL;
    
    int mid = (start + end) / 2;
    Tree* n = tree_add(NULL, arr[mid]);
    n->left = add_to_tree(arr, start, mid - 1);
    n->right = add_to_tree(arr, mid + 1, end);
    return n;
}

Tree* create_flat(int * arr, int n)
{
    qsort(arr, n, sizeof(int), cmp);
    return add_to_tree(arr, 0, n - 1);
}

void add_to_queue (Tree *branch, queue *queue) //поставить в очередь
{
    queue->Tree = realloc(queue->Tree, sizeof(Tree));
    queue->Tree[queue->i] = branch;
    (queue->i)++;
}

int check_queue_empty (queue *queue) //возвращает 1, если очередь пуста, иначе - 0
{
    if (queue->Tree == NULL || queue->i < 0)
        return 1;
    else
        return 0;
}

Tree *take_first_from_queue (queue *queue) //взять из очереди первый добавленный элемент
{
    Tree *res = malloc(sizeof(Tree));
    res->left = NULL;
    res->right = NULL;
    if (queue->Tree[queue->i - 1] != NULL)
    {
        res = queue->Tree[queue->i - 1];
        queue->Tree[queue->i - 1] = NULL;
    }
    queue->i = (queue->i) - 1;
    return res;
}

void visit (Tree *x) //посетить и написать значение
{
    if (x != NULL && x->data != NULL)
    {
        printf("%d ", x->data);
    }
    return;
}

int check_pow2(int k, int *p)
{
    if (k == pow(2, *p))
    {
        (*p)++;
        return 1;
    }
    else
        return 0;
}

void bypass (Tree *root)
{
    int k = 0;
    int *p;
    p = malloc(sizeof(int));
    *p = 0;
    Tree *x = NULL;
    queue *queue = malloc(sizeof(queue));
    queue->Tree = NULL;
    queue->i = 0;
    add_to_queue(root, queue);                  // корень в очередь
    while (check_queue_empty(queue) == 0)
    {
        if (queue != NULL)
        {
            x = take_first_from_queue(queue);
            if (x != NULL)
            {
                visit(x);
                k++;
                if (check_pow2(k, p) == 1)
                {
                    printf("\n");
                    k = 0;
                }
                if (x->left != NULL)
                    add_to_queue(x->left, queue);
                if (x->right != NULL)
                    add_to_queue(x->right, queue);
            }
        }
    }
    free(p);
    queue = NULL;
}

void tree_destroy(Tree *tree) {
    if (tree) {
        tree_destroy(tree->left);
        tree_destroy(tree->right);
        free(tree);
    }
}

int main()
{
    int n, i;
    printf("Введите кол-во элементов: ");
    scanf("%d", &n);
    int *arr;
    arr = malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        printf("a[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    Tree* root = create_flat(arr, n);
    bypass(root);
    tree_destroy(root);
    free(arr);
    return 0;
}
