#include "list.h"

index_list(int a):head->data(a){
    head->next = NULL;
    tail = head;
    size = 0;
    }
}
void push (int a){
    node* tmp = new node;
    tmp->data = a;
    tmp->next = NULL;
    tail->next = tmp;
    tail = tmp;
    size++;
    }
void pop(){
		if (head)
		{
			if (head == tail)
			{
				delete(head);
				head = NULL;
				tail = NULL;
				size--;
			}
			else
			{
				node* tmp = head;
				head = head->next;
				delete(tmp);
				size--;
			}
		}
	}
int operator [](size_t i){
    if (i <= size-1 && i > 0) {
        node tmp = head;
        for (int k = 0, k < i, k++) tmp = tmp->next;
		
		return tmp->data;
        } else {
			ofstream fout("error.txt"); 
    		fout << "Вы вышли за пределы списка!!!"; 
    		fout.close(); 
			return 0;
			};
        
    }


