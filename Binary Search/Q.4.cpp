// Question Link:- https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbXctVnJWNjlwLXpwLUJzcGJwU1FsbzZCUkhLZ3xBQ3Jtc0tsNm0tQnFOaVdlQmJ1M3BwamRaUEZnMGMyQWprRjVoSGxKYWlFUWpTS09CQW9tMlJMMEFmeEs4ZlVRZm9MREp6YnFjaVYwNnVtTE15eUhENVFyRVdoT0JFeU5iY0lObW1iSW45YlFIVEdScWI2SDN4WQ&q=https%3A%2F%2Fbit.ly%2F3rEVSK7&v=6z2HK4o8qcU
// Question:- Search in a sorted, rotated array.
/* 
Solution:-
    We learnt the concept to find pivot index, hence we know
    that both start and element of bottom line(pivot is start and end is known).
    Therefore our task of search is reduced because:- first we'll check that
    if our target element lies somewhere in bottom line,
    if not, then apply binary search it on upper line.
    STEPS:- 
    1. Find pivot
    2. Check if target lies on bottom line using condition:-
        arr[pivot] <= Target <= arr[end];
    3. If yes then apply binary search on bottom,
        else apply binary search on upper line.
*/
#include <iostream>
using namespace std;

// To get pivot:-
int pivotElement(int arr[], int size){
    int s = 0, e = size;
    int mid = s + (e-s)/2;

    while(s < e){
        if(arr[mid] >= arr[0]){ 
            s = mid + 1; 
        }
        else{
            e = mid; 
        }
        mid = s + (e-s)/2;
    }
    return s; 
}

// Binary search;-
int binarySearch( int arr[], int size, int key, int s, int e){

    //starting index
    int start = s;
    //end index 
    int end = e;;

        int mid = (start + end)/2;

    while(start <= end){
        //to search at mid index
        if(arr[mid] == key){
            return mid;
        }
        //to go towards right indices
        if(arr[mid] < key){
            start = mid + 1;
        }
        //to go towards left indices
        if(arr[mid] > key){
            end = mid - 1;
        }

        mid = (start + end)/2;
    }
    return -1;

}

// To find position
int findPosition(int arr[], int size, int key){
    int pivot = pivotElement(arr , size); //finding the pivot for comparison
    //Search in bottom line.
    if(arr[pivot] <= key && key <= arr[size]){
        int start = pivot, end = size; //customising "start" and "end" so that it search in bottom line.
        return binarySearch(arr, size, key, start, end);
    }
    //Search in upper line.
    else{
        int start = 0, end = pivot -1;//customising "start" and "end" so that it search in upper line.
        return binarySearch(arr, size, key, start, end);
    }
}


int main()
{
    int arr[6] = {8,9,1,2,3,5};
    int key = 9;
    cout <<"Index of "<<key<<" is "<< findPosition(arr, 5 , key)<<"\n";
    return 0;
}

/*
    NOTE:
    1. upper line is sorted within itself, same holds for bottom line.
    2. elements of upper line are always greater than elements of bottom line.
*/