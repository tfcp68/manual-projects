

template<typename ValueType>
ValueType longest_common_subsequence(std::vector<ValueType>& a1, std::vector<ValueType>& a2) {
    int n1 = a1.size();
    int n2 = a2.size();
    if (n1 == 0 || n2 == 0){
        return 0;
    }
    ValueType f[n1 + 1][n2 + 1];
    for (int i = 0; i <= n1; i++){
        for (int j = 0; j <= n2; j++){
            f[i][j] = 0;
        }
    }
    for (int i = 1; i <= n1; i++){
        for (int j = 1; j <= n2; j++){
            if (a1[i - 1] == a2[j - 1]){
                f[i][j] = f[i - 1][j - 1] + 1;
            }
            else{
                f[i][j] = std::max(f[i - 1][j], f[i][j - 1]);
            }
        }
    }
    return f[n1][n2];
}
