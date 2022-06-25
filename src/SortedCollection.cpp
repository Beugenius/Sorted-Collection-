#include "SortedCollection.h"
#include <iomanip>
/**TODO: override any methods necessary
 * to keep this collection of doubles in
 * sorted order.  Hint - Whenever you
 * add an item add it in the "correct"
 * spot to maintain sorted order.
 */

/**
 * @brief - this method adds an item into the array as well as sorts the item into the correct location of the array,
 *          where it sorts from smallest to largest value.
 * @param item - double item to be added.
 */

void SortedCollection::add(double item) {
    if(size_of_array_ >= capacity_) {
        delete[] temp_arr_;
        temp_arr_ = nullptr;
        // temporarily increasing capacity size to create a temp_arr_ with one size larger capacity
        // so that it can store the new item
        ++capacity_;
        temp_arr_ = new double [capacity_];
        --capacity_;
        // for loop to initialize the values in the temp array to 0.0 or NULL
        for(int i = 0; i <= capacity_; ++i) {
            temp_arr_[i] = 0.0;
        }
        // for loop that creates a temporary copy of the array into temp array
        for (int i = 0; i < size_of_array_; ++i) {
            temp_arr_[i] = arr_[i];
        }
        // increase size of array because we added one to it
        ++size_of_array_;
        delete[] arr_;
        arr_ = nullptr;
        capacity_ *= 2;
        arr_ = new double[capacity_];
        // for loop to initialize the values in the new array to 0.0 or NULL
        for (int i = 0; i < capacity_; ++i) {
            arr_[i] = 0.0;
        }
        // two temporary items for storing array values to be compared and placed within the array
        double temp_item = item;
        double temp = 0.0;
        for (int i = 0; i < size_of_array_; ++i) {
            if (temp_item < temp_arr_[i]) {
                temp = temp_arr_[i];
                arr_[i] = temp_item;
                temp_item = temp;
            }
            // essentially asking if this spot in the array is null
            else if(temp_arr_[i] == 0.0) {
                arr_[i] = temp_item;
            }
            else {
                arr_[i] = temp_arr_[i];
            }
        }
    }
    else if(size_of_array_ == 0) {
        Collection::add(item);
    }
    else {
        double temp_item = 0.0;
        temp_item = item;
        double temp = 0.0;
        for (int i = 0; i <= size_of_array_; ++i) {
            if (temp_item < arr_[i]) {
                temp = arr_[i];
                arr_[i] = temp_item;
                temp_item = temp;
            }
            if(arr_[i] == 0.0) {
                arr_[i] = temp_item;
            }
        }
        ++size_of_array_;
    }
}