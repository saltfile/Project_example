//
// Created by saltfish on 2022/2/7.
//

#include "Mytree.h"

str_link::~str_link() {
    log_debug("node is delete : "+this->data);
}

void add_str_link(str_link *root,string str,int weith){
    str_link *p = root;

    if(p->data == ""){
        p->data = str;
        p->weith = weith;
        return;
    }
    while (p->next){
        p = p->next;
    }
    str_link *node = new(str_link);
    node->next = NULL;
    node->data = str;
    node->weith = weith;
    node->prev = p;
    p->next = node;
}

void display(str_link *root) {

    str_link *p = root;
    if (p == NULL){
        log_info("这是空的了");
        return;
    }
    string str = "[";
    while (p->next){
        str +=p->data+","+to_string(p->weith)+"     ";
        p = p->next;
    }
    str+=p->data+","+to_string(p->weith)+"]";
    log_info(str);
}

int get_link_size(str_link *root){
    int res  = 0;
    str_link *p= root;
    while (p->next){
        res++;
        p=p->next;
    }
    return ++res;
}

string get_link_str(str_link *root,int len){
    string res = "";
    int arrsize = get_link_size(root);
    if(len > arrsize){
        log_erro("超出该链表长度------link.cpp");
        return NULL;
    }else if (len <= 0){
        log_erro("违规下标位置------link.cpp");
        return NULL;
    }
    str_link *p = root;
    for(int i = 1 ; i < len;i++){
        p = p->next;
    }
    res = p->data;
    return res;
}


str_link *remove_link(str_link *root,int len){
    int arrsize = get_link_size(root);
    if(len > arrsize){
        log_erro("超出该链表长度无法删除------link.cpp");
        return NULL;
    }else if (len <= 0){
        log_erro("违规下标位置无法删除---link.cpp");
        return NULL;
    }
    str_link *p = root;
    if(arrsize == 1){
        str_link *node = p;
        delete (node);
        return NULL;
    }
    for(int i = 1 ; i < len;i++){
        p = p->next;
    }
    //尾节点
    if(p->next == nullptr){
        str_link *node = p->prev;
        str_link *nodep = p;
        node->next = NULL;
        delete (nodep);
        while (node->prev){
            node = node->prev;
        }
        return node;
    } else if(p->prev == nullptr){
        str_link *node = p->next;
        str_link *nodep = p;
        node->prev = NULL;
        p = node;
        nodep->next = NULL;
        delete (nodep);
        return node;

    } else{
        str_link *pnode = p->prev;
        str_link *pres = p;
        str_link *nnode = p->next;
        pnode->next = nnode;
        nnode->prev = pnode;
        delete (pres);
        while (pnode->prev){
            pnode = pnode->prev;
        }
        return pnode;
    }
}

int get_link_weith(str_link *root,int len){
    int arr = 0;
    int arrsize = get_link_size(root);
    if(len > arrsize){
        log_erro("超出该链表长度------link.cpp");
        return NULL;
    }else if (len <= 0){
        log_erro("违规下标位置------link.cpp");
        return NULL;
    }
    str_link *p = root;
    for(int i = 1 ; i < len;i++){
        p = p->next;
    }
    arr = p->weith;
    return arr;
}


