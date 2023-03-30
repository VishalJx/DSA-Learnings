// Find first and last position of an element in sorted array.
#include <iostream>
using namespace std;

int leftMostOccurence(int arr[], int size, int key){
    int start = 0, end = size;
    int mid = (start + (end - start)/2);
    int answer; //This is the value where first encountered index of key is saved
    while(start <= end){
        if(arr[mid] == key){
            answer = mid;
            end = mid - 1; //to shift from mid to left side of array
        }
        else if(arr[mid] > key){
            end = mid - 1;
        }
        else if(arr[mid] < key){
            start = mid + 1;
        }
        mid = (start + (end - start)/2);
    }
    return answer;
}

int RightMostOccurence(int arr[], int size, int key){
    int start = 0, end = size;
    int mid = (start + (end - start)/2);
    int answer;
    while(start <= end){
        if(arr[mid] == key){
            answer = mid;
            start = mid + 1; //to shift from mid to right side of array
        }
        else if(arr[mid] > key){
            end = mid - 1;
        }
        else if(arr[mid] < key){
            start = mid + 1;
        }
        mid = (start + (end - start)/2);
    }
    return answer;
}

int main()
{
    int arr[6] = {1,2,3,3,5,12};
    int key = 3;
    int index1 = leftMostOccurence(arr, 6, key);
    int index2 = RightMostOccurence(arr, 6, key);

    cout <<"Left most occurence index of "<<key<<" is "<<index1<<endl;
    cout <<"Right most occurence index of "<<key<<" is "<<index2;
    return 0;
}

/*NOTE:
    Left most occurence is the first position of the key
    Right most occurence is the last position of the key
*/
/*IMPLEMENTATION
    We can count the number occurence of an elements in a sorted array.
    i.e. (LastOccurence - FirstOccurence);
    Otherwise it would take O(n) time complexity if we do it with linear search.
*/