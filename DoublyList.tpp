template <typename T>
DoublyList<T>::DoublyList()
: header(new Node), trailer(new Node) {
    header->next  = trailer;
    trailer->prev = header;
}

template <typename T>
DoublyList<T>::DoublyList(const DoublyList<T>& copyObj)
: header(new Node), trailer(new Node) {
    copy(copyObj);
}

template <typename T>
DoublyList<T>& DoublyList<T>::operator=(const DoublyList<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
DoublyList<T>::~DoublyList() {
    clear();
    delete header;
    delete trailer;
    header = trailer = nullptr;
}

template <typename T>
void DoublyList<T>::append(const T& elem) {
    // TO DO: Implement the code for the append
    
    
    Node *newNode = new Node;
    newNode->value= elem;
    newNode->next = trailer; //points newNode to trailer
    newNode->prev = trailer->prev;//points newNode's previous pointer to old last node
    trailer->prev->next = newNode; //takes old node's next pointer to connect it to newNode
    trailer->prev = newNode; //now updates trailer's prev pointer to be newNode

    if (header->next == trailer && trailer->prev == header)
    {
        cout << "The list is empty" << endl;
    }

}

template <typename T>
void DoublyList<T>::clear() {
    for (Node* curr = nullptr; header->next != trailer; ) {
        curr = header->next->next;
        delete header->next;
        header->next = curr;
    }

    trailer->prev = header;
    this->length  = 0;
}

template <typename T>
void DoublyList<T>::copy(const DoublyList<T>& copyObj) {
    this->length   = copyObj.length;
    Node* myCurr   = header;
    Node* copyCurr = copyObj.header->next;

    while (copyCurr != copyObj.trailer) {
        Node* n      = new Node(copyCurr->value);
        myCurr->next = n;
        n->prev      = myCurr;
        myCurr       = n;
        copyCurr     = copyCurr->next;
    }

    myCurr->next  = trailer;
    trailer->prev = myCurr;
}

template <typename T>
T DoublyList<T>::getElement(int position) const {
    // TO DO: Implent code for getElement at position, return element at given position
    Node* nodePtr = header->next; //start from first node
    int index = 0;
    
    while (nodePtr !=trailer)
    {
        if (index == position)
        {
            return nodePtr->value;
            break;
        }
        nodePtr = nodePtr ->next;
        index++;        
        /*if (position > index)
        {
            cout << "Position " << position << " is beyond list size" << endl;
            return T();
        }*/

    }
    
}

template <typename T>
int DoublyList<T>::getLength() const {
    return this->length;
}


template <typename T>
void DoublyList<T>::insert(int position, const T& elem) {
  // TO DO: Implement code to insert an element to list, insert given value at given positoin
  Node* nodePtr = header->next; //nodePtr in this case is kinda like trailer
  int index = 0;
  
  while (nodePtr != trailer)
  {
    if (position == index)
    {
        Node *newNode = new Node;
        newNode->value= elem;
        newNode->next = nodePtr;
        newNode->prev = nodePtr->prev;
        nodePtr->prev->next = newNode;
        nodePtr->prev = newNode;
        this->length++;
    }
    nodePtr = nodePtr->next;
    index++;

    if (position < 0 || position > index)
    {
        cout << "Insert failed: position " << position << " is beyond list size" << endl;
        return;
    }
  }

}

template <typename T>
bool DoublyList<T>::isEmpty() const {
    return this->length  == 0
        && header->next  == trailer
        && trailer->prev == header;
}

template <typename T>
void DoublyList<T>::remove(int position) {
    // TO DO: Implement code to remove element at given position, remove element at given position
    int index = 0;
    Node* nodePtr = header->next;

    while (nodePtr !=trailer && index < position)
    {
        nodePtr = nodePtr->next;
        index++;
        if (index == position)
        {
            
            nodePtr->prev->next = nodePtr->next;
            nodePtr->next->prev = nodePtr->prev;
            delete nodePtr;
            this->length--;
        }

        /*if (position > index || nodePtr == trailer) 
        {
            cout << "Remove failed: position " << position << " is out of range" << endl;
            return;
        }*/
        
    }
    
}

template <typename T>
bool DoublyList<T>::search(const T& elem) const 
{
    // TO DO: Implement code to search for element, check is given element exists, search, and return value at that element
    Node* nodePtr = header->next;
    //int index = 0;

    while (nodePtr !=trailer)
    {
        if (elem == nodePtr->value)
        {
            return true;
        }
        nodePtr = nodePtr->next;
    }
    return false;

}

template <typename T>
void DoublyList<T>::replace(int position, const T& elem) {
    // TO DO: Add code for replace method
}

template <typename T>
ostream& operator<<(ostream& outStream, const DoublyList<T>& myObj) {
    if (myObj.isEmpty()) {
        outStream << "List is empty, no elements to display.\n";
    }
    else {
        typename DoublyList<T>::Node* curr = myObj.header->next;
        while (curr != myObj.trailer) {
            outStream << curr->value;
            if (curr->next != myObj.trailer) {
                outStream << " <--> ";
            }
            curr = curr->next;
        }
        outStream << endl;
    }

    return outStream;
}
