#include <vector>
#include <stdlib.h>

using namespace std;

long long solution(int N) {
    long long answer = 0;
    int* arr = (int*) malloc(sizeof(int)*N);
    int i = 2;
    for(i=2;i<=N;i++)
        arr[i] = i;
    for(i=2;i<=N;i++){
        if(arr[i]==0)
            continue;
        for(int j=2*i;j<=N;j+=i)
            arr[j]=0;
    }
    for(i=2;i<=N;i++){
        if(arr[i]!=0)
            answer+=arr[i];
    }
    return answer;
}
