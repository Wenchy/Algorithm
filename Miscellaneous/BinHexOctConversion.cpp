/**
 * 数制转换, Decimal to BinHexOct
 * @author Charles Wenchy <wenchy.zwz@gmail.com>
 * @version 1.0.0
 * @copyright Wenzhou Zhu
 * @license GPL2.0
 * @since 2015-4-9
 */
#include <iostream>
#include <stack>

using namespace std;
// formula: N = (N div d) x d + N mod d
void conversion(int num, int base = 2)
{
	stack<int> mystack;
	while (num)
	{
		mystack.push(num % base);
		num = num / base;

	}
	while (!mystack.empty())
	{
		cout << mystack.top();
		mystack.pop();
	}
	cout << endl;
}
int main(){
	int num, base;
	while (cin >> num >> base)
	{
		conversion(num, base);
	}
}
