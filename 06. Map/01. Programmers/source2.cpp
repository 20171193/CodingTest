// 프로그래머스 레벨2 롤케이크 자르기


// 배열 총 2번 순회
// 1번 순회 : map a(철수)에 모든 토핑 할당.   
// 2번 순회 : map b(동생)에 하나씩 할당 <----> 철수 맵에서 --
//          : 매 반복마다 a와 b의 사이즈 체크

#include <string>
#include <vector>
#include <map>
using namespace std;

map<int, int> a, b;

int solution(vector<int> topping) {
    int answer = 0;
    // 토핑의 가짓 수
    for (int i = 0; i < topping.size(); i++)
    {
        if (a.find(topping[i]) == a.end()) a.insert({ topping[i], 1 });
        else a[topping[i]]++;
    }

    for (int i = 0; i < topping.size() - 1; i++)
    {
        if (a[topping[i]] > 1)
            a[topping[i]]--;
        else if (a[topping[i]] == 1)
            a.erase(topping[i]);

        if (b.find(topping[i]) == b.end()) b.insert({ topping[i], 1 });
        else b[topping[i]]++;

        if (a.size() == b.size()) answer++;
    }
    return answer;
}