#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;

bool strcpp(char a,char b){
    return a > b;
}

int main(){

    vector <char>arr={'d','v','t','b','d','h','l','s','a'};
    sort(arr.begin(),arr.end(),strcpp);
    for(int i=0;i<arr.size();i++){
        printf("%c ",arr[i]);
    }





return 0;
}
