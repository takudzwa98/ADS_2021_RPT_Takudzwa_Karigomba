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

    void push(const T& newElement) {
        if (!array)
        {
            this->array = new T[this->growSize];
        }
        if (size >= (capacity - 1))
        {

            T* newArray = new T[this->capacity + this->growSize];

            for (int i = 0; i < size; i++)
            {
                newArray[i] = this->array[i];
            }

            delete this->array;

            this->array = newArray;

            this->capacity += this->growSize;


        }
        int i = 0;
        for (i = 0; i < this->size; i++)
        {

            if (this->arrayData[i] > newElement)
            {
                break;
            }
        }

        for (int j = this->size; j > i; j--)
        {
            this->arrayData[j] = this->arrayData[j - 1];

            this->arrayData[i] = newElement;

            this->size += 1;
        }
    }

int length()
{
   return this->size;
}

 T getElement(int index)
        {
            if (index < 0 || index > this->size)
            {
                return T();
            }
            return this->array[index];
        }
};
