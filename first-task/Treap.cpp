#include <algorithm>
#include <iostream>

class TreapNode {
private:
  int key;
  int priority;
  TreapNode *left;
  TreapNode *right;

public:
  TreapNode(int key, int priority) {
    this->key = key;
    this->priority = priority;
    left = nullptr;
    right = nullptr;
  }

  struct treapPair {
    TreapNode *left, *right;
  } typedef treapPair;

  int getKey() const { return key; }

  const TreapNode* getRight() const {
    return this->right;
  }

  const TreapNode* getLeft() const {
    return this->left;
  }
  
  treapPair split(int k) {
    if (k <= key) {
      if (left == nullptr) {
        treapPair returnValue = treapPair();
        returnValue.left = nullptr;
        returnValue.right = this;
        return returnValue;
      }

      treapPair pair = left->split(k);

      TreapNode *LL, *LR;
      LL = pair.left;
      LR = pair.right;
      left = LR;

      treapPair returnValue = {LL, this};

      return returnValue;
    } else {
      if (right == nullptr) {
        treapPair returnValue = treapPair();
        returnValue.left = this;
        returnValue.right = nullptr;
        return returnValue;
      }

      treapPair pair = right->split(k);

      TreapNode *RL, *RR;
      RL = pair.left;
      RR = pair.right;
      right = RL;

      treapPair returnValue = {this, RR};

      return returnValue;
    }
  };

  TreapNode *merge(TreapNode *other) {
    if (other == nullptr) {
      return this;
    }

    if (priority < other->priority) {
      if (right == nullptr) {
        right = other;
      } else {
        right = right->merge(other);
      }
      return this;
    } else {
      other->left = merge(other->left);
      return other;
    }
  };

  TreapNode *insert(int new_key, int new_priority) {
    treapPair pair = this->split(new_key);
    TreapNode *L, *R;
    L = pair.left;
    R = pair.right;

    TreapNode *new_treap = new TreapNode(new_key, new_priority);

    if (L == nullptr) {
      return new_treap->merge(R);
    }
    return (L->merge(new_treap))->merge(R);
  }

  TreapNode *remove(int delete_key) {
    treapPair pair = split(delete_key);
    TreapNode *L, *R;
    L = pair.left;
    R = pair.right;

    TreapNode *new_R;

    if (R != nullptr) {
      new_R = R->right;

      R->left = nullptr;
      R->right = nullptr;

      delete R;
    }

    if (L == nullptr) {
      return new_R;
    }
    return L->merge(new_R);
  }

  ~TreapNode() {
    delete left;
    delete right;
  }
};
