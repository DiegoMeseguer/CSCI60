
#ifndef NODE_H
#define NODE_H
#include <cstdlib>
#include <ostream>
#include <iostream>
template <class T>
class node
{
public:
    node(const T & initdata = T(),//Calls the default constructor for the template type
         node * initlink = nullptr){
        data_ = initdata;
        link_ = initlink;
    }
    T data() const{
        return data_;
    }
    T & data(){
        return data_;
    }
    node * link(){
        return link_;
    }
    const node * link() const{
        return link_;
    }
    void setdata(const T & newdata){
        data_ = newdata;
    }
    void setlink(node * newlink){
        link_ = newlink;
    }
private:
    T data_;
    node * link_;
};

// linked list toolkit functions






template <class T>
std::size_t list_size(const node<T> * head){
  std::size_t count=0;
  for(const node<T>* p=head; p!=nullptr; p=(*p).link()){
    count++;
  }
  return count;
}




template <class T>
void list_head_insert(node<T>* & head,//call by reference node<T> pointer - so if you change head in the function, you change the head that was passed in
                      node<T>* & tail,
                      const T & value){
//We represent an empty linked list with head and tail
//both set to nullptr
//If the list was empty, we'll need to set the tail
//AND the head
  head=new node<T>(value, head);
  if(tail==nullptr)
    tail = head;

}

template <class T>
void list_tail_insert(node<T> * & head, node<T>* & tail,
  const T & value)
{
  //Make a new node
  //Set the link
  //reset tail
  if(head==nullptr){
    head=tail=new node<T>(value, nullptr);
  }
  else{
    //node n(value, nullptr);
    //node* temp = &n;//
    node<T>* temp =new node<T>(value, nullptr);
    //must use new so that the node still exists
    //after the function call is over
    //(*tail).set_link(temp);
    tail->setlink(temp);
    tail=tail->link();//tail=temp
  }

}
template <class T>
std::ostream & operator <<(std::ostream & os,
  const node<T>* head){
    for(const node<T>* p =head; p!=nullptr ; p=(*p).link()){
      os<<p->data()<<" ";
    }

    return os;
  }


template <class T>
const node<T>* list_search(const node<T> * head, const T & value){
  for(const node<T>* p =head; p!=nullptr ; p=(*p).link()){
    if(p->data()==value)
      return p;
  }
  return nullptr;
}
template <class T>
node<T>* list_search(node<T> * head, const T & value){
  for(node<T>* p =head; p!=nullptr ; p=(*p).link()){
    if(p->data()==value)
      return p;
  }
  return nullptr;
}

template <class T>
void list_copy(const node<T> *orig_head,
               const node<T> *orig_tail,
               node<T> * & new_head,
               node<T> * & new_tail){
                 //Can functions we've already written
                 //help?
                 //new_head=orig_head;Doesn't make a copy
                 //new_tail=orig_tail;Shares original list

new_head=new_tail=nullptr;
for(const node<T>* p =orig_head; p!=nullptr ; p=(*p).link()){
  list_tail_insert(new_head, new_tail, p->data());
  //insert each value
}
}

template <class T>
void list_remove(node<T> * previous, node<T> * &tail){

  node<T>*temp = previous->link();
  previous->setlink(temp->link());
  if(temp==tail)
    tail=previous;
  delete temp;//deletes the node

}

template <class T>
void list_head_remove(node<T> * & head, node<T> * &tail){
  node<T>*temp = head;
  head=head->link();
  delete temp;

}

//Remember, we already have head insert and tail insert
template <class T>
void list_insert(node<T> * previous, const T & value){
  node<T>* temp = new node<T>(value, previous->link());
  previous->setlink(temp);
}

#endif // NODE_H
