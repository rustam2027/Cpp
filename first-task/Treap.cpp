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
    left = 0;
    right = 0;
  }

  struct treapPair {
    TreapNode *left, *right;
  } typedef treapPair;

  int getKey() const { return key; }

  treapPair split(int k) {
    if (k <= key) {
      if (left == 0) {
        treapPair returnValue = treapPair();
        returnValue.left = 0;
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
      if (right == 0) {
        treapPair returnValue = treapPair();
        returnValue.left = this;
        returnValue.right = 0;
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
    if (other == 0) {
      return this;
    }

    if (priority < other->priority) {
      if (right == 0) {
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
    treapPair pair = split(new_key);
    TreapNode *L, *R;
    L = pair.left;
    R = pair.right;

    TreapNode *new_treap = new TreapNode(new_key, new_priority);

    if (L == 0) {
      return new_treap->merge(R);
    }
    return L->merge(new_treap)->merge(R);
  }

  TreapNode *remove(int delete_key) {
    treapPair pair = split(delete_key);
    TreapNode *L, *R;
    L = pair.left;
    R = pair.right;

    TreapNode *new_R;

    if (R != 0) {
      new_R = R->right;

      R->left = 0;
      R->right = 0;

      delete R;
    }

    if (L == 0) {
      return new_R;
    }
    return L->merge(new_R);
  }

  ~TreapNode() {
    std::cout << key << "Deleted\n";
    if (left != 0) {
      delete left;
    }
    if (right != 0) {
      delete right;
    }
  };
};
