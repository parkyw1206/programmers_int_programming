/************************************************************
 *  name : Youngwoo Park
 *  date : 10-02-2020
 *  level: l3
 *  problem source: programmers
 *  lang: C++
 *  skill:  dynamic programming
 * *********************************************************/
 #include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    vector<vector<int>> arr(triangle);
    for(int i = 0 ; i < arr.size() ; i++){
        for(int j = 0  ; j < arr[i].size() ; j++)
            arr[i][j] = 0;
    }
    arr[0][0] = triangle[0][0];
    arr[1][0] = triangle[0][0] + triangle[1][0];
    arr[1][1] = triangle[0][0] + triangle[1][1];

    for(int i  = 2 ; i < arr.size() ; i++){
        for(int j = 0 ; j < arr[i].size() ; j++){
            if(j == 0){
                arr[i][0] = arr[i-1][0] + triangle[i][0];                
            }
            else if(j == arr[i].size()-1){
                arr[i][j] = arr[i-1][j-1] + triangle[i][j];                
            }
            else{
                arr[i][j] = max(arr[i-1][j-1],arr[i-1][j]) + triangle[i][j];                
            }
        }        
    }
    
    for(int j = 0  ; j < arr[arr.size()-1].size() ; j++){
        if(answer < arr[arr.size()-1][j])
            answer = arr[arr.size()-1][j];
    }
    return answer;
}