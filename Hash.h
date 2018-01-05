#pragma once
#include "List.h"

template <typename ItemType>

class Hash {

  private:

  int table_size;
  int size;
  List<ItemType>* tracker;
  ItemType item;
  List<ItemType>* temp;

  public:

  Hash() : tracker(new List<ItemType> table[table_size]), size(0), table_size(0) item(ItemType _item){}

  int hash_mod(ItemType& item){
    unsigned int key = 0;
      for (int i = 0; i < item.length(); i++){
        key =  (key*31) + item[i];
      }
      key = key % table_size;
      return key;
  }

  void copy_table(List<ItemType>* temp){
    unsigned int key;
    for (int i = 0; i < size; ++i)
    {
      if (tracker[i] != NULL){
        while (tracker[i].size() != 0)
        {
          if(tracker[i] != NULL){
          item = tracker[i].get_item()
          key = hash_mod(item);
          tracker[i].remove();
          temp[key].insert(item);
        }
      }
      else{
        i--;
      }  
    }
  }

  void double_table(int table_size){
    temp = new List<ItemType> table[table_size];

    copy_table(temp);

  }

  void table_size_verify(){
    if ((size*2) == table_size){
      table_size = (table_size * 2)+1;
      double_table(table_size);
    }

  }

  void add(const ItemType& item) {
    if (size == 0){
      

    }


  }

  void remove(const ItemType& item) {



  }

  bool find(const ItemType& item) {

    return false;

  }


};


