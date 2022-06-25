#ifndef COLLECTION_H
#define COLLECTION_H
#include <iostream>

class Collection {
protected:
    double *arr_ = nullptr;
    double *temp_arr_ = nullptr;
    int size_of_array_ = 0;
    int capacity_ = 0;
public:
  Collection();
  Collection(int size);
  Collection(const Collection& other);
  ~Collection(){
      delete[] arr_;
      delete[] temp_arr_;
  }
  virtual int getSize() const;
  virtual int getCapacity() const;
  virtual void add(double item);
  virtual double get(int ndx) const;
  virtual int find(double needle) const;
  virtual double getFront() const;
  virtual double getEnd() const;
  virtual void removeFront();
  virtual void removeEnd();
  virtual void remove(double item);
  virtual double& operator[](int ndx);

  Collection& operator = (const Collection& other);
  virtual Collection& operator-(int count);
  virtual Collection& operator+(double item);
  virtual Collection& operator+(const Collection& other);
  virtual Collection& operator<<(double item);
  friend std::ostream& operator<<(std::ostream& out, const Collection& other);
};
#endif
