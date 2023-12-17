//
//  main.cpp
//  STACK MENGGUNAKAN SLL
//
//  NIM : A11.2021.13646
//  Created by Amanda Prawita Ningrum on 09/11/22.
//

#include <iostream>
#include <string.h>

using namespace std;

struct stack{
    char nama[40];
    int nilai;
    stack * next;
};

stack * head = NULL;
stack * tail = NULL;

int top = 1;
int max1 = 5;

void push(){
    if (top <= max1){
        stack * baru;
        baru = new stack;
        cout << "Masukkan nama  : ";
        cin >> baru -> nama;
        cout << "Masukkan nilai : ";
        cin >> baru -> nilai;
        baru -> next = NULL;
        
        if (head == NULL){
            head = tail = baru;
        }
        else{
            tail -> next = baru;
            tail = baru;
        }
    }
    else{
        cout << "Stack Penuh" << endl;
    }
}

void tampil(){
    stack * bantu;
    if (head == NULL){
        cout << "Stack Masih Kosong" << endl;
    }
    else{
        bantu = head;
        while (bantu != NULL){
            cout << bantu -> nama << " " << bantu -> nilai << endl;
            bantu = bantu -> next;
        }
    }
    cout << endl;
}

void pop(){
    stack * hapus, * bantu;
    bantu = head;
    
    if (head != NULL){
        if (head != tail){
            while (bantu != NULL){
                if (strcmp (bantu -> next -> nama, tail -> nama) == 0){
                    cout << tail -> nama << " " << tail -> nilai << " Terhapus" << endl;
                    bantu -> next = NULL;
                    delete tail;
                    tail = bantu;
                }
                bantu = bantu -> next;
            }
        }
        else{
            head = tail = NULL;
        }
        cout << " Terhapus\n";
    }
    else{
        cout << "Masih Kosong\n";
    }
}

int main()
{
    int pilih;
    do{
        cout << "\nMENU STACK" << endl;
        cout << "1. Push Data" << endl;
        cout << "2. Pop Data" << endl;
        cout << "3. Tampil Data" << endl;
        cout << "4. Keluar" << endl;
        cout << "\nPilihan anda [1-4] : ";
        cin >> pilih;
        if (pilih==1){
            push();
//            insert_belakang();
        }
        if(pilih==2){
            pop();
//            delete_belakang()
        }
        if(pilih==3){
            tampil();
//            tampil_data()
        }
    }while(pilih!=4);
    
    return 0;
}
