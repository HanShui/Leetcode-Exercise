int* twoSum(int* nums, int numsSize, int target) {
  int* results = (int*) malloc (sizeof(int) * 2);
  results[0] = -1;
  results[1] = -1;
  if(numsSize <= 1) return results;
  int* dists = (int*) malloc (sizeof(int) * numsSize);
  for(int i = 0; i < numsSize; i++)
    {
      dists[i] = target - nums[i];
      for(int j = i+1; j <numsSize; j++)
        {
          if(dists[i] == nums[j])
            {
              results[0] = i;
              results[1] = j;
              free(dists);
              return results;
            }
        }
    }
  return results;
}
