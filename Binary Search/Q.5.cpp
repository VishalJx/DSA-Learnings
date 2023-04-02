// Question Link:- https://www.codingninjas.com/codestudio/problems/square-root_893351?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2
// Question:- Find square root of a number using binary search.

#include <bits/stdc++.h>
using namespace std;

int squareRoot(int number){
    int start = 0;
    int end = number;
     int mid = start + (end - start)/2;

     int ans = -1;
     while(start <= end){
        if(mid*mid == number){
            return mid;
        }
        else if(mid*mid > number){
            end = mid-1;
        }
        else if(mid*mid < number){
            ans = mid; //since all number less than mid can be solution, hence storing it.
            start = mid + 1;
        }
        mid = start + (end - start)/2;
     }
     return ans;
}

int main() {

    int number = 35;
    cout<<squareRoot(number)<<endl;
    return 0;
}

/*
    25
*/