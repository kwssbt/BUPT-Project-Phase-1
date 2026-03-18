#include<stdio.h>
#include<stdlib.h>

typedef int T;
typedef int siz_t;
typedef struct NODE Node;
typedef struct LIST List;
void print_T(T val){
    printf("%d",val);
}

struct NODE{
    T val;
    Node*pre;
    Node*nex;
};
struct LIST{
    Node*dummy_head;
    Node*dummy_tail;
    siz_t _size;
    siz_t(*size)(List*self);
    T(*back)(List*self);
    T(*front)(List*self);
    void(*push_back)(List*self,T val);
    void(*push_front)(List*self,T val);
    void(*pop_back)(List*self);
    void(*pop_front)(List*self);
    void(*print)(List*self);
    void(*clear)(List*self);
    Node*(*find)(List*self,T key);
    void(*push_x_back)(List*self,T val,T key);
    void(*push_x_front)(List*self,T val,T key);
    void(*delete)(List*self,T key);
    void(*destroy)(List*self);
};

Node*creat_Node(int val){
    Node*node=(Node*)malloc(sizeof(Node));
    if(node==NULL){
        return NULL;
    }
    node->val=val;
    node->pre=NULL;
    node->nex=NULL;
    return node;
}
siz_t My_size(List*self){
    return self->_size;
}
T My_back(List*self){
    return self->dummy_tail->pre->val;
}
T My_front(List*self){
    return self->dummy_head->nex->val;
}
void My_push_back(List*self,T val){
    Node*node=creat_Node(val);
    if(node==NULL){
        return;
    }
    self->_size++;
    node->pre=self->dummy_tail->pre;
    node->nex=self->dummy_tail;
    self->dummy_tail->pre->nex=node;
    self->dummy_tail->pre=node;
}
void My_push_front(List*self,int val){
    Node*node=creat_Node(val);
    if(node==NULL){
        return;
    }
    self->_size++;
    node->nex=self->dummy_head->nex;
    node->pre=self->dummy_head;
    self->dummy_head->nex->pre=node;
    self->dummy_head->nex=node;
}
void My_pop_back(List*self){
    if(self->_size==0){
        return;
    }
    self->_size--;
    Node*p=self->dummy_tail->pre;
    p->pre->nex=self->dummy_tail;
    self->dummy_tail->pre=p->pre;
    free(p);
}
void My_pop_front(List*self){
    if(self->_size==0){
        return;
    }
    self->_size--;
    Node*p=self->dummy_head->nex;
    p->nex->pre=self->dummy_head;
    self->dummy_head->nex=p->nex;
    free(p);
}
void My_print(List*self){
    printf("List: ");
    Node*p=self->dummy_head->nex;
    while(p!=self->dummy_tail){
        print_T(p->val);
        printf(" <-> ");
        p=p->nex;
    }
    printf("NULL\n");
}
void My_clear(List*self){
    Node*p=self->dummy_head->nex;
    while(p!=self->dummy_tail){
        p=p->nex;
        free(p->pre);
    }
    self->dummy_head->nex=self->dummy_tail;
    self->dummy_tail->pre=self->dummy_head;
    self->_size=0;
}
Node*My_find(List*self,T key){
    Node*p=self->dummy_head->nex;
    while(p!=self->dummy_tail){
        if(p->val==key){
            return p;
        }
        p=p->nex;
    }
    return NULL;
}
void My_push_x_back(List*self,T val,T key){
    Node*p=self->find(self,key);
    if(p==NULL){
        My_push_back(self,val);
        return;
    }
    self->_size++;
    Node*node=creat_Node(val);
    node->pre=p;
    node->nex=p->nex;
    p->nex->pre=node;
    p->nex=node;
}
void My_push_x_front(List*self,T val,T key){
    Node*p=self->find(self,key);
    if(p==NULL){
        My_push_front(self,val);
        return;
    }
    self->_size++;
    Node*node=creat_Node(val);
    node->nex=p;
    node->pre=p->pre;
    p->pre->nex=node;
    p->pre=node;

}
void My_delete(List*self,T key){
    Node*p=self->find(self,key);
    if(p==NULL){
        return;
    }
    self->_size--;
    p->pre->nex=p->nex;
    p->nex->pre=p->pre;
    free(p);
}
void My_destroy(List*self){
    if(self==NULL){
        return;
    }
    self->clear(self);
    free(self->dummy_head);
    free(self->dummy_tail);
    free(self);
}
List*creat_List(){
    List*list=(List*)malloc(sizeof(List));
    if(list==NULL){
        return NULL;
    }
    list->dummy_head=creat_Node(-1);
    if(list->dummy_head==NULL){
        return NULL;
    }
    list->dummy_tail=creat_Node(-1);
    if(list->dummy_tail==NULL){
        return NULL;
    }
    list->_size=0;
    list->dummy_head->nex=list->dummy_tail;
    list->dummy_head->pre=NULL;
    list->dummy_tail->pre=list->dummy_head;
    list->dummy_tail->nex=NULL;
    list->size=My_size;
    list->back=My_back;
    list->front=My_front;
    list->push_back=My_push_back;
    list->push_front=My_push_front;
    list->pop_back=My_pop_back;
    list->pop_front=My_pop_front;
    list->print=My_print;
    list->clear=My_clear;
    list->find=My_find;
    list->push_x_back=My_push_x_back;
    list->push_x_front=My_push_x_front;
    list->delete=My_delete;
    list->destroy=My_destroy;
    return list;
}



int main(void){
    List*list=creat_List();
    
}