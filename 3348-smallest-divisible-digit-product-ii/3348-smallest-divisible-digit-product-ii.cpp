#include <bits/stdc++.h>
class Solution {
private:
    const static unordered_map<int, unordered_map<int, int>> kFactorCounts;

    pair<unordered_map<int, int>, bool> getPrimeCount(long long t) {
        unordered_map<int, int> count{{2, 0}, {3, 0}, {5, 0}, {7, 0}};
        for (const int prime : {2, 3, 5, 7}) {
            while (t % prime == 0) {
                t /= prime;
                ++count[prime];
            }
        }
        return {count, t == 1};
    }

    unordered_map<int, int> getPrimeCount(const string& num) {
        unordered_map<int, int> count{{2, 0}, {3, 0}, {5, 0}, {7, 0}};
        for (const char d : num) {
            for (const auto& [prime, freq] : kFactorCounts.at(d - '0')) {
                count[prime] += freq;
            }
        }
        return count;
    }

    unordered_map<int, int> getFactorCount(unordered_map<int, int> primeCount) {
        int count2 = primeCount[2];
        int count3 = primeCount[3];
        const int count5 = primeCount[5];
        const int count7 = primeCount[7];

        int count8 = count2 / 3;
        count2 %= 3;
        int count9 = count3 / 2;
        count3 %= 2;

        int count4 = count2 / 2;
        count2 %= 2;

        int count6 = 0;
        if (count2 == 1 && count3 == 1) {
            count2 = 0;
            count3 = 0;
            count6 = 1;
        }
        if (count3 == 1 && count4 == 1) {
            count2 = 1;
            count6 = 1;
            count3 = 0;
            count4 = 0;
        }

        return {{2, count2}, {3, count3}, {4, count4}, {5, count5},
                {6, count6}, {7, count7}, {8, count8}, {9, count9}};
    }

    string construct(const unordered_map<int, int>& factorCount) {
        string s;
        for (int d = 2; d <= 9; ++d) {
            s += string(factorCount.at(d), '0' + d);
        }
        return s;
    }

    unordered_map<int, int> subtract(unordered_map<int, int> a, const unordered_map<int, int>& b) {
        for (const auto& [key, value] : b) {
            a[key] = max(0, a[key] - value);
        }
        return a;
    }

    int sumValues(const unordered_map<int, int>& count) {
        int sum = 0;
        for (const auto& [_, value] : count) sum += value;
        return sum;
    }

    bool isSubset(const unordered_map<int, int>& a, const unordered_map<int, int>& b) {
        for (const auto& [key, value] : a) {
            if (b.at(key) < value) return false;
        }
        return true;
    }

public:
    string smallestNumber(string num, long long t) {
        const auto [primeCount, isDivisible] = getPrimeCount(t);
        if (!isDivisible) return "-1";

        const auto factorCount = getFactorCount(primeCount);
        if (sumValues(factorCount) > num.length()) {
            return construct(factorCount);
        }

        auto primeCountPrefix = getPrimeCount(num);
        int firstZeroIndex = num.find('0');
        if (firstZeroIndex == string::npos) {
            firstZeroIndex = num.length();
            if (isSubset(primeCount, primeCountPrefix)) return num;
        }

        for (int i = num.length() - 1; i >= 0; --i) {
            const int d = num[i] - '0';
            primeCountPrefix = subtract(primeCountPrefix, kFactorCounts.at(d));
            const int spaceAfterThisDigit = num.length() - 1 - i;
            if (i > firstZeroIndex) continue;

            for (int biggerDigit = d + 1; biggerDigit < 10; ++biggerDigit) {
                const auto factorsAfterReplacement = getFactorCount(
                    subtract(subtract(primeCount, primeCountPrefix), kFactorCounts.at(biggerDigit)));
                
                if (sumValues(factorsAfterReplacement) <= spaceAfterThisDigit) {
                    const int fillOnes = spaceAfterThisDigit - sumValues(factorsAfterReplacement);
                    return num.substr(0, i) + to_string(biggerDigit) +
                           string(fillOnes, '1') + construct(factorsAfterReplacement);
                }
            }
        }

        const auto factorsAfterExtension = getFactorCount(primeCount);
        return string(num.length() + 1 - sumValues(factorsAfterExtension), '1') + 
               construct(factorsAfterExtension);
    }
};

const unordered_map<int, unordered_map<int, int>> Solution::kFactorCounts = {
    {0, {}}, {1, {}}, {2, {{2, 1}}}, {3, {{3, 1}}}, {4, {{2, 2}}},
    {5, {{5, 1}}}, {6, {{2, 1}, {3, 1}}}, {7, {{7, 1}}}, {8, {{2, 3}}}, {9, {{3, 2}}}
};