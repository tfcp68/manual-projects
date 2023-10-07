

template<typename T, typename K, typename NodeComparator>
AVL_tree<T, K, NodeComparator>::AVL_tree() : root(nullptr){};

template<typename T, typename K, typename NodeComparator>
AVL_tree<T, K, NodeComparator>::Iterator::Iterator(const Iterator &other){
    this->node = other.node;
    this->post = other.post;
    this->prev = other.prev;
}

template<typename T, typename K, typename NodeComparator>
std::pair<K, T> AVL_tree<T, K, NodeComparator>::Iterator::operator*() const
{
    if(node == nullptr)
        throw std::invalid_argument("No such value");
    std::pair<K, T> A;
    A.first = node->key;
    A.second = node->data;
    return A;
}

template<typename T, typename K, typename NodeComparator>
bool AVL_tree<T, K, NodeComparator>::Iterator::operator==(const Iterator&other){
    return node == other.node;
}

template<typename T, typename K, typename NodeComparator>
bool AVL_tree<T, K, NodeComparator>::Iterator::operator!=(const Iterator&other){
    return node != other.node;
}

template<typename T, typename K, typename NodeComparator>
typename AVL_tree<T, K, NodeComparator>::Iterator AVL_tree<T, K, NodeComparator>::Iterator::operator++()
{
    node = node->right;
    while (node || size(post) > 0) {
        if (node) {
            post.push(node);
            node = node->left;
        } else {
            node = post.top();
            post.pop();
            return *this;
        }
    }
    return nullptr;
}

template<typename T, typename K, typename NodeComparator>
typename AVL_tree<T, K, NodeComparator>::Iterator AVL_tree<T, K, NodeComparator>::Iterator::operator--()
{
    node = node->left;
    while (node || size(prev) > 0) {
        if (node) {
            prev.push(node);
            node = node->right;
        } else {
            node = prev.top();
            prev.pop();
            return *this;
        }
    }
    return nullptr;
}

template<typename T, typename K, typename NodeComparator>
typename AVL_tree<T, K, NodeComparator>::Iterator& AVL_tree<T, K, NodeComparator>::Iterator::operator=(const Iterator &other){
    this->node = other.node;
    this->post = other.post;
    this->prev = other.prev;
    return *this;
}

template<typename T, typename K, typename NodeComparator>
AVL_tree<T, K, NodeComparator>::AVL_tree(const AVL_tree &other){
    this->root = copy(other.root);
    this->comparator = other.comparator;
}


template<typename T, typename K, typename NodeComparator>
AVL_tree<T, K, NodeComparator> &AVL_tree<T, K,NodeComparator>::operator=(const AVL_tree &other) {
    this->root = copy(other.root);
    this->comparator = other.comparator;
    return *this;
}

template<typename T, typename K, typename NodeComparator>
typename AVL_tree<T, K, NodeComparator>::Iterator AVL_tree<T, K, NodeComparator>::Iterator::begin() {
    while (node) {
        post.push(node);
        node = node->left;
    }
    node = post.top();
    post.pop();
    return *this;
}
template<typename T, typename K, typename NodeComparator>
typename AVL_tree<T, K, NodeComparator>::Iterator AVL_tree<T, K, NodeComparator>::Iterator::end(){
    return Iterator(nullptr);
}

template<typename T, typename K, typename NodeComparator>
std::pair<K, T> AVL_tree<T, K, NodeComparator>::RIterator::operator*() const
{
    if(node == nullptr)
        throw std::invalid_argument("No such value");
    std::pair<K, T> A;
    A.first = node->key;
    A.second = node->data;
    return A;
    //return node->data;
}

template<typename T, typename K, typename NodeComparator>
AVL_tree<T, K, NodeComparator>::~AVL_tree(){
    clear(root);
}

template<typename T, typename K, typename NodeComparator>
typename AVL_tree<T, K, NodeComparator>::RIterator AVL_tree<T, K, NodeComparator>::RIterator::operator++()
{
    node = node->left;
    while (node || size(post) > 0) {
        if (node) {
            post.push(node);
            node = node->right;
        } else {
            node = post.top();
            post.pop();
            return *this;
        }
    }
    return nullptr;
}

template<typename T, typename K, typename NodeComparator>
typename AVL_tree<T, K, NodeComparator>::RIterator AVL_tree<T, K, NodeComparator>::RIterator::operator--()
{
    node = node->left;
    while (node || size(prev) > 0) {
        if (node) {
            prev.push(node);
            node = node->right;
        } else {
            node = prev.top();
            prev.pop();
            return *this;
        }
    }
    return nullptr;
}

template<typename T, typename K, typename NodeComparator>
bool AVL_tree<T, K, NodeComparator>::RIterator::operator==(const RIterator&other){
    return node == other.node;
}


template<typename T, typename K, typename NodeComparator>
bool AVL_tree<T, K, NodeComparator>::RIterator::operator!=(const RIterator&other){
    return node != other.node;
}


template<typename T, typename K, typename NodeComparator>
typename AVL_tree<T, K, NodeComparator>::RIterator AVL_tree<T, K, NodeComparator>::RIterator::begin() {
    while (node) {
        post.push(node);
        node = node->right;
    }
    node = post.top();
    post.pop();
    return *this;
}
template<typename T, typename K, typename NodeComparator>
typename AVL_tree<T, K, NodeComparator>::RIterator AVL_tree<T, K, NodeComparator>::RIterator::end(){
    return RIterator(nullptr);
}

template<typename T, typename K, typename NodeComparator>
void AVL_tree<T, K, NodeComparator>::InsertNode(const K &key, const T &data){
    root = InsertNodeRecursive(root, key, data);
}


template<typename T, typename K, typename NodeComparator>
void AVL_tree<T, K, NodeComparator>::DeleteNode(int key){
    root = DeleteNodeRecursive(root, key);
}

template<typename T, typename K, typename NodeComparator>
typename AVL_tree<T, K, NodeComparator>::Iterator AVL_tree<T, K, NodeComparator>::FindNode(const K &key){
    AVLNode* node = FindNodeRecursive(root, key);
    if(Iterator(node) == end())
        throw std::invalid_argument("No such value");
    else
        return Iterator(node);
}