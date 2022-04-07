//
// Created by saltfish on 2022/2/7.
//
#include "Mytree.h"
void add_tree_un(unary *root,string str){
    unary *p = root;

    if(p->data == ""){
        p->data = str;
        return;
    }
    while (p->next){
        p = p->next;
    }
    unary *node = new(unary);
    node->next = NULL;
    node->data = str;
    node->prev = p;
    p->next = node;

}




void add_tree_bi(binoc *root,string str,int weith){
    binoc *p = root;
    binoc *prev = NULL;
    if(p->data == ""&&p->weith == 0){
        p->data = str;
        p->weith = weith;
        return;
    }
    while (p!=NULL){
        prev = p;
        if(weith < p->weith)
            p = p->lchild;
        else
            p = p->rchild;
    }
    binoc *node = new(binoc);
    node->data = str;
    node->weith = weith;

    if(weith < prev->weith){
        prev->lchild = node;
        node->parent = prev;
    }else{
        prev->rchild = node;
        node->parent = prev;
    }

}



//void tree_build(unary *root) {
//    unary *p = root;
//    binoc *tree = new (binoc);
//    if (p == NULL) {
//        p = new (unary);
//    }
//    for (int i = 1; i <= get_un_size(); i++) {
//        add_tree_un(p, get_cache_un(i));
//    }
//
//    int cachelen = get_bi_size();
//    int arr = 1;
//    for (int i = 1; i <= get_bi_size(); i++) {
//        if (get_cache_bi(i) == "or") {
//            arr = i;
//            break;
//        }
//    }
//    if (arr != 1) {
//        //左支
//        add_tree_bi(tree, get_cache_bi(arr), get_bi_weith(arr));
//        int low = arr;
//        while (low > 4) {
//            low -= 4;
//            string res = get_cache_bi(low);
//            if (res == "and" || res == "or") {
//                add_tree_bi(tree, res, get_bi_weith(low));
//            }
//            res = get_cache_bi(low + 2);
//            if (res == "=" || res == ">" || res == "<" || res == "!=" | res == "<=" || res == "=>") {
//                add_tree_bi(tree, get_cache_bi(low + 2), get_bi_weith(low + 2));
//            }
//            add_tree_bi(tree, get_cache_bi(low + 3), get_bi_weith(low + 3));
//            add_tree_bi(tree, get_cache_bi(low + 1), get_bi_weith(low + 1));
//
//        }
//        string res = get_cache_bi(low - 2);
//        if (res == "=" || res == ">" || res == "<" || res == "!=" | res == "<=" || res == "=>") {
//            add_tree_bi(tree, res, get_bi_weith(low - 2));
//        }
//        add_tree_bi(tree, get_cache_bi(low - 1), get_bi_weith(low - 1));
//        add_tree_bi(tree, get_cache_bi(low - 3), get_bi_weith(low - 3));
//    }
//    if (cachelen - arr >= 3) {
//        int high = cachelen;
//        while (high > cachelen - 4) {
//            high -= 4;
//            string res = get_cache_bi(high);
//            if (res == "and" || res == "or") {
//                add_tree_bi(tree, res, get_bi_weith(high));
//            }
//            res = get_cache_bi(high + 2);
//            if (res == "=" || res == ">" || res == "<" || res == "!=" | res == "<=" || res == "=>") {
//                add_tree_bi(tree, res, get_bi_weith(high + 2));
//            }
//            add_tree_bi(tree,get_cache_bi(high + 3),get_bi_weith(high + 3));
//            add_tree_bi(tree,g string res = get_cacheet_cache_bi(high + 1),get_bi_weith(high + 1));
//
//        }
//        string res = get_cache_bi(high - 2);
//        if (res == "=" || res == ">" || res == "<" || res == "!=" | res == "<=" || res == "=>") {
//            add_tree_bi(tree, res, get_bi_weith(high - 2)-4);
//        }
//        add_tree_bi(tree, get_cache_bi(high - 1), get_bi_weith(high - 1)-4);
//        add_tree_bi(tree, get_cache_bi( high - 3), get_bi_weith(high - 3)-4);
//    }
//
//}

void tree_build(unary *root) {
    unary *p = root;
    binoc *tree = new (binoc);
    if (p == NULL) {
        p = new (unary);
    }
    for (int i = 1; i <= get_un_size(); i++) {
        add_tree_un(p, get_cache_un(i));
    }

    int cachelen = get_bi_size();
    int arr = 1;
    for (int i = 1; i <= get_bi_size(); i++) {
        if (get_cache_bi(i) == "or") {
            arr = i;
            break;
        }
    }
    if (arr != 1) {
        //左支
        add_tree_bi(tree, get_cache_bi(arr), get_bi_weith(arr));
        int low = arr;
        while (low > 4) {
            low -= 4;
            string res = get_cache_bi(low);
            if (res == "and" || res == "or") {
                add_tree_bi(tree, res, get_bi_weith(low));
            }
        }

        int num = 2;
        while (num < arr){
            add_tree_bi(tree,get_cache_bi(num),get_bi_weith(num));
            num+=4;
        }
        int num1 = 1;
        while (num1 < arr){
            add_tree_bi(tree,get_cache_bi(num1),get_bi_weith(num1));
            num1+=4;
        }
        int num2 = 3;
        while (num2 < arr){
            add_tree_bi(tree,get_cache_bi(num2),get_bi_weith(num2));
            num2+=4;
        }

    }
    //右枝
    if((cachelen - arr) > 4){
        int num = arr+4;
        while (num < cachelen - 3){
            add_tree_bi(tree,get_cache_bi(num),get_bi_weith(num));
            num+=4;
        }
        int num1 = arr+2;
        while (num1 < cachelen){
            add_tree_bi(tree,get_cache_bi(num1),get_bi_weith(num1));
            num1+=4;
        }

        int num2 = arr+1;
        while (num2 < cachelen){
            add_tree_bi(tree,get_cache_bi(num2),get_bi_weith(num2));
            num2+=4;
        }

        int num3 = arr+3;
        while (num3 < cachelen){
            add_tree_bi(tree,get_cache_bi(num3),get_bi_weith(num3));
            num3+=4;
        }


    }








}








