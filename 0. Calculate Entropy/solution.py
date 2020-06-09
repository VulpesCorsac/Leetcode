import math
import numpy as np
from scipy.stats import entropy

class Solution:
    def calculateEntropy1(self, input: List[int]) -> float:
        value, counts = np.unique(input, return_counts=True)
        return entropy(counts, base=2)

    def calculateEntropy2(self, input: List[int]) -> float:
        n = len(input)
        x = {}
        Entropy = 0
        for i in range(0, n):
            if input[i] not in x.keys():
                x[input[i]] = 1
            else:
                x[input[i]] += 1
        for key in x.keys():
            p = x[key]/n
            Entropy += -p*math.log2(p)

        return Entropy

    def calculateEntropy(self, input: List[int]) -> float:
        return self.calculateEntropy2(input)