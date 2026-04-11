#include<bits/stdc++.h>
#include<type_traits>

template <typename T1, typename T2>
typename std::common_type<T1, T2>::type maxi(T1 a, T2 b) {
    return (b < a ? a : b);
}

int main(){
    int i = 1;
    std::cout << maxi(1,2) << '\n';

    // we can declare here too
    //
    //cout << maxi1<int, double, double>(4,7.2) << '\n';
}
