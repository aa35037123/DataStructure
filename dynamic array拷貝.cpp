#include <iostream>

class Array
{
private:
    int* arr;
    int size = 0;
    int capacity = 1;

public:
    Array() { arr = new int[capacity]; }
    Array(int capacity): capacity(capacity)
    {
        arr = new int[capacity];
    }

    int length() const { return size; }

    bool is_empty() const { return (length() == 0); }

    int get(int index) const { return arr[index]; }

    void set(int index, int value) { arr[index] = value; }

    void resize()
    {
        capacity *= 2;
        int* temp = new int[capacity];
        for (int i = 0; i < size; i++) { temp[i] = arr[i]; }
        arr = temp;
        delete[] temp;
        for (int i = size; i < capacity; i++) { arr[i] = 0; }
    }

    void add(int value)
    {
        if (size == capacity) { resize(); }
        arr[size++] = value;
    }

    void remove(int index)
    {
        for (int i = index; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        size--;
    }

    int& operator[](int index)
    {
        return arr[index];
    }
    void putsize(){
        std::cout<<size<< std::endl;
    }
    
};


int main()
{
    Array array;

    for (int i = 0; i < 5; i++)
    {
        array.add(i + 1);
    }
   
    for (int i = 0; i < array.length(); i++)
    {
        std::cout << array.get(i) << " ";
    }
    std::cout << '\t' << array.length() << '\n';
    std::cout<< array.length();

    return 0;
}
