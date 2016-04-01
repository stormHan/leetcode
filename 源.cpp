#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <vector>

#include "h_index.h"
#include "Min_Stack.h"
#include "LargestRectangleArea.h"
#include "binaryTreeNodes.h"
#include "SearchForRange.h"

using namespace std;

int singleNumber1(vector<int>& nums) {
	int a = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		a = a ^ nums[i];
	}
	return a;
}

void main(void)
{
	vector<int> a = { 1,2,  2,1,3,4,3};
	
	singleNumber1(a);
 	system("puase");
}