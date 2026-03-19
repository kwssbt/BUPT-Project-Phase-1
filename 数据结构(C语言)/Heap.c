#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int T;
typedef struct Vector Vector;
const int INIT_CAP=16;

void print_T(T val){
    printf("%d",val);
}

struct Vector{
    T*data;
    int _size;
    int cap;

    int(*size)(Vector*self);
    bool(*empty)(Vector*self);
    T(*back)(Vector*self);
    T(*front)(Vector*self);
    T(*get)(Vector*self,int index);
    void(*set)(Vector*self,int index,T val);

    void(*resize)(Vector*self,int new_cap);
    void(*push_back)(Vector*self,T val);
    void(*pop_back)(Vector*self);

    void(*clear)(Vector*self);
    void(*destroy)(Vector*self);
};

int My_size(Vector*self){
    return self->_size;
}
bool My_empty(Vector*self){
    return self->_size==0;
}
T My_back(Vector*self){
    return self->data[self->_size-1];
}
T My_front(Vector*self){
    return self->data[0];
}
T My_get(Vector*self,int index){
    return self->data[index];
}
void My_set(Vector*self,int index,T val){
    self->data[index]=val;
}
void My_resize(Vector*self,int new_cap){
    self->cap=new_cap;
    self->data=(T*)realloc(self->data,new_cap*sizeof(T));
}
void My_push_back(Vector*self,T val){
    if(self->_size==self->cap){
        self->resize(self,self->cap*2);
    }
    self->data[self->_size++]=val;
}
void My_pop_back(Vector*self){
    self->_size--;
}
void My_clear(Vector*self){
    self->_size=0;
}
void My_destroy(Vector*self){
    free(self->data);
    free(self);
}
Vector*creat_vector_with_cap(int init_cap){
    Vector*vector=(Vector*)malloc(sizeof(Vector));
    if(vector==NULL){
        return NULL;
    }
    vector->data=(T*)malloc(init_cap*sizeof(T));
    if(vector->data==NULL){
        return NULL;
    }
    vector->_size=0;
    vector->cap=init_cap;

    vector->size=My_size;
    vector->empty=My_empty;
    vector->back=My_back;
    vector->front=My_front;
    vector->get=My_get;
    vector->set=My_set;

    vector->resize=My_resize;
    vector->push_back=My_push_back;
    vector->pop_back=My_pop_back;

    vector->clear=My_clear;
    vector->destroy=My_destroy;

    return vector;
}
Vector*creat_vector(){
    Vector*vector=(Vector*)malloc(sizeof(Vector));
    if(vector==NULL){
        return NULL;
    }
    vector->data=(T*)malloc(INIT_CAP*sizeof(T));
    if(vector->data==NULL){
        return NULL;
    }
    vector->_size=0;
    vector->cap=INIT_CAP;

    vector->size=My_size;
    vector->empty=My_empty;
    vector->back=My_back;
    vector->front=My_front;
    vector->get=My_get;
    vector->set=My_set;

    vector->resize=My_resize;
    vector->push_back=My_push_back;
    vector->pop_back=My_pop_back;

    vector->clear=My_clear;
    vector->destroy=My_destroy;

    return vector;
}


typedef struct Heap Heap;

struct Heap{
    Vector*arr;

    int(*size)(Heap*self);
    bool(*empty)(Heap*self);
    T(*top)(Heap*self);

    void(*up)(Heap*self,int index);
    void(*down)(Heap*self,int index);

    void(*push)(Heap*self,T val);
    void(*pop)(Heap*self);
    void(*destroy)(Heap*self);
};

int My_heap_size(Heap*self){
    return self->arr->_size;
}
bool My_heap_empty(Heap*self){
    return self->arr->empty(self->arr);
}
T My_top(Heap*self){
    return self->arr->data[0];
}
void My_up(Heap*self,int index){
    while(self->arr->get(self->arr,index)>self->arr->get(self->arr,(index-1)/2)){
        T temp=self->arr->get(self->arr,index);
        self->arr->set(self->arr,index,self->arr->get(self->arr,(index-1)/2));
        self->arr->set(self->arr,(index-1)>>1,temp);
        index=(index-1)/2;
    }
}
void My_down(Heap*self,int index){
    int left=index*2+1;
    while(left<self->size(self)){
        int best=left+1<self->size(self)&&self->arr->get(self->arr,left+1)>self->arr->get(self->arr,left)?left+1:left;
        if(self->arr->get(self->arr,best)<=self->arr->get(self->arr,index)){
            return;
        }
        T temp=self->arr->get(self->arr,index);
        self->arr->set(self->arr,index,self->arr->get(self->arr,best));
        self->arr->set(self->arr,best,temp);
        index=best;
        left=index*2+1;
    }
}
void My_push(Heap*self,T val){
    self->arr->push_back(self->arr,val);
    self->up(self,self->size(self)-1);
}
void My_pop(Heap*self){
    if(self->empty(self)){
        return;
    }
    self->arr->set(self->arr,0,self->arr->back(self->arr));
    self->arr->pop_back(self->arr);
    self->down(self,0);
}
void My_heap_destroy(Heap*self){
    self->arr->destroy(self->arr);
    free(self);
}

Heap*creat_heap_with_vector(Vector*vector){
    Heap*heap=(Heap*)malloc(sizeof(Heap));
    if(heap==NULL){
        return NULL;
    }
    heap->arr=vector;

    heap->size=My_heap_size;
    heap->empty=My_heap_empty;
    heap->top=My_top;

    heap->up=My_up;
    heap->down=My_down;
    
    heap->push=My_push;
    heap->pop=My_pop;

    heap->destroy=My_heap_destroy;

    for(int i=vector->_size/2;i>=0;--i){
        heap->down(heap,i);
    }

    return heap;
}

Heap*creat_heap(){
    Heap*heap=(Heap*)malloc(sizeof(Heap));
    if(heap==NULL){
        return NULL;
    }
    heap->arr=creat_vector();
    if(heap->arr==NULL){
        return NULL;
    }

    heap->size=My_heap_size;
    heap->empty=My_heap_empty;
    heap->top=My_top;

    heap->up=My_up;
    heap->down=My_down;
    
    heap->push=My_push;
    heap->pop=My_pop;

    heap->destroy=My_heap_destroy;

    return heap;
}


int main(void){
    Heap*heap=creat_heap();
    
    heap->destroy(heap);
}