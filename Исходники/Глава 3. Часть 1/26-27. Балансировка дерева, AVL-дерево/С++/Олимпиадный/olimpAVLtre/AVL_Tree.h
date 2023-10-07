#include <iostream>
#include <vector>
#include <stack>

struct N {
    int k;
    int height;
    N *left;
    N *right;

    N(int _k) :
            k(_k),
            height(1),
            left(nullptr),
            right(nullptr) {}
};

int GH(N* node){
    if(node)
        return node->height;
    else
        return 0;
}

int BF(N* root){
    if(root)
        return (root->left ? GH(root->left) : 0) - (root->right ? GH(root->right) : 0);
    else
        return 0;
}

void H(N* root){
    root->height = (GH(root->left) > GH(root->right) ? GH(root->left) : GH(root->right)) + 1;
}

N *L(N *n) {
    N *q = n->left;
    n->left = q->right;
    q->right = n;
    H(n);
    H(q);
    return q;
}


N *R(N *n) {
    N *q = n->right;
    n->right = q->left;
    q->left = n;
    H(n);
    H(q);
    return q;
}


N *B(N *root) {
    int balance = BF(root);
    int left_balance = BF(root->left);
    int right_balance = BF(root->right);

    if (balance > 1 && left_balance >= 0)
        return L(root);
    if (balance < -1 && right_balance <= 0)
        return R(root);
    if (balance > 1 && left_balance < 0) {
        root->left = R(root->left);
        return L(root);
    }
    if (balance < -1 && right_balance > 0) {
        root->right = L(root->right);
        return R(root);
    }
    return root;
}


N *Ins(N *root, int k) {
    if (root == nullptr)
        return new N(k);
    if (k < root->k) {
        root->left = Ins(root->left, k);
    } else {
        root->right = Ins(root->right, k);
    }

    H(root);

    return B(root);

}


N *RM(N *root) {
    if (root->left == nullptr) return root->right;
    else root->left = RM(root->left);
    H(root);
    return B(root);
}


N *FM(N *root) {
    return root->left ? FM(root->left) : root;
}

N *D(N *root, int k) {
    if (root == nullptr) return nullptr;
    if (k < root->k) root->left = D(root->left, k);
    if (k > root->k) root->right = D(root->right, k);
    if (k == root->k) {
        N *left = root->left;
        N *right = root->right;
        delete root;
        if (right == nullptr) return left;
        N *min = FM(right);
        min->right = RM(right);
        min->left = left;
        H(min);
        return B(min);
    }
    H(root);
    return B(root);
}

int Search(N *root, int k) {
    if (k == root->k) {
        return root->k;
    }
    if (k < root->k)return Search(root->left, k);
    if (k > root->k)return Search(root->right, k);
    else
        throw std::invalid_argument("No such value");
}


std::vector<int> Traverse(N *node) {
    std::vector<int> v;
    std::stack<N*> s;
    while (node || size(s) > 0) {
        if (node) {
            s.push(node);
            node = node->left;
        } else {
            node = s.top();
            s.pop();
            v.push_back(node->k);
            node = node->right;
        }
    }
    return v;
}