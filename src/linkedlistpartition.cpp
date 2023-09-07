#include "generator.hpp"
//将一个单链表根据所给定的值分成三部分，分别为小于，等于以及大于该值的部分

auto partition(Node* head, int pivot)->Node*{
    try{
        if(head==nullptr)
            throw std::runtime_error("list does not exist");
    }catch(std::runtime_error err){
        cerr<<err.what()<<"\n";
    }
    Node* sH=nullptr; //small Head
    Node* sT=nullptr; //small Tail
    Node* eH=nullptr; //equal Head
    Node* eT=nullptr; //equal Tail
    Node* lH=nullptr; //large Head
    Node* lT=nullptr; //large Tail
    Node* pos=head->next;
    int elements=0;
    while(pos!=nullptr){
        elements++;
        Node* nexttemp=pos->next;
        pos->next=nullptr;
        if(pos->data<pivot){
            if(sH==nullptr){
                sH=pos;
                sT=pos;
            }else{
                sT->next=pos;
                sT=pos;
            }
        }else if(pos->data==pivot){
            if(eH==nullptr){
                eH=pos;
                eT=pos;
            }else{
                eT->next=pos;
                eT=pos;
            }
        }else{
            if(lH==nullptr){
                lH=pos;
                lT=pos;
            }else{
                lT->next=pos;
                lT=pos;
            }
        }
        pos=nexttemp;
    }
    //已经分离完成，但需要判断三个部分是否有空链表
    if(sT!=nullptr){
        sT->next=eH;
        eT=eT==nullptr?sT:eT;
    }
    if(eT!=nullptr)
        eT->next=lH;
    Node* headNode=list_init();
    headNode->next=sH!=nullptr?sH:(eH!=nullptr?eH:lH);
    headNode->data=elements;
    return headNode;
}

int main(){
    // pair<int*,int> result=generator<int,pair<int*,int>>(10,10);
    // int *arr=result.first;
    // int len=result.second;
    // bprint(arr,len);
    // pair<float*,int> resultfloat=generator<float,pair<float*,int>>(20.0,34.25);
    // float *arrfloat=resultfloat.first;
    // int lenfloat=resultfloat.second;
    // bprint(arrfloat,lenfloat);
    // Node* head1=generator<int,Node*>(30,15);
    // printList(head1);
    // head1=partition(head1,8);
    // printList(head1);
    Node* head2=list_init();
    head2=insert(head2,0,3);
    head2=insert(head2,1,-5);
    head2=insert(head2,2,-7);
    head2=insert(head2,3,12);
    head2=insert(head2,4,8);
    head2=insert(head2,5,-1);
    head2=insert(head2,6,8);
    head2=insert(head2,7,10);
    head2=insert(head2,8,-8);
    head2=insert(head2,9,12);
    printListpointer(head2);
    head2=partition(head2,8);
    printListpointer(head2);
    return 0;
}