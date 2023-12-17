//
//  main.cpp
//  Player Music
//
//  Created by Amanda Prawita Ningrum on 14/12/22.
//

#include <iostream>

using namespace std;

struct lagu{
    string judul;
    string genre;
    int durasi;
    lagu *next;
    lagu *prev;
};

lagu *head = NULL;
lagu *tail = NULL;

void add_belakang(string judul_lagu, int durasi_lagu, string genre_lagu){
    lagu * baru;
    baru = new lagu;
    baru->judul = judul_lagu;
    baru->durasi = durasi_lagu;
    baru->genre = genre_lagu;

    baru->next = NULL;
    baru->prev = NULL;
    if(head==NULL){
        head = baru;
        tail = baru;

        //circular
        tail->next = head;
        head->prev = tail;
    }
    else{
        tail->next = baru;
        baru->prev = tail;
        tail = baru;
        //circullar
        tail->next = head;
        head->prev = tail;
    }
}

void tampillagu(){
    lagu *bantu;
    bantu = head;
    int x = 1;
    if(head==NULL){
        cout << "List Lagu Masih Kosong" << endl;
    }
    else{
        cout << "List Lagu  : " << endl;
        do{
            cout << x << ". " << bantu->judul << " - " << bantu->durasi << " - " << bantu->genre << endl;
            x++;
            bantu = bantu->next
            ;
        }while(bantu!=head);
    }
    cout << endl << endl;
}

void hapusLagu(){
    lagu *bantu;
    lagu *hapus;
    string cari;

    bantu = head;
    cout << "Masukan Genre yang Ingin Dihapus : ";cin >> cari;
    if(head == NULL){
        cout << "Lagu Kosong" << endl;
    }
    else{
        do{
            if(cari == bantu->genre){
                if(bantu->genre == head->genre){
                    hapus = head;
                    head = head->next;
                    delete hapus;
                    tail->next = head;
                    head->prev = tail;
                    bantu = head;
                }
                else if(bantu->genre == tail->genre){
                    hapus = tail;
                    tail = tail->prev;
                    delete hapus;
                    tail->next = head;
                    head->prev = tail;
                    bantu = head;
                }
                else{
                    hapus = bantu;
                    bantu->prev->next = bantu->next;
                    bantu->next->prev = bantu->prev;
                    delete hapus;
                    tail->next = head;
                    head->prev = tail;
                    bantu = head;
                }
            }
            bantu = bantu->next;
        }while(bantu != head);

        if(head->next == head && cari == head->genre){
            head = NULL;
            tail = NULL;
            return;
        }
        if(cari == head->genre){
            hapus = head;
            head = head->next;
            delete hapus;
            tail->next = head;
            head->prev = tail;
        }
    }
}

void cariLagu1(){
    if(head==NULL){
        cout << "Data kosong" << endl;
    }
    else{
        string genre;
        lagu *bantu=head;
        int Cgenre = 0 ,Celse = 0, x = 1 ;
        int arr[50];
        string else1,else2,else3,else4;
        cout << "Masukkan genre: "; cin>>genre;
        if(genre == "POP")
        {
            else1 = "DANGDUT";
            else2 = "ROCK";
            else3 = "KOPLO";
            else4 = "KERONCONG";
        }else
        if(genre == "ROCK")
        {
            else1 = "DANGDUT";
            else2 = "POP";
            else3 = "KOPLO";
            else4 = "KERONCONG";
        }else
        if(genre == "DANGDUT")
        {
            else1 = "POP";
            else2 = "ROCK";
            else3 = "KOPLO";
            else4 = "KERONCONG";
        }else
        if(genre == "KOPLO")
        {
            else1 = "POP";
            else2 = "ROCK";
            else3 = "DANGDUT";
            else4 = "KERONCONG";
        }else
        if(genre == "KERONCONG")
        {
            else1 = "POP";
            else2 = "ROCK";
            else3 = "DANGDUT";
            else4 = "KOPLO";
        }
        do
        {
            if(bantu->genre == genre)
            {
                Cgenre++;
                arr[x] = 5;
            }
            else
            {
                Celse++;
                arr[x] = 0;
            }
            x++;
            bantu = bantu->next;
        }while(bantu != head);
        cout<<"genre lagu "<<genre<<" ada "<<Cgenre<<" lagu"<<endl;
        cout<<"yaitu urutan ke ";
        for(int i=0;i<x;i++)
        {
            if(arr[i] == 5)
            cout<<i<<" ";
        }
        cout<<endl;
        cout<<"sedangkan genre "<<else1<<", "<<else2<< ", "<<else3<< ", dan " <<else4 << " berjumlah "<<Celse << " lagu "<<endl;
    }
}

int main()
{
    string judul_lagu[10] = {"Hati hati dijalan", "Ambyar", "Sisa rasa", "What have you done", "Going under", "The catalyst", "Menghapus jejakmu", "Milik orang", "CINTAKU", "SERAYU"};
    int durasi_lagu[10] = {4,6,5,6,5,7,6,8,6,5};
    string genre_lagu[10] = {"POP", "DANGDUT", "POP", "ROCK", "ROCK", "ROCK", "POP", "DANGDUT", "KOPLO", "KERONCONG"};
    for(int i=0; i<10; i++){
        //cout << judul_lagu[i] << " " << durasi_lagu[i] << " " << genre_lagu[i] << endl;
        add_belakang(judul_lagu[i], durasi_lagu[i], genre_lagu[i]);
    }

    string jdul;
    int dursi;
    string gnre;
    int pilih;

    do{
        tampillagu();
        cout << "Implementasi DLL: Player Music" << endl;
        cout << "1. Tambah belakang" << endl;
        cout << "2. Tampil data" << endl;
        cout << "3. Hapus data" << endl;
        cout << "4. Cari data" << endl;
        cout << "5. EXIT" << endl;
        cout << "Masukkan pilihan anda: "; cin>>pilih;
        switch(pilih){
        case 1:
                cout << "Masukkan Judul lagu: "; getline(cin>>ws, jdul);
                cout << "Masukkan durasi lagu: "; cin>>dursi;
                cout << "Masukkan genre lagu: "; cin>>gnre;
                add_belakang(jdul, dursi, gnre);
            break;
        case 2:
            tampillagu();
            break;
        case 3:
            hapusLagu();
            break;
        case 4:
            cariLagu1();
            break;
        }

    }while(pilih!=5);
    
    return 0;
}
