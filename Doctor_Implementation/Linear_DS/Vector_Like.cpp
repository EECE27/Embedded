#include <iostream>
#include <stdexcept>

template <typename T>
class Vector
{
private:
    T* arr;       // Pointer to the dynamic array
    size_t size;  // Current number of elements
    size_t capacity; // Total allocated space

    // Function to resize when full
    void resize(size_t newCapacity)
    {
        T* newArr = new T[newCapacity];
        for (size_t i = 0; i < size; i++)
        {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
        capacity = newCapacity;
    }

public:
    // Constructor
    Vector() : size(0), capacity(2)
    {
        arr = new T[capacity];
    }

    // Destructor
    ~Vector()
    {
        delete[] arr;
    }

    // Returns current size
    size_t getSize() const
    {
        return size;
    }

    // Returns current capacity
    size_t getCapacity() const
    {
        return capacity;
    }

    // Access elements with bounds checking
    T& operator[](size_t index)
    {
        if (index >= size) throw std::out_of_range("Index out of range");
        return arr[index];
    }

    // Add element at the end
    void push_back(const T& value)
    {
        if (size == capacity) {
            resize(capacity * 2); // Double the capacity
        }
        arr[size++] = value;
    }

    // Remove last element
    void pop_back()
    {
        if (size > 0) size--;
    }

    // Insert at a specific position
    void insert(size_t index, const T& value)
    {
        if (index > size) throw std::out_of_range("Index out of range");
        if (size == capacity) resize(capacity * 2);

        for (size_t i = size; i > index; i--) {
            arr[i] = arr[i - 1];
        }
        arr[index] = value;
        size++;
    }

    // Remove an element at a specific index
    void erase(size_t index)
    {
        if (index >= size) throw std::out_of_range("Index out of range");

        for (size_t i = index; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        size--;
    }

    // Find an element and return its index (-1 if not found)
    int find(const T& value)
    {
        for (size_t i = 0; i < size; i++)
        {
            if (arr[i] == value) return i;
        }
        return -1;
    }

    // Shrink capacity to fit size
    void shrink_to_fit()
    {
        if (size < capacity)
        {
            resize(size);
        }
    }

    // Print all elements
    void print() const {
        std::cout << "[ ";
        for (size_t i = 0; i < size; i++)
        {
            std::cout << arr[i] << " ";
        }
        std::cout << "]\n";
    }
};

// Driver code to test the Vector class
int main()
{
    Vector<int> v;

    std::cout << "Adding elements:\n";
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.print();

    std::cout << "Capacity: " << v.getCapacity() << ", Size: " << v.getSize() << "\n";

    std::cout << "Inserting 99 at index 2:\n";
    v.insert(2, 99);
    v.print();

    std::cout << "Erasing element at index 1:\n";
    v.erase(1);
    v.print();

    std::cout << "Finding index of 99: " << v.find(99) << "\n";

    std::cout << "Popping last element:\n";
    v.pop_back();
    v.print();

    std::cout << "Shrinking to fit:\n";
    v.shrink_to_fit();
    std::cout << "Capacity after shrinking: " << v.getCapacity() << "\n";

    return 0;
}
