#include <string>
#include <iostream>
#include <algorithm>
#include "List.h"

using namespace std;

template <typename ItemType>

class Tree {

private:

  struct Node {

    ItemType item;
    Node* left;
    Node* right;
    int height;
    int level;
    
    Node(const ItemType& _item) : item(_item), left(NULL), right(NULL), height(1), level(0) {}
  };
  
  Node* root;
  Node* n;
  Node* temp;
  int _size;

public:

  Tree() : root(NULL), _size(0) {}

  void right_left(Node* temp){
    if (temp != NULL){
    if (temp->item == n->item){
      delete temp;
    }
    else{
      if (temp->item > n->item){
        if (n->right == NULL){

          n->right = temp;
          _size++;
        }
        else{
          n = n->right;
          right_left(temp);
        }
      }
      else{
        if (n->left == NULL){

          n->left = temp;
          _size++;
        }
        else{
          n = n->left;
          right_left(temp);
        }
      }
    }
  }
  else{}
  }

  void add(const ItemType& item) {
    if (_size == 0){
      n = new Node(item);
      root = n;
      _size++;
    }
    else{
      temp = new Node(item);
      n = root;
      right_left(temp);
    }
    balance(root);
  }

  int get_size() const {

    return _size;
  }

  void print(ofstream& out_file){

    if (_size != 0){
      leveler(root);
      int heght;
      get_height(root);
      int _level = 0;
      List <Node*> a;
      n = root;
      a.insert(root);
      heght = 0;      
      out_file << "level " << _level << ":";

      while (a.getsize() != 0){

        n = a.get_item();
        a.remove();
        if (n->left != NULL){
          a.insert(n->left);
        }
        if (n->right != NULL){

          a.insert(n->right);
        }
        if (heght < 8){
          if (n->level == _level){

            out_file <<" " << n->item << "(" << n->height << ")";
            heght++;
          }
          else{
            heght = 0;
            out_file << endl;
            heght++;
            _level++;
            out_file << "level " << _level << ": " << n->item << "(" << n->height << ")";
          }
        }
        else {
          if (n->level == _level){
            heght = 0;
            out_file << endl;
            heght++;
            out_file << "level " << _level << ": " << n->item << "(" << n->height << ")";
          }
          else{
            heght = 0;
            out_file << endl;
            heght++;
            _level++;
            out_file << "level " << _level << ": " << n->item << "(" << n->height << ")";
          }
        }
      }
      out_file << endl;
    }
    else{}
  }

  void get_height(Node* npoint){
    if (npoint != NULL){
    int heght = get_height2(npoint);
    if ((heght = 0)){}
      else{}
    }
  else{}
  }

  int get_height2(Node* npoint){

      if (npoint != NULL){
        npoint->height = (max(get_height2(npoint->left), get_height2(npoint->right)) + 1);
        return npoint->height;
      }
      else{
        return 0;
      }
  }

  void ab(int& a, int& b, Node* n){
    if(n != NULL){

    if (n->left == NULL){
      a = 0;
    }
    else{
      a = n->left->height;
    }
    if (n->right == NULL){
      b = 0;
    }
    else{
      b = n->right->height;
    }
  }
  else{}
  }

  void balance(Node* n){

    if (n != NULL){
      get_height(root);
      int a;
      int b;

      ab(a, b, n);
      if ((a - b) > 1){
        balance(n->left);
        ab(a, b, n);
        balanceCon2(a, b, n);
      }
      else if ((a - b) < -1){
        balance(n->right);
        ab(a, b, n);
        if (((a - b) <= 1) && ((a - b) >= -1)){}
        else{
          balanceCon1(n);
        }
      }
      else{}
      balance(n->left);
      balance(n->right);
    }
    else{}
  }

void balanceCon2(int a, int b, Node* n){
  if (n !=NULL){
  if (((a - b) <= 1) && ((a - b) >= -1)){}
        else{
          if (balance2(n->left) >= 0){
            rotate_right(n);
            balance(root);
          }
          else if (balance2(n->left) < 0){
            rotate_left(n->left);
            rotate_right(n);
            balance(root);
          }
          else{}
        }
  }
  else{}    
}

void balanceCon1(Node* n){
  if (n != NULL){
  if (balance2(n->right) > 0){
            rotate_right(n->right);
            rotate_left(n);
            balance(root);
          }
          else if (balance2(n->right) <= 0){
            rotate_left(n);
            balance(root);
          }
          else{}
  }
else{}
}

  int balance2(Node* n){

    if (n != NULL){
      get_height(root);
      int a;
      int b;
      if (n->left == NULL){
        a = 0;
      }
      else{
        a = n->left->height;
      }
      if (n->right == NULL){
        b = 0;
      }
      else{
        b = n->right->height;
      }
      return a - b;
    }
    else{return 0;}
  }

  void rotate_right(Node* & n) {
    if (n !=NULL){
    if (n->left != NULL){
      temp = n->left;
      n->left = temp->right;
      temp->right = n;
      find_right(n->item, root);
      find_left(n->item, root);
      if (n == root){
        root = temp;
      }
      get_height(root);
    }
    else{}
  }
else{}
  }

  void rotate_left(Node* & n) {
        if (n !=NULL){
    if (n->right != NULL){
      temp = n->right;
      n->right = temp->left;
      temp->left = n;
      find_left(n->item, root);
      find_right(n->item, root);
      if (n == root){
        root = temp;
      }
      get_height(root);
    }
    else{}
  }
else{}
  }

  void find_right(ItemType _item, Node* npoint){
    if (npoint == NULL){}
    else{
      if (npoint->left == NULL){}
      else{
        if (npoint->left->item == _item){
          if (npoint != temp){
            npoint->left = temp;
          }
          else{}
        }
        else{
          find_right(_item, npoint->left);
          find_right(_item, npoint->right);
        }
      }
    }
  }

  void find_left(ItemType _item, Node* npoint){
    if (npoint == NULL){}
    else{
      if (npoint->right == NULL){}
      else{
        if (npoint->right->item == _item){
          if (npoint != temp){
            npoint->right = temp;
          }
          else{}
        }
        else{
          find_left(_item, npoint->right);
          find_left(_item, npoint->left);
        }
      }
    }
  }

  void find_nuller(ItemType _item, Node* &npoint, Node* &nprev){
        if (npoint !=NULL){
    if (nprev !=NULL){
      if (npoint->left == NULL){
        if(npoint->right == NULL){
          nprev->right = NULL;
        }
        else{}
      }
      else{
        if (npoint->left->item == _item){
          npoint->left = NULL;
        }
        else{ find_nuller(_item, npoint->left, nprev); }
        } 
        }
        else{}  
        }
        else{} 
  }

  void leveler(Node* &npoint){
    if (npoint != NULL){
      if (npoint == root){
        npoint->level = 0;
      }
      if (npoint->left == NULL){}
      else { npoint->left->level = npoint->level + 1; }
      if (npoint->right == NULL){}
      else { npoint->right->level = npoint->level + 1; }
      leveler(npoint->left);
      leveler(npoint->right);
    }
    else{}
  }

  string find(const ItemType& _item){
    bool counter = true;
    find2(root,_item, counter);
    if (counter == false){
      return "false"; 
    }
    else{  
    if(n->item == _item){
      return "true";
    }
    else{
      return "false"; 
    }  
  }
  }

  void find2(Node* npoint,const ItemType& _item, bool& counter){
    if (npoint == NULL) {
      counter = false;
    }
    else if (_item < npoint->item) {
      find2(npoint->left,_item,counter);
    }
    else if (npoint->item < _item) {
      find2(npoint->right, _item,counter);
    }
    else {
      n = npoint;
    }
  }

  void remove(const ItemType& _item){
    bool counter = true;
    if (_size != 0){
    if (find(_item) == "false"){}
    else{
    if (_size == 1){
      delete root;
      root = NULL;
      _size--;
    }
    else{
      find2(root, _item,counter);
      if (n->right == NULL){

        temp = n->left;
        find_left(_item, root);
        find_right(_item, root);
        if (n == root){
          root = temp;
        }
        delete n;
        _size--;
        balance(root);
        get_height(root);
      }
      else if (n->left == NULL){
        temp = n->right;
        find_left(_item, root);
        find_right(_item, root);
        if (n == root){
          root = temp;
        }
        delete n;
        _size--;
        balance(root);
        get_height(root);
      }
      else{
        temp = minimin(n->right);
        remove2(_item);
      }
    }
  }
  }
else{}
  }

  void remove2(const ItemType& _item){
    if ((n->height - temp->height) == 1){
          find_left(_item, root);
          find_right(_item, root);
          temp->left = n->left;
          if (n == root){
            root = temp;
          }
          delete n;
          _size--;
          balance(root);
          get_height(root);
        }
        else{
          if (temp->right != NULL){
            ItemType container = temp->right->item;
            delete temp->right;
            _size--;
            n->item = temp->item;
            temp->item = container;
            temp->right = NULL;
            balance(root);
            get_height(root);
          }
          else{
              n->item = temp->item;
              find_nuller(temp->item, n->right,n);
              delete temp;
              _size--;
              balance(root);
              get_height(root);    
          }
        }
  }

  Node* minimin(Node* & npoint){
        if (npoint !=NULL){
    if(npoint->left == NULL){
      return npoint;
    }
    else{
      return minimin(npoint->left);
    }
  }
  else
  {      return npoint;}
  }

  void clear(){
    clear2(root);
  }

  void clear2(Node* &npoint){

    if (npoint != NULL){
      clear2(npoint->left);
      clear2(npoint->right);
      delete npoint; 
      npoint =NULL;
      _size = 0;
    }
    else{}
  }

  ~Tree()
  {
    n = root;
     clear2(n); 
  
    root = NULL;
    n = NULL;
    temp = NULL;
    _size = 0;
  }


};