#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

struct kumpulan{

    int nilaiX;
    int nilaiY;
    kumpulan *lanjut;
    
};

kumpulan *kepala, *ekor;

int jika_kosong(){
    if(kepala==NULL){
        return 1;
    }else{
        return 0;
    }
}

void masuk_depan(int baru1, int baru2){
    kumpulan *baru;
    baru = new kumpulan;
    baru->nilaiX = baru1;
    baru->nilaiY = baru2;
    baru->lanjut = NULL;
    cout << "Masukkan nilai X : ";
    cin >> baru->nilaiX;
    cout << "Masukkan nilai Y : ";
    cin >> baru->nilaiY;
    if(jika_kosong()==1){
        kepala = baru;
        ekor = baru;
        ekor->lanjut = NULL;
    }else{
        baru->lanjut = kepala;
        kepala = baru;
    }
    cout<<"Data masuk depan"<<endl;
}
void masuk_belakang(int baru1, int baru2){
    kumpulan *baru;
    baru = new kumpulan;
    baru->nilaiX = baru1;
    baru->nilaiY = baru2;
    baru->lanjut = NULL;
    cout << "Masukkan nilai X : ";
    cin >> baru->nilaiX;
    cout << "Masukkan nilai Y : ";
    cin >> baru->nilaiY;
    if(jika_kosong()==1){
        kepala = baru;
        ekor = baru;
        ekor->lanjut = NULL;
    }else{
        ekor->lanjut = baru;
        ekor = baru;
    }
}
void masuk_tengah(int baru1, int baru2){
    kumpulan *baru, *bantu;
    int cari1, cari2, pilihan;
    cout << "Masukkan posisi data sebelum data yang akan dimasukkan : " << endl;
    cout << "1. Sebelum data yang akan dicari" << endl;
    cout << "2. Sesudah data yang akan dicari" << endl;
    cout << "Pilihan : ";
    cin >> pilihan;
    if(pilihan==1){{
        cout << "Masukkan data yang akan dicari : " << endl;
        cout << "Masukkan nilai X : ";
        cin >> cari1;
        cout << "Masukkan nilai Y : ";
        cin >> cari2;
        if(jika_kosong()==0){
            bantu = kepala;
            while(bantu->lanjut != NULL){
                if(bantu->lanjut->nilaiX == cari1 && bantu->lanjut->nilaiY == cari2){
                    baru = new kumpulan;
                    baru->nilaiX = baru1;
                    baru->nilaiY = baru2;
                    cout << "Masukkan nilai X yang baru : ";
                    cin >> baru->nilaiX;
                    cout << "Masukkan nilai Y yang baru : ";
                    cin >> baru->nilaiY;
                    baru->lanjut = bantu->lanjut;
                    bantu->lanjut = baru;
                    cout << "Data berhasil dimasukkan" << endl;
                    break;
                }
                else{
                    bantu = bantu->lanjut;
                }
            }
            if(bantu->lanjut == NULL){
                cout << "Data tidak ditemukan" << endl;
            }
        }
    }
}
    else{
        cout << "Masukkan data yang akan dicari : " << endl;
        cout << "Nilai X : ";
        cin >> cari1;
        cout << "Nilai Y : ";
        cin >> cari2;
        if(jika_kosong()==0){
            bantu = kepala;
            while(bantu->lanjut != NULL){
                if(bantu->nilaiX == cari1 && bantu->nilaiY == cari2){
                    cout << "Masukkan nilai X yang baru : ";
                    cin >> baru1;
                    cout << "Masukkan nilai Y yang baru : ";
                    cin >> baru2;
                    baru = new kumpulan;
                    baru->nilaiX = baru1;
                    baru->nilaiY = baru2;
                    baru->lanjut = bantu->lanjut;
                    bantu->lanjut = baru;
                    cout << "Data berhasil dimasukkan" << endl;
                    break;
                }
                else{
                    bantu = bantu->lanjut;
                }
                   
            }
            if(bantu->lanjut == NULL){
                cout << "Data tidak ditemukan" << endl;
            }
        }
        else{
            cout << "Data kosong" << endl;
        }
    }

}
void hapus(){
    cout << "Masukkan posisi data yang akan dihapus" << endl;
    cout << "1. Depan" << endl;
    cout << "2. Tengah" << endl;
    cout << "3. Belakang" << endl;
    cout << "Pilihan : ";
    int pilihan;
    cin >> pilihan;
    if(pilihan == 1){
        if(jika_kosong()==0){
            if(kepala != ekor){
                kepala = kepala->lanjut;
            }
            else{
                kepala = NULL;
                ekor = NULL;
            }
            cout << "Data berhasil dihapus" << endl;
        }
        else{
            cout << "Data kosong" << endl;
        }
    }
    else if(pilihan == 2){
        int cari1, cari2;
        kumpulan *bantu, *hapus;
        cout << "Masukkan data yang akan dicari : " << endl;
        cout << "Nilai X : ";
        cin >> cari1;
        cout << "Nilai Y : ";
        cin >> cari2;
        if(jika_kosong()==0){
            bantu = kepala;
            while(bantu->lanjut != NULL){
                if(bantu->nilaiX == cari1 && bantu->nilaiY == cari2){
                    hapus = bantu->lanjut;
                    bantu->lanjut = hapus->lanjut;
                    delete hapus;
                    cout << "Data berhasil dihapus" << endl;
                    break;
                }
                else{
                    bantu = bantu->lanjut;
                }
                   
            }
            if(bantu->lanjut == NULL){
                cout << "Data tidak ditemukan" << endl;
            }
        }
        else{
            cout << "Data kosong" << endl;
        }
    }
    else{
        if(jika_kosong()==0){
            if(kepala != ekor){
                kumpulan *bantu;
                bantu = kepala;
                while(bantu->lanjut != ekor){
                    bantu = bantu->lanjut;
                }
                ekor = bantu;
                ekor->lanjut = NULL;
            }
            else{
                kepala = NULL;
                ekor = NULL;
            }
            cout << "Data berhasil dihapus" << endl;
        }
        else{
            cout << "Data kosong" << endl;
        }
    }
}
void cari_data(){
    int cari1, cari2;
    kumpulan *bantu;
    cout << "Masukkan data yang akan dicari : " << endl;
    cout << "Nilai X : ";
    cin >> cari1;
    cout << "Nilai Y : ";
    cin >> cari2;
    if(jika_kosong()==0){
        bantu = kepala;
        while(bantu->lanjut != NULL){
            if(bantu->nilaiX == cari1 && bantu->nilaiY == cari2){
                cout << "Data ditemukan" << endl;
                break;
            }
            else{
                bantu = bantu->lanjut;
            }
               
        }
        if(bantu->lanjut == NULL){
            cout << "Data tidak ditemukan" << endl;
        }
    }
    else{
        cout << "Data kosong" << endl;
    }
}
void tampil_data(){
    kumpulan *bantu;
    int angka=1;
    if(jika_kosong()==0){
        bantu = kepala;
        while(bantu != NULL){
            cout << angka << ". " << bantu->nilaiX << " " << bantu->nilaiY << endl;
            bantu = bantu->lanjut;
            angka++;    
        }
    }
    else{
        cout << "Data kosong" << endl;
    }
}
int main(){
    int pilihan,baru1,baru2;
    do{
        system("cls");
        tampil_data();
        cout << "Menu" << endl;
        cout << "1. Masuk depan" << endl;
        cout << "2. Masuk tengah" << endl;
        cout << "3. Masuk belakang" << endl;
        cout << "4. Hapus data" << endl;
        cout << "5. Cari data" << endl;
        cout << "6. Tampil data" << endl;
        cout << "7. Keluar" << endl;
        cout << "Pilihan : ";
        cin >> pilihan;
        switch(pilihan){
            case 1:
                masuk_depan(baru1,baru2);
                getch();
                break;
            case 2:
                masuk_tengah(baru1,baru2);
                getch();
                break;
            case 3:
                masuk_belakang(baru1,baru2);
                getch();
                break;
            case 4:
                hapus();
                getch();
                break;
            case 5:
                cari_data();
                getch();
                break;
            case 6:
                tampil_data();
                getch();
                break;
            case 7:
                cout << "Terima kasih" << endl;
                break;
            default:
                cout << "Pilihan tidak ada" << endl;
                break;
        }
    }
    while(pilihan != 7);

    return 0;
}