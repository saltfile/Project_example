//
// Created by saltfish on 2022/2/7.
//

#include "Mytree.h"
str_link *un = NULL;
str_link *bi = NULL;
void cache_build(string str){
    vector<string> res =split(str," ");
    if(un == NULL){
        un = new (str_link);
    }
    if (bi == NULL){
        bi = new (str_link);
    }

    for(int i = 0; i < res.size();i++){
     if(res[i] == "desc"||res[i] == "acs"||res[i] == "limit"){
         add_str_link(un,res[i],i);
     } else{
         add_str_link(bi,res[i],i);
     }
    }
};
void cache_clear(){
    int unlen = get_link_size(un);
    int bilen = get_link_size(bi);
    for(int i = unlen;i >= 1;i--){
        un = remove_link(un,i);
    }
    for(int i = bilen;i >= 1;i--){
        bi = remove_link(bi,i);
    }

    str_link *p = un;
    log_debug("链表缓存清空");

}

string get_cache_un(int len){
    string res = get_link_str(un,len);
    return res;
}

string get_cache_bi(int len){
    string res = get_link_str(bi,len);
    return res;
}
int get_bi_weith(int len){
    int arr = get_link_weith(bi,len);
    return arr;
}

void dis_cache(){
    display(un);
    display(bi);
}


int get_un_size(){
    int len = get_link_size(un);
    return len;
}
int get_bi_size(){
    int len = get_link_size(bi);
    return len;
}



