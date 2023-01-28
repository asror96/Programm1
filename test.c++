#include <iostream>
#include <string>  
#include<array>
#include <algorithm>
using namespace std;
class Sort_1{
    public:
    bool steam1(string numbers){
        int buf;
        const int size=end(numbers)-begin(numbers);
        int num[size];
        if(size==64){
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
                cout<<num[i]-48 <<"\n";
            }
            
            return true;
        }
        else{
            cout << " More or less than 64 symbols!." << endl;
            return false;
        }
    }


    int partition(int a[], int start, int end)
    {
        // Выбираем крайний правый элемент в качестве опорного элемента массива
        int pivot = a[end];
    
        // элементы, меньшие точки поворота, будут перемещены влево от `pIndex`
        // элементы больше, чем точка поворота, будут сдвинуты вправо от `pIndex`
        // равные элементы могут идти в любом направлении
        int pIndex = start;
    
        // каждый раз, когда мы находим элемент, меньший или равный опорному, `pIndex`
        // увеличивается, и этот элемент будет помещен перед опорной точкой.
        for (int i = start; i < end; i++)
        {
            if (a[i] >= pivot)
            {
                swap(a[i], a[pIndex]);
                pIndex++;
            }
        }
    
        // поменять местами `pIndex` с пивотом
        swap (a[pIndex], a[end]);
    
        // вернуть `pIndex` (индекс опорного элемента)
        return pIndex;
    }
    
    // Процедура быстрой сортировки
    void quicksort(int a[], int start, int end)
    {
        // базовое условие
        if (start >= end) {
            return;
        }
    
        // переставить элементы по оси
        int pivot = partition(a, start, end);
    
        // повторяем подмассив, содержащий элементы, меньшие опорной точки
        quicksort(a, start, pivot - 1);
    
        // повторяем подмассив, содержащий элементы, превышающие точку опоры
        quicksort(a, pivot + 1, end);
    }
    
};
int main() {
    Sort_1 sort;
    cout << "insert the number";	
    string numbers;
    cin >> numbers;
    
    bool flag=sort.steam1(numbers);
   
   
    
    return 0;
}