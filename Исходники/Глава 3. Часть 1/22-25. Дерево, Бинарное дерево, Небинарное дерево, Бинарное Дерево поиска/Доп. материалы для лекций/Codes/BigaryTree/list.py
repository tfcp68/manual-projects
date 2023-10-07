import random


class list_tree:
    DEFAULT = 0
    def __init__(self, key=0, default = 0):
        self.tree = [key]
        self.tree.append(0)
        self.tree.append(0)
        self.DEFAULT = default
    def insert(self, key, pos=0):
        if self.tree[pos] == self.DEFAULT:
            if 2*(pos+1) > len(self.tree):
                for i in range(2*(pos+1) - len(self.tree) + 1):
                    self.tree.append(self.DEFAULT)
            self.tree[pos] = key
            return
        if key >= self.tree[pos]:
            self.insert(key, 2*(pos+1))
        else:
            self.insert(key, 2*pos+1)

    def find(self, key, pos=0):
        if len(self.tree) == self.DEFAULT:
            return -1
        if key == self.tree[pos]:
            return pos
        if self.tree[pos] == self.DEFAULT:
            return -1
        if key >= self.tree[pos]:
            return self.find(key, 2*(pos+1))
        else:
            return self.find(key, 2*pos+1)


    def _erase(self, key, pos=0):
        position = self.find(key, pos)
        if position == -1:
            return
        else:
            position_left = 2*position+1
            position_right = 2*(position + 1)

            if self.tree[position_right] == self.DEFAULT:
                self.roothift_left(position, position_left)
                return
            elif self.tree[position_left] == self.DEFAULT:
                self.roothift_right(position, position_right)
                return
            else:
                self.tree[position] = self._minim(position_right)
                return

    def roothift_right(self, pos_old_root, pos_new_root):
        self.tree[pos_old_root] = self.tree[pos_new_root]
        self.tree[pos_new_root] = self.DEFAULT

        left_pos_old = 2 * pos_old_root + 1
        rihgt_pos_old = left_pos_old + 1
        left_pos_new = 2 * pos_new_root + 1
        rihgt_pos_new = left_pos_new + 1

        if not(self.__left_child_check(left_pos_new)):
            self.roothift_right(left_pos_old, left_pos_new)
        if not(self.__right_child_check(rihgt_pos_new)):
            self.roothift_right(rihgt_pos_old, rihgt_pos_new)


    def roothift_left(self, pos_old_root, pos_new_root):
        self.tree[pos_old_root] = self.tree[pos_new_root]
        self.tree[pos_new_root] = self.DEFAULT

        left_pos_old = 2 * pos_old_root + 1
        rihgt_pos_old = left_pos_old + 1
        left_pos_new = 2 * pos_new_root + 1
        rihgt_pos_new = left_pos_new + 1

        if not(self.__right_child_check(rihgt_pos_new)):
            self.roothift_left(rihgt_pos_old, rihgt_pos_new)
        if not(self.__left_child_check(left_pos_new)):
            self.roothift_left(left_pos_old, left_pos_new)

    def __right_child_check(self, rihgt_pos_new):
        if rihgt_pos_new >= len(self.tree) or self.tree[rihgt_pos_new] == self.DEFAULT:
            return True
        else:
            return False


    def __left_child_check(self, left_pos_new):
        if left_pos_new >= len(self.tree) or self.tree[left_pos_new] == self.DEFAULT:
            return True
        else:
            return False

    def _minim(self, pos):
        if self.tree[2 * pos + 1] == self.DEFAULT:
            minimum = self.tree[pos]
            self._erase(minimum, pos)
            return minimum
        else:
            return self._minim(2*pos + 1)

    def erase(self, key):
        self._erase(key)


