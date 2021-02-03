void qsort(vector<int> &nums, int l, int r) {
    int base = nums[l];

    if(l >= r){
        return;
    }

    int i = l;
    int j = r;

    while(i < j){
        while(i < j && nums[j] >= base){
            j--;
        }
        nums[i] = nums[j];

        while(i < j && nums[i] <= base){
            i++;
        }
        nums[j] = nums[i];
    }
    nums[i] = base;
    qsort(nums, l, i - 1);
    qsort(nums, i + 1, r);
}
