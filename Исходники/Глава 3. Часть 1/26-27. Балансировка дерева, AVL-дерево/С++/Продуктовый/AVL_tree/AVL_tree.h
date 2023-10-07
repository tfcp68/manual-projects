//
// Created by fedor on 3/11/23.
//
#ifndef AVL_TREE_AVL_TREE_H
#define AVL_TREE_AVL_TREE_H
#include <utility>
#include <stack>
#include <stdexcept>

template <typename T, typename K, typename NodeComparator = std::less<K>>
class AVL_tree{

private:

    struct AVLNode{
        /*
         * структура узла дерева
         */
        const K key;
        T data;
        int height;
        AVLNode* left;
        AVLNode* right;

        AVLNode(const K &_key, const T &_data);
    };

private:
    /*
     * корень и компратор
     */
    AVLNode *root;
    NodeComparator comparator;

public:

    class Iterator{
    /*
     * итератор по дереву
     */
    private:
        AVLNode* node;
        std::stack<AVLNode*> post;
        std::stack<AVLNode*> prev;
    public:

        Iterator(AVLNode* node):node(node){};
        Iterator(const Iterator &other);

        Iterator& operator=(const Iterator &other);

        std::pair<K, T> operator*() const;

        Iterator operator++();

        Iterator operator--();

        bool operator==(const Iterator&other);

        bool operator!=(const Iterator&other);

        Iterator begin();
        Iterator end();
    };

    class RIterator{
    /*
     * обратный итератор по дереву
     */
    private:
        AVLNode* node;
        std::stack<AVLNode*> post;
        std::stack<AVLNode*> prev;
    public:

        RIterator(AVLNode* node):node(node){};
        std::pair<K, T> operator*() const;

        RIterator operator++();

        RIterator operator--();

        bool operator==(const RIterator&other);

        bool operator!=(const RIterator&other);

        RIterator begin();
        RIterator end();
    };

    RIterator r_begin(){
        if(root)
            return RIterator(root).begin();
        else
            return nullptr;
    }
    RIterator r_end(){
        return RIterator(nullptr).end();
    }

    Iterator begin() {
        if(root)
            return Iterator(root).begin();
        else
            return nullptr;
    }
    Iterator end(){
        return Iterator(root).end();
    }

public:
    AVL_tree();


    AVL_tree(const AVL_tree &other);


    AVL_tree &operator=(const AVL_tree& other);


    ~AVL_tree();


public: // functions


    Iterator FindNode(const K &key);



    void InsertNode(const K &key, const T &data);


    void DeleteNode(int key);

private:

    AVLNode* FindNodeRecursive(AVLNode* root, const K &key);


    AVLNode* FindMinRecursive(AVLNode* node);


    AVLNode* InsertNodeRecursive(AVLNode *node, const K &key, const T &data);


    AVLNode* DeleteNodeRecursive(AVLNode* node, const K &key);

    AVLNode* copy(AVLNode* node);

    void clear(AVLNode* node);


    int GetHeight(AVLNode* node);


    int GetBalanceFactor(AVLNode* node);


    void FixHeight(AVLNode* node);


    AVLNode* RemoveMin(AVLNode* node);


    AVLNode* LeftRotation(AVLNode *node);


    AVLNode* RightRotation(AVLNode *node);


    AVLNode* MakeBalance(AVLNode* node);


};


#include "AVL_tree.tpp"
#include "AVL_tree_private.tpp"
#endif //AVL_TREE_AVL_TREE_H