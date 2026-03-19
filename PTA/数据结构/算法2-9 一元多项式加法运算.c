#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef double T;
typedef int siz_t;
typedef struct NODE Node;
typedef struct LIST List;

struct NODE{
    T val;
    int e;
    Node*pre;
    Node*nex;
};
struct LIST{
    Node*dummy_head;
    Node*dummy_tail;
    void(*push_back)(List*self,T val,int e);
    void(*clear)(List*self);
    void(*destroy)(List*self);
};

Node*creat_Node(T val,int e){
    Node*node=(Node*)malloc(sizeof(Node));
    if(node==NULL){
        return NULL;
    }
    node->e=e;
    node->val=val;
    node->pre=NULL;
    node->nex=NULL;
    return node;
}
void My_push_back(List*self,T val,int e){
    Node*node=creat_Node(val,e);
    if(node==NULL){
        return;
    }
    node->pre=self->dummy_tail->pre;
    node->nex=self->dummy_tail;
    self->dummy_tail->pre->nex=node;
    self->dummy_tail->pre=node;
}

void My_clear(List*self){
    Node*p=self->dummy_head->nex;
    while(p!=self->dummy_tail){
        p=p->nex;
        free(p->pre);
    }
    self->dummy_head->nex=self->dummy_tail;
    self->dummy_tail->pre=self->dummy_head;
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
    list->dummy_head=creat_Node(-1,-1);
    if(list->dummy_head==NULL){
        return NULL;
    }
    list->dummy_tail=creat_Node(-1,-1);
    if(list->dummy_tail==NULL){
        return NULL;
    }
    list->dummy_head->nex=list->dummy_tail;
    list->dummy_head->pre=NULL;
    list->dummy_tail->pre=list->dummy_head;
    list->dummy_tail->nex=NULL;
    list->push_back=My_push_back;
    list->clear=My_clear;
    list->destroy=My_destroy;
    return list;
}

int n;
T val;
int e;

int main(void){
    List*list1=creat_List();
    List*list2=creat_List();
    List*list3=creat_List();


    scanf("%d",&n);
    while(n--){
        scanf("%lf%d",&val,&e);
        list1->push_back(list1,val,e);
    }
    scanf("%d",&n);
    while(n--){
        scanf("%lf%d",&val,&e);
        list2->push_back(list2,val,e);
    }
    Node*p1=list1->dummy_head->nex;
    Node*p2=list2->dummy_head->nex;
    while(p1!=list1->dummy_tail&&p2!=list2->dummy_tail){
        if(p1->e>p2->e){
            list3->push_back(list3,p1->val,p1->e);
            p1=p1->nex;
        }
        else if(p1->e<p2->e){
            list3->push_back(list3,p2->val,p2->e);
            p2=p2->nex;
        }
        else{
            list3->push_back(list3,p1->val+p2->val,p2->e);
            p1=p1->nex;
            p2=p2->nex;
        }
    }
    while(p1!=list1->dummy_tail){
        list3->push_back(list3,p1->val,p1->e);
        p1=p1->nex;
    }
    while(p2!=list2->dummy_tail){
        list3->push_back(list3,p2->val,p2->e);
        p2=p2->nex;
    }
    Node*p3=list3->dummy_head->nex;
    while(p3!=list3->dummy_tail){
        if(fabs(p3->val)>1e-9){
            printf("%.2lf %d\n",p3->val,p3->e);
        }
        p3=p3->nex;
    }


    list1->destroy(list1);
    list2->destroy(list2);
    list3->destroy(list3);
}