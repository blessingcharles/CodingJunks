#include <unordered_set>
#include <bits/stdc++.h>

using namespace std;

// This function is used to get a hash value for the given size and given position of square.
int getHashValue(vector<vector<int>> &hash, int startIndOfI, int startIndOfJ, int endIndOfI, int endIndOfJ, vector<int> &p1, vector<int> &p2)
{
	int res = hash[endIndOfI][endIndOfJ] - hash[endIndOfI][startIndOfJ - 1] - hash[startIndOfI - 1][endIndOfJ] + hash[startIndOfI - 1][startIndOfJ - 1];

	res = res * p1[p1.size() - startIndOfI] * p2[p2.size() - startIndOfJ];
	return res;
}

bool ninjaAndSwordHelper(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int n1, int m1,
						 int n2, int m2, int size, vector<int> &p1, vector<int> &p2,
						 vector<vector<int>> &hashMatA, vector<vector<int>> &hashMatB)
{

	unordered_set<int> hashValueOfMat1;
	for (int i = 1; i <= n1 - size + 1; i++)
	{
		for (int j = 1; j <= m1 - size + 1; j++)
		{

			hashValueOfMat1.insert(getHashValue(hashMatA, i, j, i + size - 1, j + size - 1, p1, p2));
		}
	}

	for (int i = 1; i <= n2 - size + 1; i++)
	{
		for (int j = 1; j <= m2 - size + 1; j++)
		{

			if (hashValueOfMat1.find(getHashValue(hashMatB, i, j, i + size - 1, j + size - 1, p1, p2)) != hashValueOfMat1.end())
			{
				return true;
			}
		}
	}

	return false;
}

int ninjaAndSword(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int n1, int m1, int n2, int m2)
{
	// In these vectors we store random and unique numbers so that we get a unique hash value.
	vector<int> p1(51), p2(51);

	p1[0] = p2[0] = 1;

	for (int i = 1; i < 51; i++)
	{

		// We want random and unique numbers so we multiply with the prime numbers.
		p1[i] = p1[i - 1] * 157;
		p2[i] = p2[i - 1] * 173;
	}

	// In these vectors we store hash values for mat1 and mat2.
	vector<vector<int>> hashMatA(n1 + 1, vector<int>(m1 + 1));
	vector<vector<int>> hashMatB(n2 + 1, vector<int>(m2 + 1));

	for (int i = 1; i <= n1; i++)
	{
		for (int j = 1; j <= m1; j++)
		{
			// To find random and unique values we use p1 and p2.
			hashMatA[i][j] = hashMatA[i - 1][j] + hashMatA[i][j - 1] - hashMatA[i - 1][j - 1] + mat1[i - 1][j - 1] * p1[i] * p2[j];
		}
	}

	for (int i = 1; i <= n2; i++)
	{
		for (int j = 1; j <= m2; j++)
		{
			// To find random and unique values we use p1 and p2.
			hashMatB[i][j] = hashMatB[i - 1][j] + hashMatB[i][j - 1] - hashMatB[i - 1][j - 1] + mat2[i - 1][j - 1] * p1[i] * p2[j];
		}
	}

	int startSize = 1;
	int endSize = n1;
	int largestCommonSubsquare = 0;

	while (startSize <= endSize)
	{
		int mid = (startSize + endSize) / 2;

		if (ninjaAndSwordHelper(mat1, mat2, n1, m1, n2, m2, mid, p1, p2, hashMatA, hashMatB))
		{
			largestCommonSubsquare = mid;
			startSize = mid + 1;
		}
		else
		{
			endSize = mid - 1;
		}
	}
	return largestCommonSubsquare;
}
