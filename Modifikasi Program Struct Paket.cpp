//
//  main.cpp
//  Modifikasi Program Struct Paket
//
//  Created by Amanda Prawita Ningrum on 28/09/22.
//

#include <iostream>
#include <iomanip>

using namespace std;

struct barang{
    int top;
    string user_id = "paket";
    string password = "dompetcantik";
    string nama = "Paket Barang";
};
barang pro;

struct paket{
    int jumlahStock;
    int berat;
    char kota[30];
    string kodePaket;
    string namaPaket;
    string supplier;
};

struct stack{
    int top;
};
typedef struct stack STACK;

int jumlahBarang;

void line(){
    for(int i=0; i<95; i++){
        cout << "=";
    }
    cout << "\n";
}

void menuUtama(){
    cout << "Menu Utama\n\n";
    line();
    cout << "\n[A] Tampil Data Paket\n";
    cout << "[B] Pengembalian Paket Barang\n";
    cout << "[C] Hapus Paket Barang\n";
    cout << "[D] Exit\n";
    cout << "Pilihan [A/B/C/D]? ";
}

int main() {
    // insert code here...
    int jumlahAmbil;
    int j;
    int i;
    int coba = 0;
    char pilih;
    string user_id;
    string password;
    string ambilKode;
    STACK s;
    s.top = -1;
    
    do{
        cout << "Data Paket Barang\n";
        cout << "PT. Mlaku Alon\n\n";
        cout << "Login\n";
        cout << "User Id  : ";
        cin >> user_id;
        cout << "Password : ";
        cin >> password;
        
        if(user_id == pro.user_id && password == pro.password)
            coba = 100;
        else
            coba++;
        if(coba == 3)
            exit(0);
    }while (coba < 3);
    
    cout << "\nInput Berapa Barang : ";
    cin >> jumlahBarang;
    paket barangDagang[jumlahBarang];
    cout << "Input Data\n\n";
    
    for (int i=0; i<jumlahBarang; i++){
        cout << "Barang Ke-" << i+1 << endl;
        cout << "Kode Paket  : ";
        cin >> barangDagang[i] . kodePaket;
        cout << "Nama Paket  : ";
        cin . ignore();
        getline(cin, barangDagang[i] . namaPaket);
        cout << "Stock       : ";
        cin >> barangDagang[i] . jumlahStock;
        cout << "Berat       : ";
        cin >> barangDagang[i] . berat;
        cout << "Supplier    : ";
        cin . ignore();
        getline(cin, barangDagang[i] . supplier);
        cout << "Kota        : ";
        cin >> barangDagang[i] . kota;
        cout << "\n";
    }
    
    do{
        menuUtama();
        cin >> pilih;
        switch (pilih) {
            case 'A':
                cout << setiosflags(ios::left);
                cout << setw(5) << "No" << setw(20) << "Kode Paket" << setw(20) << "Nama Paket" << setw(10) << "Stock" << setw(10) << "Berat" << setw(20) << "Supplier" << setw(20) << "Kota" << endl;
                line();
                
                for (int i=0; i<jumlahBarang; i++){
                    cout << setw(5) << i+1 << setw(20) << barangDagang[i] . kodePaket << setw(20) << barangDagang[i] . namaPaket << setw(10) << barangDagang[i] . jumlahStock << setw(10) << barangDagang[i] . berat << setw(20) << barangDagang[i] . supplier << setw(20) << barangDagang[i] . kota << endl;
                }
                break;
            case 'B':
                line();
                    cout << "Kode Paket     : ";
                    cin >> ambilKode;
                    cout << "Jumlah Diambil : ";
                    cin >> jumlahAmbil;
                j=0;
                
                for ( ; j<jumlahBarang; j++){
                    if(ambilKode == barangDagang[j] . kodePaket){
                        barangDagang[j] . jumlahStock -= jumlahAmbil;
                        break;
                    }
                }
                cout << "Sisa Barang : " << barangDagang[j] . jumlahStock << endl;
                line();
                break;
                
            case 'C':
                if(s.top == -1)
                    cout << "STACK Kosong";
                else
                    cout << "STACK Dihapus\n";
                for (i=s.top; i>=0; --i)
                    cout << "Elemen Yang Dihapus adalah : " << (&s) << endl;
                s.top = -1;
                
            case 'D':
                exit(0);
                break;
                
            default:
                break;
        }
        cout << "Kembali Ke Menu Utama?[Y/T]";
        cin >> pilih;
    }while(pilih == 'Y');
    
    return 0;
}
