//
// Created by saltfish on 2021/9/28.
//

#include "SelfDefine.h"





class stud
{
public:
    struct Link_Node list;
    string name;
    char stu_number[18];


}num_n_stu;

int test1(){
    struct Link_Node head;
    stud stu_1;
    stud stu_2;
    stud *entry;
    struct Link_Node * p;
    stu_1.name = "asdafsdfa";
    Link_Hadd(&head,&stu_1.list);

    stu_2.name = "aaa";
    Link_Hadd(&stu_1.list,&stu_2.list);

    p=(&head)->next;
    entry = ((struct stud *)((char *)(p)-(unsigned long)(&((stud *)0)->list)));

    cout<<entry->name;
    p =(&head)->next->next;
    entry = ((struct  stud *)((char *)(p)-(unsigned long )(&((stud *)0)->list)));
    cout<<entry->name;
    return 0;
}

typedef int(*chain_func)(string buf);



class chain_ops_node{
public:
    struct Link_Node list;
    string str="";
    chain_func handler;
};
struct Link_Node head;

int handler(string buf){
    cout<<buf<<"    "<<"enter chain handler1."<<endl;
    return 0;
}

int handler2(string buf){
    cout<<buf<<"    "<<"enter chain handler2."<<endl;;
        return 1;
}
//(struct chain_ops_node *)malloc(sizeof(struct chain_ops_node)
class chain_ops_node *node1 = new (chain_ops_node);
class chain_ops_node node2;
class chain_ops_node node3;
void chain_mode1_init()
{
    node1->str = "asdafsd";
    node1->handler = handler;
    //
    node2.str = "";
    node2.handler = handler2;
    node3.str = "bbbbbbb";
    node3.handler = handler2;
    //init list
    Init_head(&head);
}


int chain_register(struct chain_ops_node* node)
{
    //lock chain_global_list
    //add node into chain_global_list according to priority
    //unlock chain_global_list
    Link_Hadd(&head,&node->list);
    Log_info("handle register.");
    return 0;
}


int chain_unregister(struct chain_ops_node* node)
{
    //lock chain_global_list
    //delete node into chain_global_list
    //unlock chain_global_list
    Link_Del(&head,&node->list);
    printf("chain unregister.\n");
    return 0;
}

int UseingTest(){
    struct Link_Node *p;
    class chain_ops_node *entry;

    chain_mode1_init();
    chain_register(node1);
    chain_register(&node2);
    chain_register(&node3);

//    p = (&head)->next->next;
//    entry = ((struct  chain_ops_node *)((char *)(p)-(unsigned long )(&((chain_ops_node *)0)->list)));
//    entry->handler("aaa");
//
    p=(&head)->next;
    while (p->next != NULL){
        entry = ((class  chain_ops_node *)((char *)(p)-(unsigned long )(&((chain_ops_node *)0)->list)));

        if(entry->str == ""){

            struct Link_Node *prt = p->prve;
            class chain_ops_node *enptr = ((class  chain_ops_node *)((char *)(prt)-(unsigned long )(&((chain_ops_node *)0)->list)));

            string res = enptr->str;

            entry->str = res;
        }

        entry->handler(entry->str);

        p = p->next;
    }
    entry = ((struct  chain_ops_node *)((char *)(p)-(unsigned long )(&((chain_ops_node *)0)->list)));
    entry->handler(entry->str);

    return 2;
}



int main(){
    expmple4();
//ser_lab();


//    vector<string> rss = SrceenDatas(res,2,25,LE);
//    res = MergeList(rss);
//    rss = SortOrChange(res,2,0,Desc);
//    TraverseList(rss);
//    Link_Node *head = new(Link_Node);
//    duty_node *srceenDatas = new(class duty_node);
//    srceenDatas->init_node(SrceenDatas,res,2,25,LE);
//    duty_register(head,srceenDatas);
//    Log_info(run_task(*head));
//ser_start();
//     ser_lab();
//byt_Lab();
//cout<<bit_filp_strlab("011000010110001001100011");

//string stry = "111100001111001100000101111100011111000111110001";
////reverse(begin(stry),end(stry));
////
////cout<<stry<<endl;
//cout<<bit_filp_strlab(stry);

    return 0;
}


