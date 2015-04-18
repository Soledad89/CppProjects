
#define MAXWORD 100

struct tnode {
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};

struct tnode *addtree(struct tnode *, char *);

void treeprint(struct tnode *);

int getword( char *, int);

struct tnode *talloc(void);

char *my_strdup(char *);

