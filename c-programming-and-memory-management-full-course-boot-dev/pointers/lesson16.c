// Forward Declaration
// Sometimes you have a struct that may need to reference itself, or be used recursively.

// For example, consider a Node struct that can contain other Nodes. This might be useful for building a linked list or a tree:

typedef struct Node {
  int value;
  node_t *next;
} node_t;

// The problem here is that node_t is not defined yet, so the compiler will complain. To fix this, we can add a forward declaration:

typedef struct Node node_t;

typedef struct Node {
  int value;
  node_t *next;
} node_t;

// Note that the forward declaration must match the eventual definition, so you can't do something like this:

typedef struct Node node_t;

typedef struct BadName {
  int value;
  node_t *next;
} node_t;


typedef struct SnekObject snekobject_t;
typedef struct SnekObject {
  char *name;
  snekobject_t *child;
} snekobject_t;

snekobject_t new_node(char *name);

#include <stdlib.h>

snekobject_t new_node(char *name) {
  snekobject_t node = {
    .name = name,
    .child = NULL
  };
  return node;
}

