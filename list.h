#ifndef __LIST_H__
#define __LIST_H__
struct node{
    int data;
    node* next;
}
class index_list{
    std::size_t size;
    node* head;
    node* tail;
public:
    index_list();
    void pop();
    void push();
    int operator [](size_t i); 
	
};

#endif // __LIST_H__