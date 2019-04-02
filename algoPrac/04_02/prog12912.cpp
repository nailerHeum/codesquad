#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    long long tmp = 0;
    
    if (a < b) {
        tmp = b - a + 1;
    } else {
        tmp = a - b + 1;
    }
    answer = (a + b)*tmp/2;
    return answer;
}
