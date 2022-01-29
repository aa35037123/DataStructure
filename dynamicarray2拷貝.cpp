#include <iostream>

//在c++最好用const，而非#define
//最好不要用using namespace std，不然在用其他using namespace時很容易出錯
const int INITIAL_CAPACITY = 5;

//建立通用class模板
template <class T>
class dynamic_array {
    T *array;
    int capacity = INITIAL_CAPACITY;
    int GROWTH_FACTOR = 2;
    int size;

public:
    // constructor init
    dynamic_array() {
        array = new T[capacity];
        size = 0;
    }
    
    // append @ the end
    void append(T element) {
        if(size == capacity) {
            resize();
        }
        array[size] = element;
        size++;

    }
    //可以直接再創一個array，用跟resize一樣的方法，創新array後，把舊的丟掉
    /*
    void erase(int pos) {
        if((pos >= size) || (pos < 0)) {
            std::cout << "Invalid index"<<std::endl;
            return;
        }
        size--;
        for(int i = pos; i < size; i++) {
            
            array[i] = array[i+1];
        }
       
    }
    */
    void erase(int pos){
        if((pos >= size) || (pos < 0)) {
            std::cout << "Invalid index"<<std::endl;
            return;
        }
        
        T *temp = new T [capacity];
        for(int i = 0,j = 0; i < size ; i++,j++){
            if(i ==  pos)
                j--;
            else
                temp[j] = array[i];
        }
        delete [] array;
        array = temp;
        --size;
    }

    void insert(int element, int pos) {
        if((pos > size) || (pos < 0)) {
            std::cout << "Invalid index"<<std::endl;
            return;
        }

        if(size == capacity) {
            resize();
        }

        size++;

        for(int i = size - 1; i >= pos; i--) {
            if(i == pos) {
                array[i] = element;
            } else {
                array[i] = array[i-1];
            }
        }
    }

    // returns size of array
    int length() const{
        return size;
    }

    // doubles capacity if it has to and deletes reference to current array.
    void resize() {
        capacity *= GROWTH_FACTOR;
        //要求記憶體
        T *temp = new T[capacity];
        std::copy(array, array+size,temp);
        delete [] array;
        array = temp;

    }

    

    // returns element in x position.
    //要用&，才會取得array內的實際值
    const T& get(const int pos) const {
        return array[pos];
    }
    //解構函數，放在class內，等程式全部跑完後會自動解構
    ~dynamic_array() {std::cout<<"成功解構";}
    
};



int main() {
    dynamic_array<int> dynArr;
    dynArr.append(3);
    dynArr.append(4);
    dynArr.append(5);
    dynArr.append(4);
    dynArr.append(11);
    dynArr.append(8);

    dynArr.erase(2);
    for (int i=0;i<dynArr.length();i++){
        std::cout<<dynArr.get(i)<<std::endl;
    }
    std::cout << dynArr.get(5);

    return 0;
}
