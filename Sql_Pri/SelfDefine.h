//
// Created by saltfish on 2021/10/18.
//

#ifndef SQL_PRI_SELFDEFINE_H
#define SQL_PRI_SELFDEFINE_H
#include <error.h>
#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include <vector>
#include <time.h>
#include <bitset>
using namespace std;



//Link_List
/**
 * 链表节点
 * @param prve:前驱 next:后继
 * */

typedef struct Link_Node{

    struct Link_Node *prve;
    struct Link_Node *next;

}Link_Node;

void Init_head(Link_Node *head);

void Link_SwapH(Link_Node *head,Link_Node *Prve_Node,Link_Node *Next_Node);

void Link_SwapT(Link_Node *head,Link_Node *Prve_Node,Link_Node *Next_Node);

void Link_Hadd(Link_Node *head,Link_Node *new_Node);

void Link_Tadd(Link_Node *head,Link_Node *new_Node);

void Link_Del(Link_Node *head,Link_Node *tail);

void Link_AllDel(Link_Node *head);


//TesTraverse测试

void TraverseList(vector<string> list);
void Log_info(string str);
void log_err(string str);
string MergeList(vector<string> list);
//两个相互反转的函数翻转字符串和二进制
string bit_filp_str(vector<bitset<8>> data);
vector<bitset<8>> str_filp_bit(string str);
string bit_filp_strlab(string bstr);
bool req_head_const(char c);





//sortData其中的一些功能

//做排序时候用来判断是什么类型的排序
enum SortType{
    Int,
    Acsll
};


enum TokenType{
    Asc,
    Desc,
    Max,
    Min,
    SELECT,
    Add ,
    Drop,
    Alter_Add_Column,
    Alter_Drop_Column,
    Database_Name,        //数据库名
    Column_Name,          //列名
    From_TableName,
    Alter_Table,
    LIMIT_Param,
    GROUPBY_Column,
    Select_Column,
    Where_Column,
    DataType,
    FROM,
    WHERE,
    AND,                 //交
    OR,                  //并
    NOT,                 //补
    LIMIT,
    GROUPBY,
    Function,
    Select_ColumnName,
    Alter,
    Create,
    GE,                   //>=
    GT,                   //>
    EQ,                   //==
    LE,                   //<=
    LT,                   //<
    LeftParen,            //(
    RightParen,           //)
    Assignment,           //=
    START,                //*
    COMMA,                //,
    END,                  //;
};
typedef vector<string>(*duty_func)(string res,int colums,int aim,TokenType type);
//
//struct duty_nodes{
//    struct Link_Node list;
//    duty_func handler;
//};

class duty_node{

public:
    struct Link_Node list;

    duty_func handler;

    string res = "";
    int colums;
    int aim;
    TokenType type;
    void init_node(duty_func handlers,string ress,int colum,int aim,TokenType type1){

        this->handler = handlers;

        this->res = ress;

        this->colums = colum;

        this->aim = aim;

        this->type = type1;
    }
    ~duty_node(){
        Log_info("节点被清理");
    }
};


//函数的底层功能函数
vector<int> StrAnInt(vector<string> strs);
void quickSort(long arr[],string str[],int begin,int end);
void IntquickSortUp(int arr[],string str[],int begin,int end);
void IntquickSortDown(int arr[],string str[],int begin,int end);
vector<int> AscllFile(vector<string> Value);
string SortMax(vector<int> arr,vector<string> rows);
string SortMin(vector<int> arr,vector<string> rows);


//第一层封装
vector<string> SortNum(vector<string> value,vector<string> rows,TokenType type);
vector<string> SortByAscll(vector<string> value,vector<string> rows,TokenType type);
vector<string> SortByInt(vector<string> value,vector<string> rows,TokenType type);
vector<string> SortByTime(vector<long> time,vector<string> rows);

//第二层封装
vector<string> SortOrChange(string res,int colums,int aim,TokenType type);
vector<string> SrceenDatas(string res,int colums,int aim,TokenType type);
vector <string> Set_operation(string res,int colums,int aim,TokenType type);


//srceens.cpp声明


vector<string> Greaters(vector<int> arr,vector<string> rows,int arrsize,int aim);

vector<string> Lesss(vector<int> arr,vector<string> rows,int arrsize,int aim);

vector<string> GreEqus(vector<int> arr,vector<string> rows,int arrsize,int aim);

vector<string> LesEqus(vector<int> arr,vector<string> rows,int arrsize,int aim);

vector<string> Equals(vector<int> arr,vector<string> rows,int arrsize,int aim);


//strfactory字符串处理（分割）

vector<string> split(const string& str,const string& delim);


//Filter过滤数据

vector<string>  FilterByValue(string strdata,int column);
vector<string> FilterColumn(string data);


//Duty责任链主要实现功能
string run_task(Link_Node head);
void duty_register(Link_Node *head,class duty_node *node );
void duty_unregister(Link_Node head,class duty_node node);


//exmple例子实现
void expmple1();
void expmple2();
void expmple3();
void expmple4();


//实现最后的limit操作
vector<string> limit_data(string data,int endnum,int aim,TokenType type);



//skt_requst.cpp
void ser_start();
int ser_lab();








#endif //SQL_PRI_SELFDEFINE_H
