#include "Collection.h"

/**
 * @brief - this is the default constructor for Collection class that initializes the arr_ to a new
 *          size of 8, sets the size_of_array_ to 0, and the capacity_ to 8.
 */

Collection::Collection(){
    arr_ = new double[8];
    size_of_array_ = 0;
    capacity_ = 8;
    // for loop that initializes the array values to 0.0
    for(int i = 0; i < capacity_; ++i) {
        arr_[i] = 0.0;
    }
}

/**
 * @brief - this constructor creates an object of class Collection with dynamically sized capacity.
 * @param size - size of array to be created
 */

Collection::Collection(int size){
    size > 0 ? arr_ = new double[size] : arr_ = new double[1];
    size > 0 ? capacity_ = size : capacity_ = 1;
}

/**
 * @brief - this is the copy constructor that creates a new object and copies the content from the referenced object
 * @param other - referenced object of Collection
 */

Collection::Collection(const Collection &other) {
    this->arr_ = new double[other.capacity_];
    // initialize entire array to 0.0 or NULL
    for(int i = 0; i < capacity_; ++i) {
        arr_[i] = 0.0;
    }
    this->capacity_ = other.capacity_;
    for(int i = 0; i < other.capacity_; ++i) {
        this->arr_[i] = other.arr_[i];
    }
    this->size_of_array_ = other.size_of_array_;
}

/**
 * @brief - getter method to get the size of the array / the amount of actual items in the array
 * @return - the size of the array
 */

int Collection::getSize() const{
   return size_of_array_;
}

/**
 * @brief - getter method to get the maximum capacity of the array
 * @return - capacity of the array
 */

int Collection::getCapacity() const{
   return capacity_;
}

/**
 * @brief - getter method used to return an item at a specified index of the array
 * @param ndx - integer value representing index to get from array
 * @return - item at index of array
 */

double Collection::get(int ndx) const{
    if(ndx > size_of_array_ - 1) {
        throw std::out_of_range("out of range");
    }
    return arr_[ndx];
}

/**
 * @brief - getter method to return the item at the front of the array
 * @return - the item at the front of the array
 */

double Collection::getFront() const{
   if(size_of_array_ == 0) {
       throw std::out_of_range("out of range in getFront()");
   }
   else {
       return arr_[0];
   }
}

/**
 * @brief - getter method to return the item at the end of the array
 * @return - item at the end of the array
 */

double Collection::getEnd() const{
    if(size_of_array_ == 0) {
        throw std::out_of_range("out of range in getEnd()");
    }
    else {
        return arr_[size_of_array_-1];
    }
}

/**
 * @brief - method to find index of specified item in the array
 * @param needle - specified item to find
 * @return - index of specified item (if found)
 */

int Collection::find(double needle) const{
   for(int i = 0; i < size_of_array_; ++i) {
       if(arr_[i] == needle) {
           return i;
       }
   }
   return -1;
}

/**
 * @brief - method to add an item to array. If the array is full, the array is doubled in size and the item is added
 * @param item - item to add into the array
 */

void Collection::add(double item) {
    if(size_of_array_ >= capacity_) {
        delete[] temp_arr_;
        temp_arr_ = nullptr;
        temp_arr_ = new double[capacity_];
        // for loop that initializes array values to 0.0 or NULL
        for(int i = 0; i < capacity_; ++i) {
            temp_arr_[i] = 0.0;
        }
        for(int i = 0; i < size_of_array_; ++i) {
            temp_arr_[i] = arr_[i];
        }
        delete[] arr_;
        arr_ = nullptr;
        arr_ = new double[capacity_*2];
        size_of_array_ = 0;
        for(int i = 0; i < capacity_; ++i) {
            arr_[i] = temp_arr_[i];
            ++size_of_array_;
        }
        capacity_ *= 2;
        delete[] temp_arr_;
        temp_arr_ = nullptr;
    }
    arr_[size_of_array_] = item;
    ++size_of_array_;
}

/**
 * @brief - method to remove the item at the front of the array, then shifts the rest of the array down accordingly
 */

void Collection::removeFront() {
    if(size_of_array_ != 0) {
        temp_arr_ = new double [size_of_array_ - 1];
        for(int i = 1; i < size_of_array_; ++i) {
            temp_arr_[i-1] = arr_[i];
        }
        --size_of_array_;
        delete[] arr_;
        arr_ = nullptr;
        arr_ = new double[capacity_];
        for(int i = 0; i < capacity_; ++i) {
            arr_[i] = 0.0;
        }
        for(int i = 0; i < size_of_array_; ++i) {
            arr_[i] = temp_arr_[i];
        }
        delete[] temp_arr_;
        temp_arr_ = nullptr;
    }
}

/**
 * @brief - simply sets the last item in the array to 0.0 and decreases the size, effectively deleting the item from
 * access
 */

void Collection::removeEnd() {
    if(size_of_array_ != 0) {
        arr_[size_of_array_] = 0.0;
        --size_of_array_;
    }
}

/**
 * @brief - removes an item from the array and shifts each item in the array down accordingly
 * @param item
 */

void Collection::remove(double item) {
    int item_index = find(item);
    if(item_index != -1) {
        temp_arr_ = new double[capacity_];
        for(int i = 0; i < capacity_; ++i) {
            temp_arr_[i] = 0.0;
        }
        int count = 0;
        for(int i = 0; i < size_of_array_; ++i) {
            if(i == item_index && i + 1 != size_of_array_) {
                ++count;
            }
            if(i == item_index && i + 1 == size_of_array_) {
                arr_[count] = 0.0;
            }
            temp_arr_[i] = arr_[count];
            ++count;
        }
        delete[] arr_;
        arr_ = nullptr;
        arr_ = new double[capacity_];
        for(int i = 0; i < capacity_; ++i) {
            arr_[i] = 0.0;
        }
        --size_of_array_;
        for (int i = 0; i < size_of_array_; ++i) {
            arr_[i] = temp_arr_[i];
        }
        delete [] temp_arr_;
        temp_arr_ = nullptr;
    }
}

/**
 * @brief - assignment operator I added in to copy an object of Collection to another object of Collection
 * @param other - referenced object of Collection
 * @return - de-referenced Collection object copied to
 */

Collection &Collection::operator=(const Collection &other) {
    if(this == &other) {
        return *this;
    }
    delete[] this->arr_;
    this->arr_ = new double[other.capacity_];
    this->capacity_ = other.capacity_;
    this->size_of_array_ = other.size_of_array_;
    for(int i = 0; i < size_of_array_; ++i) {
        arr_[i] = other.arr_[i];
    }
    return *this;
}

/**
 * @brief - overloaded [] operator that allows access to the pointer array indexes
 * @param ndx - index of the array to return
 * @return - item at the index in the array
 */

double& Collection::operator[](int ndx){
    if(ndx > size_of_array_ - 1) {
        throw std::out_of_range("out of range");
    }
    return *(&arr_[ndx]);
}

/**
 * @brief - overloaded - operator to remove a specified amount if items from the end of the array, up to the entire
 *          array
 * @param count - amount of items to remove from the end of the array
 * @return - de-referenced Collection object that was altered
 */

Collection& Collection::operator-(int count){
    if(count >= size_of_array_) {
        for(int i = 0; i <= size_of_array_; ++i) {
            arr_[i] = 0.0;
        }
        size_of_array_ = 0;
        return *this;
    }
    for(int i = 0; i < count; ++i) {
        removeEnd();
    }
    return *this;
}

/**
 * @brief - overloaded + operator that adds items to the array by calling the add method
 * @param item - item to be added into the end of the array
 * @return - de-referenced Collection object
 */

Collection& Collection::operator+(double item){
    add(item);
    return *this;
}

/**
 * @brief - overloaded + operator that appends another array into the end of the current array
 * @param other - referenced Collection object
 * @return - de-referenced Collection object that had the other Collection appended to it
 */

Collection& Collection::operator+(const Collection& other){
    for(int i = 0; i < other.size_of_array_; ++i) {
        add(other.arr_[i]);
    }
    return *this;
}

/**
 * @brief - overloaded << operator that adds items into this Collection object's array
 * @param item - item to be added into this Collection object's array
 * @return - de-referenced Collection object
 */

Collection& Collection::operator<<(double item){
    add(item);
    return *this;
}

/**
 * @brief - overloaded << operator that allows for output of Collection Object
 * @param out - referenced output location
 * @param other - referenced Collection object
 * @return - the output to be outputted
 */

std::ostream& operator<<(std::ostream& out, const Collection& other){

    return out;
}

