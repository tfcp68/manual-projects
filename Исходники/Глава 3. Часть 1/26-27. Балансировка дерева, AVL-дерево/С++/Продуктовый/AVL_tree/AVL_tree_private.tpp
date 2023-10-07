template<typename T, typename K, typename NodeComparator>
AVL_tree<T, K, NodeComparator>::AVLNode::AVLNode(const K &_key, const T &_data):// Конструктор структуры
        key(_key),
        data(_data),
        height(1),
        left(nullptr),
        right(nullptr){}

template<typename T, typename K, typename NodeComparator>
typename AVL_tree<T, K, NodeComparator>::AVLNode*  AVL_tree<T, K, NodeComparator>::FindMinRecursive(AVLNode* node){
    return node->left?FindMinRecursive(node->left):node;
}


template<typename T, typename K, typename NodeComparator>
typename AVL_tree<T, K, NodeComparator>::AVLNode* AVL_tree<T, K, NodeComparator>::InsertNodeRecursive(AVLNode *node, const K &key, const T &data) {
    if (node == nullptr)
        return new AVLNode(key, data);
    if (comparator(key, node->key)) {
        //node->height++;
        node->left = InsertNodeRecursive(node->left, key, data);
    }
    else if (!comparator(key, node->key)){
        //node->height++;
        node->right = InsertNodeRecursive(node->right, key, data);
    }
    return MakeBalance(node);
}


template<typename T, typename K, typename NodeComparator>
typename AVL_tree<T, K, NodeComparator>::AVLNode* AVL_tree<T, K, NodeComparator>::DeleteNodeRecursive(AVLNode* node, const K &key){
    if(node == nullptr) return 0;
    if(comparator(key, node->key)) node->left = DeleteNodeRecursive(node->left, key);
    if(!comparator(key,  node->key)) node->right = DeleteNodeRecursive(node->right, key);
    if(key == node->key){
        AVLNode* left = node->left;
        AVLNode* right = node->right;
        delete node;
        if(right == nullptr) return left;
        AVLNode* min = FindMinRecursive(right);
        min->right = RemoveMin(right);
        min->left = left;
        return MakeBalance(min);
    }
    return MakeBalance(node);
}


template<typename T, typename K, typename NodeComparator>
void AVL_tree<T, K, NodeComparator>::clear(AVLNode* node){
    if (node != nullptr) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}


template<typename T, typename K, typename NodeComparator>
int AVL_tree<T, K, NodeComparator>::GetHeight(AVLNode* node)
{
    return node?node->height:0;
}


template<typename T, typename K, typename NodeComparator>
int AVL_tree<T, K, NodeComparator>::GetBalanceFactor(AVL_tree::AVLNode *node) {
    return GetHeight(node->left) - GetHeight(node->right);
}


template<typename T, typename K, typename NodeComparator>
void AVL_tree<T, K, NodeComparator>::FixHeight(AVLNode* node){
    node->height = ((GetHeight(node->left) > GetHeight(node->right)) ? GetHeight(node->left) : GetHeight(node->right)) + 1;
}


template<typename T, typename K, typename NodeComparator>
typename AVL_tree<T, K, NodeComparator>::AVLNode* AVL_tree<T, K, NodeComparator>::RemoveMin(AVLNode* node){
    if(node->left == nullptr) return node->right;
    else node->left = RemoveMin(node->left);
    return MakeBalance(node);
}


template<typename T, typename K, typename NodeComparator>
typename AVL_tree<T, K, NodeComparator>::AVLNode* AVL_tree<T, K, NodeComparator>::LeftRotation(AVLNode *node){
    AVLNode *q = node->left;
    node->left = q->right;
    q->right = node;
    FixHeight(node);
    FixHeight(q);
    return q;
}


template<typename T, typename K, typename NodeComparator>
typename AVL_tree<T, K, NodeComparator>::AVLNode* AVL_tree<T, K, NodeComparator>::RightRotation(AVLNode *node){
    AVLNode *q = node->right;
    node->right = q->left;
    q->left = node;
    FixHeight(node);
    FixHeight(q);
    return q;
}


template<typename T, typename K, typename NodeComparator>
typename AVL_tree<T, K, NodeComparator>::AVLNode* AVL_tree<T, K, NodeComparator>::MakeBalance(AVLNode* node){
    FixHeight(node);
    int balance_factor = GetBalanceFactor(node);
    if(balance_factor > 1){
        if(GetBalanceFactor(node->left) < 0){
            node->left = RightRotation(node->left);
        }
        return LeftRotation(node);
    }

    if(balance_factor < -1){
        if(GetBalanceFactor(node->right) > 0){
            node->right = LeftRotation(node->right);
        }
        return RightRotation(node);
    }
    return node;
}

template<typename T, typename K, typename NodeComparator>
typename AVL_tree<T, K, NodeComparator>::AVLNode *AVL_tree<T, K, NodeComparator>::FindNodeRecursive(AVLNode* root, const K &key){
    if(root) {
        if (key == root->key) {
            return root;
        }
        if (key < root->key) {
            return FindNodeRecursive(root->left, key);
        }
        if (key > root->key) {
            return FindNodeRecursive(root->right, key);
        }
    }
    else
        return nullptr;
}

template<typename T, typename K, typename NodeComparator>
typename AVL_tree<T, K, NodeComparator>::AVLNode *AVL_tree<T, K, NodeComparator>::copy(AVLNode* node){
    if(!node){
        return nullptr;
    }
    auto newNode = new AVLNode(node->key, node->data);
    newNode->height = node->height;
    newNode->left = copy(node->left);
    newNode->right = copy(node->right);
    return newNode;
}