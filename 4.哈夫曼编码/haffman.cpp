/*************************************************************************
	> File Name: haffman.cpp
	> Author: liyijia
	> Mail: liyijiax@163.com
	> Created Time: 2019年11月04日 星期一 15时38分16秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max_n 1000
#define swap(a, b) {\
    __typeof(a) temp = a;\
    a =b, b = temp;\
}

typedef struct Node {
    char ch;
    double p;
    struct Node *next[2]; 
} Node;

typedef struct Data {
    char ch;
    double p;
} Data;

typedef struct Code {
    char ch;
    char *str;
} Code;

typedef struct HaffmanTree {
    Node *root;
    int n;
    Code *codes;
} HaffmanTree;

Data arr[max_n + 5];

Node *getNewNode(Data *obj) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->ch = (obj ? obj->ch : 0);
    p->p = (obj ? obj->p : 0);
    p->next[0] = p->next[1] = NULL;
    return p;
}

void insertOnce(Node **arr, int n) {
    for (int j = n; j >= 1; j--) {
        if (arr[j]->p > arr[j - 1]->p) {
            swap(arr[j], arr[j - 1]);
            continue;
        }
        break;
    }
    return ;
}

HaffmanTree *getNewTree(int n) {
    HaffmanTree *tree = (HaffmanTree *)malloc(sizeof(HaffmanTree));
    tree->root = NULL;
    tree->n = n;
    tree->codes = (Code *)malloc(sizeof(Code) * n);
    return tree;

}

int extractCodes(Node *root, Code *arr, int k, int l, char *buff) {
    buff[l] = 0;
    if (root->next[0] == NULL && root->next[1] == NULL) {
        arr[k].ch = root->ch;
        arr[k].str = strdup(buff);
        return 1;
    } 
    int delta = 0;
    buff[l] = '0';
    delta += extractCodes(root->next[0], arr, k + delta, l + 1, buff);
    buff[l] = '1';
    delta += extractCodes(root->next[1], arr, k + delta, l + 1, buff);
    return delta;
}

HaffmanTree *build(Data *arr, int n) {
    Node **nodes = (Node **)malloc(sizeof(Node *) * n);
    for (int i = 0; i < n; i++) {
        nodes[i] = getNewNode(arr + i);
    }
    for (int i = 1; i < n; i++) {
        insertOnce(nodes, i);
    }
    for (int i = n - 1; i >= 1; i--) {
        Node *p = getNewNode(NULL);
        p->next[0] = nodes[i - 1];
        p->next[1] = nodes[i];
        p->p = p->next[0]->p + p->next[1]->p;
        nodes[i - 1] = p;
        insertOnce(nodes, i - 1);
    }
    char *buff = (char *)malloc(sizeof(char) * n);
    HaffmanTree *tree = getNewTree(n);
    tree->root = nodes[0];
    extractCodes(tree->root, tree->codes, 0, 0, buff);
    free(nodes);
    free(buff);
    return tree;
}

void output(Node *root, char ch) {
    Node *p = root;
    int flag = 0;
    int cnt = 0;
    while (p->next[0] != NULL && p->next[1] != NULL) {
        if (flag) scanf("%c", &ch);
        flag = 1;
        //printf("%d", cnt);
        //printf("%c", ch);
        if (ch - '0') p = p->next[1];
        else p = p->next[0];
        cnt++;
    }
    //printf("%d", cnt);
    printf("%c", p->ch);
    return ;
}

void solve(Node *root) {
    char ch;
    char *s;
    scanf("%c", &ch);
    while (scanf("%c", &ch) != EOF) {
        output(root, ch); 
    } 
    return ;
}

int main() {
    int n;
    char str[10];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s%lf", str, &arr[i].p); 
        arr[i].ch = str[0];
    }
    HaffmanTree *tree = build(arr, n);
    // 输出哈夫曼编码
    /*
    printf("%d\n", n);
    for (int i = 0; i < tree->n; i++) {
        printf("%c %s\n", tree->codes[i].ch, tree->codes[i].str);
    }*/
    //解码
    solve(tree->root);
    return 0;
}
