const twoSum = (nums, target) => {
  const nums_with_idx = [...nums].map((i, idx) => [i, idx]);
  const sorted = nums_with_idx.sort((a, b) => a[0] - b[0]);
  let i = 0;
  let j = sorted.length - 1;
  while (i < j) {
    const sum = sorted[i][0] + sorted[j][0];
    if (sum == target) return [sorted[i][1], sorted[j][1]];
    if (sum > target) j--;
    else i++;
  }
  return [];
};

console.log(twoSum([2, 7, 11, 15], 9));
console.log(twoSum([3, 2, 4], 6));
