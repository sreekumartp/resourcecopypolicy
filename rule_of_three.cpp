#include <stdlib.h>
#include <iostream>

class MyMovableClass
{
private:
    int _size;
    int *_data;

public:
    MyMovableClass(size_t size) // constructor
    {
        _size = size;
        _data = new int[_size];
        std::cout << "CREATING instance of MyMovableClass at " << this << " allocated with size = " << _size*sizeof(int)  << " bytes" << std::endl;
    }
    
    MyMovableClass(const MyMovableClass &source)
    {
        _size = source._size;
        
        _data = new int[_size];
        
        *_data =*source._data;
        
        
    }
    
    MyMovableClass &operator = (const MyMovableClass &source)
    {
        
        std::cout << "Assigning content of instance" << &source << "to" << this << std::endl;
        
        if(this == &source) return *this;
        
        delete[] _data;
        
        _data = new int[source._size];
        *_data = *source._data;
        _size = source._size;
        
        return *this;
                
    }

    ~MyMovableClass() // 1 : destructor
    {
        std::cout << "DELETING instance of MyMovableClass at " << this << std::endl;
        delete[] _data;
    }
};