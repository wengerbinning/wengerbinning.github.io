AVL树是G.M. Adelson-Velsky与E.M. Landis提出的一种自平衡二叉搜索树。该树是最早的自平衡二叉搜索树。
该树通过引入平衡因子(balance factor)来确保二叉树相对平衡，以提高搜索效率，该树的增删改查的时间复杂度
为logn。该结构的C语言的实现存在与linubox中。

```c
struct avl_node {
    struct list_head list;
    struct avl_node *parent;
    struct avl_node *left;
    struct avl_node *right;
    const void *key;
    signed char balance;
    bool leader;
}

struct avl_tree {
    struct list_head list_head;
    struct avl_node *root;
    unsigned int count;
    bool allow_dups;
    avl_tree_comp comp;
    void *cmp_ptr;
}
```