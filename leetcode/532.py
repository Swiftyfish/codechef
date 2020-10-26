def get_kdiff(nums, k):
    res = len(set(nums) & set(n+k for n in nums))
    return res