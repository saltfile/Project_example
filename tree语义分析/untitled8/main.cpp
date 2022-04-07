#include "Mytree.h"

int main() {





//
//    binoc *tree = new(binoc);
//    add_tree_bi(tree,"aaa",10);
//    add_tree_bi(tree,"bbb",5);
//    add_tree_bi(tree,"ccc",4);
//    add_tree_bi(tree,"ddd",2);
//    add_tree_bi(tree,"eee",1);
//    add_tree_bi(tree,"fff",13);
//    add_tree_bi(tree,"ggg",12);
//    add_tree_bi(tree,"hhh",15);









    cache_build("num > 4 and age < 12 and id = 4 or name = xxx and push > 65 and cd < 65 desc limit");
    dis_cache();
    int arr = get_bi_weith(3);
    string sss = get_cache_bi(3);
    string str = get_cache_un(1);
    string str2 = get_cache_bi(3);
    unary *root = new (unary);
    tree_build(root);


//    cache_clear();
//    dis_cache();
    return 0;
}
