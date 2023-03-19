//
// Created by 홍준근 on 2023/03/18.
//
#include <iostream>

typedef struct _node{
    int data;
    struct _node* next;
} Node;

int main(){
    Node *head = nullptr;
    Node *tail = nullptr;
    Node *currentPosition = nullptr;
    Node *newNode = nullptr;

    int readData;

    while(true){
        std::cout<<"자연수 입력: ";
        std::cin>>readData;
        if(readData < 1){
            break;
        }

        newNode = (Node *) malloc(sizeof(Node));
        newNode->data = readData;
        newNode->next = nullptr;

        if(head == nullptr){
            head = newNode;
        }else{
            tail -> next = newNode;
        }

        tail = newNode;
    }
    std::cout<<std::endl;

    std::cout<<"입력받은 전체 데이터 출력!"<<std::endl;
    if(head == nullptr){
        std::cout<<"지정된 자연수가 존재하지 않습니다."<<std::endl;
    }else{
        currentPosition = head;
        std::cout<<currentPosition->data<<" ";

        while(currentPosition->next != nullptr){
            currentPosition = currentPosition->next;
            std::cout<<currentPosition->data<<" ";
        }
    }

    std::cout<<std::endl<<std::endl;
    if(head == nullptr){
        return 0;
    }else{
        Node* delNode = head;
        Node* delNextNode = head->next;

        std::cout<<delNode->data<<"을(를) 삭제합니다."<<std::endl;
        free(delNode);
        while(delNextNode != nullptr){
            delNode = delNextNode;
            delNextNode = delNode->next;
            std::cout<<delNode->data<<"을(를) 삭제합니다."<<std::endl;
            free(delNode);
        }
    }

    return 0;
}