//Intuition
//Let's say we have number i. If i is a consecutive sequence, the sequence would be
//[...i-2,i-1]+[i]+[i+1,i+2+...]
//
//Implementation
//We first use the hashTable to store the frequency of each number. Then we traverse the array. The element of the array is what I call I. This I must belongs to some sequence in the format of [...i-2,i-1]+[i]+[i+1,i+2+...]. We start with I and do a left/right traverse. Meanwhile, we will update our hashTable for avoiding duplicate check.
//
//Time Complexity
//O(n)O(n). Time Complexity is O(n) since every number is visited at most twice.
//
//Space Complexity
//O(n)O(n) We use an unordered_map to store the whole array in a format of [value:frequency]

int solve(vector<int>& nums) {
    int res = 0;
    unordered_map<int, int> hash;
    for (int i : nums) {
        hash[i]++;
    }

    for (int i : nums) {
        if (hash[i] == 0) continue;
        int cnt = 1;
        int next = i + 1;
        int pre = i - 1;
        while (hash.find(next) != hash.end() && hash[next] > 0) {
            cnt++;
            hash[next++]--;
        }
        while (hash.find(pre) != hash.end() && hash[pre] > 0) {
            cnt++;
            hash[pre--]--;
        }

        res = max(res, cnt);
    }

    return res;
}
