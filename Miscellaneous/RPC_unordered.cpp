//??????
/**************************************************************************************************************************	
	???????RPC????????????
	?????????????????????, ???????1,??(1, 2, 5, 8, 10, 4, 3, 6, 9, 7)????,???:
	1
	2
	3, 4, 5
	6
	7, 8, 9, 10

	?????,3????????4, 5???????????????????(3, 4, 5)??????

	??:
	1. ??????????????,??????????????
	2. ?????????????
	*************************************************************************************************************************
	????:
		????????(???????)
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
