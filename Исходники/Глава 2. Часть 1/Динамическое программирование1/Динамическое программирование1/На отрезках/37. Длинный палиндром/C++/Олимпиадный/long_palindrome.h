#include <bits/stdc++.h>
#include <cassert>

using namespace std;

int long_palindrome(const string& l) {
    int n = l.length();
    int p[n][n];
    for (int i = 0; i < n; i++){
        p[i][i] = 1;
    }
    for (int len_ = 1; len_ < n; len_++){
        for (int i = 0; i < n - len_; i++){
            int j = i + len_;
            if (l[i] == l[j]){
                p[i][j] = p[i + 1][j - 1] + 2;
            }
            else{
                p[i][j] = max(p[i + 1][j], p[i][j - 1]);
            }
        }
    }
    return p[0][n - 1];
}

//int long_palindrome_memory(const string& l) {
//    int n = l.length();
//    int f[n][n];
//    for (int i = 0; i < n; i++){
//        f[i][i] = 1;
//    }
//    std::vector<std::vector<int>>m(n, std::vector<int>(n, 0));
//    for (int len_ = 1; len_ < n; len_++){
//        for (int i = 0; i < n - len_; i++){
//            int j = i + len_;
//            if (l[i] == l[j]){
//                f[i][j] = f[i + 1][j - 1] + 2;
//            }
//            else{
//                f[i][j] = max(f[i + 1][j], f[i][j - 1]);
//                if (f[i][j] == f[i + 1][j]){
//                    m[i][j] = 1;
//                }
//                else{
//                    m[i][j] = 2;
//                }
//            }
//        }
//    }
//    return {f[0][n - 1], m};
//}
//
//vector<char> print_palindrome(int i, int j, const string& s, std::vector<std::vector<int>>& memory){
//    vector<char> arr;
//    if (i > j) {
//        return arr;
//    }
//    if (i == j) {
//        return {s[i]};
//    }
//    if (memory[i][j] == 0) {
//        arr.push_back(s[i]);
//        auto mid = print_palindrome(i + 1, j - 1, s,memory);
//        arr.insert(arr.end(), mid.begin(), mid.end());
//        arr.push_back(s[j]);
//    } else if (memory[i][j] == 1) {
//        arr = print_palindrome(i + 1, j, s, memory);
//    } else {
//        arr = print_palindrome(i, j - 1, s, memory);
//    }
//    return arr;
//}
