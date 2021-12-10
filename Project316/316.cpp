#include <stdio.h>

int T, map[6][6] = ;

int main() {
	scanf("%d", &T);
	for (int f = 1; f <= T; f++) {
	}
    int count = 0;
    Arrays.sort(nums);
    for (int i = 0; i < nums.length - 2; i++) {
        int k = i + 2;
        for (int j = i + 1; j < nums.length - 1 && nums[i] != 0; j++) {
            while (k < nums.length && nums[i] + nums[j] > nums[k])
                k++;
            count += k - j - 1;
        }
    }

	return 0;
}