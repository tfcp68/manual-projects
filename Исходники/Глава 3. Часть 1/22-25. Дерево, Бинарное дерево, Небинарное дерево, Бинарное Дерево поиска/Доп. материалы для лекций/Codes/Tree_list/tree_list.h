#include <iostream>
#include <vector>

using namespace std;

template<class T, class DEFAULT>
class Tree_vector {
private:
    DEFAULT def;

    long find_pos(T key, long pos = 0) {
        if (trees.size() == 0) {
            return -1;
        }
        if (pos > (trees.size() - 1)) {
            return -1;
        } else {
            if (key == trees[pos]) {
                return pos;
            } else {
                if (key > trees[pos]) {
                    find_pos(key, 2 * (pos + 1));
                } else {
                    find_pos(key, 2 * pos + 1);
                }
            }
        }
    }

    void erase_privat(T key, long pos = 0) {
        long position = find_pos(key,pos);
        if (position == -1) {
            return;
        } else {
            long position_left = 2 * position + 1;
            long position_right = 2 * (position + 1);
            if (trees[position_right] == def and trees[position_right] == def) {
                trees[position] = def;
                return;
            }
            if (trees[position_right] == def) {
                roothift_left(position, position_left);
                return;
            }
            if (trees[position_left] == def) {
                roothift_right(position, position_right);
                return;
            } else {
                trees[position] = minim(position_right);
                return;
            }
        }
    }


    void roothift_right(long pos_old, long pos_new) {
        trees[pos_old] = trees[pos_new];
        trees[pos_new] = def;

        long pos_old_left = 2 * pos_old + 1;
        long pos_old_right = pos_old_left + 1;
        long pos_new_left = 2 * pos_new + 1;
        long pos_new_right = pos_new_left + 1;

        if (not(child_check(pos_new_left))) {
            roothift_right(pos_old_left, pos_new_left);
        }
        if (not(child_check(pos_new_right))) {
            roothift_right(pos_old_right, pos_new_right);
        }

    }

    void roothift_left(long pos_old, long pos_new) {
        trees[pos_old] = trees[pos_new];
        trees[pos_new] = def;

        long pos_old_left = 2 * pos_old + 1;
        long pos_old_right = pos_old_left + 1;
        long pos_new_left = 2 * pos_new + 1;
        long pos_new_right = pos_new_left + 1;

        if (not(child_check(pos_new_right))) {
            roothift_left(pos_old_right, pos_new_right);
        }
        if (not(child_check(pos_new_left))) {
            roothift_left(pos_old_left, pos_new_left);
        }

    }

    bool child_check(long pos_new){
        if (pos_new >= trees.size() or trees[pos_new] == def){
            return true;
        } else{
            return false;
        }
    }


    T minim(long pos){
    if (trees[2 * pos + 1] == 0){
        T minimum = trees[pos];
        erase_privat(minimum, pos);
        return minimum;
    }
    else{
        return minim(2 * pos + 1);
    }
}

public:
    vector<T>trees;
    Tree_vector(T key, DEFAULT dafault = 0){
        def = dafault;
        trees.push_back(key);
        trees.push_back(def);
        trees.push_back(def);
    }
    ~Tree_vector(){
        trees.clear();
    }
    void insert(T key, long pos = 0){
        if (trees[pos] == def){
            trees[pos] = key;
            if ((2 * (pos +2) - trees.size()) > 0){
                long sizes = trees.size();
                for (long i = 0; i < (2 * (pos +2) - sizes); i++){
                    trees.push_back(0);
                }
            }
            return;
        }
        else {
                if (key >= trees[pos]) {
                    insert(key, 2 * (pos + 1));
                } else {
                    insert(key, 2 * pos + 1);
                }
            }
        }

    bool find(T key, long pos = 0 ){
       if (find_pos(key) == -1){
           return false;
       } else{
           return true;
       }
    }


    void erase_all(T key, long pos = 0){
        while (find(key, pos)){
            erase(key, pos);
        }
    }

    void erase(T key){
        erase_privat(key);
    }

    vector<T> print(){
        vector<T> list1;
        for (int i = 0; i<trees.size(); i++){
            if (trees[i] != def){
                list1.push_back(trees[i]);
            }
        }
        return list1;
    }
};



