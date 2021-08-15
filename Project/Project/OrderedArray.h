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

    // Destructor 
    ~OrderedArray()
    {
        this->growSize = 0;
        this->capacity = 0;
        this->size = 0;
        if (this->array)
            delete array;
    }
   // putting an element into the array in order
void push(const T& newElement)
{
    if (size >= (capacity - 1))
        {
            T* newArrayData = new T[this->capacity + this->growSize];
            for (int i = 0; i < size; i++)
            {
                newArrayData[i] = this->array[i];
            }
            delete this->array;
            this->array = newArrayData;
            this->capacity += this->growSize;
        }
       
int i = 0;
        for (i = 0; i < this->size; i++)
        {
       
            if (this->array[i] > newElement)
            {
                break;
            }
        }
    
        for (int j = this->size; j > i; j--)
        {
            this->array[j] = this->array[j - 1];
        }
        this->array[i] = newElement;

        this->size += 1;
    }
//returning array elements
int length()
{
   return this->size;
}
//returning a copy of the element corresponding to the given index

 T getElement(int index)
        {
            if (index < 0 || index > this->size)
            {
                return T();
            }
            return this->array[index];
        }

 void clear()
 {
     if (this->array)
         delete this->array;
     this->array = NULL;
     this->size = 0;
 }
};
