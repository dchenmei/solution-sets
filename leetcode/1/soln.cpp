#include <bits/stdc++.h>

using namespace std;

/* Need someone to make test cases? */

/* Notes / Assumptions / Constraints / Pitfalls
 * - Notice that if you sort the vector, the indices wll not be the same
 * - There can be duplicates elements! 
 * - Order of the indices does not matter
 */

vector<int> two_sum(vector<int>& nums, int target)
{
	/* Brute Force Solution
     * Go through every possible pair with nested loop and check their sum
     * Runtime: O(n^2)
     */

	/* Two Pass Map
     * 1. Go through every element and map value to index
     * 2. Go through every element and check if (target - element) is in the map
     *
     * Runtime: O(n)
     * Space  : O(n)
     */

	/* One pass Map (beats 99%+)
     * Similar runtime to Two Pass, read below
     *
     * If there is a guaranteed solution, why would only going through once work?
     * Ans: Let's say there is an answer (a, b). One is after the other meaning 
     *      one would have been inserted before hand so match will happen.
     */

	map<int, int> m;
	vector<int> ret = { -1, -1 };
	for (int i = 0; i < nums.size(); ++i)
	{
		if (m.find(target - nums[i]) != m.end())
		{
			ret[0] = m[target - nums[i]];
			ret[1] = i;
			break;
		}

		m[nums[i]] = i; /* Inserting after prevents twice usage accidents such as 3 + 3 = 6 */
	}

	/* Possible Optimization 
     * - If current element is bigger than target, don't map it
     */

	return ret;
}

