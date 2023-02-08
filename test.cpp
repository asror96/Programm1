#include <iostream>
#include<fstream>
#include <string>  
#include<array>
#include <stdio.h>
#include <algorithm>
#include <thread>
#include<cstdio>
#include <mutex>

using namespace std;
mutex mtx;
class Steam{
    public:
    bool steam1(){
        cout << "Steam 1 with id : "<< this_thread::get_id() <<endl;
  
        cout << "Insert the number : ";	
       
        string numbers;
        cin >> numbers;
       
        int c;
        int buf;
        const int size=end(numbers)-begin(numbers);
        string array[size];
    
        int num[size];
        if(size<=64){
            for(int i=0;i<size;i++){
                buf=(int)numbers[i];
                if(buf<48||buf>57){
                    cout<<"Incorrect array!.\n";
                    return false;
                }
            }              
            cout<<"Correct array!.\n";
            for(int i=0;i<size;i++){
                num[i]=(int)numbers[i];
            }
            quicksort(num, 0, size);
            for (size_t i = 0; i < size; i++)
            {
                cout<<num[i]-48 ;
                c=(num[i]-48)%2;
                if(c==0&&(num[i]-48)!=0){
                    array[i]="KB";
                }
                else{
                    array[i]=(char)num[i];
                }

            }
            cout<<endl;
            ofstream fout;
           fout.open("buffer.txt");

            
            if (fout.is_open()){
                for (size_t i = 0; i < size; i++){
                    fout<<array[i];
                }
                fout<<endl;
            }
            else{
                cout<<"Error file open!"<< endl;
                cout<<"Steam end with id : "<< this_thread::get_id() <<endl;
                return false;
            }
            fout.close();
            cout<<"Steam end with id : "<< this_thread::get_id() <<endl;
            return true;
        }
        else{
            cout << " More than 64 symbols!." << endl;
            cout<<"Steam end with id : "<< this_thread::get_id() <<endl;
            return false;
        }
        cout<<"Steam end with id : "<< this_thread::get_id() <<endl;
        return false;
        
    }


    int partition(int a[], int start, int end)
    {
        int pivot = a[end];
        int pIndex = start;
        for (int i = start; i < end; i++)
        {
            if (a[i] >= pivot)
            {
                swap(a[i], a[pIndex]);
                pIndex++;
            }
        }
        swap (a[pIndex], a[end]);
        return pIndex;
    }
    void quicksort(int a[], int start, int end)
    {
        if (start >= end) {
            return;
        }
        int pivot = partition(a, start, end);
        quicksort(a, start, pivot - 1);
        quicksort(a, pivot + 1, end);
    }
    int steam2(){
        cout<<"Steam 2 with id : "<< this_thread::get_id()<< endl;
       
        int result;
        string temp;
        fstream fin;
        fin.open("buffer.txt");
        if(fin.is_open()){
           fin >> temp ;
        }
        else{
            cout<<"Error file open!"<< endl;
        }
        fin.close();
        const int size=end(temp)-begin(temp);
        int proverka;
        for (size_t i = 0; i < size; i++)
        {
           proverka=(int)temp[i];
           if(proverka >= 48 && proverka <= 57){
                result=result+proverka;
           }
        }
        cout<<endl;
        ofstream ofs ("buffer.txt", ios::out | ios::trunc);
        ofs.close ();
        cout<<"Steam 2 end with id : "<< this_thread::get_id() <<endl;
        return result;
    }
    
};
class Prog2
{
private:
    /* data */
public:
   void print(int result){
    cout<<"Prog2 with id : "<< this_thread::get_id() <<endl;

    cout<<result<<endl;
    int colichestvo=result;
    
    bool flag=true;
    int p=1;
        while (flag)
        {   
            colichestvo=colichestvo/10;
            p++;
            if(colichestvo/10==0){
                flag=false;
            }
        }
    
       int kratnost_32=result%32;
        if(p>2&&kratnost_32==0){
            cout<<result<<endl;
            cout<<"Prog2 end with id : "<<this_thread::get_id()<<endl;
        }
        else{
            cout<<"It is not more than 2 characters and it is not a multiple of 32 !!!."<<endl;
            cout<<"Prog2 end with id : "<<this_thread::get_id()<<endl;
        }
       
        
   }
};



int main() {
    cout<<"Main start with id : "<<this_thread::get_id()<<endl;
    setlocale(LC_ALL,"ru");
    Steam Steam;
    Prog2 Prog;
    bool flag=false;
    int res;
    thread st1([&](){
        flag=Steam.steam1();
    });
    st1.join();
    if(flag==true){
        res=Steam.steam2();
        Prog.print(res);
    }
    
    
    return 0;
}