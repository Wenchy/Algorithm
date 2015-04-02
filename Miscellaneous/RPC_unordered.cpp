//阿里巴巴笔试
/**************************************************************************************************************************	
	分布式系统中的RPC请求经常出现乱序的情况。
	写一个算法来将一个乱序的序列保序输出。例如, 假设起始序号是1，对于(1, 2, 5, 8, 10, 4, 3, 6, 9, 7)这个序列，输出是:
	1
	2
	3, 4, 5
	6
	7, 8, 9, 10

	上述例子中，3到来的时候会发现4, 5已经在了。因此将已经满足顺序的整个序列（3, 4, 5）输出为一行。

	要求：
	1. 写一个高效的算法完成上述功能，实现要尽可能的健壮、易于维护
	2. 为该算法设计并实现单元测试
	*************************************************************************************************************************
	解题思路：
		顺序由小到大查找（反转顺序再处理）
*****************************************************************************************************************************/
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm> 
using namespace std;
class Sequence
{
public:
	Sequence(vector<int> seqVector);
	void printSeq();

private:
	map<int, vector<int> *> mapSeq;
};

Sequence::Sequence(vector<int> seq)
{
	vector<int> seqVector = seq;
	//reverse the vertor for easy processing.
	reverse(seqVector.begin(), seqVector.end());
	while (! seqVector.empty())
	{

		int key = seqVector[0];
		vector<int> *pvec = new vector<int>;
		pvec->push_back(key);
		mapSeq.insert(make_pair(key, pvec));

		//assign the iter after erasing the first element in vector.
		auto iter = seqVector.erase(seqVector.begin());
		while (iter != seqVector.end())
		{
			if (*iter >= key)
			{
				pvec->push_back(*iter);
				// Important because of the iterator is invalid after erasing an element of vector.
				iter = seqVector.erase(iter);
			}else{
				iter++;
			}
		}
		sort(pvec->begin(), pvec->end());
	}

}
void Sequence::printSeq()
{
	for (auto mapIter = mapSeq.begin(); mapIter != mapSeq.end(); ++mapIter)
	{
		for (auto vectorIter = mapIter->second->begin(); vectorIter != mapIter->second->end(); ++vectorIter)
			cout << *(vectorIter) << " ";
		cout << endl;
	}
}

int main(int argc, char* argv[])
{
	vector<int> seqVector = { 1, 2, 5, 8, 10, 4, 3, 6, 9, 7 };
	Sequence seq(seqVector);
	seq.printSeq();
	return 0;
}