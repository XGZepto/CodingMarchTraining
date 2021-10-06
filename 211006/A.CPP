    string x;
    for (int i = 'a' ; i <= 'z' ; ++i){
        map<string, int> cnt;
        int res = 0;
        for (int j = 2 ; j <= n - 1; ++j){
            if (x[j] != i) continue;
            cnt[x[j-1] + x[j+1]]++;
            res = max(res, cnt[x[j-1] + x[j+1]]);
        }
    }


    int seq[4] = {1, 2, 3, 4};
    // permutation
    do{
        // cal

    }while(next_permutation(seq, seq + 4));