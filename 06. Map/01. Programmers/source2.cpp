// ���α׷��ӽ� ����2 ������ũ �ڸ���


// �迭 �� 2�� ��ȸ
// 1�� ��ȸ : map a(ö��)�� ��� ���� �Ҵ�.   
// 2�� ��ȸ : map b(����)�� �ϳ��� �Ҵ� <----> ö�� �ʿ��� --
//          : �� �ݺ����� a�� b�� ������ üũ

#include <string>
#include <vector>
#include <map>
using namespace std;

map<int, int> a, b;

int solution(vector<int> topping) {
    int answer = 0;
    // ������ ���� ��
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