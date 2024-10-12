class SubsetSum:
    def __init__(self, nums, target):
        self.nums = nums
        self.target = target

    def is_subset_sum(self, n, target):
        if target == 0:
            return True
        if n == 0:
            return False

        if self.nums[n-1] > target:
            return self.is_subset_sum(n-1, target)

        return (self.is_subset_sum(n-1, target) or 
                self.is_subset_sum(n-1, target - self.nums[n-1]))

    def find_subset_sum(self):
        return self.is_subset_sum(len(self.nums), self.target)


if __name__ == "__main__":
    nums = [3, 34, 4, 12, 5, 2]
    target = 9

    subset_sum = SubsetSum(nums, target)
    if subset_sum.find_subset_sum():
        print(f"A subset with the sum {target} exists.")
    else:
        print(f"No subset with the sum {target} exists.")
