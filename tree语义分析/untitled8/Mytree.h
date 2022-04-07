//
// Created by saltfish on 2022/2/6.
//

#ifndef UNTITLED8_MYTREE_H
#define UNTITLED8_MYTREE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <iostream>
#include <time.h>
using namespace std;
//日志输出-----自封带色彩
void log_info(string str);
void log_erro(string str);
void log_debug(string str);
//缓存列表
class str_link{
public:
    string data;
    int weith;//顺便表明权重
    str_link *next = NULL;
    str_link *prev = NULL;

    ~str_link();
};

vector<string> split(const string& str,const string& delim);
void add_str_link(str_link *root,string str,int weith);
void display(str_link *root);
int get_link_size(str_link *root);
string get_link_str(str_link *root,int len);
int get_link_weith(str_link *root,int len);
str_link *remove_link(str_link *root,int len);


//缓存部分
void cache_build(string str);
void cache_clear();
void dis_cache();
string get_cache_un(int len);
string get_cache_bi(int len);
int get_bi_weith(int len);
int get_un_size();
int get_bi_size();


//这里不太确定是否使用二叉树，所以先写一个树
class binoc{
public:
    string data;
    int weith = 0;
    binoc *parent = NULL;//父节点
    binoc *lchild = NULL;//左节点
    binoc *rchild = NULL;//右节点
};

class unary{
public:
    string data;
    unary *next = NULL;//子节点
    unary *prev = NULL;//父节点
    binoc *tree = NULL;
};


//开始树的建立link
void tree_build(unary *root);
void add_tree_un(unary *root,string str);


//开始树的建立tree
void add_tree_bi(binoc *root,string str,int weith);






#endif //UNTITLED8_MYTREE_H
