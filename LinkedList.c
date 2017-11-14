//
// Created by 王靖凯 on 2017/11/9.
//

#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

/*建立一个节点*/
struct list *create_list() {
    return calloc(1, sizeof(struct list));
}

/*循环遍历链表*/
void traverse(struct list *ls) {
    struct list *p = ls->next;
    while (p) {
        printf("%d\n",p->data);
        p = p->next;
    }
}

/*在指定位置插入元素*/
struct list *insert_list(struct list *ls, int n, int data) {
    list *p = ls;
    while (p && n--) {
        p = p->next;
    }
    if (!p)
        return NULL;
    else {
        list *node = create_list();
        node->data = data;
        node->next = p->next;
        p->next = node;
        return node;
    }
}

/*删除指定位置元素*/
int delete_list(struct list *ls, int n) {
    list *p = ls;
    while (p && --n) {
        p = p->next;
    }
    if (!p)
        return 0;
    list *node = p->next;
    if (!node)
        return 0;
    p->next = node->next;
    free(node);
    return 1;
}

/*返回链表元素个数*/
int count_list(struct list *ls) {
    list *p = ls->next;
    int len = 0;
    while (p) {
        len++;
        p = p->next;
    }
    return len;
}

/*清空链表，只保留首节点*/
void clear_list(struct list *ls) {
    if (!ls->next)
        return;
    list *s = ls;
    list *p = ls->next;
    list *n = p->next;
    while (n) {
        free(p);
        p = n;
        n = n->next;
    }
    s->next = NULL;
}

/*返回链表是否为空*/
int empty_list(struct list *ls) {
    return ls->next == NULL ? 0 : 1;
}

/*返回链表指定位置的节点*/
struct list *locale_list(struct list *ls, int n) {
    list *p = ls;
    while (p && n--) {
        p = p->next;
    }
    if (!p)
        return NULL;
    return p;
}

/*返回数据域等于data的节点*/
struct list *elem_locale(struct list *ls, int data) {
    list *p = ls->next;
    int n = 1;
    while (p) {
        if (p->data == data)
            return p;
        p = p->next;
        n++;
    }
    return NULL;
}

/*返回数据域等于data的节点位置*/
int elem_pos(struct list *ls, int data) {
    list *p = ls;
    int n = 0;
    while (p) {
        if (data == p->data)
            return n;
        n++;
        p = p->next;
    }
    return -1;
}

/*得到链表最后一个节点*/
struct list *last_list(struct list *ls) {
    list *p = ls;
    while (p) {
        p = p->next;
    }
    return p;
}

/*合并两个链表,结果放入ls1中*/
void merge_list(struct list *ls1, struct list *ls2) {
    if (!ls2->next)
        return;
    list *p = ls1;
    list *pre = p;
    while (p) {
        pre = p;
        p = p->next;
    }
    pre->next = ls2->next;
}

/*链表逆置*/
void reverse(struct list *ls) {
    if (!ls->next)
        return;
    list *s = ls;
    list *pre = NULL;
    list *cur = ls->next;
    list *next = NULL;
    while (cur) {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    s->next = pre;
}