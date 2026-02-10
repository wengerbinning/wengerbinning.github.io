## 数据类型

#### struct avl_node

```c
/**
 * This element is a member of a avl-tree. It must be contained in all
 * larger structs that should be put into a tree.
 */
struct avl_node {
  /**
   * Linked list node for supporting easy iteration and multiple
   * elments with the same key.
   *
   * this must be the first element of an avl_node to
   * make casting for lists easier
   */
  struct list_head list;

  /**
   * Pointer to parent node in tree, NULL if root node
   */
  struct avl_node *parent;

  /**
   * Pointer to left child
   */
  struct avl_node *left;

  /**
   * Pointer to right child
   */
  struct avl_node *right;

  /**
   * pointer to key of node
   */
  const void *key;

  /**
   * balance state of AVL tree (0,-1,+1)
   */
  signed char balance;

  /**
   * true if first of a series of nodes with same key
   */
  bool leader;
};
```

#### struct avl_tree

```c
/**
 * Prototype for avl comparators
 * @param k1 first key
 * @param k2 second key
 * @param ptr custom data for tree comparator
 * @return +1 if k1>k2, -1 if k1<k2, 0 if k1==k2
 */
typedef int (*avl_tree_comp) (const void *k1, const void *k2, void *ptr);

/**
 * This struct is the central management part of an avl tree.
 * One of them is necessary for each avl_tree.
 */
struct avl_tree {
  /**
   * Head of linked list node for supporting easy iteration
   * and multiple elments with the same key.
   */
  struct list_head list_head;

  /**
   * pointer to the root node of the avl tree, NULL if tree is empty
   */
  struct avl_node *root;

  /**
   * number of nodes in the avl tree
   */
  unsigned int count;

  /**
   * true if multiple nodes with the same key are
   * allowed in the tree, false otherwise
   */
  bool allow_dups;

  /**
   * pointer to the tree comparator
   *
   * First two parameters are keys to compare,
   * third parameter is a copy of cmp_ptr
   */
  avl_tree_comp comp;

  /**
   * custom pointer delivered to the tree comparator
   */
  void *cmp_ptr;
};
```

## 函数接口

* AVL_TREE_INIT
* AVL_TREE

* avl_init
* avl_find
* avl_find_greaterequal
* avl_find_lessequal
* avl_insert
* avl_delete

* avl_is_first
* avl_is_last
* avl_is_empty
* avl_find_element
* avl_find_le_element
* avl_find_ge_element
* avl_first_element
* avl_last_element
* avl_next_element
* avl_prev_element
* avl_for_element_range
* avl_for_element_range_reverse
* avl_for_each_element
* avl_for_each_element_reverse
* avl_for_element_to_last
* avl_for_element_to_last_reverse
* avl_for_first_to_element
* avl_for_first_to_element_reverse
* avl_for_element_range_reverse_safe
* avl_for_each_element_safe
* avl_for_each_element_reverse_safe
* avl_remove_all_elements
