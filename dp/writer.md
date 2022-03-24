W = 8

w = {3,4,5}
v = {30,50,60}


for(int i = 0 ; i < n ; i++)

    if(W-w[i] <= 0 ) continue
    temp = func(W-w[i])
    max_weight = max(max_weight ,temp+val[i])

return memo[W] = max_weight
