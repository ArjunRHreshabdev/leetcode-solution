int** findDifference(int* nums1, int nums1Size,
                     int* nums2, int nums2Size,
                     int* returnSize, int** returnColumnSizes) {

    int hash1[2001] = {0};
    int hash2[2001] = {0};

    // Store elements
    for (int i = 0; i < nums1Size; i++) {
        hash1[nums1[i] + 1000] = 1;
    }

    for (int i = 0; i < nums2Size; i++) {
        hash2[nums2[i] + 1000] = 1;
    }

    // Maximum possible result sizes
    int* ret0 = malloc(nums1Size * sizeof(int));
    int* ret1 = malloc(nums2Size * sizeof(int));

    int len1 = 0;
    int len2 = 0;

    // nums1 elements not present in nums2
    for (int i = 0; i < nums1Size; i++) {
        if (hash2[nums1[i] + 1000] == 0) {
            ret0[len1++] = nums1[i];

            // Prevent duplicates
            hash2[nums1[i] + 1000] = 1;
        }
    }

    // nums2 elements not present in nums1
    for (int i = 0; i < nums2Size; i++) {
        if (hash1[nums2[i] + 1000] == 0) {
            ret1[len2++] = nums2[i];

            // Prevent duplicates
            hash1[nums2[i] + 1000] = 1;
        }
    }

    int** result = malloc(2 * sizeof(int*));

    result[0] = ret0;
    result[1] = ret1;

    *returnSize = 2;

    *returnColumnSizes = malloc(2 * sizeof(int));
    (*returnColumnSizes)[0] = len1;
    (*returnColumnSizes)[1] = len2;

    return result;
}

