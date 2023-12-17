//
//  main.cpp
//  Single Linked List
//
//  Created by Amanda Prawita Ningrum on 11/10/22.
//

//system("read -n1 -p''key");

#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

struct TNode{
    int nilaiX;
    int nilaiY;
    string target;
    TNode *next;
};

TNode *head, *tail;

void init(){
    head = NULL;
    tail = NULL;
}

int isEmpty(){
    if(tail==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void insertDepan(int databaru, int databaru1, string databaru2){
    TNode *baru;
    baru = new TNode;
    baru->nilaiX = databaru;
    baru->nilaiY = databaru1;
    baru->target = databaru2;
    baru->next = NULL;

    if(isEmpty()==1){
        head=tail=baru;
        tail->next=NULL;
    }
    else{
        baru->next = head;
        head=baru;
    }
    cout << "Data masuk" << endl;
}

void insertBelakang(int databaru, int databaru1, string databaru2){
    TNode *baru;
    baru = new TNode;
    baru->nilaiX = databaru;
    baru->nilaiY = databaru1;
    baru->target = databaru2;
    baru->next = NULL;

    if(head==NULL){
        head=baru;
        tail=baru;
    }else{
        tail->next = baru;
        tail=baru;
    }
    cout << "Data masuk" << endl;
}

void tampil(){
    TNode *bantu;
    bantu=head;
    if(isEmpty()==0){
        while(bantu!=NULL){
        cout << bantu->nilaiX << " ";
        cout << bantu->nilaiY << " ";
        cout << bantu->target << " ";
        cout << endl;
        bantu=bantu->next;
        }
    }
    else{
        cout <<"Data masih kosong" << endl;
    }
}

void hapusDepan(){
    TNode *hapus;
    int d;
    int d1;
    string d2;
    if(head != NULL){
        if(head != tail){
            hapus = head;
            d = hapus->nilaiX;
            d1 = hapus->nilaiY;
            d2 = hapus->target;
            head = head->next;
            delete hapus;
        }else{
            d = tail->nilaiX;
            d1 = tail->nilaiY;
            d2 = tail->target;
            head = tail = NULL;
        }
        cout << d << "terhapus" << endl;
        cout << d1 << "terhapus" << endl;
        cout << d2 << "terhapus" << endl;
    }
    else{
        cout << "Masih kosong" << endl;
    }
}

void hapusBelakang(){
    TNode *hapus;
    int d, d1;
    string d2;
    hapus = tail;
    if(head == tail){
        delete hapus;
        head = NULL;
        tail = NULL;
    }
    else{
        TNode *bantu;
        bantu = head;
        do{
            if(bantu->next->nilaiX == tail->nilaiX) {
                d = bantu->next->nilaiX;
                d1 = bantu->next->nilaiY;
                d2 = bantu->next->target;
                tail = bantu;
                tail->next = NULL;
                delete hapus;
            }
            bantu = bantu->next;
        }while(bantu != NULL);
     }
    cout << d << " terhapus" << endl;
    cout << d1 << " terhapus" << endl;
    cout << d2 << " terhapus" << endl;
}

void hapusTengah(){
    TNode *hapus, *bantu;
    int d;
    int d1;
    string d2;
    int cari;
    cout << "masukan data yang anda cari : ";
    cin >> cari;
    bantu = head;

    if (isEmpty() == 0){
        if (head != tail){
            do{
                if (bantu->next->nilaiX == cari){
                    hapus = bantu->next;

                    d = bantu->next->nilaiX;
                    d1 = bantu->next->nilaiY;
                    d2 = bantu->next->target;
                    bantu->next = bantu->next->next;

                    delete hapus;
                    break;
                }
                bantu = bantu->next;
            }while (bantu != NULL);
        }
        else{
            d = tail->nilaiX;
            d1 = tail->nilaiY;
            d2 = tail->target;
            head = tail = NULL;
        }
        cout << d << " terhapus " << endl;
        cout << d1 << " terhapus " << endl;
        cout << d2 << " terhapus " << endl;
    }
    else{
        cout << "Data masih kosong" << endl;
    }
}

void clear(){
    TNode *bantu, *hapus;
    bantu = head;
    while(bantu != NULL){
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = NULL;
    printf("clear");
}

void caridata(){
    TNode *bantu;
    int cari;
    string cari1;
    if(head == NULL){
        cout << "Data Masih Kosong" << endl;
    }
    else{
        cout << "Masukan data yang dicari (integer) : "; cin>>cari;
        cout << "Masukan data yang dicari (string) : "; cin>>cari1;

        int ketemu = 0;
        bantu = head;

        do{
            if(cari == bantu->next->nilaiX || cari1 == bantu->next->target){
                ketemu = 1;
                cout << "Data ketemu" << endl;
                break;
            }
            bantu = bantu->next;
        } while (tail != NULL);

        if(ketemu == 0){
            cout << "Data tidak ketemu" << endl;
        }
    }
}

void insertafter(int databaru, int databaru1, string databaru2){
    TNode *bantu;
    TNode *baru;
    baru = new TNode;
    baru->nilaiX = databaru;
    baru->nilaiY = databaru1;
    baru->target = databaru2;
    int setelahapa1, setelahapa2;
    //baru->next = NULL;

    if (head == NULL){
        head = baru;
        tail = baru;
    }
    else{
        cout << "masukan data setelah data apa : "; cin>>setelahapa1;

        int ketemu = 0;
        bantu = head;

        do{
            if (setelahapa1 == bantu->nilaiX){
                baru->next = bantu->next;
                bantu->next = baru;

                ketemu = 1;
                break;
            }

            bantu = bantu->next;
        } while (tail != NULL);

        if (ketemu == 0){
            tail->next = baru;
            tail = baru;
        }
    }
}

void insertbefore(int databaru, int databaru1, string databaru2){
    TNode *bantu;
    TNode *baru;
    baru = new TNode;
    baru->nilaiX = databaru;
    baru->nilaiY = databaru1;
    baru->target = databaru2;
    int sebelumapa1, setelahapa2;
    //baru->next = NULL;

    if (head == NULL){
        head = baru;
        tail = baru;
    }
    else{
        cout << "masukan data sebelum data apa : "; cin>>sebelumapa1;

        int ketemu = 0;
        bantu = head;

        do{
            if (sebelumapa1 == bantu->next->nilaiX){
                baru->next = bantu->next;
                bantu->next = baru;

                ketemu = 1;
                break;
            }

            bantu = bantu->next;
        } while (tail != NULL);

        if (ketemu == 0){
            tail->next = baru;
            tail = baru;
        }
    }

}

int main()
{
    int pil, databaru1, databaru2;
    string databaru3;
    do
    {
        system("cls");
        tampil();
        cout<<endl;
        cout<<" ========================================="<<endl;
        cout<<" =======   PROGRAM LINKED LIST    ========"<<endl;
        cout<<" ========================================="<<endl;
        cout<<" = 1. Tambah Data di Depan               ="<<endl;
        cout<<" = 2. Tambah Data di Belakang            ="<<endl;
        cout<<" = 3. Tambah Data Setelah Data Tertentu  ="<<endl;
        cout<<" = 4. Tambah Data Sebelum Data Tertentu  ="<<endl;
        cout<<" = 5. Hapus Data di Depan                ="<<endl;
        cout<<" = 6. Hapus Data di Belakang             ="<<endl;
        cout<<" = 7. Hapus Data di Tengah               ="<<endl;
        cout<<" = 8. Mencari Data                       ="<<endl;
        cout<<" = 9. Menampilkan Data                   ="<<endl;
        cout<<" = 10. Keluar                            ="<<endl;
        cout<<" ========================================="<<endl;
        cout<<" Masukan Pilihan : ";cin>>pil;
        switch(pil){
            case 1: system("cls");{
                cout<<"Masukan Data = ";cin>>databaru1;
                cout<<"Masukan Data = ";cin>>databaru2;
                cout<<"Masukan Data = ";cin>>databaru3;
                insertDepan(databaru1, databaru2, databaru3);
                break;
            }
            case 2: system("cls");{
                cout<<"Masukan Data = ";cin>>databaru1;
                cout<<"Masukan Data = ";cin>>databaru2;
                cout<<"Masukan Data = ";cin>>databaru3;
                insertBelakang(databaru1, databaru2, databaru3);
                break;
            }
            case 3: system("cls");{
                cout<<"Masukan Data = ";cin>>databaru1;
                cout<<"Masukan Data = ";cin>>databaru2;
                cout<<"Masukan Data = ";cin>>databaru3;
                insertafter(databaru1, databaru2, databaru3);
                break;
            }
            case 4: system("cls");{
                cout<<"Masukan Data = ";cin>>databaru1;
                cout<<"Masukan Data = ";cin>>databaru2;
                cout<<"Masukan Data = ";cin>>databaru3;
                insertbefore(databaru1, databaru2, databaru3);
                break;
            }
            case 5: system("cls");{
                hapusDepan();
                break;
            }
            case 6: system("cls");{
                hapusBelakang();
                break;
            }
            case 7: system("cls");{
                hapusTengah();
                break;
            }
            case 8: system("cls");{
                caridata();
                break;
            }
            case 9: system("cls");{
                tampil();
                break;
            }
            case 10: system("cls");{
                return 0;
                break;
            }
        }
        system("read -n1 -p''key");
    }while(pil!=10);
}
