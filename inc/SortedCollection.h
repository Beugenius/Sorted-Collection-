#ifndef SORTED_DOUBLE_COLLECTION_H
#define SORTED_DOUBLE_COLLECTION_H
#include "Collection.h"

class SortedCollection: public Collection{

/**TODO: override any methods necessary
 * to keep this collection of doubles in
 * sorted order.  Hint - Whenever you
 * add an item add it in the "correct"
 * spot to maintain sorted order and
 * remember there are several ways to add
 * items to the collection.
 */
public:
    void add(double item) override;
};
#endif
