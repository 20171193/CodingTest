// 백준 9935 재풀이

#include <iostream>
#include <string>
using namespace std;

string target, bomb, ret;
string emp = "FRULA";

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> target >> bomb;

	for (int i = 0; i < target.length(); i++)
	{
		ret += target[i];

		if (ret.length() >= bomb.length() &&
			ret.substr(ret.length() - bomb.length(), bomb.length()) == bomb)
		{
			for (int j = 0; j < bomb.length(); j++)
				ret.pop_back();
		}
	}
	if (ret.length() < 1)
		cout << emp << '\n';
	else
		cout << ret << '\n';


	return 0;
}