
#ifndef ORDEREDARRAY_H_
#define ORDEREDARRAY_H_


template<class T>
class OrderedArray
{
private:
    T* array;
    int growSize;
    int size;
    int capacity;

public:
    // Constructor for an OrderedArray
    OrderedArray(int grow_size)
    {
        this->growSize = grow_size;
        this->array = new T[this->growSize];
        this->size = 0;
        this->capacity = grow_size;
    }

    // Default constructor
    OrderedArray()
    {
        this->growSize = 0;
        this->array = new T[this->growSize];
        this->size = 0;
        this->capacity = 0;
    }

    // Destructor.
    ~OrderedArray()
    {
        this->growSize = 0;
        this->capacity = 0;
        this->size = 0;
        if (this->array)
            delete array;
    }

};
