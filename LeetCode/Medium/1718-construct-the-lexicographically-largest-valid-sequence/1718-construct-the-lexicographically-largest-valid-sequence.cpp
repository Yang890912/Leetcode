class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        vector<int> sequence(2 * n - 1, -1);
        vector<bool> used(n + 1, false);

        for (int i = 0; i < sequence.size(); i++) { 
            if (sequence[i] != -1) continue;

            for (int j = n; j >= 1; j--) {
                if (used[j]) continue;
                if (j == 1) {
                    sequence[i] = j;
                    used[j] = true;
                    break;
                }
                if (i + j >= sequence.size()) continue;
                if (sequence[i + j] != -1) continue;

                vector<int> prevSeq = sequence;
                vector<bool> prevUsed = used;

                sequence[i] = j;
                sequence[i + j] = j;
                used[j] = true;

                if (canPut(n - 1, sequence, used)) {
                    sequence = prevSeq;
                    used = prevUsed;

                    sequence[i] = j;
                    sequence[i + j] = j;
                    used[j] = true;
                    break;
                }
                else {
                    sequence = prevSeq;
                    used = prevUsed;
                }
            }
        }
        return sequence;
    }

    bool canPut(int n, vector<int>& sequence, vector<bool>& used) {
        if (n == 0) return true;
        if (used[n]) return canPut(n - 1, sequence, used);

        for (int i = 0; i < sequence.size(); i++) {
            if (n == 1 && sequence[i] == -1) {
                sequence[i] = 1;
                used[n] = true;
                return true;
            }

            if (i + n >= sequence.size()) return false;
            if (sequence[i] != -1 || sequence[i + n] != -1) continue;

            sequence[i] = n;
            sequence[i + n] = n;
            used[n] = true;

            if (canPut(n - 1, sequence, used)) return true;

            sequence[i] = -1;
            sequence[i + n] = -1;
            used[n] = false;
        }
        return false;
    }
};