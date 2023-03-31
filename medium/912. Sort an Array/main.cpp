class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);

        return nums;
    }

private:
    void merge(vector<int> &arr, int left, int mid, int right){
        int leftSize = mid - left + 1;
        int rightSize = right - mid;
        vector<int> leftArr(leftSize), rightArr(rightSize);

        for(int i=0;i<leftSize;i++){
            leftArr[i] = arr[left + i];
        }

        for(int i=0;i<rightSize;i++){
            rightArr[i] = arr[mid + i + 1];
        }

        int l = 0, r = 0, k = left;
        while(l < leftSize && r < rightSize){
            if(leftArr[l] <= rightArr[r]){
                arr[k] = leftArr[l];
                l++; k++;
            }
            else {
                arr[k] = rightArr[r];
                r++; k++;
            }
        }

        while(l < leftSize){
            arr[k] = leftArr[l];
            l++; k++;
        }
        while(r < rightSize){
            arr[k] = rightArr[r];
            r++; k++;
        }
    }

    void mergeSort(vector<int> &arr, int left, int right){
        if(left < right){
            int mid = left + (right - left) / 2;
            mergeSort(arr, left, mid);
            mergeSort(arr, mid+1, right);

            merge(arr, left, mid, right);
        }
    }
};
